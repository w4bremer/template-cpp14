#pragma once

#include "tb_enum/generated/api/tb_enum.h"
#include "tb_enum/generated/api/common.h"
#include "apigear/mqtt/mqttservice.h"
#include "mqttisink.h"

namespace Test {
namespace TbEnum {
namespace MQTT {
class TEST_TB_ENUM_EXPORT EnumInterfaceService : public virtual ApiGear::MQTT::ISink, public IEnumInterfaceSubscriber
{
public:
    explicit EnumInterfaceService(std::shared_ptr<IEnumInterface> impl, std::shared_ptr<ApiGear::MQTT::Service> service);
    virtual ~EnumInterfaceService() override;

    void onConnectionStatusChanged(bool connectionStatus);
    // sink interface
    void onSignal(const ApiGear::MQTT::Topic&, const std::string&) override {};
    void onPropertyChanged(const ApiGear::MQTT::Topic&, const std::string&) override {};
    void onInvoke(const ApiGear::MQTT::Topic& topic, const std::string& args, const ApiGear::MQTT::Topic& responseTopic, const std::string& correlationData) override;

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
    std::shared_ptr<ApiGear::MQTT::Service> m_service;
    // id for connection status registration
    int m_connectionStatusRegistrationID;
};
} // namespace MQTT
} // namespace TbEnum
} // namespace Test
