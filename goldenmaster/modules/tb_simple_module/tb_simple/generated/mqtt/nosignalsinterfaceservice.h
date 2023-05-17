#pragma once

#include "tb_simple/generated/api/tb_simple.h"
#include "tb_simple/generated/api/common.h"
#include "apigear/mqtt/mqttcppclient.h"
#include "mqttisink.h"

namespace Test {
namespace TbSimple {
namespace MQTT {
class TEST_TB_SIMPLE_EXPORT NoSignalsInterfaceService : public virtual ApiGear::MQTT::ISink, public INoSignalsInterfaceSubscriber
{
public:
    explicit NoSignalsInterfaceService(std::shared_ptr<INoSignalsInterface> impl, std::shared_ptr<ApiGear::MQTT::Client> client);
    virtual ~NoSignalsInterfaceService() override;

    // sink interface
    void onConnected() override;
    void onSignal(const ApiGear::MQTT::Topic&, const std::string&) override {};
    void onPropertyChanged(const ApiGear::MQTT::Topic&, const std::string&) override {};
    void onInvoke(const ApiGear::MQTT::Topic& topic, const std::string& args, const ApiGear::MQTT::Topic& responseTopic, const std::string& correlationData) override;

    // INoSignalsInterfaceSubscriber interface
    void onPropBoolChanged(bool propBool) override;
    void onPropIntChanged(int propInt) override;

private:
    std::shared_ptr<INoSignalsInterface> m_impl;
    std::shared_ptr<ApiGear::MQTT::Client> m_client;
};
} // namespace MQTT
} // namespace TbSimple
} // namespace Test
