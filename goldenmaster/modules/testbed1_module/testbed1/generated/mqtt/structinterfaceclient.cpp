#include "testbed1/generated/mqtt/structinterfaceclient.h"
#include "testbed1/generated/core/structinterface.publisher.h"
#include "testbed1/generated/core/testbed1.json.adapter.h"

using namespace Test::Testbed1;
using namespace Test::Testbed1::MQTT;

StructInterfaceClient::StructInterfaceClient(std::shared_ptr<ApiGear::MQTT::Client> client)
    : m_isReady(false)
    , m_client(client)
    , m_publisher(std::make_unique<StructInterfacePublisher>())
{
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed1","StructInterface",ApiGear::MQTT::Topic::TopicType::Property,"propBool"), std::bind(&StructInterfaceClient::onPropertyChanged, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed1","StructInterface",ApiGear::MQTT::Topic::TopicType::Property,"propInt"), std::bind(&StructInterfaceClient::onPropertyChanged, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed1","StructInterface",ApiGear::MQTT::Topic::TopicType::Property,"propFloat"), std::bind(&StructInterfaceClient::onPropertyChanged, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed1","StructInterface",ApiGear::MQTT::Topic::TopicType::Property,"propString"), std::bind(&StructInterfaceClient::onPropertyChanged, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed1","StructInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sigBool"), std::bind(&StructInterfaceClient::onSignal, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed1","StructInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sigInt"), std::bind(&StructInterfaceClient::onSignal, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed1","StructInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sigFloat"), std::bind(&StructInterfaceClient::onSignal, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed1","StructInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sigString"), std::bind(&StructInterfaceClient::onSignal, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed1","StructInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcBool",m_client->getClientId()+"/result"), nullptr);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed1","StructInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcInt",m_client->getClientId()+"/result"), nullptr);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed1","StructInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcFloat",m_client->getClientId()+"/result"), nullptr);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed1","StructInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcString",m_client->getClientId()+"/result"), nullptr);
}

StructInterfaceClient::~StructInterfaceClient()
{
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed1","StructInterface",ApiGear::MQTT::Topic::TopicType::Property,"propBool"), std::bind(&StructInterfaceClient::onPropertyChanged, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed1","StructInterface",ApiGear::MQTT::Topic::TopicType::Property,"propInt"), std::bind(&StructInterfaceClient::onPropertyChanged, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed1","StructInterface",ApiGear::MQTT::Topic::TopicType::Property,"propFloat"), std::bind(&StructInterfaceClient::onPropertyChanged, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed1","StructInterface",ApiGear::MQTT::Topic::TopicType::Property,"propString"), std::bind(&StructInterfaceClient::onPropertyChanged, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed1","StructInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sigBool"), std::bind(&StructInterfaceClient::onSignal, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed1","StructInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sigInt"), std::bind(&StructInterfaceClient::onSignal, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed1","StructInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sigFloat"), std::bind(&StructInterfaceClient::onSignal, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed1","StructInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sigString"), std::bind(&StructInterfaceClient::onSignal, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed1","StructInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcBool",m_client->getClientId()+"/result"), nullptr);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed1","StructInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcInt",m_client->getClientId()+"/result"), nullptr);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed1","StructInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcFloat",m_client->getClientId()+"/result"), nullptr);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed1","StructInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcString",m_client->getClientId()+"/result"), nullptr);
}

void StructInterfaceClient::applyState(const nlohmann::json& fields) 
{
    if(fields.contains("propBool")) {
        setPropBoolLocal(fields["propBool"].get<StructBool>());
    }
    if(fields.contains("propInt")) {
        setPropIntLocal(fields["propInt"].get<StructInt>());
    }
    if(fields.contains("propFloat")) {
        setPropFloatLocal(fields["propFloat"].get<StructFloat>());
    }
    if(fields.contains("propString")) {
        setPropStringLocal(fields["propString"].get<StructString>());
    }
}

void StructInterfaceClient::setPropBool(const StructBool& propBool)
{
    if(m_client == nullptr) {
        return;
    }
    static const auto topic = ApiGear::MQTT::Topic("testbed1","StructInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setpropBool");
    m_client->setRemoteProperty(topic, nlohmann::json(propBool).dump());
}

void StructInterfaceClient::setPropBoolLocal(const StructBool& propBool)
{
    if (m_data.m_propBool != propBool) {
        m_data.m_propBool = propBool;
        m_publisher->publishPropBoolChanged(propBool);
    }
}

const StructBool& StructInterfaceClient::getPropBool() const
{
    return m_data.m_propBool;
}

void StructInterfaceClient::setPropInt(const StructInt& propInt)
{
    if(m_client == nullptr) {
        return;
    }
    static const auto topic = ApiGear::MQTT::Topic("testbed1","StructInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setpropInt");
    m_client->setRemoteProperty(topic, nlohmann::json(propInt).dump());
}

void StructInterfaceClient::setPropIntLocal(const StructInt& propInt)
{
    if (m_data.m_propInt != propInt) {
        m_data.m_propInt = propInt;
        m_publisher->publishPropIntChanged(propInt);
    }
}

const StructInt& StructInterfaceClient::getPropInt() const
{
    return m_data.m_propInt;
}

void StructInterfaceClient::setPropFloat(const StructFloat& propFloat)
{
    if(m_client == nullptr) {
        return;
    }
    static const auto topic = ApiGear::MQTT::Topic("testbed1","StructInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setpropFloat");
    m_client->setRemoteProperty(topic, nlohmann::json(propFloat).dump());
}

