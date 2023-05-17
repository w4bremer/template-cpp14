#include "tb_same1/generated/mqtt/samestruct2interfaceclient.h"
#include "tb_same1/generated/core/samestruct2interface.publisher.h"
#include "tb_same1/generated/core/tb_same1.json.adapter.h"

using namespace Test::TbSame1;
using namespace Test::TbSame1::MQTT;

SameStruct2InterfaceClient::SameStruct2InterfaceClient(std::shared_ptr<ApiGear::MQTT::Client> client)
    : m_isReady(false)
    , m_client(client)
    , m_publisher(std::make_unique<SameStruct2InterfacePublisher>())
{
    m_client->subscribeTopic(ApiGear::MQTT::Topic("tb.same1","SameStruct2Interface",ApiGear::MQTT::Topic::TopicType::Property,"prop1"), this);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("tb.same1","SameStruct2Interface",ApiGear::MQTT::Topic::TopicType::Property,"prop2"), this);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("tb.same1","SameStruct2Interface",ApiGear::MQTT::Topic::TopicType::Signal,"sig1"), this);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("tb.same1","SameStruct2Interface",ApiGear::MQTT::Topic::TopicType::Signal,"sig2"), this);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("tb.same1","SameStruct2Interface",ApiGear::MQTT::Topic::TopicType::Operation,"func1",m_client->getClientId()+"/result"), nullptr);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("tb.same1","SameStruct2Interface",ApiGear::MQTT::Topic::TopicType::Operation,"func2",m_client->getClientId()+"/result"), nullptr);
}

SameStruct2InterfaceClient::~SameStruct2InterfaceClient()
{
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("tb.same1","SameStruct2Interface",ApiGear::MQTT::Topic::TopicType::Property,"prop1"), this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("tb.same1","SameStruct2Interface",ApiGear::MQTT::Topic::TopicType::Property,"prop2"), this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("tb.same1","SameStruct2Interface",ApiGear::MQTT::Topic::TopicType::Signal,"sig1"), this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("tb.same1","SameStruct2Interface",ApiGear::MQTT::Topic::TopicType::Signal,"sig2"), this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("tb.same1","SameStruct2Interface",ApiGear::MQTT::Topic::TopicType::Operation,"func1",m_client->getClientId()+"/result"), nullptr);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("tb.same1","SameStruct2Interface",ApiGear::MQTT::Topic::TopicType::Operation,"func2",m_client->getClientId()+"/result"), nullptr);
}

void SameStruct2InterfaceClient::applyState(const nlohmann::json& fields) 
{
    if(fields.contains("prop1")) {
        setProp1Local(fields["prop1"].get<Struct2>());
    }
    if(fields.contains("prop2")) {
        setProp2Local(fields["prop2"].get<Struct2>());
    }
}

void SameStruct2InterfaceClient::setProp1(const Struct2& prop1)
{
    if(m_client == nullptr) {
        return;
    }
    static const auto topic = ApiGear::MQTT::Topic("tb.same1","SameStruct2Interface",ApiGear::MQTT::Topic::TopicType::Operation,"_setprop1");
    m_client->setRemoteProperty(topic, nlohmann::json(prop1).dump());
}

void SameStruct2InterfaceClient::setProp1Local(const Struct2& prop1)
{
    if (m_data.m_prop1 != prop1) {
        m_data.m_prop1 = prop1;
        m_publisher->publishProp1Changed(prop1);
    }
}

const Struct2& SameStruct2InterfaceClient::getProp1() const
{
    return m_data.m_prop1;
}

void SameStruct2InterfaceClient::setProp2(const Struct2& prop2)
{
    if(m_client == nullptr) {
        return;
    }
    static const auto topic = ApiGear::MQTT::Topic("tb.same1","SameStruct2Interface",ApiGear::MQTT::Topic::TopicType::Operation,"_setprop2");
    m_client->setRemoteProperty(topic, nlohmann::json(prop2).dump());
}

void SameStruct2InterfaceClient::setProp2Local(const Struct2& prop2)
{
    if (m_data.m_prop2 != prop2) {
        m_data.m_prop2 = prop2;
        m_publisher->publishProp2Changed(prop2);
    }
}

const Struct2& SameStruct2InterfaceClient::getProp2() const
{
    return m_data.m_prop2;
}

Struct1 SameStruct2InterfaceClient::func1(const Struct1& param1)
{
    if(m_client == nullptr) {
        return Struct1();
    }
    Struct1 value(func1Async(param1).get());
    return value;
}

std::future<Struct1> SameStruct2InterfaceClient::func1Async(const Struct1& param1)
{
    if(m_client == nullptr) {
        throw std::runtime_error("Client is not initialized");
    }
    return std::async(std::launch::async, [this,
                    param1]()
        {
            std::promise<Struct1> resultPromise;
            static const auto topic = ApiGear::MQTT::Topic("tb.same1","SameStruct2Interface",ApiGear::MQTT::Topic::TopicType::Operation,"func1");
            m_client->invokeRemote(topic,
                nlohmann::json::array({param1}).dump(), [&resultPromise](ApiGear::MQTT::InvokeReplyArg arg) {
                    const Struct1& value = arg.value.get<Struct1>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

Struct1 SameStruct2InterfaceClient::func2(const Struct1& param1, const Struct2& param2)
{
    if(m_client == nullptr) {
        return Struct1();
    }
    Struct1 value(func2Async(param1, param2).get());
    return value;
}

std::future<Struct1> SameStruct2InterfaceClient::func2Async(const Struct1& param1, const Struct2& param2)
{
    if(m_client == nullptr) {
        throw std::runtime_error("Client is not initialized");
    }
    return std::async(std::launch::async, [this,
                    param1,
                    param2]()
        {
            std::promise<Struct1> resultPromise;
            static const auto topic = ApiGear::MQTT::Topic("tb.same1","SameStruct2Interface",ApiGear::MQTT::Topic::TopicType::Operation,"func2");
            m_client->invokeRemote(topic,
                nlohmann::json::array({param1, param2}).dump(), [&resultPromise](ApiGear::MQTT::InvokeReplyArg arg) {
                    const Struct1& value = arg.value.get<Struct1>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

void SameStruct2InterfaceClient::onSignal(const ApiGear::MQTT::Topic& topic, const std::string& args)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    if(topic.getEntityName() == "sig1") {
        m_publisher->publishSig1(json_args[0].get<Struct1>());
        return;
    }
    if(topic.getEntityName() == "sig2") {
        m_publisher->publishSig2(json_args[0].get<Struct1>(),json_args[1].get<Struct2>());
        return;
    }
}

void SameStruct2InterfaceClient::onPropertyChanged(const ApiGear::MQTT::Topic& topic, const std::string& args)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string& name = topic.getEntityName();
    applyState({ {name, json_args} });
    return;
}

bool SameStruct2InterfaceClient::isReady() const
{
    return m_isReady;
}

ISameStruct2InterfacePublisher& SameStruct2InterfaceClient::_getPublisher() const
{
    return *m_publisher;
}
