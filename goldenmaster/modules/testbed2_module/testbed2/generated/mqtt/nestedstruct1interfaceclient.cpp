#include "testbed2/generated/mqtt/nestedstruct1interfaceclient.h"
#include "testbed2/generated/core/nestedstruct1interface.publisher.h"
#include "testbed2/generated/core/testbed2.json.adapter.h"

using namespace Test::Testbed2;
using namespace Test::Testbed2::MQTT;

NestedStruct1InterfaceClient::NestedStruct1InterfaceClient(std::shared_ptr<ApiGear::MQTT::Client> client)
    : m_isReady(false)
    , m_client(client)
    , m_publisher(std::make_unique<NestedStruct1InterfacePublisher>())
{
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed2","NestedStruct1Interface",ApiGear::MQTT::Topic::TopicType::Property,"prop1"), std::bind(&NestedStruct1InterfaceClient::onPropertyChanged, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed2","NestedStruct1Interface",ApiGear::MQTT::Topic::TopicType::Signal,"sig1"), std::bind(&NestedStruct1InterfaceClient::onSignal, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed2","NestedStruct1Interface",ApiGear::MQTT::Topic::TopicType::Operation,"func1",m_client->getClientId()+"/result"), nullptr);
}

NestedStruct1InterfaceClient::~NestedStruct1InterfaceClient()
{
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed2","NestedStruct1Interface",ApiGear::MQTT::Topic::TopicType::Property,"prop1"), std::bind(&NestedStruct1InterfaceClient::onPropertyChanged, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed2","NestedStruct1Interface",ApiGear::MQTT::Topic::TopicType::Signal,"sig1"), std::bind(&NestedStruct1InterfaceClient::onSignal, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed2","NestedStruct1Interface",ApiGear::MQTT::Topic::TopicType::Operation,"func1",m_client->getClientId()+"/result"), nullptr);
}

void NestedStruct1InterfaceClient::applyState(const nlohmann::json& fields) 
{
    if(fields.contains("prop1")) {
        setProp1Local(fields["prop1"].get<NestedStruct1>());
    }
}

void NestedStruct1InterfaceClient::setProp1(const NestedStruct1& prop1)
{
    if(m_client == nullptr) {
        return;
    }
    static const auto topic = ApiGear::MQTT::Topic("testbed2","NestedStruct1Interface",ApiGear::MQTT::Topic::TopicType::Operation,"_setprop1");
    m_client->setRemoteProperty(topic, nlohmann::json(prop1).dump());
}

void NestedStruct1InterfaceClient::setProp1Local(const NestedStruct1& prop1)
{
    if (m_data.m_prop1 != prop1) {
        m_data.m_prop1 = prop1;
        m_publisher->publishProp1Changed(prop1);
    }
}

const NestedStruct1& NestedStruct1InterfaceClient::getProp1() const
{
    return m_data.m_prop1;
}

NestedStruct1 NestedStruct1InterfaceClient::func1(const NestedStruct1& param1)
{
    if(m_client == nullptr) {
        return NestedStruct1();
    }
    NestedStruct1 value(func1Async(param1).get());
    return value;
}

std::future<NestedStruct1> NestedStruct1InterfaceClient::func1Async(const NestedStruct1& param1)
{
    if(m_client == nullptr) {
        throw std::runtime_error("Client is not initialized");
    }
    return std::async(std::launch::async, [this,
                    param1]()
        {
            std::promise<NestedStruct1> resultPromise;
            static const auto topic = ApiGear::MQTT::Topic("testbed2","NestedStruct1Interface",ApiGear::MQTT::Topic::TopicType::Operation,"func1");
            m_client->invokeRemote(topic,
                nlohmann::json::array({param1}).dump(), [&resultPromise](ApiGear::MQTT::InvokeReplyArg arg) {
                    const NestedStruct1& value = arg.value.get<NestedStruct1>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

void NestedStruct1InterfaceClient::onSignal(const ApiGear::MQTT::Topic& topic, const std::string& args, const ApiGear::MQTT::Topic&, const std::string&)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    if(topic.getEntityName() == "sig1") {
        m_publisher->publishSig1(json_args[0].get<NestedStruct1>());
        return;
    }
}

void NestedStruct1InterfaceClient::onPropertyChanged(const ApiGear::MQTT::Topic& topic, const std::string& args, const ApiGear::MQTT::Topic&, const std::string&)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string& name = topic.getEntityName();
    applyState({ {name, json_args} });
    return;
}

bool NestedStruct1InterfaceClient::isReady() const
{
    return m_isReady;
}

INestedStruct1InterfacePublisher& NestedStruct1InterfaceClient::_getPublisher() const
{
    return *m_publisher;
}
