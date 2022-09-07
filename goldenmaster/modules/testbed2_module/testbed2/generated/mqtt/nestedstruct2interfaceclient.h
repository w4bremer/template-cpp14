#pragma once

#include <future>
#include "testbed2/generated/api/common.h"
#include "testbed2/generated/api/testbed2.h"
#include "testbed2/generated/core/nestedstruct2interface.data.h"
#include "apigear/mqtt/mqttcppclient.h"

namespace Test {
namespace Testbed2 {
namespace mqtt {
class TEST_TESTBED2_EXPORT NestedStruct2InterfaceClient : public INestedStruct2Interface, public virtual ApiGear::MQTTImpl::ISink
{
public:
    explicit NestedStruct2InterfaceClient(std::shared_ptr<ApiGear::MQTTImpl::Client> client);
    virtual ~NestedStruct2InterfaceClient() override;
    const NestedStruct1& getProp1() const override;
    void setProp1(const NestedStruct1& prop1) override;
    const NestedStruct2& getProp2() const override;
    void setProp2(const NestedStruct2& prop2) override;
    NestedStruct1 func1(const NestedStruct1& param1) override;
    std::future<NestedStruct1> func1Async(const NestedStruct1& param1) override;
    NestedStruct1 func2(const NestedStruct1& param1, const NestedStruct2& param2) override;
    std::future<NestedStruct1> func2Async(const NestedStruct1& param1, const NestedStruct2& param2) override;
    INestedStruct2InterfacePublisher& _getPublisher() const override;

    bool isReady() const;

    void onConnected() override {};
    void onSignal(const ApiGear::MQTTImpl::Topic& topic, const std::string& args) override;
    void onPropertyChanged(const ApiGear::MQTTImpl::Topic& topic, const std::string& args) override;
    void onInvoke(const ApiGear::MQTTImpl::Topic&, const std::string&, const ApiGear::MQTTImpl::Topic&, const std::string&) override {};

private:
    void setProp1Local(const NestedStruct1& prop1);
    void setProp2Local(const NestedStruct2& prop2);

    void applyState(const nlohmann::json& fields);

    bool m_isReady;
    /** Local storage for properties values. */
    NestedStruct2InterfaceData m_data;
    std::shared_ptr<ApiGear::MQTTImpl::Client> m_client;

    /** The publisher for NestedStruct2Interface */
    std::unique_ptr<INestedStruct2InterfacePublisher> m_publisher;
};
} // namespace mqtt
} // namespace Testbed2
} // namespace Test
