#include "testbed1/generated/mqtt/structarrayinterfaceclient.h"
#include "testbed1/generated/core/structarrayinterface.publisher.h"
#include "testbed1/generated/core/testbed1.json.adapter.h"

using namespace Test::Testbed1;
using namespace Test::Testbed1::MQTT;

StructArrayInterfaceClient::StructArrayInterfaceClient(std::shared_ptr<ApiGear::MQTT::Client> client)
    : m_isReady(false)
    , m_client(client)
    , m_publisher(std::make_unique<StructArrayInterfacePublisher>())
{
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed1","StructArrayInterface",ApiGear::MQTT::Topic::TopicType::Property,"propBool"), this);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed1","StructArrayInterface",ApiGear::MQTT::Topic::TopicType::Property,"propInt"), this);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed1","StructArrayInterface",ApiGear::MQTT::Topic::TopicType::Property,"propFloat"), this);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed1","StructArrayInterface",ApiGear::MQTT::Topic::TopicType::Property,"propString"), this);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed1","StructArrayInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sigBool"), this);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed1","StructArrayInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sigInt"), this);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed1","StructArrayInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sigFloat"), this);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed1","StructArrayInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sigString"), this);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed1","StructArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcBool",m_client->getClientId()+"/result"), nullptr);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed1","StructArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcInt",m_client->getClientId()+"/result"), nullptr);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed1","StructArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcFloat",m_client->getClientId()+"/result"), nullptr);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed1","StructArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcString",m_client->getClientId()+"/result"), nullptr);
}

StructArrayInterfaceClient::~StructArrayInterfaceClient()
{
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed1","StructArrayInterface",ApiGear::MQTT::Topic::TopicType::Property,"propBool"), this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed1","StructArrayInterface",ApiGear::MQTT::Topic::TopicType::Property,"propInt"), this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed1","StructArrayInterface",ApiGear::MQTT::Topic::TopicType::Property,"propFloat"), this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed1","StructArrayInterface",ApiGear::MQTT::Topic::TopicType::Property,"propString"), this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed1","StructArrayInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sigBool"), this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed1","StructArrayInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sigInt"), this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed1","StructArrayInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sigFloat"), this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed1","StructArrayInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sigString"), this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed1","StructArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcBool",m_client->getClientId()+"/result"), nullptr);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed1","StructArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcInt",m_client->getClientId()+"/result"), nullptr);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed1","StructArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcFloat",m_client->getClientId()+"/result"), nullptr);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed1","StructArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcString",m_client->getClientId()+"/result"), nullptr);
}

void StructArrayInterfaceClient::applyState(const nlohmann::json& fields) 
{
    if(fields.contains("propBool")) {
        setPropBoolLocal(fields["propBool"].get<std::list<StructBool>>());
    }
    if(fields.contains("propInt")) {
        setPropIntLocal(fields["propInt"].get<std::list<StructInt>>());
    }
    if(fields.contains("propFloat")) {
        setPropFloatLocal(fields["propFloat"].get<std::list<StructFloat>>());
    }
    if(fields.contains("propString")) {
        setPropStringLocal(fields["propString"].get<std::list<StructString>>());
    }
}

void StructArrayInterfaceClient::setPropBool(const std::list<StructBool>& propBool)
{
    if(m_client == nullptr) {
        return;
    }
    static const auto topic = ApiGear::MQTT::Topic("testbed1","StructArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setpropBool");
    m_client->setRemoteProperty(topic, nlohmann::json(propBool).dump());
}

void StructArrayInterfaceClient::setPropBoolLocal(const std::list<StructBool>& propBool)
{
    if (m_data.m_propBool != propBool) {
        m_data.m_propBool = propBool;
        m_publisher->publishPropBoolChanged(propBool);
    }
}

const std::list<StructBool>& StructArrayInterfaceClient::getPropBool() const
{
    return m_data.m_propBool;
}

void StructArrayInterfaceClient::setPropInt(const std::list<StructInt>& propInt)
{
    if(m_client == nullptr) {
        return;
    }
    static const auto topic = ApiGear::MQTT::Topic("testbed1","StructArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setpropInt");
    m_client->setRemoteProperty(topic, nlohmann::json(propInt).dump());
}

void StructArrayInterfaceClient::setPropIntLocal(const std::list<StructInt>& propInt)
{
    if (m_data.m_propInt != propInt) {
        m_data.m_propInt = propInt;
        m_publisher->publishPropIntChanged(propInt);
    }
}

const std::list<StructInt>& StructArrayInterfaceClient::getPropInt() const
{
    return m_data.m_propInt;
}

void StructArrayInterfaceClient::setPropFloat(const std::list<StructFloat>& propFloat)
{
    if(m_client == nullptr) {
        return;
    }
    static const auto topic = ApiGear::MQTT::Topic("testbed1","StructArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setpropFloat");
    m_client->setRemoteProperty(topic, nlohmann::json(propFloat).dump());
}

void StructArrayInterfaceClient::setPropFloatLocal(const std::list<StructFloat>& propFloat)
{
    if (m_data.m_propFloat != propFloat) {
        m_data.m_propFloat = propFloat;
        m_publisher->publishPropFloatChanged(propFloat);
    }
}

const std::list<StructFloat>& StructArrayInterfaceClient::getPropFloat() const
{
    return m_data.m_propFloat;
}

