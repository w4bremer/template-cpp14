#pragma once

#include "tb_simple/generated/api/tb_simple.h"
#include "tb_simple/generated/api/common.h"
#include "apigear/mqtt/mqttcppclient.h"
#include "mqttisink.h"

namespace Test {
namespace TbSimple {
namespace MQTT {
class TEST_TB_SIMPLE_EXPORT SimpleArrayInterfaceService : public virtual ApiGear::MQTT::ISink, public ISimpleArrayInterfaceSubscriber
{
public:
    explicit SimpleArrayInterfaceService(std::shared_ptr<ISimpleArrayInterface> impl, std::shared_ptr<ApiGear::MQTT::Client> client);
    virtual ~SimpleArrayInterfaceService() override;

    // sink interface
    void onConnected() override;
    void onSignal(const ApiGear::MQTT::Topic&, const std::string&) override {};
    void onPropertyChanged(const ApiGear::MQTT::Topic&, const std::string&) override {};
    void onInvoke(const ApiGear::MQTT::Topic& topic, const std::string& args, const ApiGear::MQTT::Topic& responseTopic, const std::string& correlationData) override;

    // ISimpleArrayInterfaceSubscriber interface
    void onSigBool(const std::list<bool>& paramBool) override;
    void onSigInt(const std::list<int>& paramInt) override;
    void onSigInt32(const std::list<int32_t>& paramInt32) override;
    void onSigInt64(const std::list<int64_t>& paramInt64) override;
    void onSigFloat(const std::list<float>& paramFloat) override;
    void onSigFloat32(const std::list<float>& paramFloa32) override;
    void onSigFloat64(const std::list<double>& paramFloat64) override;
    void onSigString(const std::list<std::string>& paramString) override;
    void onPropBoolChanged(const std::list<bool>& propBool) override;
    void onPropIntChanged(const std::list<int>& propInt) override;
    void onPropInt32Changed(const std::list<int32_t>& propInt32) override;
    void onPropInt64Changed(const std::list<int64_t>& propInt64) override;
    void onPropFloatChanged(const std::list<float>& propFloat) override;
    void onPropFloat32Changed(const std::list<float>& propFloat32) override;
    void onPropFloat64Changed(const std::list<double>& propFloat64) override;
    void onPropStringChanged(const std::list<std::string>& propString) override;

private:
    std::shared_ptr<ISimpleArrayInterface> m_impl;
    std::shared_ptr<ApiGear::MQTT::Client> m_client;
};
} // namespace MQTT
} // namespace TbSimple
} // namespace Test
