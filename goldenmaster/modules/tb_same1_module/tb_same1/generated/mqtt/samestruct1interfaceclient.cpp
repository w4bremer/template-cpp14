#include "tb_same1/generated/mqtt/samestruct1interfaceclient.h"
#include "tb_same1/generated/core/samestruct1interface.publisher.h"
#include "tb_same1/generated/core/tb_same1.json.adapter.h"

using namespace Test::TbSame1;
using namespace Test::TbSame1::MQTT;

SameStruct1InterfaceClient::SameStruct1InterfaceClient(std::shared_ptr<ApiGear::MQTT::Client> client)
    : m_isReady(false)
    , m_client(client)
    , m_publisher(std::make_unique<SameStruct1InterfacePublisher>())
{
    m_client->subscribeTopic(ApiGear::MQTT::Topic("tb.same1","SameStruct1Interface",ApiGear::MQTT::Topic::TopicType::Property,"prop1"), std::bind(&SameStruct1InterfaceClient::onPropertyChanged, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->subscribeTopic(ApiGear::MQTT::Topic("tb.same1","SameStruct1Interface",ApiGear::MQTT::Topic::TopicType::Signal,"sig1"), std::bind(&SameStruct1InterfaceClient::onSignal, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->subscribeTopic(ApiGear::MQTT::Topic("tb.same1","SameStruct1Interface",ApiGear::MQTT::Topic::TopicType::Operation,"func1",m_client->getClientId()+"/result"), nullptr);
}

SameStruct1InterfaceClient::~SameStruct1InterfaceClient()
{
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("tb.same1","SameStruct1Interface",ApiGear::MQTT::Topic::TopicType::Property,"prop1"), std::bind(&SameStruct1InterfaceClient::onPropertyChanged, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("tb.same1","SameStruct1Interface",ApiGear::MQTT::Topic::TopicType::Signal,"sig1"), std::bind(&SameStruct1InterfaceClient::onSignal, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("tb.same1","SameStruct1Interface",ApiGear::MQTT::Topic::TopicType::Operation,"func1",m_client->getClientId()+"/result"), nullptr);
}

void SameStruct1InterfaceClient::applyState(const nlohmann::json& fields) 
{
    if(fields.contains("prop1")) {
        setProp1Local(fields["prop1"].get<Struct1>());
    }
}

void SameStruct1InterfaceClient::setProp1(const Struct1& prop1)
{
    if(m_client == nullptr) {
        return;
    }
    static const auto topic = ApiGear::MQTT::Topic("tb.same1","SameStruct1Interface",ApiGear::MQTT::Topic::TopicType::Operation,"_setprop1");
    m_client->setRemoteProperty(topic, nlohmann::json(prop1).dump());
}

void SameStruct1InterfaceClient::setProp1Local(const Struct1& prop1)
{
    if (m_data.m_prop1 != prop1) {
        m_data.m_prop1 = prop1;
        m_publisher->publishProp1Changed(prop1);
    }
}

const Struct1& SameStruct1InterfaceClient::getProp1() const
{
    return m_data.m_prop1;
}

Struct1 SameStruct1InterfaceClient::func1(const Struct1& param1)
{
    if(m_client == nullptr) {
        return Struct1();
    }
    Struct1 value(func1Async(param1).get());
    return value;
}

std::future<Struct1> SameStruct1InterfaceClient::func1Async(const Struct1& param1)
{
    if(m_client == nullptr) {
        throw std::runtime_error("Client is not initialized");
    }
    return std::async(std::launch::async, [this,
                    param1]()
        {
            std::promise<Struct1> resultPromise;
            static const auto topic = ApiGear::MQTT::Topic("tb.same1","SameStruct1Interface",ApiGear::MQTT::Topic::TopicType::Operation,"func1");
            m_client->invokeRemote(topic,
                nlohmann::json::array({param1}).dump(), [&resultPromise](ApiGear::MQTT::InvokeReplyArg arg) {
                    const Struct1& value = arg.value.get<Struct1>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

void SameStruct1InterfaceClient::onSignal(const ApiGear::MQTT::Topic& topic, const std::string& args, const ApiGear::MQTT::Topic&, const std::string&)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    if(topic.getEntityName() == "sig1") {
        m_publisher->publishSig1(json_args[0].get<Struct1>());
        return;
    }
}

void SameStruct1InterfaceClient::onPropertyChanged(const ApiGear::MQTT::Topic& topic, const std::string& args, const ApiGear::MQTT::Topic&, const std::string&)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string& name = topic.getEntityName();
    applyState({ {name, json_args} });
    return;
}

bool SameStruct1InterfaceClient::isReady() const
{
    return m_isReady;
}

ISameStruct1InterfacePublisher& SameStruct1InterfaceClient::_getPublisher() const
{
    return *m_publisher;
}
