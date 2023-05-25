#pragma once

#include <future>
#include "tb_same1/generated/api/common.h"
#include "tb_same1/generated/api/tb_same1.h"
#include "tb_same1/generated/core/samestruct2interface.data.h"
#include "apigear/mqtt/mqttclient.h"
#include "mqttisink.h"

namespace Test {
namespace TbSame1 {
namespace MQTT {
class TEST_TB_SAME1_EXPORT SameStruct2InterfaceClient : public ISameStruct2Interface, public virtual ApiGear::MQTT::ISink
{
public:
    explicit SameStruct2InterfaceClient(std::shared_ptr<ApiGear::MQTT::Client> client);
    virtual ~SameStruct2InterfaceClient() override;
    const Struct2& getProp1() const override;
    void setProp1(const Struct2& prop1) override;
    const Struct2& getProp2() const override;
    void setProp2(const Struct2& prop2) override;
    Struct1 func1(const Struct1& param1) override;
    std::future<Struct1> func1Async(const Struct1& param1) override;
    Struct1 func2(const Struct1& param1, const Struct2& param2) override;
    std::future<Struct1> func2Async(const Struct1& param1, const Struct2& param2) override;
    ISameStruct2InterfacePublisher& _getPublisher() const override;

    bool isReady() const;

    void onSignal(const ApiGear::MQTT::Topic& topic, const std::string& args) override;
    void onPropertyChanged(const ApiGear::MQTT::Topic& topic, const std::string& args) override;
    void onInvoke(const ApiGear::MQTT::Topic&, const std::string&, const ApiGear::MQTT::Topic&, const std::string&) override {};

private:
    void setProp1Local(const Struct2& prop1);
    void setProp2Local(const Struct2& prop2);

    void applyState(const nlohmann::json& fields);

    bool m_isReady;
    /** Local storage for properties values. */
    SameStruct2InterfaceData m_data;
    std::shared_ptr<ApiGear::MQTT::Client> m_client;

    /** The publisher for SameStruct2Interface */
    std::unique_ptr<ISameStruct2InterfacePublisher> m_publisher;
};
} // namespace MQTT
} // namespace TbSame1
} // namespace Test
