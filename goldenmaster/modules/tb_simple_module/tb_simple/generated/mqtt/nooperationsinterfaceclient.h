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

    void onInvokeReply(const std::string& args, const std::string& correlationData);

private:
    /// @brief factory to create the topic map which is used for bindings
    /// @return map with all topics and corresponding function callbacks
    std::map<std::string, ApiGear::MQTT::CallbackFunction> createTopicMap(const std::string&);
    /// @brief sets the value for the property PropBool coming from the service
    /// @param fields contains the param of the type bool
    void setPropBoolLocal(const nlohmann::json& fields);
    /// @brief sets the value for the property PropInt coming from the service
    /// @param fields contains the param of the type int
    void setPropIntLocal(const nlohmann::json& fields);
    /// @brief publishes the value for the signal SigVoid coming from the service
    /// @param args contains the param(s) of the type(s) 
    void onSigVoid(const std::string& args) const;
    /// @brief publishes the value for the signal SigBool coming from the service
    /// @param args contains the param(s) of the type(s) bool paramBool
    void onSigBool(const std::string& args) const;

    bool m_isReady;
    /** Local storage for properties values. */
    NoOperationsInterfaceData m_data;
    std::shared_ptr<ApiGear::MQTT::Client> m_client;

    /** The publisher for NoOperationsInterface */
    std::unique_ptr<INoOperationsInterfacePublisher> m_publisher;

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
} // namespace TbSimple
} // namespace Test
