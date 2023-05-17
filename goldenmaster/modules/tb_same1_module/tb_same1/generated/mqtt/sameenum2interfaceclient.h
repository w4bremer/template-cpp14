#pragma once

#include <future>
#include "tb_same1/generated/api/common.h"
#include "tb_same1/generated/api/tb_same1.h"
#include "tb_same1/generated/core/sameenum2interface.data.h"
#include "apigear/mqtt/mqttcppclient.h"
#include "mqttisink.h"

namespace Test {
namespace TbSame1 {
namespace MQTT {
class TEST_TB_SAME1_EXPORT SameEnum2InterfaceClient : public ISameEnum2Interface, public virtual ApiGear::MQTT::ISink
{
public:
    explicit SameEnum2InterfaceClient(std::shared_ptr<ApiGear::MQTT::Client> client);
    virtual ~SameEnum2InterfaceClient() override;
    Enum1Enum getProp1() const override;
    void setProp1(Enum1Enum prop1) override;
    Enum2Enum getProp2() const override;
    void setProp2(Enum2Enum prop2) override;
    Enum1Enum func1(Enum1Enum param1) override;
    std::future<Enum1Enum> func1Async(Enum1Enum param1) override;
    Enum1Enum func2(Enum1Enum param1, Enum2Enum param2) override;
    std::future<Enum1Enum> func2Async(Enum1Enum param1, Enum2Enum param2) override;
    ISameEnum2InterfacePublisher& _getPublisher() const override;

    bool isReady() const;

    void onConnected() override {};
    void onSignal(const ApiGear::MQTT::Topic& topic, const std::string& args) override;
    void onPropertyChanged(const ApiGear::MQTT::Topic& topic, const std::string& args) override;
    void onInvoke(const ApiGear::MQTT::Topic&, const std::string&, const ApiGear::MQTT::Topic&, const std::string&) override {};

private:
    void setProp1Local(Enum1Enum prop1);
    void setProp2Local(Enum2Enum prop2);

    void applyState(const nlohmann::json& fields);

    bool m_isReady;
    /** Local storage for properties values. */
    SameEnum2InterfaceData m_data;
    std::shared_ptr<ApiGear::MQTT::Client> m_client;

    /** The publisher for SameEnum2Interface */
    std::unique_ptr<ISameEnum2InterfacePublisher> m_publisher;
};
} // namespace MQTT
} // namespace TbSame1
} // namespace Test
