#include <Poco/Util/TimerTaskAdapter.h>
#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>

#include "olink/clientregistry.h"
#include "olink/iobjectsink.h"
#include "olinkconnection.h"

#include <iostream>
#include <memory>

using namespace ApiGear::PocoImpl;

namespace{
    const std::string jsonContentType = "application/json";
    const std::string defaultGatewayUrl = "ws://localhost:8000/ws";
    const std::string closeFramePayload = "bye";
    const std::string pingFramePayload = "ping";
    long retryInterval = 500; //Milliseconds
    long smallDelay = 10; //Milliseconds
    long tryReconnectDelay = 500; //Milliseconds
}

OlinkConnection::OlinkConnection(ApiGear::ObjectLink::ClientRegistry& registry)
    : m_node(ApiGear::ObjectLink::ClientNode::create(registry)),
    m_isConnecting(false),
    m_disconnectRequested(false)
{
    auto writeFunction = [this](const auto& msg) {
        std::unique_lock<std::timed_mutex> lock(m_queueMutex);
        m_queue.push_back(msg);
        lock.unlock();
        scheduleProcessMessages(smallDelay);
    };
    m_node->onWrite(writeFunction);
}

OlinkConnection::~OlinkConnection()
{
    m_disconnectRequested = true;
    // DisconnectAndUnlink modifies collection.
    auto copyObjectLinkStatus = m_objectLinkStatus;
    for(auto& object : copyObjectLinkStatus){
        disconnectAndUnlink(object.first);
    }
    closeQueue();
    if (m_receivingDone.valid()){
        m_receivingDone.wait();
    }
    onDisconnected();
}

void OlinkConnection::receiveInLoop()
{
    onConnected();
    auto serverClosedConnection = false;
    do{
        try {
            // TODO change buffer size
            char buffer[1024];
            std::memset(buffer, 0, sizeof buffer);
            int flags;
            auto canSocketRead = m_socket ? m_socket->poll(Poco::Timespan(10000), Poco::Net::WebSocket::SELECT_READ) : false;
            if (canSocketRead && !m_disconnectRequested && m_socket) {
                std::unique_lock<std::timed_mutex> lock(m_socketMutex);
                auto frameSize = m_socket->receiveFrame(buffer, sizeof(buffer), flags);
                lock.unlock();

                auto frameOpCode = flags & Poco::Net::WebSocket::FRAME_OP_BITMASK;
                if (frameOpCode == Poco::Net::WebSocket::FRAME_OP_PING){
                    writeMessage(buffer, Poco::Net::WebSocket::FRAME_OP_PONG);
                } else if (frameOpCode == Poco::Net::WebSocket::FRAME_OP_PONG) {
                    // handle pong
                } else if (frameSize == 0 || frameOpCode == Poco::Net::WebSocket::FRAME_OP_CLOSE){
                    std::cout << "close connection" << std::endl;
                    serverClosedConnection = true;
                } else {
                    handleTextMessage(buffer);
                }
            }
        }
        catch(Poco::Exception& e) {
            serverClosedConnection = true;
            std::cout << "connection closed with exception:"  << e.what() << std::endl;
        }
    } while (!serverClosedConnection && !m_disconnectRequested);
    if (serverClosedConnection)
    {
        onDisconnected();
    }
}

void OlinkConnection::connectAndLinkObject(std::shared_ptr<ApiGear::ObjectLink::IObjectSink> object)
{
    if (!object){
        std::cout << "could not link an object, because it is not valid" ;
        return;
    }

    m_node->registry().addSink(object);
    if (m_socket){
        m_node->linkRemote(object->olinkObjectName());
        m_objectLinkStatus[object->olinkObjectName()] = LinkStatus::Linked;
    }
    else 
    {
        m_objectLinkStatus[object->olinkObjectName()] = LinkStatus::NotLinked;
    }
}

void OlinkConnection::disconnectAndUnlink(const std::string& objectId)  
{
    auto objectStatus = m_objectLinkStatus.find(objectId);
    if (objectStatus != m_objectLinkStatus.end()) {
        if (objectStatus->second != LinkStatus::NotLinked){
            m_node->unlinkRemote(objectId);
        }
        m_objectLinkStatus.erase(objectStatus);
    }
    m_node->registry().removeSink(objectId);
}

