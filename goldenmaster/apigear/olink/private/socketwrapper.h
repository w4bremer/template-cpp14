#pragma once

#include "apigear_olink.h"

#include <Poco/Net/WebSocket.h>

#include <atomic>
#include <memory>
#include <future>

namespace ApiGear {


namespace PocoImpl {

class ISocketUser;

/**
* A helper class for wrapping POCO::WebSocket.
* Adds receiving message in a separate thread.
* Adds thread safety for writing and reading through socket.
*/
class APIGEAR_OLINK_EXPORT  SocketWrapper
{
public:

    /**
    * ctor
    * @param socketUser A user that will be notified about events defined as ISocketUser API.
    */
    SocketWrapper(ISocketUser& socketUser);

    /** 
    * Sends message through the socket.
    * If the connection is not working, message will not be stored to resend.
    * @param message a message in network format to be send as it is.
    * @param the frame opcode. Use FRAME_TEXT or FRAME_BINARY for regular text messages
    *   see Poco::Net::WebSocket Frame Opcodes for more info.
    * @return true if message was sent, false otherwise.
    */
    bool writeMessage(std::string message, int frameOpCode);
    /**
    * Checks if connection is in closed state
    * @return true if connection is in closed state, false if it is up and running.
    */
    bool isClosed() const;
    
    /**
    * Requests closing connection with sending a close frame and puts the class in closed state.
    * From now the messages cannot be received and send, connection cannot be restored.
    * This is final state from which socket cannot recover, only a new socket can be given to SocketWrapper to wrap and use.
    * see SocketWrapper::changeSocket function
    */
    void close();

    /**
    * Use this function to set new socket that SocketWrapper is wrapping.
    * @param otherSocket. A socket that SocketWrapper is about to wrap and take ownership of.
    * @return A socket that SocketWrapper was wrapping before this function call, and which ownership is
    *   given away to a caller. May be empty if no socket was used before or if connection is already closed. 
    */
    std::unique_ptr<Poco::Net::WebSocket> changeSocket(std::unique_ptr<Poco::Net::WebSocket> otherSocket);

private:
    /**
    * Receives messages from clients. Blocking function, run in a separate thread.
    */
    void startReceiving();
    /** Helper function to finalize closing socket and cleans up resources. */
    void onClosed();

    /** The websocket used for connection.*/
    std::unique_ptr<Poco::Net::WebSocket> m_socket;
    /** A mutex for the socket */
    std::timed_mutex m_socketMutex;
    /** Flag handled between the threads with information that the connection should be closed. */
    std::atomic<bool> m_disconnectRequested;
    /** Result of receiveInLoop. Used to wait for end of its work after m_stopConnection is set to true*/
    std::future<void> m_receivingDone;
    /** A user that will be notified about events defined as ISocketUser API. */
    ISocketUser& m_socketUser;
};

}}   //namespace ApiGear::PocoImpl
