#pragma once

#include "testbed2/generated/api/testbed2.h"
#include "testbed2/generated/api/common.h"
#include "apigear/mqtt/mqttservice.h"

namespace Test {
namespace Testbed2 {
namespace MQTT {
class TEST_TESTBED2_EXPORT NestedStruct1InterfaceService : public INestedStruct1InterfaceSubscriber
{
public:
    explicit NestedStruct1InterfaceService(std::shared_ptr<INestedStruct1Interface> impl, std::shared_ptr<ApiGear::MQTT::Service> service);
    virtual ~NestedStruct1InterfaceService() override;

    void onConnectionStatusChanged(bool connectionStatus);

    // INestedStruct1InterfaceSubscriber interface
    void onSig1(const NestedStruct1& param1) override;

private:
    /// @brief factory to create the topic map which is used for bindings
    /// @return map with all topics and corresponding function callbacks
    std::map<std::string, ApiGear::MQTT::CallbackFunction> createTopicMap();
    void onInvokeFunc1(const std::string& args, const std::string& responseTopic, const std::string& correlationData) const;
    void onProp1Changed(const NestedStruct1& prop1) override;
    /// @brief requests to set the value for the property Prop1 coming from the client
    /// @param fields contains the param of the type NestedStruct1
    void onSetProp1(const std::string& args) const;

    std::shared_ptr<INestedStruct1Interface> m_impl;
    std::shared_ptr<ApiGear::MQTT::Service> m_service;
    // id for connection status registration
    int m_connectionStatusRegistrationID;

    /// @brief has all the topics of this service and the corresponding function callbacks
    const std::map<std::string, ApiGear::MQTT::CallbackFunction> m_topics;
};
} // namespace MQTT
} // namespace Testbed2
} // namespace Test
