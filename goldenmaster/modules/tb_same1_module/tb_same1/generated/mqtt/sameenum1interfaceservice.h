#pragma once

#include "tb_same1/generated/api/tb_same1.h"
#include "tb_same1/generated/api/common.h"
#include "apigear/mqtt/mqttcppclient.h"
#include "mqttisink.h"

namespace Test {
namespace TbSame1 {
namespace MQTT {
class TEST_TB_SAME1_EXPORT SameEnum1InterfaceService : public virtual ApiGear::MQTT::ISink, public ISameEnum1InterfaceSubscriber
{
public:
    explicit SameEnum1InterfaceService(std::shared_ptr<ISameEnum1Interface> impl, std::shared_ptr<ApiGear::MQTT::Client> client);
    virtual ~SameEnum1InterfaceService() override;

    void onConnectionStatusChanged(bool connectionStatus);
    // sink interface
    void onSignal(const ApiGear::MQTT::Topic&, const std::string&) override {};
    void onPropertyChanged(const ApiGear::MQTT::Topic&, const std::string&) override {};
    void onInvoke(const ApiGear::MQTT::Topic& topic, const std::string& args, const ApiGear::MQTT::Topic& responseTopic, const std::string& correlationData) override;

    // ISameEnum1InterfaceSubscriber interface
    void onSig1(Enum1Enum param1) override;
    void onProp1Changed(Enum1Enum prop1) override;

private:
    std::shared_ptr<ISameEnum1Interface> m_impl;
    std::shared_ptr<ApiGear::MQTT::Client> m_client;
    // id for connection status registration
    int m_connectionStatusRegistrationID;
};
} // namespace MQTT
} // namespace TbSame1
} // namespace Test
