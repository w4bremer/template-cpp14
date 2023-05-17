#pragma once

#include <future>
#include "testbed1/generated/api/common.h"
#include "testbed1/generated/api/testbed1.h"
#include "testbed1/generated/core/structarrayinterface.data.h"
#include "apigear/mqtt/mqttcppclient.h"

namespace Test {
namespace Testbed1 {
namespace MQTT {
class TEST_TESTBED1_EXPORT StructArrayInterfaceClient : public IStructArrayInterface, public virtual ApiGear::MQTT::ISink
{
public:
    explicit StructArrayInterfaceClient(std::shared_ptr<ApiGear::MQTT::Client> client);
    virtual ~StructArrayInterfaceClient() override;
    const std::list<StructBool>& getPropBool() const override;
    void setPropBool(const std::list<StructBool>& propBool) override;
    const std::list<StructInt>& getPropInt() const override;
    void setPropInt(const std::list<StructInt>& propInt) override;
    const std::list<StructFloat>& getPropFloat() const override;
    void setPropFloat(const std::list<StructFloat>& propFloat) override;
    const std::list<StructString>& getPropString() const override;
    void setPropString(const std::list<StructString>& propString) override;
    StructBool funcBool(const std::list<StructBool>& paramBool) override;
    std::future<StructBool> funcBoolAsync(const std::list<StructBool>& paramBool) override;
    StructBool funcInt(const std::list<StructInt>& paramInt) override;
    std::future<StructBool> funcIntAsync(const std::list<StructInt>& paramInt) override;
    StructBool funcFloat(const std::list<StructFloat>& paramFloat) override;
    std::future<StructBool> funcFloatAsync(const std::list<StructFloat>& paramFloat) override;
    StructBool funcString(const std::list<StructString>& paramString) override;
    std::future<StructBool> funcStringAsync(const std::list<StructString>& paramString) override;
    IStructArrayInterfacePublisher& _getPublisher() const override;

    bool isReady() const;

    void onConnected() override {};
    void onSignal(const ApiGear::MQTT::Topic& topic, const std::string& args) override;
    void onPropertyChanged(const ApiGear::MQTT::Topic& topic, const std::string& args) override;
    void onInvoke(const ApiGear::MQTT::Topic&, const std::string&, const ApiGear::MQTT::Topic&, const std::string&) override {};

private:
    void setPropBoolLocal(const std::list<StructBool>& propBool);
    void setPropIntLocal(const std::list<StructInt>& propInt);
    void setPropFloatLocal(const std::list<StructFloat>& propFloat);
    void setPropStringLocal(const std::list<StructString>& propString);

    void applyState(const nlohmann::json& fields);

    bool m_isReady;
    /** Local storage for properties values. */
    StructArrayInterfaceData m_data;
    std::shared_ptr<ApiGear::MQTT::Client> m_client;

    /** The publisher for StructArrayInterface */
    std::unique_ptr<IStructArrayInterfacePublisher> m_publisher;
};
} // namespace MQTT
} // namespace Testbed1
} // namespace Test
