#pragma once

#include "tb_same1/generated/api/tb_same1.h"
#include "tb_same1/generated/api/common.h"
#include "apigear/mqtt/mqttcppclient.h"

namespace Test {
namespace TbSame1 {
namespace MQTT {
class TEST_TB_SAME1_EXPORT SameEnum2InterfaceService : public virtual ApiGear::MQTT::ISink, public ISameEnum2InterfaceSubscriber
{
public:
    explicit SameEnum2InterfaceService(std::shared_ptr<ISameEnum2Interface> impl, std::shared_ptr<ApiGear::MQTT::Client> client);
    virtual ~SameEnum2InterfaceService() override;

    // sink interface
    void onConnected() override;
    void onSignal(const ApiGear::MQTT::Topic&, const std::string&) override {};
    void onPropertyChanged(const ApiGear::MQTT::Topic&, const std::string&) override {};
    void onInvoke(const ApiGear::MQTT::Topic& topic, const std::string& args, const ApiGear::MQTT::Topic& responseTopic, const std::string& correlationData) override;

    // ISameEnum2InterfaceSubscriber interface
    void onSig1(Enum1Enum param1) override;
    void onSig2(Enum1Enum param1, Enum2Enum param2) override;
    void onProp1Changed(Enum1Enum prop1) override;
    void onProp2Changed(Enum2Enum prop2) override;

private:
    std::shared_ptr<ISameEnum2Interface> m_impl;
    std::shared_ptr<ApiGear::MQTT::Client> m_client;
};
} // namespace MQTT
} // namespace TbSame1
} // namespace Test
