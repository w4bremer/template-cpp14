#pragma once

#include "tb_same2/generated/api/tb_same2.h"
#include "tb_same2/generated/api/common.h"
#include "apigear/mqtt/mqttservice.h"

namespace Test {
namespace TbSame2 {
namespace MQTT {
class TEST_TB_SAME2_EXPORT SameStruct2InterfaceService : public ISameStruct2InterfaceSubscriber
{
public:
    explicit SameStruct2InterfaceService(std::shared_ptr<ISameStruct2Interface> impl, std::shared_ptr<ApiGear::MQTT::Service> service);
    virtual ~SameStruct2InterfaceService() override;

    void onConnectionStatusChanged(bool connectionStatus);

    void onInvoke(const std::string& topic, const std::string& args, const std::string& responseTopic, const std::string& correlationData);

    // ISameStruct2InterfaceSubscriber interface
    void onSig1(const Struct1& param1) override;
    void onSig2(const Struct1& param1, const Struct2& param2) override;
    void onProp1Changed(const Struct2& prop1) override;
    /// @brief requests to set the value for the property Prop1 coming from the client
    /// @param fields contains the param of the type Struct2
    void onSetProp1(const std::string& args) const;
    void onProp2Changed(const Struct2& prop2) override;
    /// @brief requests to set the value for the property Prop2 coming from the client
    /// @param fields contains the param of the type Struct2
    void onSetProp2(const std::string& args) const;

private:
    std::shared_ptr<ISameStruct2Interface> m_impl;
    std::shared_ptr<ApiGear::MQTT::Service> m_service;
    // id for connection status registration
    int m_connectionStatusRegistrationID;

    /// @brief has all the topics of this service and the corresponding function callbacks
    const std::map<std::string, ApiGear::MQTT::CallbackFunction> m_topics;
};
} // namespace MQTT
} // namespace TbSame2
} // namespace Test
