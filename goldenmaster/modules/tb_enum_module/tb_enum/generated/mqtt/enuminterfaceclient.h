#pragma once

#include <future>
#include "tb_enum/generated/api/common.h"
#include "tb_enum/generated/api/tb_enum.h"
#include "tb_enum/generated/core/enuminterface.data.h"
#include "apigear/mqtt/mqttclient.h"

namespace Test {
namespace TbEnum {
namespace MQTT {
class TEST_TB_ENUM_EXPORT EnumInterfaceClient : public IEnumInterface
{
public:
    explicit EnumInterfaceClient(std::shared_ptr<ApiGear::MQTT::Client> client);
    virtual ~EnumInterfaceClient() override;
    Enum0Enum getProp0() const override;
    void setProp0(Enum0Enum prop0) override;
    Enum1Enum getProp1() const override;
    void setProp1(Enum1Enum prop1) override;
    Enum2Enum getProp2() const override;
    void setProp2(Enum2Enum prop2) override;
    Enum3Enum getProp3() const override;
    void setProp3(Enum3Enum prop3) override;
    Enum0Enum func0(Enum0Enum param0) override;
    std::future<Enum0Enum> func0Async(Enum0Enum param0) override;
    Enum1Enum func1(Enum1Enum param1) override;
    std::future<Enum1Enum> func1Async(Enum1Enum param1) override;
    Enum2Enum func2(Enum2Enum param2) override;
    std::future<Enum2Enum> func2Async(Enum2Enum param2) override;
    Enum3Enum func3(Enum3Enum param3) override;
    std::future<Enum3Enum> func3Async(Enum3Enum param3) override;
    IEnumInterfacePublisher& _getPublisher() const override;

    bool isReady() const;

    void onSignal(const std::string& topic, const std::string& args);
    void onInvokeReply(const std::string& args, const std::string& correlationData);
    /// @brief sets the value for the property Prop0 coming from the service
    /// @param args contains the param of the type Enum0Enum
    void setProp0Local(const std::string& args);
    /// @brief sets the value for the property Prop1 coming from the service
    /// @param args contains the param of the type Enum1Enum
    void setProp1Local(const std::string& args);
    /// @brief sets the value for the property Prop2 coming from the service
    /// @param args contains the param of the type Enum2Enum
    void setProp2Local(const std::string& args);
    /// @brief sets the value for the property Prop3 coming from the service
    /// @param args contains the param of the type Enum3Enum
    void setProp3Local(const std::string& args);

private:
    bool m_isReady;
    /** Local storage for properties values. */
    EnumInterfaceData m_data;
    std::shared_ptr<ApiGear::MQTT::Client> m_client;

    /** The publisher for EnumInterface */
    std::unique_ptr<IEnumInterfacePublisher> m_publisher;

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
} // namespace TbEnum
} // namespace Test
