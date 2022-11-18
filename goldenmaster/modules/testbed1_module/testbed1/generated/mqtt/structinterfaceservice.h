#pragma once

#include "testbed1/generated/api/testbed1.h"
#include "testbed1/generated/api/common.h"
#include "apigear/mqtt/mqttcppclient.h"

namespace Test {
namespace Testbed1 {
namespace mqtt {
class TEST_TESTBED1_EXPORT StructInterfaceService : public virtual ApiGear::MQTTImpl::ISink, public IStructInterfaceSubscriber
{
public:
    explicit StructInterfaceService(std::shared_ptr<IStructInterface> impl, std::shared_ptr<ApiGear::MQTTImpl::Client> client);
    virtual ~StructInterfaceService() override;

    // sink interface
    void onConnected() override;
    void onSignal(const ApiGear::MQTTImpl::Topic&, const std::string&) override {};
    void onPropertyChanged(const ApiGear::MQTTImpl::Topic&, const std::string&) override {};
    void onInvoke(const ApiGear::MQTTImpl::Topic& topic, const std::string& args, const ApiGear::MQTTImpl::Topic& responseTopic, const std::string& correlationData) override;

    // IStructInterfaceSubscriber interface
    void onSigBool(const StructBool& paramBool) override;
    void onSigInt(const StructInt& paramInt) override;
    void onSigFloat(const StructFloat& paramFloat) override;
    void onSigString(const StructString& paramString) override;
    void onPropBoolChanged(const StructBool& propBool) override;
    void onPropIntChanged(const StructInt& propInt) override;
    void onPropFloatChanged(const StructFloat& propFloat) override;
    void onPropStringChanged(const StructString& propString) override;

private:
    std::shared_ptr<IStructInterface> m_impl;
    std::shared_ptr<ApiGear::MQTTImpl::Client> m_client;
};
} // namespace mqtt
} // namespace Testbed1
} // namespace Test
