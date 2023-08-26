#pragma once

#include <future>
#include "tb_same2/generated/api/common.h"
#include "tb_same2/generated/api/tb_same2.h"
#include "tb_same2/generated/core/samestruct1interface.data.h"
#include "apigear/mqtt/mqttclient.h"

namespace Test {
namespace TbSame2 {
namespace MQTT {
class TEST_TB_SAME2_EXPORT SameStruct1InterfaceClient : public ISameStruct1Interface
{
public:
    explicit SameStruct1InterfaceClient(std::shared_ptr<ApiGear::MQTT::Client> client);
    virtual ~SameStruct1InterfaceClient() override;
    const Struct1& getProp1() const override;
    void setProp1(const Struct1& prop1) override;
    Struct1 func1(const Struct1& param1) override;
    std::future<Struct1> func1Async(const Struct1& param1) override;
    ISameStruct1InterfacePublisher& _getPublisher() const override;

    bool isReady() const;

    void onSignal(const std::string& topic, const std::string& args);
    void onInvokeReply(const std::string& args, const std::string& correlationData);
    /// @brief sets the value for the property Prop1 coming from the service
    /// @param fields contains the param of the type Struct1
    void setProp1Local(const nlohmann::json& fields);

private:
    bool m_isReady;
    /** Local storage for properties values. */
    SameStruct1InterfaceData m_data;
    std::shared_ptr<ApiGear::MQTT::Client> m_client;

    /** The publisher for SameStruct1Interface */
    std::unique_ptr<ISameStruct1InterfacePublisher> m_publisher;

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
} // namespace TbSame2
} // namespace Test
