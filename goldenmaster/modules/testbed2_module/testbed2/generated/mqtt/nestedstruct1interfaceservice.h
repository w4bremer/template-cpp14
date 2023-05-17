#pragma once

#include "testbed2/generated/api/testbed2.h"
#include "testbed2/generated/api/common.h"
#include "apigear/mqtt/mqttcppclient.h"

namespace Test {
namespace Testbed2 {
namespace MQTT {
class TEST_TESTBED2_EXPORT NestedStruct1InterfaceService : public virtual ApiGear::MQTT::ISink, public INestedStruct1InterfaceSubscriber
{
public:
    explicit NestedStruct1InterfaceService(std::shared_ptr<INestedStruct1Interface> impl, std::shared_ptr<ApiGear::MQTT::Client> client);
    virtual ~NestedStruct1InterfaceService() override;

    // sink interface
    void onConnected() override;
    void onSignal(const ApiGear::MQTT::Topic&, const std::string&) override {};
    void onPropertyChanged(const ApiGear::MQTT::Topic&, const std::string&) override {};
    void onInvoke(const ApiGear::MQTT::Topic& topic, const std::string& args, const ApiGear::MQTT::Topic& responseTopic, const std::string& correlationData) override;

    // INestedStruct1InterfaceSubscriber interface
    void onSig1(const NestedStruct1& param1) override;
    void onProp1Changed(const NestedStruct1& prop1) override;

private:
    std::shared_ptr<INestedStruct1Interface> m_impl;
    std::shared_ptr<ApiGear::MQTT::Client> m_client;
};
} // namespace MQTT
} // namespace Testbed2
} // namespace Test
