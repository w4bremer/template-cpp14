#include "private/socketwrapper.h"
#include "private/isocketuser.h"
#include "../utilities/logger.h"

#include <Poco/Net/WebSocket.h>
#include "Poco/Buffer.h"
#include "Poco/Exception.h"

#include <iostream>

namespace
{
    const std::string closeFramePayload = "bye";
}


namespace ApiGear {
namespace PocoImpl {

SocketWrapper::SocketWrapper(ISocketUser& socketUser)
    : m_socketUser(socketUser),
    m_disconnectRequested(false)
{
}

void SocketWrapper::startReceiving()
{
    auto closedFromNetwork = false;
    do{
        try {
            // receiveFrame requires pocobuffer with initial size 0, as it always extends it with adding frame content.
            Poco::Buffer<char> pocobuffer(0);
            int flags;
            auto canSocketRead = m_socket ? m_socket->poll(Poco::Timespan(10000), Poco::Net::WebSocket::SELECT_READ) : false;
            if (canSocketRead && !m_disconnectRequested && m_socket) {
                std::unique_lock<std::timed_mutex> lock(m_socketMutex);
                auto frameSize = m_socket->receiveFrame(pocobuffer, flags);
                lock.unlock();
                auto messagePayload = std::string(pocobuffer.begin(), frameSize);
                auto frameOpCode = flags & Poco::Net::WebSocket::FRAME_OP_BITMASK;
                if (frameOpCode == Poco::Net::WebSocket::FRAME_OP_PING){
                    writeMessage(messagePayload, Poco::Net::WebSocket::FRAME_OP_PONG);
                }
                else if (frameOpCode == Poco::Net::WebSocket::FRAME_OP_PONG) {
                    // handle pong
                }
                else if (frameSize == 0 || frameOpCode == Poco::Net::WebSocket::FRAME_OP_CLOSE){
                    AG_LOG_INFO("close connection");
                    closedFromNetwork = true;
                }
                else {
                    m_socketUser.handleTextMessage(messagePayload);
                }
            }
        }
        catch (Poco::Exception& e) {
            closedFromNetwork = true;
            AG_LOG_ERROR("connection closed with exception: "+ std::string(e.what()));
        }
    } while (!closedFromNetwork && !m_disconnectRequested);
    if (closedFromNetwork)
    {
        onClosed();
        m_socketUser.onConnectionClosedFromNetwork();
    }
}

bool SocketWrapper::writeMessage(std::string message, int frameOpCode)
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
        AG_LOG_ERROR("writeMessage Exception: "+ std::string(e.what()));
    }
    return succeed;
}

bool SocketWrapper::isClosed() const
{
    return m_socket == nullptr || m_disconnectRequested;
}

void SocketWrapper::close()
{
    m_disconnectRequested = true;
    if (m_receivingDone.valid()){
        m_receivingDone.wait();
    }
    writeMessage(closeFramePayload, Poco::Net::WebSocket::FRAME_OP_CLOSE);
    onClosed();
}

void SocketWrapper::onClosed()
{
    std::unique_lock<std::timed_mutex> lock(m_socketMutex, std::defer_lock);
    if (!lock.try_lock_for(std::chrono::milliseconds(100))) {
        AG_LOG_INFO("Closing socket, some messages may be dropped");
    }
    m_socket.reset();
    lock.unlock();
}

std::unique_ptr<Poco::Net::WebSocket> SocketWrapper::changeSocket(std::unique_ptr<Poco::Net::WebSocket> otherSocket)
{
    m_disconnectRequested = true;
    if (m_receivingDone.valid()){
        m_receivingDone.wait();
    }
    std::unique_lock<std::timed_mutex> lock(m_socketMutex);
    std::swap(m_socket, otherSocket);
    lock.unlock();
    if (m_socket){
        // Common default maximum frame size is 1Mb
        m_socket->setMaxPayloadSize(1048576);
        m_receivingDone = std::async(std::launch::async, [this](){startReceiving(); });
    }
    m_disconnectRequested = false;
    return otherSocket;
}

}}   //namespace ApiGear::PocoImpl
