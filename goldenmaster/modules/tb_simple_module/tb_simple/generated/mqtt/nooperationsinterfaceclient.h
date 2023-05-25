#pragma once

#include <future>
#include "tb_simple/generated/api/common.h"
#include "tb_simple/generated/api/tb_simple.h"
#include "tb_simple/generated/core/nooperationsinterface.data.h"
#include "apigear/mqtt/mqttclient.h"

namespace Test {
namespace TbSimple {
namespace MQTT {
class TEST_TB_SIMPLE_EXPORT NoOperationsInterfaceClient : public INoOperationsInterface
{
public:
    explicit NoOperationsInterfaceClient(std::shared_ptr<ApiGear::MQTT::Client> client);
    virtual ~NoOperationsInterfaceClient() override;
    bool getPropBool() const override;
    void setPropBool(bool propBool) override;
    int getPropInt() const override;
    void setPropInt(int propInt) override;
    INoOperationsInterfacePublisher& _getPublisher() const override;

    bool isReady() const;

    void onSignal(const ApiGear::MQTT::Topic& topic, const std::string& args, const ApiGear::MQTT::Topic& responseTopic, const std::string& correlationData);
    void onPropertyChanged(const ApiGear::MQTT::Topic& topic, const std::string& args, const ApiGear::MQTT::Topic& responseTopic, const std::string& correlationData);

private:
    void setPropBoolLocal(bool propBool);
    void setPropIntLocal(int propInt);

    void applyState(const nlohmann::json& fields);

    bool m_isReady;
    /** Local storage for properties values. */
    NoOperationsInterfaceData m_data;
    std::shared_ptr<ApiGear::MQTT::Client> m_client;

    /** The publisher for NoOperationsInterface */
    std::unique_ptr<INoOperationsInterfacePublisher> m_publisher;
};
} // namespace MQTT
} // namespace TbSimple
} // namespace Test
