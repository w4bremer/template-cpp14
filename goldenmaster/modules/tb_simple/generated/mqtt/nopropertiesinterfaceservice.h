#pragma once

#include "tb_simple/generated/api/tb_simple.h"
#include "tb_simple/generated/api/common.h"
#include "apigear/mqtt/mqttservice.h"

namespace Test {
namespace TbSimple {
namespace MQTT {
class TEST_TB_SIMPLE_EXPORT NoPropertiesInterfaceService : public INoPropertiesInterfaceSubscriber
{
public:
    explicit NoPropertiesInterfaceService(std::shared_ptr<INoPropertiesInterface> impl, std::shared_ptr<ApiGear::MQTT::Service> service);
    virtual ~NoPropertiesInterfaceService() override;

    void onConnectionStatusChanged(bool connectionStatus);

    // INoPropertiesInterfaceSubscriber interface
    void onSigVoid() override;
    void onSigBool(bool paramBool) override;

private:
    /// @brief factory to create the topic map which is used for bindings
    /// @return map with all topics and corresponding function callbacks
    std::map<std::string, ApiGear::MQTT::CallbackFunction> createTopicMap();
    void onInvokeFuncVoid(const std::string& args, const std::string& responseTopic, const std::string& correlationData) const;
    void onInvokeFuncBool(const std::string& args, const std::string& responseTopic, const std::string& correlationData) const;

    std::shared_ptr<INoPropertiesInterface> m_impl;
    std::shared_ptr<ApiGear::MQTT::Service> m_service;
    // id for connection status registration
    int m_connectionStatusRegistrationID;

    /// @brief has all the topics of this service and the corresponding function callbacks
    const std::map<std::string, ApiGear::MQTT::CallbackFunction> m_topics;
};
} // namespace MQTT
} // namespace TbSimple
} // namespace Test
