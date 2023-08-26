#pragma once

#include <future>
#include "tb_simple/generated/api/common.h"
#include "tb_simple/generated/api/tb_simple.h"
#include "tb_simple/generated/core/simplearrayinterface.data.h"
#include "apigear/mqtt/mqttclient.h"

namespace Test {
namespace TbSimple {
namespace MQTT {
class TEST_TB_SIMPLE_EXPORT SimpleArrayInterfaceClient : public ISimpleArrayInterface
{
public:
    explicit SimpleArrayInterfaceClient(std::shared_ptr<ApiGear::MQTT::Client> client);
    virtual ~SimpleArrayInterfaceClient() override;
    const std::list<bool>& getPropBool() const override;
    void setPropBool(const std::list<bool>& propBool) override;
    const std::list<int>& getPropInt() const override;
    void setPropInt(const std::list<int>& propInt) override;
    const std::list<int32_t>& getPropInt32() const override;
    void setPropInt32(const std::list<int32_t>& propInt32) override;
    const std::list<int64_t>& getPropInt64() const override;
    void setPropInt64(const std::list<int64_t>& propInt64) override;
    const std::list<float>& getPropFloat() const override;
    void setPropFloat(const std::list<float>& propFloat) override;
    const std::list<float>& getPropFloat32() const override;
    void setPropFloat32(const std::list<float>& propFloat32) override;
    const std::list<double>& getPropFloat64() const override;
    void setPropFloat64(const std::list<double>& propFloat64) override;
    const std::list<std::string>& getPropString() const override;
    void setPropString(const std::list<std::string>& propString) override;
    std::list<bool> funcBool(const std::list<bool>& paramBool) override;
    std::future<std::list<bool>> funcBoolAsync(const std::list<bool>& paramBool) override;
    std::list<int> funcInt(const std::list<int>& paramInt) override;
    std::future<std::list<int>> funcIntAsync(const std::list<int>& paramInt) override;
    std::list<int32_t> funcInt32(const std::list<int32_t>& paramInt32) override;
    std::future<std::list<int32_t>> funcInt32Async(const std::list<int32_t>& paramInt32) override;
    std::list<int64_t> funcInt64(const std::list<int64_t>& paramInt64) override;
    std::future<std::list<int64_t>> funcInt64Async(const std::list<int64_t>& paramInt64) override;
    std::list<float> funcFloat(const std::list<float>& paramFloat) override;
    std::future<std::list<float>> funcFloatAsync(const std::list<float>& paramFloat) override;
    std::list<float> funcFloat32(const std::list<float>& paramFloat32) override;
    std::future<std::list<float>> funcFloat32Async(const std::list<float>& paramFloat32) override;
    std::list<double> funcFloat64(const std::list<double>& paramFloat) override;
    std::future<std::list<double>> funcFloat64Async(const std::list<double>& paramFloat) override;
    std::list<std::string> funcString(const std::list<std::string>& paramString) override;
    std::future<std::list<std::string>> funcStringAsync(const std::list<std::string>& paramString) override;
    ISimpleArrayInterfacePublisher& _getPublisher() const override;

    bool isReady() const;

    void onSignal(const std::string& topic, const std::string& args);
    void onInvokeReply(const std::string& args, const std::string& correlationData);
    /// @brief sets the value for the property PropBool coming from the service
    /// @param fields contains the param of the type std::list<bool>
    void setPropBoolLocal(const nlohmann::json& fields);
    /// @brief sets the value for the property PropInt coming from the service
    /// @param fields contains the param of the type std::list<int>
    void setPropIntLocal(const nlohmann::json& fields);
    /// @brief sets the value for the property PropInt32 coming from the service
    /// @param fields contains the param of the type std::list<int32_t>
    void setPropInt32Local(const nlohmann::json& fields);
    /// @brief sets the value for the property PropInt64 coming from the service
    /// @param fields contains the param of the type std::list<int64_t>
    void setPropInt64Local(const nlohmann::json& fields);
    /// @brief sets the value for the property PropFloat coming from the service
    /// @param fields contains the param of the type std::list<float>
    void setPropFloatLocal(const nlohmann::json& fields);
    /// @brief sets the value for the property PropFloat32 coming from the service
    /// @param fields contains the param of the type std::list<float>
    void setPropFloat32Local(const nlohmann::json& fields);
    /// @brief sets the value for the property PropFloat64 coming from the service
    /// @param fields contains the param of the type std::list<double>
    void setPropFloat64Local(const nlohmann::json& fields);
    /// @brief sets the value for the property PropString coming from the service
    /// @param fields contains the param of the type std::list<std::string>
    void setPropStringLocal(const nlohmann::json& fields);

private:
    bool m_isReady;
    /** Local storage for properties values. */
    SimpleArrayInterfaceData m_data;
    std::shared_ptr<ApiGear::MQTT::Client> m_client;

    /** The publisher for SimpleArrayInterface */
    std::unique_ptr<ISimpleArrayInterfacePublisher> m_publisher;

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
