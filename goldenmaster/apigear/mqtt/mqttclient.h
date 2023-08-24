#pragma once

#include <memory>
#include "nlohmann/json.hpp"
#include "mqttcommon.h"
#include "mqtttypes.h"

namespace ApiGear {
namespace MQTT {

class APIGEAR_MQTT_EXPORT Client
{
public:
    explicit Client(const std::string& clientID);
    virtual ~Client();

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

    // client interface
    void invokeRemote(const std::string& name, const std::string& responseTopic, const std::string& value, int responseId);
    void setRemoteProperty(const std::string& name, const std::string& value);

    void subscribeTopic(const std::string& name, CallbackFunction func);
    void unsubscribeTopic(const std::string& name);

    const std::string& getClientId() const;

private:
    std::shared_ptr<class CWrapper> m_cwrapper;
};
} // namespace MQTT
} // namespace ApiGear
