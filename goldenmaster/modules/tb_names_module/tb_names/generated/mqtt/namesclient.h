#pragma once

#include <future>
#include "tb_names/generated/api/common.h"
#include "tb_names/generated/api/tb_names.h"
#include "tb_names/generated/core/names.data.h"
#include "apigear/mqtt/mqttclient.h"

namespace Test {
namespace TbNames {
namespace MQTT {
class TEST_TB_NAMES_EXPORT NamesClient : public INames
{
public:
    explicit NamesClient(std::shared_ptr<ApiGear::MQTT::Client> client);
    virtual ~NamesClient() override;
    bool getSwitch() const override;
    void setSwitch(bool Switch) override;
    INamesPublisher& _getPublisher() const override;

    bool isReady() const;

    void onInvokeReply(const std::string& args, const std::string& correlationData);

    void onConnectionStatusChanged(bool connectionStatus);
private:
    /// @brief factory to create the topic map which is used for bindings
    /// @return map with all topics and corresponding function callbacks
    std::map<std::string, ApiGear::MQTT::CallbackFunction> createTopicMap(const std::string&);
    /// @brief sets the value for the property Switch coming from the service
    /// @param args contains the param of the type bool
    void setSwitchLocal(const std::string& args);

    bool m_isReady;
    /** Local storage for properties values. */
    NamesData m_data;
    std::shared_ptr<ApiGear::MQTT::Client> m_client;

    /** The publisher for Names */
    std::unique_ptr<INamesPublisher> m_publisher;

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
} // namespace TbNames
} // namespace Test
