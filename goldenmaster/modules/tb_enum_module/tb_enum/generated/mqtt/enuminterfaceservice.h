#pragma once

#include "tb_enum/generated/api/tb_enum.h"
#include "tb_enum/generated/api/common.h"
#include "apigear/mqtt/mqttservice.h"

namespace Test {
namespace TbEnum {
namespace MQTT {
class TEST_TB_ENUM_EXPORT EnumInterfaceService : public IEnumInterfaceSubscriber
{
public:
    explicit EnumInterfaceService(std::shared_ptr<IEnumInterface> impl, std::shared_ptr<ApiGear::MQTT::Service> service);
    virtual ~EnumInterfaceService() override;

    void onConnectionStatusChanged(bool connectionStatus);
    void onInvokeFunc0(const std::string& args, const std::string& responseTopic, const std::string& correlationData) const;
    void onInvokeFunc1(const std::string& args, const std::string& responseTopic, const std::string& correlationData) const;
    void onInvokeFunc2(const std::string& args, const std::string& responseTopic, const std::string& correlationData) const;
    void onInvokeFunc3(const std::string& args, const std::string& responseTopic, const std::string& correlationData) const;

    // IEnumInterfaceSubscriber interface
    void onSig0(Enum0Enum param0) override;
    void onSig1(Enum1Enum param1) override;
    void onSig2(Enum2Enum param2) override;
    void onSig3(Enum3Enum param3) override;
    void onProp0Changed(Enum0Enum prop0) override;
    /// @brief requests to set the value for the property Prop0 coming from the client
    /// @param fields contains the param of the type Enum0Enum
    void onSetProp0(const std::string& args) const;
    void onProp1Changed(Enum1Enum prop1) override;
    /// @brief requests to set the value for the property Prop1 coming from the client
    /// @param fields contains the param of the type Enum1Enum
    void onSetProp1(const std::string& args) const;
    void onProp2Changed(Enum2Enum prop2) override;
    /// @brief requests to set the value for the property Prop2 coming from the client
    /// @param fields contains the param of the type Enum2Enum
    void onSetProp2(const std::string& args) const;
    void onProp3Changed(Enum3Enum prop3) override;
    /// @brief requests to set the value for the property Prop3 coming from the client
    /// @param fields contains the param of the type Enum3Enum
    void onSetProp3(const std::string& args) const;

private:
    std::shared_ptr<IEnumInterface> m_impl;
    std::shared_ptr<ApiGear::MQTT::Service> m_service;
    // id for connection status registration
    int m_connectionStatusRegistrationID;

    /// @brief has all the topics of this service and the corresponding function callbacks
    const std::map<std::string, ApiGear::MQTT::CallbackFunction> m_topics;
};
} // namespace MQTT
} // namespace TbEnum
} // namespace Test
