#pragma once

#include "tb_enum/generated/api/tb_enum.h"
#include "tb_enum/generated/api/common.h"
#include "apigear/mqtt/mqttcppclient.h"

namespace Test {
namespace TbEnum {
namespace mqtt {
class TEST_TB_ENUM_EXPORT EnumInterfaceService : public virtual ApiGear::MQTTImpl::ISink, public IEnumInterfaceSubscriber
{
public:
    explicit EnumInterfaceService(std::shared_ptr<IEnumInterface> impl, std::shared_ptr<ApiGear::MQTTImpl::Client> client);
    virtual ~EnumInterfaceService() override;

    // sink interface
    void onConnected() override;
    void onSignal(const ApiGear::MQTTImpl::Topic&, const std::string&) override {};
    void onPropertyChanged(const ApiGear::MQTTImpl::Topic&, const std::string&) override {};
    void onInvoke(const ApiGear::MQTTImpl::Topic& topic, const std::string& args, const ApiGear::MQTTImpl::Topic& responseTopic, const std::string& correlationData) override;

    // IEnumInterfaceSubscriber interface
    void onSig0(Enum0Enum param0) override;
    void onSig1(Enum1Enum param1) override;
    void onSig2(Enum2Enum param2) override;
    void onSig3(Enum3Enum param3) override;
    void onProp0Changed(Enum0Enum prop0) override;
    void onProp1Changed(Enum1Enum prop1) override;
    void onProp2Changed(Enum2Enum prop2) override;
    void onProp3Changed(Enum3Enum prop3) override;

private:
    std::shared_ptr<IEnumInterface> m_impl;
    std::shared_ptr<ApiGear::MQTTImpl::Client> m_client;
};
} // namespace mqtt
} // namespace TbEnum
} // namespace Test
