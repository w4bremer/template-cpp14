#pragma once

#include <future>
#include "tb_simple/generated/api/common.h"
#include "tb_simple/generated/api/tb_simple.h"
#include "tb_simple/generated/core/nosignalsinterface.data.h"
#include "apigear/mqtt/mqttcppclient.h"
#include "mqttisink.h"

namespace Test {
namespace TbSimple {
namespace MQTT {
class TEST_TB_SIMPLE_EXPORT NoSignalsInterfaceClient : public INoSignalsInterface, public virtual ApiGear::MQTT::ISink
{
public:
    explicit NoSignalsInterfaceClient(std::shared_ptr<ApiGear::MQTT::Client> client);
    virtual ~NoSignalsInterfaceClient() override;
    bool getPropBool() const override;
    void setPropBool(bool propBool) override;
    int getPropInt() const override;
    void setPropInt(int propInt) override;
    void funcVoid() override;
    std::future<void> funcVoidAsync() override;
    bool funcBool(bool paramBool) override;
    std::future<bool> funcBoolAsync(bool paramBool) override;
    INoSignalsInterfacePublisher& _getPublisher() const override;

    bool isReady() const;

    void onSignal(const ApiGear::MQTT::Topic& topic, const std::string& args) override;
    void onPropertyChanged(const ApiGear::MQTT::Topic& topic, const std::string& args) override;
    void onInvoke(const ApiGear::MQTT::Topic&, const std::string&, const ApiGear::MQTT::Topic&, const std::string&) override {};

private:
    void setPropBoolLocal(bool propBool);
    void setPropIntLocal(int propInt);

    void applyState(const nlohmann::json& fields);

    bool m_isReady;
    /** Local storage for properties values. */
    NoSignalsInterfaceData m_data;
    std::shared_ptr<ApiGear::MQTT::Client> m_client;

    /** The publisher for NoSignalsInterface */
    std::unique_ptr<INoSignalsInterfacePublisher> m_publisher;
};
} // namespace MQTT
} // namespace TbSimple
} // namespace Test
