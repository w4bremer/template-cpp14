#include <iostream>
#include <Poco/Util/TimerTaskAdapter.h>
#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include "olinkclient.h"

using namespace ApiGear::PocoImpl;

OLinkClient::OLinkClient(ApiGear::ObjectLink::ClientRegistry& registry)
    : m_socket(nullptr)
    , m_node(registry)
    , m_registry(&registry)
    , m_disconnectRequested(false)
{
    m_node.onLog(m_logger.logFunc());
    m_registry->onLog(m_logger.logFunc());
    ApiGear::ObjectLink::WriteMessageFunc func = [this](std::string msg) {
        m_queueMutex.lock(100);
        m_queue.push(msg);
        m_queueMutex.unlock();
        process();
    };
    m_node.onWrite(func);

    // socket connection retry
    m_task = new Poco::Util::TimerTaskAdapter<OLinkClient>(*this, &OLinkClient::processMessages);
    m_retryTimer.schedule(m_task, 10, 5000);
}

OLinkClient::~OLinkClient()
{
    for (auto& object: m_linkedObjects){
        m_node.registry().unlinkClientNode(object, &m_node);
    }
}

void OLinkClient::run()
{
    onConnected();
    // TODO change buffer size
    char buffer[1024];
    int flags;
    int n = 0;
    bool connectionClosed = false;
    do
    {
        try {
            if (m_socket->poll(Poco::Timespan(10000), 1)) {
                std::memset(buffer, 0, sizeof buffer);
                n = m_socket->receiveFrame(buffer, sizeof(buffer), flags);
                if (m_socket != nullptr && ((flags & Poco::Net::WebSocket::FRAME_OP_BITMASK) == Poco::Net::WebSocket::FRAME_OP_PING))
                {
                    m_socket->sendFrame(buffer, n, Poco::Net::WebSocket::FRAME_OP_PONG);
                } else if (m_socket != nullptr && ((flags & Poco::Net::WebSocket::FRAME_OP_BITMASK) == Poco::Net::WebSocket::FRAME_OP_PONG))
                {
                    // handle pong
                }
                else if (n == 0 || (flags & Poco::Net::WebSocket::FRAME_OP_BITMASK) == Poco::Net::WebSocket::FRAME_OP_CLOSE)
                {
                    std::cout << "close connection" << std::endl;
                    connectionClosed = true;
                }
                else {
                    handleTextMessage(buffer);
                }
            }
        }
        catch(Poco::Exception& e) {
            connectionClosed = true;
            std::cout << "connection closed with exception:"  << e.what() << std::endl;
        }
    }
    while (!connectionClosed && !m_disconnectRequested);
    this->onDisconnected();
}

void OLinkClient::connectToHost(Poco::URI url)
{
    static bool connecting = false;
    std::clog << "Connecting to host " << url.toString() << std::endl;
    if(url.empty()) {
        std::string gatewayUrl = "ws://localhost:8000/ws";
        m_serverUrl = Poco::URI(gatewayUrl);
    } else {
        m_serverUrl = url;
    }
    
    Poco::Net::HTTPClientSession session(m_serverUrl.getHost(), m_serverUrl.getPort());
    Poco::Net::HTTPRequest request(Poco::Net::HTTPRequest::HTTP_GET, "/ws", Poco::Net::HTTPMessage::HTTP_1_1);
    request.setKeepAlive(true);
    request.setContentType("application/json");
    Poco::Net::HTTPResponse response;

    if(m_socket == nullptr && !connecting) {
        try {
            connecting = true;
            m_socket = new Poco::Net::WebSocket(session, request, response);
            Poco::ThreadPool::defaultPool().start(*this);
        } catch (std::exception &e) {
            m_socket = nullptr;
            std::cerr << "Exception " << e.what() << std::endl;
        }
        connecting = false;
    }
}

void OLinkClient::disconnect() {
    for (auto& object: m_linkedObjects){
        m_node.unlinkRemote(object);
        m_node.registry().unlinkClientNode(object, &m_node);
    }
    m_linkedObjects.clear();
    
    try {
        if(m_socket != nullptr) {
            m_socket->sendFrame("bye", 3, Poco::Net::WebSocket::FRAME_OP_CLOSE);
        }
    } catch (std::exception &e) {
        std::cerr << "Exception " << e.what() << std::endl;
        return;
    }
    m_disconnectRequested = true;
    m_task->cancel();
    Poco::ThreadPool::defaultPool().joinAll();
}

ApiGear::ObjectLink::ClientRegistry &OLinkClient::registry()
{
    return m_node.registry();
}

ApiGear::ObjectLink::ClientNode &OLinkClient::node()
{
    return m_node;
}

void OLinkClient::linkObjectSource(std::string name)
{
    std::clog << "linkObjectSource:" << name << std::endl;
    m_node.registry().linkClientNode(name, &m_node);
    m_linkedObjects.insert(name);
}

void OLinkClient::onConnected()
{
    std::clog << " socket connected" << std::endl;
    for (auto& object: m_linkedObjects){
        m_node.linkRemote(object);
    }
    process();
}

void OLinkClient::onDisconnected()
{
    delete m_socket;
    m_socket = nullptr;
    std::clog << " socket disconnected" << std::endl;
}

void OLinkClient::handleTextMessage(const std::string &message)
{
    m_node.handleMessage(message);
}

void OLinkClient::process()
{
    m_task->cancel();
    m_task = new Poco::Util::TimerTaskAdapter<OLinkClient>(*this, &OLinkClient::processMessages);
    m_retryTimer.schedule(m_task, 10, 5000);
}

void OLinkClient::processMessages(Poco::Util::TimerTask& task)
{
    if (m_socket == nullptr) {
        m_task->cancel();
        connectToHost(m_serverUrl);
        m_task = new Poco::Util::TimerTaskAdapter<OLinkClient>(*this, &OLinkClient::processMessages);
        m_retryTimer.schedule(m_task, 5000, 5000);
        return;
    }
    m_socket->sendFrame("ping", 4, Poco::Net::WebSocket::FRAME_OP_PING);
    m_queueMutex.lock(100);
    while(!m_queue.empty()) {
        // if we are using JSON we need to use txt message
        // otherwise binary messages
        const std::string msg = m_queue.front();
        std::clog << "write message to socket " << msg << std::endl;
        try {
            if(m_socket != nullptr) {
                m_socket->sendFrame(msg.c_str(),msg.size());
                m_queue.pop();
            }
            else
            {
                return;
            }
        } catch (std::exception &e) {
            std::cerr << "Exception " << e.what() << std::endl;
            return;
        }
    }
    m_queueMutex.unlock();
}
