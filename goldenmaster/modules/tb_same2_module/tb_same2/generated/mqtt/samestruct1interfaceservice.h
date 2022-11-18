#pragma once

#include "tb_same2/generated/api/tb_same2.h"
#include "tb_same2/generated/api/common.h"
#include "apigear/mqtt/mqttcppclient.h"

namespace Test {
namespace TbSame2 {
namespace mqtt {
class TEST_TB_SAME2_EXPORT SameStruct1InterfaceService : public virtual ApiGear::MQTTImpl::ISink, public ISameStruct1InterfaceSubscriber
{
public:
    explicit SameStruct1InterfaceService(std::shared_ptr<ISameStruct1Interface> impl, std::shared_ptr<ApiGear::MQTTImpl::Client> client);
    virtual ~SameStruct1InterfaceService() override;

    // sink interface
    void onConnected() override;
    void onSignal(const ApiGear::MQTTImpl::Topic&, const std::string&) override {};
    void onPropertyChanged(const ApiGear::MQTTImpl::Topic&, const std::string&) override {};
    void onInvoke(const ApiGear::MQTTImpl::Topic& topic, const std::string& args, const ApiGear::MQTTImpl::Topic& responseTopic, const std::string& correlationData) override;

    // ISameStruct1InterfaceSubscriber interface
    void onSig1(const Struct1& param1) override;
    void onProp1Changed(const Struct1& prop1) override;

private:
    std::shared_ptr<ISameStruct1Interface> m_impl;
    std::shared_ptr<ApiGear::MQTTImpl::Client> m_client;
};
} // namespace mqtt
} // namespace TbSame2
} // namespace Test
