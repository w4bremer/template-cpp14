#include "tb_same1/generated/mqtt/sameenum2interfaceclient.h"
#include "tb_same1/generated/core/sameenum2interface.publisher.h"
#include "tb_same1/generated/core/tb_same1.json.adapter.h"

using namespace Test::TbSame1;
using namespace Test::TbSame1::mqtt;

SameEnum2InterfaceClient::SameEnum2InterfaceClient(std::shared_ptr<ApiGear::MQTTImpl::Client> client)
    : m_isReady(false)
    , m_client(client)
    , m_publisher(std::make_unique<SameEnum2InterfacePublisher>())
{
    m_client->subscribeTopic(ApiGear::MQTTImpl::Topic("tb.same1","SameEnum2Interface",ApiGear::MQTTImpl::Topic::TopicType::Property,"prop1"), this);
    m_client->subscribeTopic(ApiGear::MQTTImpl::Topic("tb.same1","SameEnum2Interface",ApiGear::MQTTImpl::Topic::TopicType::Property,"prop2"), this);
    m_client->subscribeTopic(ApiGear::MQTTImpl::Topic("tb.same1","SameEnum2Interface",ApiGear::MQTTImpl::Topic::TopicType::Signal,"sig1"), this);
    m_client->subscribeTopic(ApiGear::MQTTImpl::Topic("tb.same1","SameEnum2Interface",ApiGear::MQTTImpl::Topic::TopicType::Signal,"sig2"), this);
    m_client->subscribeTopic(ApiGear::MQTTImpl::Topic("tb.same1","SameEnum2Interface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"func1",m_client->getClientId()+"/result"), nullptr);
    m_client->subscribeTopic(ApiGear::MQTTImpl::Topic("tb.same1","SameEnum2Interface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"func2",m_client->getClientId()+"/result"), nullptr);
}

SameEnum2InterfaceClient::~SameEnum2InterfaceClient()
{
    m_client->unsubscribeTopic(ApiGear::MQTTImpl::Topic("tb.same1","SameEnum2Interface",ApiGear::MQTTImpl::Topic::TopicType::Property,"prop1"), this);
    m_client->unsubscribeTopic(ApiGear::MQTTImpl::Topic("tb.same1","SameEnum2Interface",ApiGear::MQTTImpl::Topic::TopicType::Property,"prop2"), this);
    m_client->unsubscribeTopic(ApiGear::MQTTImpl::Topic("tb.same1","SameEnum2Interface",ApiGear::MQTTImpl::Topic::TopicType::Signal,"sig1"), this);
    m_client->unsubscribeTopic(ApiGear::MQTTImpl::Topic("tb.same1","SameEnum2Interface",ApiGear::MQTTImpl::Topic::TopicType::Signal,"sig2"), this);
    m_client->unsubscribeTopic(ApiGear::MQTTImpl::Topic("tb.same1","SameEnum2Interface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"func1",m_client->getClientId()+"/result"), nullptr);
    m_client->unsubscribeTopic(ApiGear::MQTTImpl::Topic("tb.same1","SameEnum2Interface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"func2",m_client->getClientId()+"/result"), nullptr);
}

void SameEnum2InterfaceClient::applyState(const nlohmann::json& fields) 
{
    if(fields.contains("prop1")) {
        setProp1Local(fields["prop1"].get<Enum1Enum>());
    }
    if(fields.contains("prop2")) {
        setProp2Local(fields["prop2"].get<Enum2Enum>());
    }
}

void SameEnum2InterfaceClient::setProp1(Enum1Enum prop1)
{
    if(m_client == nullptr) {
        return;
    }
    static const auto topic = ApiGear::MQTTImpl::Topic("tb.same1","SameEnum2Interface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"_setprop1");
    m_client->setRemoteProperty(topic, nlohmann::json(prop1).dump());
}

void SameEnum2InterfaceClient::setProp1Local(Enum1Enum prop1)
{
    if (m_data.m_prop1 != prop1) {
        m_data.m_prop1 = prop1;
        m_publisher->publishProp1Changed(prop1);
    }
}

Enum1Enum SameEnum2InterfaceClient::getProp1() const
{
    return m_data.m_prop1;
}

void SameEnum2InterfaceClient::setProp2(Enum2Enum prop2)
{
    if(m_client == nullptr) {
        return;
    }
    static const auto topic = ApiGear::MQTTImpl::Topic("tb.same1","SameEnum2Interface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"_setprop2");
    m_client->setRemoteProperty(topic, nlohmann::json(prop2).dump());
}

void SameEnum2InterfaceClient::setProp2Local(Enum2Enum prop2)
{
    if (m_data.m_prop2 != prop2) {
        m_data.m_prop2 = prop2;
        m_publisher->publishProp2Changed(prop2);
    }
}

Enum2Enum SameEnum2InterfaceClient::getProp2() const
{
    return m_data.m_prop2;
}

Enum1Enum SameEnum2InterfaceClient::func1(Enum1Enum param1)
{
    if(m_client == nullptr) {
        return Enum1Enum::value1;
    }
    Enum1Enum value(func1Async(param1).get());
    return value;
}

std::future<Enum1Enum> SameEnum2InterfaceClient::func1Async(Enum1Enum param1)
{
    if(m_client == nullptr) {
        throw std::runtime_error("Client is not initialized");
    }
    return std::async(std::launch::async, [this,
                    param1]()
        {
            std::promise<Enum1Enum> resultPromise;
            static const auto topic = ApiGear::MQTTImpl::Topic("tb.same1","SameEnum2Interface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"func1");
            m_client->invokeRemote(topic,
                nlohmann::json::array({param1}).dump(), [&resultPromise](ApiGear::MQTTImpl::InvokeReplyArg arg) {
                    const Enum1Enum& value = arg.value.get<Enum1Enum>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

Enum1Enum SameEnum2InterfaceClient::func2(Enum1Enum param1, Enum2Enum param2)
{
    if(m_client == nullptr) {
        return Enum1Enum::value1;
    }
    Enum1Enum value(func2Async(param1, param2).get());
    return value;
}

std::future<Enum1Enum> SameEnum2InterfaceClient::func2Async(Enum1Enum param1, Enum2Enum param2)
{
    if(m_client == nullptr) {
        throw std::runtime_error("Client is not initialized");
    }
    return std::async(std::launch::async, [this,
                    param1,
                    param2]()
        {
            std::promise<Enum1Enum> resultPromise;
            static const auto topic = ApiGear::MQTTImpl::Topic("tb.same1","SameEnum2Interface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"func2");
            m_client->invokeRemote(topic,
                nlohmann::json::array({param1, param2}).dump(), [&resultPromise](ApiGear::MQTTImpl::InvokeReplyArg arg) {
                    const Enum1Enum& value = arg.value.get<Enum1Enum>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

void SameEnum2InterfaceClient::onSignal(const ApiGear::MQTTImpl::Topic& topic, const std::string& args)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    if(topic.getEntityName() == "sig1") {
        m_publisher->publishSig1(json_args[0].get<Enum1Enum>());
        return;
    }
    if(topic.getEntityName() == "sig2") {
        m_publisher->publishSig2(json_args[0].get<Enum1Enum>(),json_args[1].get<Enum2Enum>());
        return;
    }
}

void SameEnum2InterfaceClient::onPropertyChanged(const ApiGear::MQTTImpl::Topic& topic, const std::string& args)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string& name = topic.getEntityName();
    applyState({ {name, json_args} });
    return;
}

bool SameEnum2InterfaceClient::isReady() const
{
    return m_isReady;
}

ISameEnum2InterfacePublisher& SameEnum2InterfaceClient::_getPublisher() const
{
    return *m_publisher;
}
