#pragma once

#include <future>
#include "testbed2/generated/api/common.h"
#include "testbed2/generated/api/testbed2.h"
#include "testbed2/generated/core/nestedstruct1interface.data.h"
#include "apigear/mqtt/mqttclient.h"

namespace Test {
namespace Testbed2 {
namespace MQTT {
class TEST_TESTBED2_EXPORT NestedStruct1InterfaceClient : public INestedStruct1Interface
{
public:
    explicit NestedStruct1InterfaceClient(std::shared_ptr<ApiGear::MQTT::Client> client);
    virtual ~NestedStruct1InterfaceClient() override;
    const NestedStruct1& getProp1() const override;
    void setProp1(const NestedStruct1& prop1) override;
    NestedStruct1 func1(const NestedStruct1& param1) override;
    std::future<NestedStruct1> func1Async(const NestedStruct1& param1) override;
    INestedStruct1InterfacePublisher& _getPublisher() const override;

    bool isReady() const;

    void onSignal(const ApiGear::MQTT::Topic& topic, const std::string& args, const ApiGear::MQTT::Topic& responseTopic, const std::string& correlationData);
    void onPropertyChanged(const ApiGear::MQTT::Topic& topic, const std::string& args, const ApiGear::MQTT::Topic& responseTopic, const std::string& correlationData);

private:
    void setProp1Local(const NestedStruct1& prop1);

    void applyState(const nlohmann::json& fields);

    bool m_isReady;
    /** Local storage for properties values. */
    NestedStruct1InterfaceData m_data;
    std::shared_ptr<ApiGear::MQTT::Client> m_client;

    /** The publisher for NestedStruct1Interface */
    std::unique_ptr<INestedStruct1InterfacePublisher> m_publisher;
};
} // namespace MQTT
} // namespace Testbed2
} // namespace Test
