#pragma once

#include "tb_same1/generated/api/tb_same1.h"
#include "tb_same1/generated/api/common.h"
#include "apigear/mqtt/mqttcppclient.h"

namespace Test {
namespace TbSame1 {
namespace mqtt {
class TEST_TB_SAME1_EXPORT SameEnum1InterfaceService : public virtual ApiGear::MQTTImpl::ISink, public ISameEnum1InterfaceSubscriber
{
public:
    explicit SameEnum1InterfaceService(std::shared_ptr<ISameEnum1Interface> impl, std::shared_ptr<ApiGear::MQTTImpl::Client> client);
    virtual ~SameEnum1InterfaceService() override;

    // sink interface
    void onConnected() override;
    void onSignal(const ApiGear::MQTTImpl::Topic&, const std::string&) override {};
    void onPropertyChanged(const ApiGear::MQTTImpl::Topic&, const std::string&) override {};
    void onInvoke(const ApiGear::MQTTImpl::Topic& topic, const std::string& args, const ApiGear::MQTTImpl::Topic& responseTopic, const std::string& correlationData) override;

    // ISameEnum1InterfaceSubscriber interface
    void onSig1(Enum1Enum param1) override;
    void onProp1Changed(Enum1Enum prop1) override;

private:
    std::shared_ptr<ISameEnum1Interface> m_impl;
    std::shared_ptr<ApiGear::MQTTImpl::Client> m_client;
};
} // namespace mqtt
} // namespace TbSame1
} // namespace Test
