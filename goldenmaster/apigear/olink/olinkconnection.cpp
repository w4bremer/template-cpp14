#include <Poco/Util/TimerTaskAdapter.h>
#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/WebSocket.h>

#include "olinkconnection.h"
#include "olink/clientregistry.h"
#include "olink/iobjectsink.h"
#include "../utilities/logger.h"

#include <iostream>
#include <memory>

using namespace ApiGear::PocoImpl;

namespace{
    const std::string jsonContentType = "application/json";
    const std::string defaultGatewayUrl = "ws://localhost:8000/ws";
    const std::string pingFramePayload = "ping";
    long retryInterval = 500; //Milliseconds
    long smallDelay = 10; //Milliseconds
    long tryReconnectDelay = 500; //Milliseconds
}

OlinkConnection::OlinkConnection(ApiGear::ObjectLink::ClientRegistry& registry)
    : m_node(ApiGear::ObjectLink::ClientNode::create(registry)),
    m_socket(*this),
    m_isConnecting(false)
{
    auto writeFunction = [this](const auto& msg) {
        std::unique_lock<std::timed_mutex> lock(m_queueMutex);
        m_queue.push_back(msg);
        lock.unlock();
        scheduleProcessMessages(smallDelay);
    };
    m_node->onWrite(writeFunction);
}

void OlinkConnection::onConnectionClosedFromNetwork()
{
    onDisconnected();
    scheduleProcessMessages(tryReconnectDelay);
}

OlinkConnection::~OlinkConnection()
{
    // DisconnectAndUnlink modifies collection.
    auto copyObjectLinkStatus = m_objectLinkStatus;
    for(auto& object : copyObjectLinkStatus){
        disconnectAndUnlink(object.first);
    }
    closeQueue();
    if (!m_socket.isClosed())
    {
        m_socket.close();
    }
    onDisconnected();
}

void OlinkConnection::connectAndLinkObject(std::shared_ptr<ApiGear::ObjectLink::IObjectSink> object)
{
    if (!object){
        AG_LOG_WARNING("could not link an object, because it is not valid");
        return;
    }

    m_node->registry().addSink(object);
    if (!m_socket.isClosed()){
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
    if (m_processMessagesTask) {
        std::unique_lock<std::timed_mutex> lock(m_taskMutex);
        m_processMessagesTask->cancel();
        m_processMessagesTask.reset();
        lock.unlock();
    }

    if(url.empty()) {
        m_serverUrl = Poco::URI(defaultGatewayUrl);
        AG_LOG_DEBUG("No host url provided");
    } else {
        m_serverUrl = url;
    }
    
    if(m_socket.isClosed() && !m_isConnecting) {
        AG_LOG_INFO("Connecting to host " + url.toString());
        try {
            m_isConnecting = true;
            Poco::Net::HTTPClientSession session(m_serverUrl.getHost(), m_serverUrl.getPort());
            Poco::Net::HTTPRequest request(Poco::Net::HTTPRequest::HTTP_GET, "/ws", Poco::Net::HTTPMessage::HTTP_1_1);
            request.setKeepAlive(true);
            request.setContentType(jsonContentType);
            Poco::Net::HTTPResponse response;
            auto socket = std::make_unique<Poco::Net::WebSocket>(session, request, response);
            m_socket.changeSocket(std::move(socket));
            onConnected();

        } catch (std::exception &e) {
            m_socket.close();
            AG_LOG_ERROR("Exception " + std::string(e.what()));
        }
        m_isConnecting = false;
    }
}

void OlinkConnection::disconnect() {
    AG_LOG_DEBUG("request to disconnect socket");
    for (auto& object : m_objectLinkStatus){
        if (object.second != LinkStatus::NotLinked){
            m_node->unlinkRemote(object.first);
        }
    }
    closeQueue();
    m_socket.close();
    onDisconnected();
}

void OlinkConnection::closeQueue()
{
    if (m_processMessagesTask){
        std::unique_lock<std::timed_mutex> lock(m_taskMutex);
        m_processMessagesTask->cancel();
        m_processMessagesTask.reset();
        lock.unlock();
    }
    flushMessages();
}


std::shared_ptr<ApiGear::ObjectLink::ClientNode> OlinkConnection::node()
{
    return m_node;
}

void OlinkConnection::onConnected()
{
    AG_LOG_INFO("socket connected");
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
    AG_LOG_INFO("socket disconnected");
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
        if (!m_processMessagesTask){
            m_processMessagesTask = new Poco::Util::TimerTaskAdapter<OlinkConnection>(*this, &OlinkConnection::processMessages);
            m_retryTimer.schedule(m_processMessagesTask, delayMiliseconds, retryInterval);
            lock.unlock();
        }
    }
}

void OlinkConnection::processMessages(Poco::Util::TimerTask& /*task*/)
{
    if (m_socket.isClosed()) {
        connectToHost(m_serverUrl);
        scheduleProcessMessages(tryReconnectDelay);
        return;
    }
    std::unique_lock<std::timed_mutex> lock(m_taskMutex);
    m_processMessagesTask->cancel();
    m_processMessagesTask.reset();
    m_socket.writeMessage(pingFramePayload, Poco::Net::WebSocket::FRAME_OP_PING);
    lock.unlock();
    flushMessages();
}

void OlinkConnection::flushMessages()
{
    if (!m_socket.isClosed())
    {
        std::deque<std::string> copyQueue;
        std::unique_lock<std::timed_mutex> lock(m_queueMutex);
        std::swap(copyQueue, m_queue);
        lock.unlock();

        while (!copyQueue.empty()) {
            auto message = copyQueue.front();
            AG_LOG_DEBUG("write message to socket " + message);
            // if we are using JSON we need to use txt message otherwise binary messages
            auto messageSent = m_socket.writeMessage(message, Poco::Net::WebSocket::FRAME_TEXT);
            if (messageSent){
                copyQueue.pop_front();
            }
            else {
                if (!m_socket.isClosed()){
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
