#pragma once

#include "iolinkconnector.h"
#include "private/socketwrapper.h"
#include "private/apigear_olink.h"
#include "private/isocketuser.h"

#include "olink/clientnode.h"

#include <Poco/URI.h>
#include <Poco/Util/Timer.h>
#include <Poco/Util/TimerTask.h>

#include <atomic>
#include <deque>
#include <memory>
#include <map>

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
class APIGEAR_OLINK_EXPORT OlinkConnection: public ApiGear::PocoImpl::IOlinkConnector, public ISocketUser
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

    /**
    * ISocketUser::handleTextMessage implementation.
    * Handler for raw message received.
    */
    void handleTextMessage(const std::string& message) override;
    /**
    * ISocketUser::onConnectionClosedFromNetwork implementation
    * A callback to inform the socket user that connection was closed with close frame received from network.
    */
    void onConnectionClosedFromNetwork() override;

private:
    /** Sends all the waiting messages when the connection is up. */
    void onConnected();
    /** Cleans up resources after connection closed either from server side(close frame received)
    *   or client side(close frame sent).
    */
    void onDisconnected();

    /* Sends all queued messages and sends close frame*/
    void closeQueue();
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
    SocketWrapper m_socket;

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
