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
#include <deque>
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
public:
    /**
    * ctor
    * @param registry. A global client registry to which the client node and sink object are added.
    * Remark: the registered objects must provide unique identifiers
    */
    OlinkConnection(ApiGear::ObjectLink::ClientRegistry& registry);

    /** dtor */
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
    std::shared_ptr<ApiGear::ObjectLink::ClientNode> node();

    /** IOlinkConnector::connectAndLinkObject implementation*/
    void connectAndLinkObject(std::shared_ptr<ApiGear::ObjectLink::IObjectSink> object) override;
    /** IOlinkConnector::disconnectAndUnlink implementation*/
    void disconnectAndUnlink(const std::string& objectId)  override;

private:
    /** 
    * Implements handling incoming messages in a loop.
    */
    void receiveInLoop();
    /** Sends all the waiting messages when the connection is up. */
    void onConnected();
    /** Cleans up resources after connection closed either from server side(close frame received)
    *   or client side(close frame sent).
    */
    void onDisconnected();

    /* Sends all queued messages and sends close frame*/
    void closeQueue();

    /** Handler for raw messages.*/
    void handleTextMessage(const std::string& message);
    /**
    * Processes queued messages.
    * @param task. Parameter is not used. The function uses most recent task stored as a member.
    */
    void processMessages(Poco::Util::TimerTask& task);
    /** Schedules a process messages task.
        @param delayMiliseconds. A delay with which task is scheduled.
    */
    void scheduleProcessMessages(long delayMiliseconds);

    /** Sends all stored messages*/
    void flushMessages();

    /** Tries to send message immediately without queuing. 
    * If the connection is not working, message will not be stored to resend.
    * @param message a message in network format to be send as it is.
    * @param the frame opcode. Use FRAME_TEXT or FRAME_BINARY for regular text messages
    *   see Poco::Net::WebSocket Frame Opcodes for more info.
    * @return true if message was sent, false otherwise.
    */
    bool writeMessage(std::string message, int frameOpCode);

    /** Client node that separates sinks Objects from created socket, and handles incoming and outgoing messages. */
    std::shared_ptr<ApiGear::ObjectLink::ClientNode> m_node;

    enum class LinkStatus
    {
        Linked,
        NotLinked
    };
    std::map<std::string, LinkStatus> m_objectLinkStatus;

    /** The server url to which socket connects. */
    Poco::URI m_serverUrl;
    /** The websocket used for connection.*/
    std::unique_ptr<Poco::Net::WebSocket> m_socket;
    /** A mutex for the socket */
    std::timed_mutex m_socketMutex;
    /** Flag handled between the threads with information that the connection should be closed. */
    std::atomic<bool> m_disconnectRequested;
    /** Result of receiveInLoop. Used to wait for end of its work after m_disconnectRequested is set to true*/
    std::future<void> m_receivingDone;

    /** Flag to protect against opening a connection from many threads at the same time*/
    std::atomic<bool> m_isConnecting;

    /** The timer used for to process messages. */
    Poco::Util::Timer m_retryTimer;
    /** Poco Task that handles processing messages */
    Poco::Util::TimerTask::Ptr m_processMessagesTask;
    /** A mutex for the process messages task */
    std::timed_mutex m_taskMutex;
    /** Messages queue, store messages to send also before the connection is set. */
    std::deque<std::string> m_queue;
    /** A mutex for the message queue */
    std::timed_mutex m_queueMutex;


};
}} // namespace ApiGear::PocoImpl