#pragma once

#include <future>
#include "tb_same2/generated/api/common.h"
#include "tb_same2/generated/api/tb_same2.h"
#include "tb_same2/generated/core/samestruct1interface.data.h"
#include "apigear/mqtt/mqttcppclient.h"
#include "mqttisink.h"

namespace Test {
namespace TbSame2 {
namespace MQTT {
class TEST_TB_SAME2_EXPORT SameStruct1InterfaceClient : public ISameStruct1Interface, public virtual ApiGear::MQTT::ISink
{
public:
    explicit SameStruct1InterfaceClient(std::shared_ptr<ApiGear::MQTT::Client> client);
    virtual ~SameStruct1InterfaceClient() override;
    const Struct1& getProp1() const override;
    void setProp1(const Struct1& prop1) override;
    Struct1 func1(const Struct1& param1) override;
    std::future<Struct1> func1Async(const Struct1& param1) override;
    ISameStruct1InterfacePublisher& _getPublisher() const override;

    bool isReady() const;

    void onConnected() override {};
    void onSignal(const ApiGear::MQTT::Topic& topic, const std::string& args) override;
    void onPropertyChanged(const ApiGear::MQTT::Topic& topic, const std::string& args) override;
    void onInvoke(const ApiGear::MQTT::Topic&, const std::string&, const ApiGear::MQTT::Topic&, const std::string&) override {};

private:
    void setProp1Local(const Struct1& prop1);

    void applyState(const nlohmann::json& fields);

    bool m_isReady;
    /** Local storage for properties values. */
    SameStruct1InterfaceData m_data;
    std::shared_ptr<ApiGear::MQTT::Client> m_client;

    /** The publisher for SameStruct1Interface */
    std::unique_ptr<ISameStruct1InterfacePublisher> m_publisher;
};
} // namespace MQTT
} // namespace TbSame2
} // namespace Test
