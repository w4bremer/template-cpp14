#pragma once

#include "tb_simple/generated/api/tb_simple.h"
#include "tb_simple/generated/api/common.h"
#include "apigear/mqtt/mqttcppclient.h"
#include "mqttisink.h"

namespace Test {
namespace TbSimple {
namespace MQTT {
class TEST_TB_SIMPLE_EXPORT NoOperationsInterfaceService : public virtual ApiGear::MQTT::ISink, public INoOperationsInterfaceSubscriber
{
public:
    explicit NoOperationsInterfaceService(std::shared_ptr<INoOperationsInterface> impl, std::shared_ptr<ApiGear::MQTT::Client> client);
    virtual ~NoOperationsInterfaceService() override;

    // sink interface
    void onConnected() override;
    void onSignal(const ApiGear::MQTT::Topic&, const std::string&) override {};
    void onPropertyChanged(const ApiGear::MQTT::Topic&, const std::string&) override {};
    void onInvoke(const ApiGear::MQTT::Topic& topic, const std::string& args, const ApiGear::MQTT::Topic& responseTopic, const std::string& correlationData) override;

    // INoOperationsInterfaceSubscriber interface
    void onSigVoid() override;
    void onSigBool(bool paramBool) override;
    void onPropBoolChanged(bool propBool) override;
    void onPropIntChanged(int propInt) override;

private:
    std::shared_ptr<INoOperationsInterface> m_impl;
    std::shared_ptr<ApiGear::MQTT::Client> m_client;
};
} // namespace MQTT
} // namespace TbSimple
} // namespace Test
