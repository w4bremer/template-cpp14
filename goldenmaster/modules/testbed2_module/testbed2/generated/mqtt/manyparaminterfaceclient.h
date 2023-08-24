#pragma once

#include <future>
#include "testbed2/generated/api/common.h"
#include "testbed2/generated/api/testbed2.h"
#include "testbed2/generated/core/manyparaminterface.data.h"
#include "apigear/mqtt/mqttclient.h"

namespace Test {
namespace Testbed2 {
namespace MQTT {
class TEST_TESTBED2_EXPORT ManyParamInterfaceClient : public IManyParamInterface
{
public:
    explicit ManyParamInterfaceClient(std::shared_ptr<ApiGear::MQTT::Client> client);
    virtual ~ManyParamInterfaceClient() override;
    int getProp1() const override;
    void setProp1(int prop1) override;
    int getProp2() const override;
    void setProp2(int prop2) override;
    int getProp3() const override;
    void setProp3(int prop3) override;
    int getProp4() const override;
    void setProp4(int prop4) override;
    int func1(int param1) override;
    std::future<int> func1Async(int param1) override;
    int func2(int param1, int param2) override;
    std::future<int> func2Async(int param1, int param2) override;
    int func3(int param1, int param2, int param3) override;
    std::future<int> func3Async(int param1, int param2, int param3) override;
    int func4(int param1, int param2, int param3, int param4) override;
    std::future<int> func4Async(int param1, int param2, int param3, int param4) override;
    IManyParamInterfacePublisher& _getPublisher() const override;

    bool isReady() const;

    void onSignal(const std::string& topic, const std::string& args);
    void onPropertyChanged(const std::string& topic, const std::string& args);
    void onInvokeReply(const std::string& args, const std::string& correlationData);

private:
    void setProp1Local(int prop1);
    void setProp2Local(int prop2);
    void setProp3Local(int prop3);
    void setProp4Local(int prop4);

    void applyState(const nlohmann::json& fields);

    bool m_isReady;
    /** Local storage for properties values. */
    ManyParamInterfaceData m_data;
    std::shared_ptr<ApiGear::MQTT::Client> m_client;

    /** The publisher for ManyParamInterface */
    std::unique_ptr<IManyParamInterfacePublisher> m_publisher;

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
} // namespace Testbed2
} // namespace Test
