#pragma once

#include "testbed1/generated/api/testbed1.h"
#include "testbed1/generated/api/common.h"
#include "apigear/mqtt/mqttservice.h"

namespace Test {
namespace Testbed1 {
namespace MQTT {
class TEST_TESTBED1_EXPORT StructArrayInterfaceService : public IStructArrayInterfaceSubscriber
{
public:
    explicit StructArrayInterfaceService(std::shared_ptr<IStructArrayInterface> impl, std::shared_ptr<ApiGear::MQTT::Service> service);
    virtual ~StructArrayInterfaceService() override;

    void onConnectionStatusChanged(bool connectionStatus);

    void onSetProperty(const std::string& topic, const std::string& args);
    void onInvoke(const std::string& topic, const std::string& args, const std::string& responseTopic, const std::string& correlationData);

    // IStructArrayInterfaceSubscriber interface
    void onSigBool(const std::list<StructBool>& paramBool) override;
    void onSigInt(const std::list<StructInt>& paramInt) override;
    void onSigFloat(const std::list<StructFloat>& paramFloat) override;
    void onSigString(const std::list<StructString>& paramString) override;
    void onPropBoolChanged(const std::list<StructBool>& propBool) override;
    void onPropIntChanged(const std::list<StructInt>& propInt) override;
    void onPropFloatChanged(const std::list<StructFloat>& propFloat) override;
    void onPropStringChanged(const std::list<StructString>& propString) override;

private:
    std::shared_ptr<IStructArrayInterface> m_impl;
    std::shared_ptr<ApiGear::MQTT::Service> m_service;
    // id for connection status registration
    int m_connectionStatusRegistrationID;

    /// @brief has all the topics of this service and the corresponding function callbacks
    const std::map<std::string, ApiGear::MQTT::CallbackFunction> m_topics;
};
} // namespace MQTT
} // namespace Testbed1
} // namespace Test
