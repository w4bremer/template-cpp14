#pragma once

#include "testbed2/generated/api/testbed2.h"
#include "testbed2/generated/api/common.h"
#include "apigear/mqtt/mqttcppclient.h"

namespace Test {
namespace Testbed2 {
namespace MQTT {
class TEST_TESTBED2_EXPORT ManyParamInterfaceService : public virtual ApiGear::MQTT::ISink, public IManyParamInterfaceSubscriber
{
public:
    explicit ManyParamInterfaceService(std::shared_ptr<IManyParamInterface> impl, std::shared_ptr<ApiGear::MQTT::Client> client);
    virtual ~ManyParamInterfaceService() override;

    // sink interface
    void onConnected() override;
    void onSignal(const ApiGear::MQTT::Topic&, const std::string&) override {};
    void onPropertyChanged(const ApiGear::MQTT::Topic&, const std::string&) override {};
    void onInvoke(const ApiGear::MQTT::Topic& topic, const std::string& args, const ApiGear::MQTT::Topic& responseTopic, const std::string& correlationData) override;

    // IManyParamInterfaceSubscriber interface
    void onSig1(int param1) override;
    void onSig2(int param1, int param2) override;
    void onSig3(int param1, int param2, int param3) override;
    void onSig4(int param1, int param2, int param3, int param4) override;
    void onProp1Changed(int prop1) override;
    void onProp2Changed(int prop2) override;
    void onProp3Changed(int prop3) override;
    void onProp4Changed(int prop4) override;

private:
    std::shared_ptr<IManyParamInterface> m_impl;
    std::shared_ptr<ApiGear::MQTT::Client> m_client;
};
} // namespace MQTT
} // namespace Testbed2
} // namespace Test
