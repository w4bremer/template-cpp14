#pragma once

#include "tb_names/generated/api/tb_names.h"
#include "tb_names/generated/api/common.h"
#include "apigear/mqtt/mqttservice.h"

namespace Test {
namespace TbNames {
namespace MQTT {
class TEST_TB_NAMES_EXPORT NamesService : public INamesSubscriber
{
public:
    explicit NamesService(std::shared_ptr<INames> impl, std::shared_ptr<ApiGear::MQTT::Service> service);
    virtual ~NamesService() override;

    void onConnectionStatusChanged(bool connectionStatus);

private:
    /// @brief factory to create the topic map which is used for bindings
    /// @return map with all topics and corresponding function callbacks
    std::map<std::string, ApiGear::MQTT::CallbackFunction> createTopicMap();
    void onSwitchChanged(bool Switch) override;
    /// @brief requests to set the value for the property Switch coming from the client
    /// @param fields contains the param of the type bool
    void onSetSwitch(const std::string& args) const;

    std::shared_ptr<INames> m_impl;
    std::shared_ptr<ApiGear::MQTT::Service> m_service;
    // id for connection status registration
    int m_connectionStatusRegistrationID;

    /// @brief has all the topics of this service and the corresponding function callbacks
    const std::map<std::string, ApiGear::MQTT::CallbackFunction> m_topics;
};
} // namespace MQTT
} // namespace TbNames
} // namespace Test
