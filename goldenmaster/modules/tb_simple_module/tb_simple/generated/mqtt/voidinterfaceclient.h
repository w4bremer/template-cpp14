#pragma once

#include <future>
#include "tb_simple/generated/api/common.h"
#include "tb_simple/generated/api/tb_simple.h"
#include "tb_simple/generated/core/voidinterface.data.h"
#include "apigear/mqtt/mqttcppclient.h"
#include "mqttisink.h"

namespace Test {
namespace TbSimple {
namespace MQTT {
class TEST_TB_SIMPLE_EXPORT VoidInterfaceClient : public IVoidInterface, public virtual ApiGear::MQTT::ISink
{
public:
    explicit VoidInterfaceClient(std::shared_ptr<ApiGear::MQTT::Client> client);
    virtual ~VoidInterfaceClient() override;
    void funcVoid() override;
    std::future<void> funcVoidAsync() override;
    IVoidInterfacePublisher& _getPublisher() const override;

    bool isReady() const;

    void onSignal(const ApiGear::MQTT::Topic& topic, const std::string& args) override;
    void onPropertyChanged(const ApiGear::MQTT::Topic& topic, const std::string& args) override;
    void onInvoke(const ApiGear::MQTT::Topic&, const std::string&, const ApiGear::MQTT::Topic&, const std::string&) override {};

private:

    void applyState(const nlohmann::json& fields);

    bool m_isReady;
    std::shared_ptr<ApiGear::MQTT::Client> m_client;

    /** The publisher for VoidInterface */
    std::unique_ptr<IVoidInterfacePublisher> m_publisher;
};
} // namespace MQTT
} // namespace TbSimple
} // namespace Test
