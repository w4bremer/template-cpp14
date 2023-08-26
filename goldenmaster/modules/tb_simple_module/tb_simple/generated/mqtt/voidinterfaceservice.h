#pragma once

#include "tb_simple/generated/api/tb_simple.h"
#include "tb_simple/generated/api/common.h"
#include "apigear/mqtt/mqttservice.h"

namespace Test {
namespace TbSimple {
namespace MQTT {
class TEST_TB_SIMPLE_EXPORT VoidInterfaceService : public IVoidInterfaceSubscriber
{
public:
    explicit VoidInterfaceService(std::shared_ptr<IVoidInterface> impl, std::shared_ptr<ApiGear::MQTT::Service> service);
    virtual ~VoidInterfaceService() override;

    void onConnectionStatusChanged(bool connectionStatus);
    void onInvokeFuncVoid(const std::string& args, const std::string& responseTopic, const std::string& correlationData) const;

    // IVoidInterfaceSubscriber interface
    void onSigVoid() override;

private:
    std::shared_ptr<IVoidInterface> m_impl;
    std::shared_ptr<ApiGear::MQTT::Service> m_service;
    // id for connection status registration
    int m_connectionStatusRegistrationID;

    /// @brief has all the topics of this service and the corresponding function callbacks
    const std::map<std::string, ApiGear::MQTT::CallbackFunction> m_topics;
};
} // namespace MQTT
} // namespace TbSimple
} // namespace Test
