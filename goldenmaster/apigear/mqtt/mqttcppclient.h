#pragma once

#include "nlohmann/json.hpp"
#include "private/mqttcwrapper.h"
#include "mqttcommon.h"
#include "mqtttopic.h"

namespace ApiGear {
namespace MQTT {

class ISink;

/**
 * @brief Describes incoming part of messages of the protocol for client side.
 * 
 * Since in MQTT there are only clients connected to a central broker,
 * the service and client side use this class to connect to each other via the broker.
 */
class APIGEAR_MQTT_EXPORT Client
{
public:
    explicit Client(const std::string& clientID);
    virtual ~Client() = default;
public:
    /**
    * Connects to the specified broker brokerURL
    * @param brokerURL The address of the broker
    */
    void connectToHost(const std::string& brokerURL);
    /**
    * Disconnects from the broker
    */
    void disconnect();

    // subscribe to be notified about connection changes
    int subscribeToConnectionStatus(OnConnectionStatusChangedCallBackFunction callBack);
    // unsubscribe from connection changes
    void unsubscribeToConnectionStatus(int subscriptionID);

    // service interface
    void notifyPropertyChange(const Topic& name, const std::string& value);
    void notifySignal(const Topic& name, const std::string& args);
    void notifyInvokeResponse(const Topic& responseTopic, const std::string& value, const std::string& correlationData);

    // client interface
    void invokeRemote(const Topic& name, const std::string& value, InvokeReplyFunc func=nullptr);
    void setRemoteProperty(const Topic& name, const std::string& value);

    void subscribeTopic(const Topic& name, ISink* sink);
    void unsubscribeTopic(const Topic& name, ISink* sink);

    void confirmSubscription(const Topic& name, ISink& sink);
    void removeSubscription(const Topic& name);

    const std::string& getClientId() const;

private:
    std::unique_ptr<CWrapper> m_cwrapper;
};
} // namespace MQTT
} // namespace ApiGear