void StructArrayInterfaceClient::setPropString(const std::list<StructString>& propString)
{
    if(m_client == nullptr) {
        return;
    }
    static const auto topic = ApiGear::MQTT::Topic("testbed1","StructArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setpropString");
    m_client->setRemoteProperty(topic, nlohmann::json(propString).dump());
}

void StructArrayInterfaceClient::setPropStringLocal(const std::list<StructString>& propString)
{
    if (m_data.m_propString != propString) {
        m_data.m_propString = propString;
        m_publisher->publishPropStringChanged(propString);
    }
}

const std::list<StructString>& StructArrayInterfaceClient::getPropString() const
{
    return m_data.m_propString;
}

StructBool StructArrayInterfaceClient::funcBool(const std::list<StructBool>& paramBool)
{
    if(m_client == nullptr) {
        return StructBool();
    }
    StructBool value(funcBoolAsync(paramBool).get());
    return value;
}

std::future<StructBool> StructArrayInterfaceClient::funcBoolAsync(const std::list<StructBool>& paramBool)
{
    if(m_client == nullptr) {
        throw std::runtime_error("Client is not initialized");
    }
    return std::async(std::launch::async, [this,
                    paramBool]()
        {
            std::promise<StructBool> resultPromise;
            static const auto topic = ApiGear::MQTT::Topic("testbed1","StructArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcBool");
            m_client->invokeRemote(topic,
                nlohmann::json::array({paramBool}).dump(), [&resultPromise](ApiGear::MQTT::InvokeReplyArg arg) {
                    const StructBool& value = arg.value.get<StructBool>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

StructBool StructArrayInterfaceClient::funcInt(const std::list<StructInt>& paramInt)
{
    if(m_client == nullptr) {
        return StructBool();
    }
    StructBool value(funcIntAsync(paramInt).get());
    return value;
}

std::future<StructBool> StructArrayInterfaceClient::funcIntAsync(const std::list<StructInt>& paramInt)
{
    if(m_client == nullptr) {
        throw std::runtime_error("Client is not initialized");
    }
    return std::async(std::launch::async, [this,
                    paramInt]()
        {
            std::promise<StructBool> resultPromise;
            static const auto topic = ApiGear::MQTT::Topic("testbed1","StructArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcInt");
            m_client->invokeRemote(topic,
                nlohmann::json::array({paramInt}).dump(), [&resultPromise](ApiGear::MQTT::InvokeReplyArg arg) {
                    const StructBool& value = arg.value.get<StructBool>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

StructBool StructArrayInterfaceClient::funcFloat(const std::list<StructFloat>& paramFloat)
{
    if(m_client == nullptr) {
        return StructBool();
    }
    StructBool value(funcFloatAsync(paramFloat).get());
    return value;
}

std::future<StructBool> StructArrayInterfaceClient::funcFloatAsync(const std::list<StructFloat>& paramFloat)
{
    if(m_client == nullptr) {
        throw std::runtime_error("Client is not initialized");
    }
    return std::async(std::launch::async, [this,
                    paramFloat]()
        {
            std::promise<StructBool> resultPromise;
            static const auto topic = ApiGear::MQTT::Topic("testbed1","StructArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcFloat");
            m_client->invokeRemote(topic,
                nlohmann::json::array({paramFloat}).dump(), [&resultPromise](ApiGear::MQTT::InvokeReplyArg arg) {
                    const StructBool& value = arg.value.get<StructBool>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

StructBool StructArrayInterfaceClient::funcString(const std::list<StructString>& paramString)
{
    if(m_client == nullptr) {
        return StructBool();
    }
    StructBool value(funcStringAsync(paramString).get());
    return value;
}

std::future<StructBool> StructArrayInterfaceClient::funcStringAsync(const std::list<StructString>& paramString)
{
    if(m_client == nullptr) {
        throw std::runtime_error("Client is not initialized");
    }
    return std::async(std::launch::async, [this,
                    paramString]()
        {
            std::promise<StructBool> resultPromise;
            static const auto topic = ApiGear::MQTT::Topic("testbed1","StructArrayInterface",ApiGear::MQTT::Topic::TopicType::Operation,"funcString");
            m_client->invokeRemote(topic,
                nlohmann::json::array({paramString}).dump(), [&resultPromise](ApiGear::MQTT::InvokeReplyArg arg) {
                    const StructBool& value = arg.value.get<StructBool>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

void StructArrayInterfaceClient::onSignal(const ApiGear::MQTT::Topic& topic, const std::string& args)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    if(topic.getEntityName() == "sigBool") {
        m_publisher->publishSigBool(json_args[0].get<std::list<StructBool>>());
        return;
    }
    if(topic.getEntityName() == "sigInt") {
        m_publisher->publishSigInt(json_args[0].get<std::list<StructInt>>());
        return;
    }
    if(topic.getEntityName() == "sigFloat") {
        m_publisher->publishSigFloat(json_args[0].get<std::list<StructFloat>>());
        return;
    }
    if(topic.getEntityName() == "sigString") {
        m_publisher->publishSigString(json_args[0].get<std::list<StructString>>());
        return;
    }
}

void StructArrayInterfaceClient::onPropertyChanged(const ApiGear::MQTT::Topic& topic, const std::string& args)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string& name = topic.getEntityName();
    applyState({ {name, json_args} });
    return;
}

bool StructArrayInterfaceClient::isReady() const
{
    return m_isReady;
}

IStructArrayInterfacePublisher& StructArrayInterfaceClient::_getPublisher() const
{
    return *m_publisher;
}
