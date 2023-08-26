#pragma once

#include "tb_same2/generated/api/tb_same2.h"
#include "tb_same2/generated/api/common.h"
#include "apigear/mqtt/mqttservice.h"

namespace Test {
namespace TbSame2 {
namespace MQTT {
class TEST_TB_SAME2_EXPORT SameStruct1InterfaceService : public ISameStruct1InterfaceSubscriber
{
public:
    explicit SameStruct1InterfaceService(std::shared_ptr<ISameStruct1Interface> impl, std::shared_ptr<ApiGear::MQTT::Service> service);
    virtual ~SameStruct1InterfaceService() override;

    void onConnectionStatusChanged(bool connectionStatus);
    void onInvokeFunc1(const std::string& args, const std::string& responseTopic, const std::string& correlationData) const;

    // ISameStruct1InterfaceSubscriber interface
    void onSig1(const Struct1& param1) override;
    void onProp1Changed(const Struct1& prop1) override;
    /// @brief requests to set the value for the property Prop1 coming from the client
    /// @param fields contains the param of the type Struct1
    void onSetProp1(const std::string& args) const;

private:
    std::shared_ptr<ISameStruct1Interface> m_impl;
    std::shared_ptr<ApiGear::MQTT::Service> m_service;
    // id for connection status registration
    int m_connectionStatusRegistrationID;

    /// @brief has all the topics of this service and the corresponding function callbacks
    const std::map<std::string, ApiGear::MQTT::CallbackFunction> m_topics;
};
} // namespace MQTT
} // namespace TbSame2
} // namespace Test
