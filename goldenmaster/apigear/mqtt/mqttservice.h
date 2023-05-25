#pragma once

#include <memory>
#include "nlohmann/json.hpp"
#include "mqttcommon.h"
#include "mqtttopic.h"
#include "mqtttypes.h"

namespace ApiGear {
namespace MQTT {

class ISink;

class APIGEAR_MQTT_EXPORT Service
{
public:
    explicit Service(const std::string& clientID);
    virtual ~Service();

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

    void subscribeTopic(const Topic& name, ISink* sink);
    void unsubscribeTopic(const Topic& name, ISink* sink);

    const std::string& getClientId() const;

private:
    std::unique_ptr<class CWrapper> m_cwrapper;
};
} // namespace MQTT
} // namespace ApiGear
