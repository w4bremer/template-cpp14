#pragma once

#include "tb_same2/generated/api/tb_same2.h"
#include "tb_same2/generated/api/common.h"
#include "apigear/mqtt/mqttcppclient.h"

namespace Test {
namespace TbSame2 {
namespace mqtt {
class TEST_TB_SAME2_EXPORT SameStruct2InterfaceService : public virtual ApiGear::MQTTImpl::ISink, public ISameStruct2InterfaceSubscriber
{
public:
    explicit SameStruct2InterfaceService(ISameStruct2Interface& impl, std::shared_ptr<ApiGear::MQTTImpl::Client> client);
    virtual ~SameStruct2InterfaceService() override;

    // sink interface
    void onConnected() override;
    void onSignal(const ApiGear::MQTTImpl::Topic&, const std::string&) override {};
    void onPropertyChanged(const ApiGear::MQTTImpl::Topic&, const std::string&) override {};
    void onInvoke(const ApiGear::MQTTImpl::Topic& topic, const std::string& args, const ApiGear::MQTTImpl::Topic& responseTopic, const std::string& correlationData) override;

    // ISameStruct2InterfaceSubscriber interface
    void onSig1(const Struct1& param1) override;
    void onSig2(const Struct1& param1, const Struct2& param2) override;
    void onProp1Changed(const Struct2& prop1) override;
    void onProp2Changed(const Struct2& prop2) override;

private:
    ISameStruct2Interface& m_impl;
    std::shared_ptr<ApiGear::MQTTImpl::Client> m_client;
};
} // namespace mqtt
} // namespace TbSame2
} // namespace Test
