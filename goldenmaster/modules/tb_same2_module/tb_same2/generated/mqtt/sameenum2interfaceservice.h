#pragma once

#include "tb_same2/generated/api/tb_same2.h"
#include "tb_same2/generated/api/common.h"
#include "apigear/mqtt/mqttcppclient.h"

namespace Test {
namespace TbSame2 {
namespace mqtt {
class TEST_TB_SAME2_EXPORT SameEnum2InterfaceService : public virtual ApiGear::MQTTImpl::ISink, public ISameEnum2InterfaceSubscriber
{
public:
    explicit SameEnum2InterfaceService(ISameEnum2Interface& impl, std::shared_ptr<ApiGear::MQTTImpl::Client> client);
    virtual ~SameEnum2InterfaceService() override;

    // sink interface
    void onConnected() override;
    void onSignal(const ApiGear::MQTTImpl::Topic&, const std::string&) override {};
    void onPropertyChanged(const ApiGear::MQTTImpl::Topic&, const std::string&) override {};
    void onInvoke(const ApiGear::MQTTImpl::Topic& topic, const std::string& args, const ApiGear::MQTTImpl::Topic& responseTopic, const std::string& correlationData) override;

    // ISameEnum2InterfaceSubscriber interface
    void onSig1(Enum1Enum param1) override;
    void onSig2(Enum1Enum param1, Enum2Enum param2) override;
    void onProp1Changed(Enum1Enum prop1) override;
    void onProp2Changed(Enum2Enum prop2) override;

private:
    ISameEnum2Interface& m_impl;
    std::shared_ptr<ApiGear::MQTTImpl::Client> m_client;
};
} // namespace mqtt
} // namespace TbSame2
} // namespace Test
