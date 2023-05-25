#include "testbed2/generated/mqtt/nestedstruct3interfaceclient.h"
#include "testbed2/generated/core/nestedstruct3interface.publisher.h"
#include "testbed2/generated/core/testbed2.json.adapter.h"

using namespace Test::Testbed2;
using namespace Test::Testbed2::MQTT;

NestedStruct3InterfaceClient::NestedStruct3InterfaceClient(std::shared_ptr<ApiGear::MQTT::Client> client)
    : m_isReady(false)
    , m_client(client)
    , m_publisher(std::make_unique<NestedStruct3InterfacePublisher>())
{
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed2","NestedStruct3Interface",ApiGear::MQTT::Topic::TopicType::Property,"prop1"), std::bind(&NestedStruct3InterfaceClient::onPropertyChanged, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed2","NestedStruct3Interface",ApiGear::MQTT::Topic::TopicType::Property,"prop2"), std::bind(&NestedStruct3InterfaceClient::onPropertyChanged, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed2","NestedStruct3Interface",ApiGear::MQTT::Topic::TopicType::Property,"prop3"), std::bind(&NestedStruct3InterfaceClient::onPropertyChanged, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed2","NestedStruct3Interface",ApiGear::MQTT::Topic::TopicType::Signal,"sig1"), std::bind(&NestedStruct3InterfaceClient::onSignal, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed2","NestedStruct3Interface",ApiGear::MQTT::Topic::TopicType::Signal,"sig2"), std::bind(&NestedStruct3InterfaceClient::onSignal, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed2","NestedStruct3Interface",ApiGear::MQTT::Topic::TopicType::Signal,"sig3"), std::bind(&NestedStruct3InterfaceClient::onSignal, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed2","NestedStruct3Interface",ApiGear::MQTT::Topic::TopicType::Operation,"func1",m_client->getClientId()+"/result"), nullptr);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed2","NestedStruct3Interface",ApiGear::MQTT::Topic::TopicType::Operation,"func2",m_client->getClientId()+"/result"), nullptr);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed2","NestedStruct3Interface",ApiGear::MQTT::Topic::TopicType::Operation,"func3",m_client->getClientId()+"/result"), nullptr);
}

NestedStruct3InterfaceClient::~NestedStruct3InterfaceClient()
{
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed2","NestedStruct3Interface",ApiGear::MQTT::Topic::TopicType::Property,"prop1"), std::bind(&NestedStruct3InterfaceClient::onPropertyChanged, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed2","NestedStruct3Interface",ApiGear::MQTT::Topic::TopicType::Property,"prop2"), std::bind(&NestedStruct3InterfaceClient::onPropertyChanged, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed2","NestedStruct3Interface",ApiGear::MQTT::Topic::TopicType::Property,"prop3"), std::bind(&NestedStruct3InterfaceClient::onPropertyChanged, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed2","NestedStruct3Interface",ApiGear::MQTT::Topic::TopicType::Signal,"sig1"), std::bind(&NestedStruct3InterfaceClient::onSignal, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed2","NestedStruct3Interface",ApiGear::MQTT::Topic::TopicType::Signal,"sig2"), std::bind(&NestedStruct3InterfaceClient::onSignal, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed2","NestedStruct3Interface",ApiGear::MQTT::Topic::TopicType::Signal,"sig3"), std::bind(&NestedStruct3InterfaceClient::onSignal, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed2","NestedStruct3Interface",ApiGear::MQTT::Topic::TopicType::Operation,"func1",m_client->getClientId()+"/result"), nullptr);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed2","NestedStruct3Interface",ApiGear::MQTT::Topic::TopicType::Operation,"func2",m_client->getClientId()+"/result"), nullptr);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed2","NestedStruct3Interface",ApiGear::MQTT::Topic::TopicType::Operation,"func3",m_client->getClientId()+"/result"), nullptr);
}

void NestedStruct3InterfaceClient::applyState(const nlohmann::json& fields) 
{
    if(fields.contains("prop1")) {
        setProp1Local(fields["prop1"].get<NestedStruct1>());
    }
    if(fields.contains("prop2")) {
        setProp2Local(fields["prop2"].get<NestedStruct2>());
    }
    if(fields.contains("prop3")) {
        setProp3Local(fields["prop3"].get<NestedStruct3>());
    }
}

void NestedStruct3InterfaceClient::setProp1(const NestedStruct1& prop1)
{
    if(m_client == nullptr) {
        return;
    }
    static const auto topic = ApiGear::MQTT::Topic("testbed2","NestedStruct3Interface",ApiGear::MQTT::Topic::TopicType::Operation,"_setprop1");
    m_client->setRemoteProperty(topic, nlohmann::json(prop1).dump());
}

void NestedStruct3InterfaceClient::setProp1Local(const NestedStruct1& prop1)
{
    if (m_data.m_prop1 != prop1) {
        m_data.m_prop1 = prop1;
        m_publisher->publishProp1Changed(prop1);
    }
}

const NestedStruct1& NestedStruct3InterfaceClient::getProp1() const
{
    return m_data.m_prop1;
}

void NestedStruct3InterfaceClient::setProp2(const NestedStruct2& prop2)
{
    if(m_client == nullptr) {
        return;
    }
    static const auto topic = ApiGear::MQTT::Topic("testbed2","NestedStruct3Interface",ApiGear::MQTT::Topic::TopicType::Operation,"_setprop2");
    m_client->setRemoteProperty(topic, nlohmann::json(prop2).dump());
}

