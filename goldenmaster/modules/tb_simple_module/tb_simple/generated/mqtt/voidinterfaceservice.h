#pragma once

#include "tb_simple/generated/api/tb_simple.h"
#include "tb_simple/generated/api/common.h"
#include "apigear/mqtt/mqttcppclient.h"

namespace Test {
namespace TbSimple {
namespace mqtt {
class TEST_TB_SIMPLE_EXPORT VoidInterfaceService : public virtual ApiGear::MQTTImpl::ISink, public IVoidInterfaceSubscriber
{
public:
    explicit VoidInterfaceService(IVoidInterface& impl, std::shared_ptr<ApiGear::MQTTImpl::Client> client);
    virtual ~VoidInterfaceService() override;

    // sink interface
    void onConnected() override;
    void onSignal(const ApiGear::MQTTImpl::Topic&, const std::string&) override {};
    void onPropertyChanged(const ApiGear::MQTTImpl::Topic&, const std::string&) override {};
    void onInvoke(const ApiGear::MQTTImpl::Topic& topic, const std::string& args, const ApiGear::MQTTImpl::Topic& responseTopic, const std::string& correlationData) override;

    // IVoidInterfaceSubscriber interface
    void onSigVoid() override;

private:
    IVoidInterface& m_impl;
    std::shared_ptr<ApiGear::MQTTImpl::Client> m_client;
};
} // namespace mqtt
} // namespace TbSimple
} // namespace Test
