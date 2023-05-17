#pragma once

#include <future>
#include "testbed1/generated/api/common.h"
#include "testbed1/generated/api/testbed1.h"
#include "testbed1/generated/core/structinterface.data.h"
#include "apigear/mqtt/mqttcppclient.h"

namespace Test {
namespace Testbed1 {
namespace MQTT {
class TEST_TESTBED1_EXPORT StructInterfaceClient : public IStructInterface, public virtual ApiGear::MQTT::ISink
{
public:
    explicit StructInterfaceClient(std::shared_ptr<ApiGear::MQTT::Client> client);
    virtual ~StructInterfaceClient() override;
    const StructBool& getPropBool() const override;
    void setPropBool(const StructBool& propBool) override;
    const StructInt& getPropInt() const override;
    void setPropInt(const StructInt& propInt) override;
    const StructFloat& getPropFloat() const override;
    void setPropFloat(const StructFloat& propFloat) override;
    const StructString& getPropString() const override;
    void setPropString(const StructString& propString) override;
    StructBool funcBool(const StructBool& paramBool) override;
    std::future<StructBool> funcBoolAsync(const StructBool& paramBool) override;
    StructBool funcInt(const StructInt& paramInt) override;
    std::future<StructBool> funcIntAsync(const StructInt& paramInt) override;
    StructFloat funcFloat(const StructFloat& paramFloat) override;
    std::future<StructFloat> funcFloatAsync(const StructFloat& paramFloat) override;
    StructString funcString(const StructString& paramString) override;
    std::future<StructString> funcStringAsync(const StructString& paramString) override;
    IStructInterfacePublisher& _getPublisher() const override;

    bool isReady() const;

    void onConnected() override {};
    void onSignal(const ApiGear::MQTT::Topic& topic, const std::string& args) override;
    void onPropertyChanged(const ApiGear::MQTT::Topic& topic, const std::string& args) override;
    void onInvoke(const ApiGear::MQTT::Topic&, const std::string&, const ApiGear::MQTT::Topic&, const std::string&) override {};

private:
    void setPropBoolLocal(const StructBool& propBool);
    void setPropIntLocal(const StructInt& propInt);
    void setPropFloatLocal(const StructFloat& propFloat);
    void setPropStringLocal(const StructString& propString);

    void applyState(const nlohmann::json& fields);

    bool m_isReady;
    /** Local storage for properties values. */
    StructInterfaceData m_data;
    std::shared_ptr<ApiGear::MQTT::Client> m_client;

    /** The publisher for StructInterface */
    std::unique_ptr<IStructInterfacePublisher> m_publisher;
};
} // namespace MQTT
} // namespace Testbed1
} // namespace Test