void OlinkConnection::connectToHost(Poco::URI url)
{
    if (m_processMessagesTask){
        m_processMessagesTask->cancel();
    }
    m_disconnectRequested = false;
    if(url.empty()) {
        m_serverUrl = Poco::URI(defaultGatewayUrl);
        std::clog << "No host url provided" << std::endl;
    } else {
        m_serverUrl = url;
    }
    
    if(!m_socket && !m_isConnecting) {
        std::clog << "Connecting to host " << url.toString() << std::endl;
        try {
            m_isConnecting = true;
            Poco::Net::HTTPClientSession session(m_serverUrl.getHost(), m_serverUrl.getPort());
            Poco::Net::HTTPRequest request(Poco::Net::HTTPRequest::HTTP_GET, "/ws", Poco::Net::HTTPMessage::HTTP_1_1);
            request.setKeepAlive(true);
            request.setContentType(jsonContentType);
            Poco::Net::HTTPResponse response;

            m_socket = std::make_unique<Poco::Net::WebSocket>(session, request, response);
            m_receivingDone = std::async(std::launch::async, [this](){receiveInLoop(); });
        } catch (std::exception &e) {
            m_socket.reset();
            std::cerr << "Exception " << e.what() << std::endl;
        }
        m_isConnecting = false;
    }

    // schedule retry if connection fails
    scheduleProcessMessages(smallDelay);
}

void OlinkConnection::disconnect() {
    std::clog << " request to disconnect socket" << std::endl;
    m_disconnectRequested = true;

    for (auto& object : m_objectLinkStatus){
        if (object.second != LinkStatus::NotLinked){
            m_node->unlinkRemote(object.first);
        }
    }
    closeQueue();
    if (m_receivingDone.valid()){
        m_receivingDone.wait();
    }
    onDisconnected();
}

void OlinkConnection::closeQueue()
{
    if (m_processMessagesTask){
        m_processMessagesTask->cancel();
    }
    flushMessages();
    writeMessage(closeFramePayload, Poco::Net::WebSocket::FRAME_OP_CLOSE);
}


std::shared_ptr<ApiGear::ObjectLink::ClientNode> OlinkConnection::node()
{
    return m_node;
}

void OlinkConnection::onConnected()
{
    std::clog << " socket connected" << std::endl;
    for(auto& object : m_objectLinkStatus)
    {
        m_node->linkRemote(object.first);
        object.second = LinkStatus::Linked;
    }
    scheduleProcessMessages(smallDelay);
}

void OlinkConnection::onDisconnected()
{
    for (auto& object : m_objectLinkStatus)
    {
        object.second = LinkStatus::NotLinked;
    }
    m_socket.reset();
    std::clog << " socket disconnected" << std::endl;
}

void OlinkConnection::handleTextMessage(const std::string &message)
{
    m_node->handleMessage(message);
}

void OlinkConnection::scheduleProcessMessages(long delayMiliseconds)
{
    std::unique_lock<std::timed_mutex> lock(m_taskMutex, std::defer_lock);
    if (lock.try_lock()) // else other thread is scheduling a task currently, so the messages would be sent anyway.
    {
        if(m_processMessagesTask){
            m_processMessagesTask->cancel();
        }
        m_processMessagesTask = new Poco::Util::TimerTaskAdapter<OlinkConnection>(*this, &OlinkConnection::processMessages);
        lock.unlock();
        m_retryTimer.schedule(m_processMessagesTask, delayMiliseconds, retryInterval);
    }
}

void OlinkConnection::processMessages(Poco::Util::TimerTask& /*task*/)
{
    if (!m_socket && !m_disconnectRequested) {
        connectToHost(m_serverUrl);
        scheduleProcessMessages(tryReconnectDelay);
        return;
    }
    writeMessage(pingFramePayload, Poco::Net::WebSocket::FRAME_OP_PING);
    flushMessages();    
}

void OlinkConnection::flushMessages()
{
    if (m_socket)
    {
        std::deque<std::string> copyQueue;
        std::unique_lock<std::timed_mutex> lock(m_queueMutex);
        std::swap(copyQueue, m_queue);
        lock.unlock();

        while (!copyQueue.empty()) {
            auto message = copyQueue.front();
            std::clog << "write message to socket " << message << std::endl;
            // if we are using JSON we need to use txt message otherwise binary messages
            auto messageSent = writeMessage(message, Poco::Net::WebSocket::FRAME_TEXT);
            if (messageSent){
                copyQueue.pop_front();
            }
            else {
                if (!m_disconnectRequested){
                    lock.lock();
                    // push again not sent elements to queue front 
                    m_queue.insert(m_queue.begin(), copyQueue.begin(), copyQueue.end());
                    lock.unlock();
                    scheduleProcessMessages(tryReconnectDelay);
                }
                break;
            }
        }
    }
}

bool OlinkConnection::writeMessage(std::string message, int frameOpCode)
{
    bool succeed = false;
    try {
        if (m_socket) {
            std::unique_lock<std::timed_mutex> lock(m_socketMutex);
            m_socket->sendFrame(message.c_str(), static_cast<int>(message.size()), frameOpCode);
            lock.unlock();
            succeed = true;
        }
    }
    catch (std::exception& e) {
        std::cerr << "Exception " << e.what() << std::endl;
    }
    return succeed;
}
