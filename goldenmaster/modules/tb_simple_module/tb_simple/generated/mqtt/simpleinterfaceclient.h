#pragma once

#include <future>
#include "tb_simple/generated/api/common.h"
#include "tb_simple/generated/api/tb_simple.h"
#include "tb_simple/generated/core/simpleinterface.data.h"
#include "apigear/mqtt/mqttcppclient.h"

namespace Test {
namespace TbSimple {
namespace mqtt {
class TEST_TB_SIMPLE_EXPORT SimpleInterfaceClient : public ISimpleInterface, public virtual ApiGear::MQTTImpl::ISink
{
public:
    explicit SimpleInterfaceClient(std::shared_ptr<ApiGear::MQTTImpl::Client> client);
    virtual ~SimpleInterfaceClient() override;
    bool getPropBool() const override;
    void setPropBool(bool propBool) override;
    int getPropInt() const override;
    void setPropInt(int propInt) override;
    int32_t getPropInt32() const override;
    void setPropInt32(int32_t propInt32) override;
    int64_t getPropInt64() const override;
    void setPropInt64(int64_t propInt64) override;
    float getPropFloat() const override;
    void setPropFloat(float propFloat) override;
    float getPropFloat32() const override;
    void setPropFloat32(float propFloat32) override;
    double getPropFloat64() const override;
    void setPropFloat64(double propFloat64) override;
    const std::string& getPropString() const override;
    void setPropString(const std::string& propString) override;
    bool funcBool(bool paramBool) override;
    std::future<bool> funcBoolAsync(bool paramBool) override;
    int funcInt(int paramInt) override;
    std::future<int> funcIntAsync(int paramInt) override;
    int32_t funcInt32(int32_t paramInt32) override;
    std::future<int32_t> funcInt32Async(int32_t paramInt32) override;
    int64_t funcInt64(int64_t paramInt64) override;
    std::future<int64_t> funcInt64Async(int64_t paramInt64) override;
    float funcFloat(float paramFloat) override;
    std::future<float> funcFloatAsync(float paramFloat) override;
    float funcFloat32(float paramFloat32) override;
    std::future<float> funcFloat32Async(float paramFloat32) override;
    double funcFloat64(double paramFloat) override;
    std::future<double> funcFloat64Async(double paramFloat) override;
    std::string funcString(const std::string& paramString) override;
    std::future<std::string> funcStringAsync(const std::string& paramString) override;
    ISimpleInterfacePublisher& _getPublisher() const override;

    bool isReady() const;

    void onConnected() override {};
    void onSignal(const ApiGear::MQTTImpl::Topic& topic, const std::string& args) override;
    void onPropertyChanged(const ApiGear::MQTTImpl::Topic& topic, const std::string& args) override;
    void onInvoke(const ApiGear::MQTTImpl::Topic&, const std::string&, const ApiGear::MQTTImpl::Topic&, const std::string&) override {};

private:
    void setPropBoolLocal(bool propBool);
    void setPropIntLocal(int propInt);
    void setPropInt32Local(int32_t propInt32);
    void setPropInt64Local(int64_t propInt64);
    void setPropFloatLocal(float propFloat);
    void setPropFloat32Local(float propFloat32);
    void setPropFloat64Local(double propFloat64);
    void setPropStringLocal(const std::string& propString);

    void applyState(const nlohmann::json& fields);

    bool m_isReady;
    /** Local storage for properties values. */
    SimpleInterfaceData m_data;
    std::shared_ptr<ApiGear::MQTTImpl::Client> m_client;

    /** The publisher for SimpleInterface */
    std::unique_ptr<ISimpleInterfacePublisher> m_publisher;
};
} // namespace mqtt
} // namespace TbSimple
} // namespace Test
