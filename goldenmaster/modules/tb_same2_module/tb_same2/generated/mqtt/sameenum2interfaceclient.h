#pragma once

#include <future>
#include "tb_same2/generated/api/common.h"
#include "tb_same2/generated/api/tb_same2.h"
#include "tb_same2/generated/core/sameenum2interface.data.h"
#include "apigear/mqtt/mqttclient.h"

namespace Test {
namespace TbSame2 {
namespace MQTT {
class TEST_TB_SAME2_EXPORT SameEnum2InterfaceClient : public ISameEnum2Interface
{
public:
    explicit SameEnum2InterfaceClient(std::shared_ptr<ApiGear::MQTT::Client> client);
    virtual ~SameEnum2InterfaceClient() override;
    Enum1Enum getProp1() const override;
    void setProp1(Enum1Enum prop1) override;
    Enum2Enum getProp2() const override;
    void setProp2(Enum2Enum prop2) override;
    Enum1Enum func1(Enum1Enum param1) override;
    std::future<Enum1Enum> func1Async(Enum1Enum param1) override;
    Enum1Enum func2(Enum1Enum param1, Enum2Enum param2) override;
    std::future<Enum1Enum> func2Async(Enum1Enum param1, Enum2Enum param2) override;
    ISameEnum2InterfacePublisher& _getPublisher() const override;

    bool isReady() const;

    void onSignal(const std::string& topic, const std::string& args);
    void onPropertyChanged(const std::string& topic, const std::string& args);
    void onInvokeReply(const std::string& args, const std::string& correlationData);

private:
    void setProp1Local(Enum1Enum prop1);
    void setProp2Local(Enum2Enum prop2);

    void applyState(const nlohmann::json& fields);

    bool m_isReady;
    /** Local storage for properties values. */
    SameEnum2InterfaceData m_data;
    std::shared_ptr<ApiGear::MQTT::Client> m_client;

    /** The publisher for SameEnum2Interface */
    std::unique_ptr<ISameEnum2InterfacePublisher> m_publisher;

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
