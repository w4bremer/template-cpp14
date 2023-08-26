#pragma once

#include <future>
#include "testbed1/generated/api/common.h"
#include "testbed1/generated/api/testbed1.h"
#include "testbed1/generated/core/structinterface.data.h"
#include "apigear/mqtt/mqttclient.h"

namespace Test {
namespace Testbed1 {
namespace MQTT {
class TEST_TESTBED1_EXPORT StructInterfaceClient : public IStructInterface
{
public:
    explicit StructInterfaceClient(std::shared_ptr<ApiGear::MQTT::Client> client);
    virtual ~StructInterfaceClient() override;
    const StructBool& getPropBool() const override;
    void setPropBool(const StructBool& propBool) override;
    const StructInt& getPropInt() const override;
    void setPropInt(const StructInt& propInt) override;
    const StructFloat& getPropFloat() const override;
    void setPropFloat(const StructFloat& propFloat) override;
    const StructString& getPropString() const override;
    void setPropString(const StructString& propString) override;
    StructBool funcBool(const StructBool& paramBool) override;
    std::future<StructBool> funcBoolAsync(const StructBool& paramBool) override;
    StructBool funcInt(const StructInt& paramInt) override;
    std::future<StructBool> funcIntAsync(const StructInt& paramInt) override;
    StructFloat funcFloat(const StructFloat& paramFloat) override;
    std::future<StructFloat> funcFloatAsync(const StructFloat& paramFloat) override;
    StructString funcString(const StructString& paramString) override;
    std::future<StructString> funcStringAsync(const StructString& paramString) override;
    IStructInterfacePublisher& _getPublisher() const override;

    bool isReady() const;

    void onSignal(const std::string& topic, const std::string& args);
    void onInvokeReply(const std::string& args, const std::string& correlationData);
    /// @brief sets the value for the property PropBool coming from the service
    /// @param fields contains the param of the type StructBool
    void setPropBoolLocal(const nlohmann::json& fields);
    /// @brief sets the value for the property PropInt coming from the service
    /// @param fields contains the param of the type StructInt
    void setPropIntLocal(const nlohmann::json& fields);
    /// @brief sets the value for the property PropFloat coming from the service
    /// @param fields contains the param of the type StructFloat
    void setPropFloatLocal(const nlohmann::json& fields);
    /// @brief sets the value for the property PropString coming from the service
    /// @param fields contains the param of the type StructString
    void setPropStringLocal(const nlohmann::json& fields);

private:
    bool m_isReady;
    /** Local storage for properties values. */
    StructInterfaceData m_data;
    std::shared_ptr<ApiGear::MQTT::Client> m_client;

    /** The publisher for StructInterface */
    std::unique_ptr<IStructInterfacePublisher> m_publisher;

    /**
     * @brief register a response handler for an operation invocation
     * 
     * @param handler function to be called on return
     * @return int unique id of the call
     */
    int registerResponseHandler(ApiGear::MQTT::InvokeReplyFunc handler);
    std::mutex m_responseHandlerMutex;
    std::map<int, ApiGear::MQTT::InvokeReplyFunc> m_responseHandlerMap;

    /// @brief has all the topics of this client and the corresponding function callbacks
    const std::map<std::string, ApiGear::MQTT::CallbackFunction> m_topics;
};
} // namespace MQTT
} // namespace Testbed1
} // namespace Test
