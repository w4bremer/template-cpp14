#include "testbed2/generated/mqtt/nestedstruct2interfaceclient.h"
#include "testbed2/generated/core/nestedstruct2interface.publisher.h"
#include "testbed2/generated/core/testbed2.json.adapter.h"

using namespace Test::Testbed2;
using namespace Test::Testbed2::MQTT;

NestedStruct2InterfaceClient::NestedStruct2InterfaceClient(std::shared_ptr<ApiGear::MQTT::Client> client)
    : m_isReady(false)
    , m_client(client)
    , m_publisher(std::make_unique<NestedStruct2InterfacePublisher>())
{
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed2","NestedStruct2Interface",ApiGear::MQTT::Topic::TopicType::Property,"prop1"), this);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed2","NestedStruct2Interface",ApiGear::MQTT::Topic::TopicType::Property,"prop2"), this);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed2","NestedStruct2Interface",ApiGear::MQTT::Topic::TopicType::Signal,"sig1"), this);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed2","NestedStruct2Interface",ApiGear::MQTT::Topic::TopicType::Signal,"sig2"), this);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed2","NestedStruct2Interface",ApiGear::MQTT::Topic::TopicType::Operation,"func1",m_client->getClientId()+"/result"), nullptr);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed2","NestedStruct2Interface",ApiGear::MQTT::Topic::TopicType::Operation,"func2",m_client->getClientId()+"/result"), nullptr);
}

NestedStruct2InterfaceClient::~NestedStruct2InterfaceClient()
{
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed2","NestedStruct2Interface",ApiGear::MQTT::Topic::TopicType::Property,"prop1"), this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed2","NestedStruct2Interface",ApiGear::MQTT::Topic::TopicType::Property,"prop2"), this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed2","NestedStruct2Interface",ApiGear::MQTT::Topic::TopicType::Signal,"sig1"), this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed2","NestedStruct2Interface",ApiGear::MQTT::Topic::TopicType::Signal,"sig2"), this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed2","NestedStruct2Interface",ApiGear::MQTT::Topic::TopicType::Operation,"func1",m_client->getClientId()+"/result"), nullptr);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed2","NestedStruct2Interface",ApiGear::MQTT::Topic::TopicType::Operation,"func2",m_client->getClientId()+"/result"), nullptr);
}

void NestedStruct2InterfaceClient::applyState(const nlohmann::json& fields) 
{
    if(fields.contains("prop1")) {
        setProp1Local(fields["prop1"].get<NestedStruct1>());
    }
    if(fields.contains("prop2")) {
        setProp2Local(fields["prop2"].get<NestedStruct2>());
    }
}

void NestedStruct2InterfaceClient::setProp1(const NestedStruct1& prop1)
{
    if(m_client == nullptr) {
        return;
    }
    static const auto topic = ApiGear::MQTT::Topic("testbed2","NestedStruct2Interface",ApiGear::MQTT::Topic::TopicType::Operation,"_setprop1");
    m_client->setRemoteProperty(topic, nlohmann::json(prop1).dump());
}

void NestedStruct2InterfaceClient::setProp1Local(const NestedStruct1& prop1)
{
    if (m_data.m_prop1 != prop1) {
        m_data.m_prop1 = prop1;
        m_publisher->publishProp1Changed(prop1);
    }
}

const NestedStruct1& NestedStruct2InterfaceClient::getProp1() const
{
    return m_data.m_prop1;
}

void NestedStruct2InterfaceClient::setProp2(const NestedStruct2& prop2)
{
    if(m_client == nullptr) {
        return;
    }
    static const auto topic = ApiGear::MQTT::Topic("testbed2","NestedStruct2Interface",ApiGear::MQTT::Topic::TopicType::Operation,"_setprop2");
    m_client->setRemoteProperty(topic, nlohmann::json(prop2).dump());
}

void NestedStruct2InterfaceClient::setProp2Local(const NestedStruct2& prop2)
{
    if (m_data.m_prop2 != prop2) {
        m_data.m_prop2 = prop2;
        m_publisher->publishProp2Changed(prop2);
    }
}

const NestedStruct2& NestedStruct2InterfaceClient::getProp2() const
{
    return m_data.m_prop2;
}

NestedStruct1 NestedStruct2InterfaceClient::func1(const NestedStruct1& param1)
{
    if(m_client == nullptr) {
        return NestedStruct1();
    }
    NestedStruct1 value(func1Async(param1).get());
    return value;
}

std::future<NestedStruct1> NestedStruct2InterfaceClient::func1Async(const NestedStruct1& param1)
{
    if(m_client == nullptr) {
        throw std::runtime_error("Client is not initialized");
    }
    return std::async(std::launch::async, [this,
                    param1]()
        {
            std::promise<NestedStruct1> resultPromise;
            static const auto topic = ApiGear::MQTT::Topic("testbed2","NestedStruct2Interface",ApiGear::MQTT::Topic::TopicType::Operation,"func1");
            m_client->invokeRemote(topic,
                nlohmann::json::array({param1}).dump(), [&resultPromise](ApiGear::MQTT::InvokeReplyArg arg) {
                    const NestedStruct1& value = arg.value.get<NestedStruct1>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

NestedStruct1 NestedStruct2InterfaceClient::func2(const NestedStruct1& param1, const NestedStruct2& param2)
{
    if(m_client == nullptr) {
        return NestedStruct1();
    }
    NestedStruct1 value(func2Async(param1, param2).get());
    return value;
}

std::future<NestedStruct1> NestedStruct2InterfaceClient::func2Async(const NestedStruct1& param1, const NestedStruct2& param2)
{
    if(m_client == nullptr) {
        throw std::runtime_error("Client is not initialized");
    }
    return std::async(std::launch::async, [this,
                    param1,
                    param2]()
        {
            std::promise<NestedStruct1> resultPromise;
            static const auto topic = ApiGear::MQTT::Topic("testbed2","NestedStruct2Interface",ApiGear::MQTT::Topic::TopicType::Operation,"func2");
            m_client->invokeRemote(topic,
                nlohmann::json::array({param1, param2}).dump(), [&resultPromise](ApiGear::MQTT::InvokeReplyArg arg) {
                    const NestedStruct1& value = arg.value.get<NestedStruct1>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

void NestedStruct2InterfaceClient::onSignal(const ApiGear::MQTT::Topic& topic, const std::string& args)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    if(topic.getEntityName() == "sig1") {
        m_publisher->publishSig1(json_args[0].get<NestedStruct1>());
        return;
    }
    if(topic.getEntityName() == "sig2") {
        m_publisher->publishSig2(json_args[0].get<NestedStruct1>(),json_args[1].get<NestedStruct2>());
        return;
    }
}

void NestedStruct2InterfaceClient::onPropertyChanged(const ApiGear::MQTT::Topic& topic, const std::string& args)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string& name = topic.getEntityName();
    applyState({ {name, json_args} });
    return;
}

bool NestedStruct2InterfaceClient::isReady() const
{
    return m_isReady;
}

INestedStruct2InterfacePublisher& NestedStruct2InterfaceClient::_getPublisher() const
{
    return *m_publisher;
}
