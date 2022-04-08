/*
* MIT License
*
* Copyright (c) 2021 ApiGear
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/
#include "Poco/Net/HTTPServerRequest.h"
#include "olinkhost.h"
#include <atomic>
#include <iostream>
#include <set>
#include "Poco/Buffer.h"

using namespace ApiGear::PocoImpl;
class OLinkWebsocketHandler;

class OLinkRemote : public Poco::Runnable
{
public:
    explicit OLinkRemote(RequestHandlerFactory* factory, Poco::Net::WebSocket* socket);
    ~OLinkRemote();
    void writeMessage(const std::string msg);
    void handleMessage(const std::string& msg);

    void run() override;
    void close();

private:
    Poco::Net::WebSocket* m_socket;
    ApiGear::ObjectLink::RemoteNode m_node;
    ApiGear::ObjectLink::ConsoleLogger m_log;
    std::atomic<bool> m_stopRequested;
    Poco::Thread m_thread;
    RequestHandlerFactory* m_factory;
};

class OLinkWebsocketHandler :  public Poco::Net::HTTPRequestHandler
{
public:
    explicit OLinkWebsocketHandler(RequestHandlerFactory* factory);
    void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response) override;
    void close();
private:
    RequestHandlerFactory* m_factory;
};

class RequestHandlerFactory: public Poco::Net::HTTPRequestHandlerFactory
{
public:
    RequestHandlerFactory(ApiGear::ObjectLink::RemoteRegistry& registry): m_registry(&registry) {};
    
	Poco::Net::HTTPRequestHandler* createRequestHandler(const Poco::Net::HTTPServerRequest& request)
	{
		std::cout << "Request from " 
			<<request.clientAddress().toString()
			<<": "
			<<request.getMethod()
			<<" "
			<<request.getURI()
			<<" "
			<<request.getVersion() << std::endl;
			
		for (Poco::Net::HTTPServerRequest::ConstIterator it = request.begin(); it != request.end(); ++it)
		{
			std::cout << it->first << ": " << it->second << std::endl;
		}
		
		if(request.find("Upgrade") != request.end() && Poco::icompare(request["Upgrade"], "websocket") == 0) {
            std::cout << "wss.newConnection()\n";
            OLinkWebsocketHandler* handler = new OLinkWebsocketHandler(this);
            return handler;
        }
	}

    void addRemoteConnection(OLinkRemote* connection) {
        m_remoteConnections.insert(connection);
    }

    void  removeRemoteConnection(OLinkRemote* connection) {
        m_remoteConnections.erase(connection);
        delete connection;
    }

    void close()
    {
        for(auto remoteConnection: m_remoteConnections){
            remoteConnection->close();
            delete remoteConnection;
        }
        m_remoteConnections.clear();
    }

    ApiGear::ObjectLink::RemoteRegistry* getRegistry(){
        return m_registry;
    }
private:
    std::set<OLinkRemote*> m_remoteConnections;
    ApiGear::ObjectLink::RemoteRegistry* m_registry;
};

OLinkHost::OLinkHost(ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_webserver(nullptr)
    , m_handlerFactory(nullptr)
    , m_registry(&registry)
{
    m_registry->onLog(m_log.logFunc());
}

OLinkHost::~OLinkHost()
{
    m_webserver->stop();
    delete m_webserver;
    m_webserver = nullptr;
}

void OLinkHost::listen(int port)
{
    std::cout << "wss.listen() on ";
    if(m_handlerFactory == nullptr)
    {
        m_handlerFactory = new RequestHandlerFactory(*m_registry);
    }
    m_webserver = new Poco::Net::HTTPServer(m_handlerFactory, port);
    std::cout << m_webserver->port() << std::endl;
    m_webserver->start();
}

void OLinkHost::close()
{
    m_handlerFactory->close();
    m_webserver->stop();
}

void OLinkHost::onClosed()
{
    std::cout << "wss.closed()\n";
}

OLinkWebsocketHandler::OLinkWebsocketHandler(RequestHandlerFactory* factory)
    :m_factory(factory)
    {}

void OLinkWebsocketHandler::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response){
    m_factory->addRemoteConnection(new OLinkRemote(m_factory, new Poco::Net::WebSocket(request, response)));
}

OLinkRemote::OLinkRemote(RequestHandlerFactory* factory, Poco::Net::WebSocket* socket)
    : m_socket(socket)
    , m_stopRequested(false)
    , m_factory(factory)
    , m_node(*factory->getRegistry())
{
    m_node.onLog(m_log.logFunc());
    ApiGear::ObjectLink::WriteMessageFunc writeFunc = [this](std::string msg) {
        writeMessage(msg);
    };
    m_node.onWrite(writeFunc);
    m_thread.start(*this);
}

OLinkRemote::~OLinkRemote(){

}

void OLinkRemote::close(){
    m_stopRequested = true;
    m_factory = nullptr;
    m_thread.join();
    try {
        if(m_socket != nullptr) {
            m_socket->sendFrame("bye", 3, Poco::Net::WebSocket::FRAME_OP_CLOSE);
        }
    } catch (Poco::Exception &e) {
        std::cerr << "Exception " << e.what() << std::endl;
        return;
    }
}

void OLinkRemote::writeMessage(const std::string msg)
{
    std::cout << msg;
    if(m_socket == nullptr) {
        return;
    }

    try {
        m_socket->sendFrame(msg.c_str(), msg.size());
    }
    catch(Poco::Exception& e) {
        std::cerr << "Exception " << e.what() << std::endl;
        return;
    }
}

void OLinkRemote::handleMessage(const std::string &msg)
{
    std::cout << msg;

    m_node.handleMessage(msg);
}

void OLinkRemote::run(){
    // TODO change buffer size
    char buffer[1024];
    int flags;
    int n;
    bool connectionClosed = false;
    do
    {
        try {
            if (m_socket->poll(Poco::Timespan(10000), 1) && !m_stopRequested) {
                std::memset(buffer, 0, sizeof buffer);
                n = m_socket->receiveFrame(buffer, sizeof(buffer), flags);
                if ((flags & Poco::Net::WebSocket::FRAME_OP_BITMASK) == Poco::Net::WebSocket::FRAME_OP_PING) {
                    m_socket->sendFrame(buffer, n, Poco::Net::WebSocket::FRAME_OP_PONG);
                }
                else if (m_socket != nullptr && ((flags & Poco::Net::WebSocket::FRAME_OP_BITMASK) == Poco::Net::WebSocket::FRAME_OP_PONG))
                {
                    // handle pong
                }
                else if (n == 0 || (flags & Poco::Net::WebSocket::FRAME_OP_BITMASK) == Poco::Net::WebSocket::FRAME_OP_CLOSE)
                {
                    std::cout << "close connection" << std::endl;
                    connectionClosed = true;
                }
                else {
                    handleMessage(buffer);
                }
            }
        }
        catch(Poco::Exception& e) {
            connectionClosed = true;
        }
    }
    while (!connectionClosed && !m_stopRequested);
    std::cout << "connection closed" << std::endl;
    if (m_factory != nullptr) {
        m_factory->removeRemoteConnection(this);
    }
}
