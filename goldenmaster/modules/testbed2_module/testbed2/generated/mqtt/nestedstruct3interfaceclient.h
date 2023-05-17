#pragma once

#include <future>
#include "testbed2/generated/api/common.h"
#include "testbed2/generated/api/testbed2.h"
#include "testbed2/generated/core/nestedstruct3interface.data.h"
#include "apigear/mqtt/mqttcppclient.h"
#include "mqttisink.h"

namespace Test {
namespace Testbed2 {
namespace MQTT {
class TEST_TESTBED2_EXPORT NestedStruct3InterfaceClient : public INestedStruct3Interface, public virtual ApiGear::MQTT::ISink
{
public:
    explicit NestedStruct3InterfaceClient(std::shared_ptr<ApiGear::MQTT::Client> client);
    virtual ~NestedStruct3InterfaceClient() override;
    const NestedStruct1& getProp1() const override;
    void setProp1(const NestedStruct1& prop1) override;
    const NestedStruct2& getProp2() const override;
    void setProp2(const NestedStruct2& prop2) override;
    const NestedStruct3& getProp3() const override;
    void setProp3(const NestedStruct3& prop3) override;
    NestedStruct1 func1(const NestedStruct1& param1) override;
    std::future<NestedStruct1> func1Async(const NestedStruct1& param1) override;
    NestedStruct1 func2(const NestedStruct1& param1, const NestedStruct2& param2) override;
    std::future<NestedStruct1> func2Async(const NestedStruct1& param1, const NestedStruct2& param2) override;
    NestedStruct1 func3(const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3) override;
    std::future<NestedStruct1> func3Async(const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3) override;
    INestedStruct3InterfacePublisher& _getPublisher() const override;

    bool isReady() const;

    void onConnected() override {};
    void onSignal(const ApiGear::MQTT::Topic& topic, const std::string& args) override;
    void onPropertyChanged(const ApiGear::MQTT::Topic& topic, const std::string& args) override;
    void onInvoke(const ApiGear::MQTT::Topic&, const std::string&, const ApiGear::MQTT::Topic&, const std::string&) override {};

private:
    void setProp1Local(const NestedStruct1& prop1);
    void setProp2Local(const NestedStruct2& prop2);
    void setProp3Local(const NestedStruct3& prop3);

    void applyState(const nlohmann::json& fields);

    bool m_isReady;
    /** Local storage for properties values. */
    NestedStruct3InterfaceData m_data;
    std::shared_ptr<ApiGear::MQTT::Client> m_client;

    /** The publisher for NestedStruct3Interface */
    std::unique_ptr<INestedStruct3InterfacePublisher> m_publisher;
};
} // namespace MQTT
} // namespace Testbed2
} // namespace Test
