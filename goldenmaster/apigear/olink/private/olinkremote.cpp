#include "Poco/Buffer.h"
#include "Poco/Exception.h"
#include "Poco/Net/WebSocket.h"
#include "private/olinkremote.h"
#include "private/requesthandlerfactory.h"
#include "private/iconnectionstorage.h"
#include "olink/remotenode.h"
#include "olink/remoteregistry.h"
#include <iostream>
#include <chrono>
#include <future>
#include <mutex>

namespace 
{
    const std::string closeFramePayload = "bye";
}

namespace ApiGear {
namespace PocoImpl {

OLinkRemote::OLinkRemote(std::unique_ptr<Poco::Net::WebSocket> socket, IConnectionStorage& connectionStorage, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_socket(std::move(socket)),
     m_connectionStorage(connectionStorage),
     m_stopConnection(false),
     m_node(ApiGear::ObjectLink::RemoteNode::createRemoteNode(registry)),
     m_registry(registry)
{
    if (m_socket){
        // Common default maximum frame size is 1Mb
        m_socket->setMaxPayloadSize(1048576);
    }
    m_node->onLog(m_log.logFunc());
    m_node->onWrite([this](std::string msg) {
        writeMessage(msg, Poco::Net::WebSocket::FRAME_TEXT);
    });
    m_receivingDone = std::async(std::launch::async, [this](){receiveInLoop(); });
}

OLinkRemote::~OLinkRemote(){
    if(m_socket)
    {
        close();
    }
}

void OLinkRemote::close(){
    m_stopConnection = true;
    m_receivingDone.wait();
    writeMessage(closeFramePayload, Poco::Net::WebSocket::FRAME_OP_CLOSE);
    closeSocket();
}

void OLinkRemote::writeMessage(const std::string msg, int frameOpcode)
{
    std::cout << "writing " << msg << std::endl;

    if (m_socket ){
        try {
            std::unique_lock<std::timed_mutex> lock(m_socketMutex);
            m_socket->sendFrame(msg.c_str(), static_cast<int>(msg.size()), frameOpcode);
            lock.unlock();
        }
        catch (Poco::Exception& e) {
            std::cerr << "Exception " << e.what() << std::endl;
        }
    }
}

void OLinkRemote::handleMessage(const std::string& msg)
{
    std::cout << msg;
    if (m_node)
    {
        m_node->handleMessage(msg);
    }
}

void OLinkRemote::receiveInLoop(){
    // TODO change buffer size
    bool clientClosedConnection = false;
    do
    {
        try {
            Poco::Buffer<char> pocobuffer(0);
            int flags;
            auto canSocketRead = m_socket ? m_socket->poll(Poco::Timespan(10000), Poco::Net::WebSocket::SELECT_READ) : false;
            if (canSocketRead && !m_stopConnection){
                std::unique_lock<std::timed_mutex> lock(m_socketMutex);
                auto frameSize = m_socket->receiveFrame(pocobuffer, flags);
                lock.unlock();
                auto messagePayload = std::string(pocobuffer.begin(), frameSize);
                auto frameOpCode = flags & Poco::Net::WebSocket::FRAME_OP_BITMASK;
                if (frameOpCode == Poco::Net::WebSocket::FRAME_OP_PING){
                    writeMessage(messagePayload, Poco::Net::WebSocket::FRAME_OP_PONG);
                } else if (frameOpCode == Poco::Net::WebSocket::FRAME_OP_PONG) {
                    // handle pong
                } else if (frameSize == 0 || frameOpCode == Poco::Net::WebSocket::FRAME_OP_CLOSE){
                    std::cout << "close connection" << std::endl;
                    clientClosedConnection = true;
                } else {
                    handleMessage(messagePayload);
                }
            }
        } catch (Poco::Exception& /*e*/) {
            clientClosedConnection = true;
        }
    } while (!clientClosedConnection && !m_stopConnection);
    if (!m_stopConnection)
    {   
        closeSocket();
        m_connectionStorage.notifyConnectionClosed();
    }
}


bool OLinkRemote::isClosed() const
{
    return m_socket == nullptr;
}

void OLinkRemote::closeSocket()
{
    removeNodeFromRegistryIfNotUnlikend();
    std::unique_lock<std::timed_mutex> lock(m_socketMutex, std::defer_lock);
    if (!lock.try_lock_for(std::chrono::milliseconds(100))) {
        std::cout << "Closing socket, some messages may be dropped" << std::endl;
    }
    m_socket.reset();
    lock.unlock();
}

void OLinkRemote::removeNodeFromRegistryIfNotUnlikend()
{
    auto objectsUsingNode = m_registry.getObjectIds(m_node);
    for (auto objectId : objectsUsingNode)
    {
        m_registry.removeNodeFromSource(m_node, objectId);
    }
}

}}  //namespace ApiGear::PocoImpl
