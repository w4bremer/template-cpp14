#pragma once

#include "tb_simple/generated/api/tb_simple.h"
#include "tb_simple/generated/api/common.h"
#include "apigear/mqtt/mqttcppclient.h"
#include "mqttisink.h"

namespace Test {
namespace TbSimple {
namespace MQTT {
class TEST_TB_SIMPLE_EXPORT NoPropertiesInterfaceService : public virtual ApiGear::MQTT::ISink, public INoPropertiesInterfaceSubscriber
{
public:
    explicit NoPropertiesInterfaceService(std::shared_ptr<INoPropertiesInterface> impl, std::shared_ptr<ApiGear::MQTT::Client> client);
    virtual ~NoPropertiesInterfaceService() override;

    // sink interface
    void onConnected() override;
    void onSignal(const ApiGear::MQTT::Topic&, const std::string&) override {};
    void onPropertyChanged(const ApiGear::MQTT::Topic&, const std::string&) override {};
    void onInvoke(const ApiGear::MQTT::Topic& topic, const std::string& args, const ApiGear::MQTT::Topic& responseTopic, const std::string& correlationData) override;

    // INoPropertiesInterfaceSubscriber interface
    void onSigVoid() override;
    void onSigBool(bool paramBool) override;

private:
    std::shared_ptr<INoPropertiesInterface> m_impl;
    std::shared_ptr<ApiGear::MQTT::Client> m_client;
};
} // namespace MQTT
} // namespace TbSimple
} // namespace Test
