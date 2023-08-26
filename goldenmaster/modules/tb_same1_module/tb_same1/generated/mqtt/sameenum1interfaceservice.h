#pragma once

#include "tb_same1/generated/api/tb_same1.h"
#include "tb_same1/generated/api/common.h"
#include "apigear/mqtt/mqttservice.h"

namespace Test {
namespace TbSame1 {
namespace MQTT {
class TEST_TB_SAME1_EXPORT SameEnum1InterfaceService : public ISameEnum1InterfaceSubscriber
{
public:
    explicit SameEnum1InterfaceService(std::shared_ptr<ISameEnum1Interface> impl, std::shared_ptr<ApiGear::MQTT::Service> service);
    virtual ~SameEnum1InterfaceService() override;

    void onConnectionStatusChanged(bool connectionStatus);
    void onInvokeFunc1(const std::string& args, const std::string& responseTopic, const std::string& correlationData) const;

    // ISameEnum1InterfaceSubscriber interface
    void onSig1(Enum1Enum param1) override;
    void onProp1Changed(Enum1Enum prop1) override;
    /// @brief requests to set the value for the property Prop1 coming from the client
    /// @param fields contains the param of the type Enum1Enum
    void onSetProp1(const std::string& args) const;

private:
    std::shared_ptr<ISameEnum1Interface> m_impl;
    std::shared_ptr<ApiGear::MQTT::Service> m_service;
    // id for connection status registration
    int m_connectionStatusRegistrationID;

    /// @brief has all the topics of this service and the corresponding function callbacks
    const std::map<std::string, ApiGear::MQTT::CallbackFunction> m_topics;
};
} // namespace MQTT
} // namespace TbSame1
} // namespace Test
