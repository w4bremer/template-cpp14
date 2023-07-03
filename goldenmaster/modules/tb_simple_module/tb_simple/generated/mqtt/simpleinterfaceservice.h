#pragma once

#include "tb_simple/generated/api/tb_simple.h"
#include "tb_simple/generated/api/common.h"
#include "apigear/mqtt/mqttservice.h"
#include "mqttisink.h"

namespace Test {
namespace TbSimple {
namespace MQTT {
class TEST_TB_SIMPLE_EXPORT SimpleInterfaceService : public virtual ApiGear::MQTT::ISink, public ISimpleInterfaceSubscriber
{
public:
    explicit SimpleInterfaceService(std::shared_ptr<ISimpleInterface> impl, std::shared_ptr<ApiGear::MQTT::Service> service);
    virtual ~SimpleInterfaceService() override;

    void onConnectionStatusChanged(bool connectionStatus);
    // sink interface
    void onSignal(const ApiGear::MQTT::Topic&, const std::string&) override {};
    void onPropertyChanged(const ApiGear::MQTT::Topic&, const std::string&) override {};
    void onInvoke(const ApiGear::MQTT::Topic& topic, const std::string& args, const ApiGear::MQTT::Topic& responseTopic, const std::string& correlationData) override;

    // ISimpleInterfaceSubscriber interface
    void onSigBool(bool paramBool) override;
    void onSigInt(int paramInt) override;
    void onSigInt32(int32_t paramInt32) override;
    void onSigInt64(int64_t paramInt64) override;
    void onSigFloat(float paramFloat) override;
    void onSigFloat32(float paramFloa32) override;
    void onSigFloat64(double paramFloat64) override;
    void onSigString(const std::string& paramString) override;
    void onPropBoolChanged(bool propBool) override;
    void onPropIntChanged(int propInt) override;
    void onPropInt32Changed(int32_t propInt32) override;
    void onPropInt64Changed(int64_t propInt64) override;
    void onPropFloatChanged(float propFloat) override;
    void onPropFloat32Changed(float propFloat32) override;
    void onPropFloat64Changed(double propFloat64) override;
    void onPropStringChanged(const std::string& propString) override;

private:
    std::shared_ptr<ISimpleInterface> m_impl;
    std::shared_ptr<ApiGear::MQTT::Service> m_service;
    // id for connection status registration
    int m_connectionStatusRegistrationID;
};
} // namespace MQTT
} // namespace TbSimple
} // namespace Test
