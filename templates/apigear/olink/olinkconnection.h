#pragma once

#if defined _WIN32 || defined __CYGWIN__
#ifdef __GNUC__
  #define APIGEAR_OLINK_EXPORT __attribute__ ((dllexport))
#else
  #define APIGEAR_OLINK_EXPORT __declspec(dllexport)
#endif
#else
  #if __GNUC__ >= 4
    #define APIGEAR_OLINK_EXPORT __attribute__ ((visibility ("default")))
  #else
    #define APIGEAR_OLINK_EXPORT
  #endif
#endif

#include <Poco/URI.h>
#include <Poco/Util/Timer.h>
#include <Poco/Util/TimerTask.h>
#include <Poco/Mutex.h>
#include <Poco/Net/WebSocket.h>

#include "olink/clientnode.h"
#include "olink/consolelogger.h"

#include "iolinkconnector.h"

#include <atomic>
#include <queue>
#include <set>
#include <memory>
#include <future>

namespace ApiGear {

namespace ObjectLink {
// Forward declaration for ApiGear::ObjectLink::IObjectSink
    class IObjectSink;
}// namespace ObjectLink

namespace PocoImpl {

/**
* A class responsible for network connection for ObjectLink client side. Creates a socket and provides write function
* that allows a client node it holds to use the sink.
* It handles linking and unlinking with remote service for the sink with regard to the connection state.
* Implements a message queue.
*/
class APIGEAR_OLINK_EXPORT OlinkConnection: public ApiGear::PocoImpl::IOlinkConnector
{
protected:
    /**
    * ctor
    * @param registry. A global client registry to which the client node and sink object are added.
    * Remark: the registered objects must provide unique identifiers
    */
    OlinkConnection(ApiGear::ObjectLink::ClientRegistry& registry);
public:
    /**
    * Factory method to get shared_ptr<OlinkConnection>
    * @param registry. A global client registry to which the client node and sink object are added.
    * Remark: the registered objects must provide unique identifiers
    */
    static std::shared_ptr<OlinkConnection> create(ApiGear::ObjectLink::ClientRegistry& registry);
    //TODO what with closing the connection
    virtual ~OlinkConnection();

    /**
    * Use this function to set up a connection to server.
    * Automatically links all the sinks that requested linking with the remote sources when connection is established.
    * @param url the server url.
    */
    void connectToHost(Poco::URI url=Poco::URI());
    /**
    * Use this function to close connection with server.
    * Automatically unlinks all the sinks that are using its connection.
    */
    void disconnect();
    /**
    * Get underlaying client node.
    * @retunr a client node for which this OlinkConnection sets up the connection.
    */
    ApiGear::ObjectLink::ClientNode& node();

    /** IOlinkConnector::connectAndLinkObject implementation*/
    void connectAndLinkObject(ApiGear::ObjectLink::IObjectSink& object) override;
    /** IOlinkConnector::disconnectAndUnlink implementation*/
    void disconnectAndUnlink(const std::string& objectId)  override;

private:
    /** 
    * Implements handling incoming messages in a loop.
    */
    void receiveInLoop();
    /** Sends all the waiting messages when the connection is up. */
    void onConnected();
    /** Handle disconnect sent from server side.
    Sends all the necessary close messages when about to close socket. */
    void onDisconnected();
    /** Handler for raw messages.*/
    void handleTextMessage(const std::string& message);
    /**
    * Processes queued messages.
    * @param task. Parameter is not used. The function uses most recent task stored as a member.
    */
    void processMessages(Poco::Util::TimerTask& task);
    /** Schedules a process messages task.*/
    void scheduleProcessMessages();

    /** Finalize close connection. */
    void cleanupConnectionResources();
    /** Tries to send message immediately without queuing. 
    * If the connection is not working, message will not be stored to resend.
    * @param message a message in network format to be send as it is.
    * @param the frame opcode. Use FRAME_TEXT or FRAME_BINARY for regular text messages
    *   see Poco::Net::WebSocket Frame Opcodes for more info.
    * @return true if message was sent, false otherwise.
    */
    bool trySendImmediately(std::string message, int frameOpCode);

    /** Client node that separates sinks Objects from created socket, and handles incoming and outgoing messages. */
    ApiGear::ObjectLink::ClientNode m_node;

    /** The server url to which socket connects. */
    Poco::URI m_serverUrl;
    /** The websocket used for connection.*/
    std::unique_ptr<Poco::Net::WebSocket> m_socket;
    /** The timer used for to process messages. */
    Poco::Util::Timer m_retryTimer;
    /** Poco Task that handles processing messages */
    Poco::Util::TimerTask::Ptr m_processMessagesTask;
    /** Messages queue, store messages to send also before the connection is set. */
    std::queue<std::string> m_queue;
    /** A mutex for the message queue */
    Poco::Mutex m_queueMutex;
    /** Flag handled between the threads with information that the connection should be closed. */
    std::atomic<bool> m_disconnectRequested;
    /** Result of receiveInLoop. Used to wait for end of its work after m_stopConnection is set to true*/
    std::future<void> m_receivingDone;
};
}} // namespace ApiGear::PocoImpl
