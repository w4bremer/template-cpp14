#pragma once

#include "olink/remotenode.h"
#include "olink/consolelogger.h"

#include <Poco/Net/WebSocket.h>
#include <atomic>
#include <memory>
#include <mutex>
#include <future>

namespace ApiGear {

namespace ObjectLink {
// Forward declaration of RemoteRegistry
class RemoteRegistry;
} // namespace ObjectLink

namespace PocoImpl {
// Forward declaration of IConnectionStorage
class IConnectionStorage;

/**
* ServerConnection provides network implementation for connection.
* It receives messages for given websocket and allows writing messages to it.
*/
class OLinkRemote
{
public:
    /**
    * ctor
    * @param socket A socket used for this connection.
    * @param connectionStorage Storage that needs to be informed if client ended the connection.
    * @param registry. A global registry to which network endpoints are added for olink objects.
    */
    explicit OLinkRemote(std::unique_ptr<Poco::Net::WebSocket> socket,
                        IConnectionStorage& connectionStorage,
                        ApiGear::ObjectLink::RemoteRegistry& registry);
    /**dtor*/
    ~OLinkRemote();
    /**
    * Writes given message with a frame opcode into network.
    * @param msg A ready to send message in network order. No changes will be made for the message.
    * @param frameOpcode. Use Poco::Net::WebSocket::FRAME_TEXT or Poco::Net::WebSocket::FRAME_BINARY for regular text messages.
    */
    void writeMessage(const std::string msg, int frameOpcode);
    /**
    * Closes connection with sending a close frame and puts the class in closed state.
    * From now the messages cannot be received and send, connection cannot be restored.
    * This is final state from which class cannot recover.
    */
    void close();
    /** 
    * Checks if connection is in closed state
    * @return true if connection is in closed state, false if it is up and running.
    */
    bool isClosed() const;

private:
    /**
    * Calls the message handler for a regular successfully received frame.
    */
    void handleMessage(const std::string& msg);
    /**
    * Closes socket and puts the class in closed state.
    * From now the messages cannot be received and send, connection cannot be restored.
    * This is final state from which class cannot recover.
    */
    void closeSocket();
    /**
    * Receives messages from clients. Blocking function.
    */
    void receiveInLoop();
    /**
    * Call this function when closing connection.
    * Removes the node from registry, for objects which didn't got the unlink message for this connection.
    */
    void removeNodeFromRegistryIfNotUnlikend();

    /**A socket used for this connection.*/
    std::unique_ptr<Poco::Net::WebSocket> m_socket;
    /**Storage that needs to be informed if client ended the connection.*/
    IConnectionStorage& m_connectionStorage;

    /** Flag to inform a receiving working in a loop to stop work when set to true.*/
    std::atomic<bool> m_stopConnection;
    /** Result of receiveInLoop. Used to wait for end of its work after m_stopConnection is set to true*/
    std::future<void> m_receivingDone;
    /** A mutex for the using socket */
    std::timed_mutex m_socektMutex;

    /** An abstract connection endpoint for services, network implementation independent.
    *   may serve several services associated with this node by the unique objectId given in link message.
    */
    std::shared_ptr<ApiGear::ObjectLink::RemoteNode> m_node;
    /**A global registry to which network endpoints are added for olink objects. */
    ApiGear::ObjectLink::RemoteRegistry& m_registry;
    /** Logger*/
    ApiGear::ObjectLink::ConsoleLogger m_log;
};
}}   //namespace ApiGear::PocoImpl
