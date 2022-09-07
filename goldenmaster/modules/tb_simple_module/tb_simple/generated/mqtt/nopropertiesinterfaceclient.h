#pragma once

#include <future>
#include "tb_simple/generated/api/common.h"
#include "tb_simple/generated/api/tb_simple.h"
#include "tb_simple/generated/core/nopropertiesinterface.data.h"
#include "apigear/mqtt/mqttcppclient.h"

namespace Test {
namespace TbSimple {
namespace mqtt {
class TEST_TB_SIMPLE_EXPORT NoPropertiesInterfaceClient : public INoPropertiesInterface, public virtual ApiGear::MQTTImpl::ISink
{
public:
    explicit NoPropertiesInterfaceClient(std::shared_ptr<ApiGear::MQTTImpl::Client> client);
    virtual ~NoPropertiesInterfaceClient() override;
    void funcVoid() override;
    std::future<void> funcVoidAsync() override;
    bool funcBool(bool paramBool) override;
    std::future<bool> funcBoolAsync(bool paramBool) override;
    INoPropertiesInterfacePublisher& _getPublisher() const override;

    bool isReady() const;

    void onConnected() override {};
    void onSignal(const ApiGear::MQTTImpl::Topic& topic, const std::string& args) override;
    void onPropertyChanged(const ApiGear::MQTTImpl::Topic& topic, const std::string& args) override;
    void onInvoke(const ApiGear::MQTTImpl::Topic&, const std::string&, const ApiGear::MQTTImpl::Topic&, const std::string&) override {};

private:

    void applyState(const nlohmann::json& fields);

    bool m_isReady;
    std::shared_ptr<ApiGear::MQTTImpl::Client> m_client;

    /** The publisher for NoPropertiesInterface */
    std::unique_ptr<INoPropertiesInterfacePublisher> m_publisher;
};
} // namespace mqtt
} // namespace TbSimple
} // namespace Test
