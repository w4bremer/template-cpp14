#pragma once

#include <future>
#include "testbed1/generated/api/common.h"
#include "testbed1/generated/api/testbed1.h"
#include "testbed1/generated/core/structarrayinterface.data.h"
#include "apigear/mqtt/mqttclient.h"

namespace Test {
namespace Testbed1 {
namespace MQTT {
class TEST_TESTBED1_EXPORT StructArrayInterfaceClient : public IStructArrayInterface
{
public:
    explicit StructArrayInterfaceClient(std::shared_ptr<ApiGear::MQTT::Client> client);
    virtual ~StructArrayInterfaceClient() override;
    const std::list<StructBool>& getPropBool() const override;
    void setPropBool(const std::list<StructBool>& propBool) override;
    const std::list<StructInt>& getPropInt() const override;
    void setPropInt(const std::list<StructInt>& propInt) override;
    const std::list<StructFloat>& getPropFloat() const override;
    void setPropFloat(const std::list<StructFloat>& propFloat) override;
    const std::list<StructString>& getPropString() const override;
    void setPropString(const std::list<StructString>& propString) override;
    StructBool funcBool(const std::list<StructBool>& paramBool) override;
    std::future<StructBool> funcBoolAsync(const std::list<StructBool>& paramBool) override;
    StructBool funcInt(const std::list<StructInt>& paramInt) override;
    std::future<StructBool> funcIntAsync(const std::list<StructInt>& paramInt) override;
    StructBool funcFloat(const std::list<StructFloat>& paramFloat) override;
    std::future<StructBool> funcFloatAsync(const std::list<StructFloat>& paramFloat) override;
    StructBool funcString(const std::list<StructString>& paramString) override;
    std::future<StructBool> funcStringAsync(const std::list<StructString>& paramString) override;
    IStructArrayInterfacePublisher& _getPublisher() const override;

    bool isReady() const;

    void onSignal(const std::string& topic, const std::string& args);
    void onInvokeReply(const std::string& args, const std::string& correlationData);
    /// @brief sets the value for the property PropBool coming from the service
    /// @param args contains the param of the type std::list<StructBool>
    void setPropBoolLocal(const std::string& args);
    /// @brief sets the value for the property PropInt coming from the service
    /// @param args contains the param of the type std::list<StructInt>
    void setPropIntLocal(const std::string& args);
    /// @brief sets the value for the property PropFloat coming from the service
    /// @param args contains the param of the type std::list<StructFloat>
    void setPropFloatLocal(const std::string& args);
    /// @brief sets the value for the property PropString coming from the service
    /// @param args contains the param of the type std::list<StructString>
    void setPropStringLocal(const std::string& args);

private:
    bool m_isReady;
    /** Local storage for properties values. */
    StructArrayInterfaceData m_data;
    std::shared_ptr<ApiGear::MQTT::Client> m_client;

    /** The publisher for StructArrayInterface */
    std::unique_ptr<IStructArrayInterfacePublisher> m_publisher;

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