void NestedStruct3InterfaceClient::setProp2Local(const NestedStruct2& prop2)
{
    if (m_data.m_prop2 != prop2) {
        m_data.m_prop2 = prop2;
        m_publisher->publishProp2Changed(prop2);
    }
}

const NestedStruct2& NestedStruct3InterfaceClient::getProp2() const
{
    return m_data.m_prop2;
}

void NestedStruct3InterfaceClient::setProp3(const NestedStruct3& prop3)
{
    if(m_client == nullptr) {
        return;
    }
    static const auto topic = ApiGear::MQTT::Topic("testbed2","NestedStruct3Interface",ApiGear::MQTT::Topic::TopicType::Operation,"_setprop3");
    m_client->setRemoteProperty(topic, nlohmann::json(prop3).dump());
}

void NestedStruct3InterfaceClient::setProp3Local(const NestedStruct3& prop3)
{
    if (m_data.m_prop3 != prop3) {
        m_data.m_prop3 = prop3;
        m_publisher->publishProp3Changed(prop3);
    }
}

const NestedStruct3& NestedStruct3InterfaceClient::getProp3() const
{
    return m_data.m_prop3;
}

NestedStruct1 NestedStruct3InterfaceClient::func1(const NestedStruct1& param1)
{
    if(m_client == nullptr) {
        return NestedStruct1();
    }
    NestedStruct1 value(func1Async(param1).get());
    return value;
}

std::future<NestedStruct1> NestedStruct3InterfaceClient::func1Async(const NestedStruct1& param1)
{
    if(m_client == nullptr) {
        throw std::runtime_error("Client is not initialized");
    }
    return std::async(std::launch::async, [this,
                    param1]()
        {
            std::promise<NestedStruct1> resultPromise;
            static const auto topic = ApiGear::MQTT::Topic("testbed2","NestedStruct3Interface",ApiGear::MQTT::Topic::TopicType::Operation,"func1");
            m_client->invokeRemote(topic,
                nlohmann::json::array({param1}).dump(), [&resultPromise](ApiGear::MQTT::InvokeReplyArg arg) {
                    const NestedStruct1& value = arg.value.get<NestedStruct1>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

NestedStruct1 NestedStruct3InterfaceClient::func2(const NestedStruct1& param1, const NestedStruct2& param2)
{
    if(m_client == nullptr) {
        return NestedStruct1();
    }
    NestedStruct1 value(func2Async(param1, param2).get());
    return value;
}

std::future<NestedStruct1> NestedStruct3InterfaceClient::func2Async(const NestedStruct1& param1, const NestedStruct2& param2)
{
    if(m_client == nullptr) {
        throw std::runtime_error("Client is not initialized");
    }
    return std::async(std::launch::async, [this,
                    param1,
                    param2]()
        {
            std::promise<NestedStruct1> resultPromise;
            static const auto topic = ApiGear::MQTT::Topic("testbed2","NestedStruct3Interface",ApiGear::MQTT::Topic::TopicType::Operation,"func2");
            m_client->invokeRemote(topic,
                nlohmann::json::array({param1, param2}).dump(), [&resultPromise](ApiGear::MQTT::InvokeReplyArg arg) {
                    const NestedStruct1& value = arg.value.get<NestedStruct1>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

NestedStruct1 NestedStruct3InterfaceClient::func3(const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3)
{
    if(m_client == nullptr) {
        return NestedStruct1();
    }
    NestedStruct1 value(func3Async(param1, param2, param3).get());
    return value;
}

std::future<NestedStruct1> NestedStruct3InterfaceClient::func3Async(const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3)
{
    if(m_client == nullptr) {
        throw std::runtime_error("Client is not initialized");
    }
    return std::async(std::launch::async, [this,
                    param1,
                    param2,
                    param3]()
        {
            std::promise<NestedStruct1> resultPromise;
            static const auto topic = ApiGear::MQTT::Topic("testbed2","NestedStruct3Interface",ApiGear::MQTT::Topic::TopicType::Operation,"func3");
            m_client->invokeRemote(topic,
                nlohmann::json::array({param1, param2, param3}).dump(), [&resultPromise](ApiGear::MQTT::InvokeReplyArg arg) {
                    const NestedStruct1& value = arg.value.get<NestedStruct1>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

void NestedStruct3InterfaceClient::onSignal(const ApiGear::MQTT::Topic& topic, const std::string& args, const ApiGear::MQTT::Topic&, const std::string&)
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
    if(topic.getEntityName() == "sig3") {
        m_publisher->publishSig3(json_args[0].get<NestedStruct1>(),json_args[1].get<NestedStruct2>(),json_args[2].get<NestedStruct3>());
        return;
    }
}

void NestedStruct3InterfaceClient::onPropertyChanged(const ApiGear::MQTT::Topic& topic, const std::string& args, const ApiGear::MQTT::Topic&, const std::string&)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string& name = topic.getEntityName();
    applyState({ {name, json_args} });
    return;
}

bool NestedStruct3InterfaceClient::isReady() const
{
    return m_isReady;
}

INestedStruct3InterfacePublisher& NestedStruct3InterfaceClient::_getPublisher() const
{
    return *m_publisher;
}