void StructInterfaceClient::setPropFloatLocal(const StructFloat& propFloat)
{
    if (m_data.m_propFloat != propFloat) {
        m_data.m_propFloat = propFloat;
        m_publisher->publishPropFloatChanged(propFloat);
    }
}

const StructFloat& StructInterfaceClient::getPropFloat() const
{
    return m_data.m_propFloat;
}

void StructInterfaceClient::setPropString(const StructString& propString)
{
    if(m_client == nullptr) {
        return;
    }
    static const auto topic = ApiGear::MQTT::Topic("testbed1","StructInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setpropString");
    m_client->setRemoteProperty(topic, nlohmann::json(propString).dump());
}

void StructInterfaceClient::setPropStringLocal(const StructString& propString)
{
    if (m_data.m_propString != propString) {
        m_data.m_propString = propString;
        m_publisher->publishPropStringChanged(propString);
    }
}

const StructString& StructInterfaceClient::getPropString() const
{
    return m_data.m_propString;
}

StructBool StructInterfaceClient::funcBool(const StructBool& paramBool)
{
    if(m_client == nullptr) {
        return StructBool();
    }
    StructBool value(funcBoolAsync(paramBool).get());
    return value;
}

std::future<StructBool> StructInterfaceClient::funcBoolAsync(const StructBool& paramBool)
{
    if(m_client == nullptr) {
        throw std::runtime_error("Client is not initialized");
    }
    return std::async(std::launch::async, [this,
                    paramBool]()
        {
            std::promise<StructBool> resultPromise;
            static const auto topic = ApiGear::MQTT::Topic("testbed1","StructInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcBool");
            m_client->invokeRemote(topic,
                nlohmann::json::array({paramBool}).dump(), [&resultPromise](ApiGear::MQTT::InvokeReplyArg arg) {
                    const StructBool& value = arg.value.get<StructBool>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

StructBool StructInterfaceClient::funcInt(const StructInt& paramInt)
{
    if(m_client == nullptr) {
        return StructBool();
    }
    StructBool value(funcIntAsync(paramInt).get());
    return value;
}

std::future<StructBool> StructInterfaceClient::funcIntAsync(const StructInt& paramInt)
{
    if(m_client == nullptr) {
        throw std::runtime_error("Client is not initialized");
    }
    return std::async(std::launch::async, [this,
                    paramInt]()
        {
            std::promise<StructBool> resultPromise;
            static const auto topic = ApiGear::MQTT::Topic("testbed1","StructInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcInt");
            m_client->invokeRemote(topic,
                nlohmann::json::array({paramInt}).dump(), [&resultPromise](ApiGear::MQTT::InvokeReplyArg arg) {
                    const StructBool& value = arg.value.get<StructBool>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

StructFloat StructInterfaceClient::funcFloat(const StructFloat& paramFloat)
{
    if(m_client == nullptr) {
        return StructFloat();
    }
    StructFloat value(funcFloatAsync(paramFloat).get());
    return value;
}

std::future<StructFloat> StructInterfaceClient::funcFloatAsync(const StructFloat& paramFloat)
{
    if(m_client == nullptr) {
        throw std::runtime_error("Client is not initialized");
    }
    return std::async(std::launch::async, [this,
                    paramFloat]()
        {
            std::promise<StructFloat> resultPromise;
            static const auto topic = ApiGear::MQTT::Topic("testbed1","StructInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcFloat");
            m_client->invokeRemote(topic,
                nlohmann::json::array({paramFloat}).dump(), [&resultPromise](ApiGear::MQTT::InvokeReplyArg arg) {
                    const StructFloat& value = arg.value.get<StructFloat>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

StructString StructInterfaceClient::funcString(const StructString& paramString)
{
    if(m_client == nullptr) {
        return StructString();
    }
    StructString value(funcStringAsync(paramString).get());
    return value;
}

std::future<StructString> StructInterfaceClient::funcStringAsync(const StructString& paramString)
{
    if(m_client == nullptr) {
        throw std::runtime_error("Client is not initialized");
    }
    return std::async(std::launch::async, [this,
                    paramString]()
        {
            std::promise<StructString> resultPromise;
            static const auto topic = ApiGear::MQTT::Topic("testbed1","StructInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcString");
            m_client->invokeRemote(topic,
                nlohmann::json::array({paramString}).dump(), [&resultPromise](ApiGear::MQTT::InvokeReplyArg arg) {
                    const StructString& value = arg.value.get<StructString>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

void StructInterfaceClient::onSignal(const ApiGear::MQTT::Topic& topic, const std::string& args, const ApiGear::MQTT::Topic&, const std::string&)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    if(topic.getEntityName() == "sigBool") {
        m_publisher->publishSigBool(json_args[0].get<StructBool>());
        return;
    }
    if(topic.getEntityName() == "sigInt") {
        m_publisher->publishSigInt(json_args[0].get<StructInt>());
        return;
    }
    if(topic.getEntityName() == "sigFloat") {
        m_publisher->publishSigFloat(json_args[0].get<StructFloat>());
        return;
    }
    if(topic.getEntityName() == "sigString") {
        m_publisher->publishSigString(json_args[0].get<StructString>());
        return;
    }
}

void StructInterfaceClient::onPropertyChanged(const ApiGear::MQTT::Topic& topic, const std::string& args, const ApiGear::MQTT::Topic&, const std::string&)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string& name = topic.getEntityName();
    applyState({ {name, json_args} });
    return;
}

bool StructInterfaceClient::isReady() const
{
    return m_isReady;
}

IStructInterfacePublisher& StructInterfaceClient::_getPublisher() const
{
    return *m_publisher;
}
