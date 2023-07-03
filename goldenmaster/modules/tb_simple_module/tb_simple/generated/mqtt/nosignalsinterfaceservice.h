#pragma once

#include "tb_simple/generated/api/tb_simple.h"
#include "tb_simple/generated/api/common.h"
#include "apigear/mqtt/mqttservice.h"

namespace Test {
namespace TbSimple {
namespace MQTT {
class TEST_TB_SIMPLE_EXPORT NoSignalsInterfaceService : public INoSignalsInterfaceSubscriber
{
public:
    explicit NoSignalsInterfaceService(std::shared_ptr<INoSignalsInterface> impl, std::shared_ptr<ApiGear::MQTT::Service> service);
    virtual ~NoSignalsInterfaceService() override;

    void onConnectionStatusChanged(bool connectionStatus);

    void onInvoke(const ApiGear::MQTT::Topic& topic, const std::string& args, const ApiGear::MQTT::Topic& responseTopic, const std::string& correlationData);

    // INoSignalsInterfaceSubscriber interface
    void onPropBoolChanged(bool propBool) override;
    void onPropIntChanged(int propInt) override;

private:
    std::shared_ptr<INoSignalsInterface> m_impl;
    std::shared_ptr<ApiGear::MQTT::Service> m_service;
    // id for connection status registration
    int m_connectionStatusRegistrationID;
};
} // namespace MQTT
} // namespace TbSimple
} // namespace Test
