#pragma once

#include "testbed1/generated/api/testbed1.h"
#include "testbed1/generated/api/common.h"
#include "apigear/mqtt/mqttcppclient.h"
#include "mqttisink.h"

namespace Test {
namespace Testbed1 {
namespace MQTT {
class TEST_TESTBED1_EXPORT StructArrayInterfaceService : public virtual ApiGear::MQTT::ISink, public IStructArrayInterfaceSubscriber
{
public:
    explicit StructArrayInterfaceService(std::shared_ptr<IStructArrayInterface> impl, std::shared_ptr<ApiGear::MQTT::Client> client);
    virtual ~StructArrayInterfaceService() override;

    // sink interface
    void onConnected() override;
    void onSignal(const ApiGear::MQTT::Topic&, const std::string&) override {};
    void onPropertyChanged(const ApiGear::MQTT::Topic&, const std::string&) override {};
    void onInvoke(const ApiGear::MQTT::Topic& topic, const std::string& args, const ApiGear::MQTT::Topic& responseTopic, const std::string& correlationData) override;

    // IStructArrayInterfaceSubscriber interface
    void onSigBool(const std::list<StructBool>& paramBool) override;
    void onSigInt(const std::list<StructInt>& paramInt) override;
    void onSigFloat(const std::list<StructFloat>& paramFloat) override;
    void onSigString(const std::list<StructString>& paramString) override;
    void onPropBoolChanged(const std::list<StructBool>& propBool) override;
    void onPropIntChanged(const std::list<StructInt>& propInt) override;
    void onPropFloatChanged(const std::list<StructFloat>& propFloat) override;
    void onPropStringChanged(const std::list<StructString>& propString) override;

private:
    std::shared_ptr<IStructArrayInterface> m_impl;
    std::shared_ptr<ApiGear::MQTT::Client> m_client;
};
} // namespace MQTT
} // namespace Testbed1
} // namespace Test
