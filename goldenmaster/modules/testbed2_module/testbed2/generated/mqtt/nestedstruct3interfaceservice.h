#pragma once

#include "testbed2/generated/api/testbed2.h"
#include "testbed2/generated/api/common.h"
#include "apigear/mqtt/mqttservice.h"

namespace Test {
namespace Testbed2 {
namespace MQTT {
class TEST_TESTBED2_EXPORT NestedStruct3InterfaceService : public INestedStruct3InterfaceSubscriber
{
public:
    explicit NestedStruct3InterfaceService(std::shared_ptr<INestedStruct3Interface> impl, std::shared_ptr<ApiGear::MQTT::Service> service);
    virtual ~NestedStruct3InterfaceService() override;

    void onConnectionStatusChanged(bool connectionStatus);

    void onSetProperty(const std::string& topic, const std::string& args);
    void onInvoke(const std::string& topic, const std::string& args, const std::string& responseTopic, const std::string& correlationData);

    // INestedStruct3InterfaceSubscriber interface
    void onSig1(const NestedStruct1& param1) override;
    void onSig2(const NestedStruct1& param1, const NestedStruct2& param2) override;
    void onSig3(const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3) override;
    void onProp1Changed(const NestedStruct1& prop1) override;
    void onProp2Changed(const NestedStruct2& prop2) override;
    void onProp3Changed(const NestedStruct3& prop3) override;

private:
    std::shared_ptr<INestedStruct3Interface> m_impl;
    std::shared_ptr<ApiGear::MQTT::Service> m_service;
    // id for connection status registration
    int m_connectionStatusRegistrationID;
};
} // namespace MQTT
} // namespace Testbed2
} // namespace Test
