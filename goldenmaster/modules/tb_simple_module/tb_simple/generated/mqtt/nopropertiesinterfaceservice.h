#pragma once

#include "tb_simple/generated/api/tb_simple.h"
#include "tb_simple/generated/api/common.h"
#include "apigear/mqtt/mqttservice.h"

namespace Test {
namespace TbSimple {
namespace MQTT {
class TEST_TB_SIMPLE_EXPORT NoPropertiesInterfaceService : public INoPropertiesInterfaceSubscriber
{
public:
    explicit NoPropertiesInterfaceService(std::shared_ptr<INoPropertiesInterface> impl, std::shared_ptr<ApiGear::MQTT::Service> service);
    virtual ~NoPropertiesInterfaceService() override;

    void onConnectionStatusChanged(bool connectionStatus);

    void onInvoke(const ApiGear::MQTT::Topic& topic, const std::string& args, const ApiGear::MQTT::Topic& responseTopic, const std::string& correlationData);

    // INoPropertiesInterfaceSubscriber interface
    void onSigVoid() override;
    void onSigBool(bool paramBool) override;

private:
    std::shared_ptr<INoPropertiesInterface> m_impl;
    std::shared_ptr<ApiGear::MQTT::Service> m_service;
    // id for connection status registration
    int m_connectionStatusRegistrationID;
};
} // namespace MQTT
} // namespace TbSimple
} // namespace Test
