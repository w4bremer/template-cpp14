#pragma once

#include "testbed2/generated/api/testbed2.h"
#include "testbed2/generated/api/common.h"
#include "apigear/mqtt/mqttservice.h"

namespace Test {
namespace Testbed2 {
namespace MQTT {
class TEST_TESTBED2_EXPORT NestedStruct2InterfaceService : public INestedStruct2InterfaceSubscriber
{
public:
    explicit NestedStruct2InterfaceService(std::shared_ptr<INestedStruct2Interface> impl, std::shared_ptr<ApiGear::MQTT::Service> service);
    virtual ~NestedStruct2InterfaceService() override;

    void onConnectionStatusChanged(bool connectionStatus);
    void onInvokeFunc1(const std::string& args, const std::string& responseTopic, const std::string& correlationData) const;
    void onInvokeFunc2(const std::string& args, const std::string& responseTopic, const std::string& correlationData) const;

    // INestedStruct2InterfaceSubscriber interface
    void onSig1(const NestedStruct1& param1) override;
    void onSig2(const NestedStruct1& param1, const NestedStruct2& param2) override;
    void onProp1Changed(const NestedStruct1& prop1) override;
    /// @brief requests to set the value for the property Prop1 coming from the client
    /// @param fields contains the param of the type NestedStruct1
    void onSetProp1(const std::string& args) const;
    void onProp2Changed(const NestedStruct2& prop2) override;
    /// @brief requests to set the value for the property Prop2 coming from the client
    /// @param fields contains the param of the type NestedStruct2
    void onSetProp2(const std::string& args) const;

private:
    std::shared_ptr<INestedStruct2Interface> m_impl;
    std::shared_ptr<ApiGear::MQTT::Service> m_service;
    // id for connection status registration
    int m_connectionStatusRegistrationID;

    /// @brief has all the topics of this service and the corresponding function callbacks
    const std::map<std::string, ApiGear::MQTT::CallbackFunction> m_topics;
};
} // namespace MQTT
} // namespace Testbed2
} // namespace Test
