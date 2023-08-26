#include "testbed1/generated/mqtt/structarrayinterfaceclient.h"
#include "testbed1/generated/core/structarrayinterface.publisher.h"
#include "testbed1/generated/core/testbed1.json.adapter.h"
#include "apigear/mqtt/mqtttopic.h"
#include <random>

using namespace Test::Testbed1;
using namespace Test::Testbed1::MQTT;

namespace {
    std::mt19937 randomNumberGenerator (std::random_device{}());

    std::map<std::string, ApiGear::MQTT::CallbackFunction> createTopicMap(const std::string&clientId, StructArrayInterfaceClient* client)
    {
        return {
            { std::string("testbed1/StructArrayInterface/prop/propBool"), [client](const std::string&, const std::string& args, const std::string&, const std::string&){ client->setPropBoolLocal(args); } },
            { std::string("testbed1/StructArrayInterface/prop/propInt"), [client](const std::string&, const std::string& args, const std::string&, const std::string&){ client->setPropIntLocal(args); } },
            { std::string("testbed1/StructArrayInterface/prop/propFloat"), [client](const std::string&, const std::string& args, const std::string&, const std::string&){ client->setPropFloatLocal(args); } },
            { std::string("testbed1/StructArrayInterface/prop/propString"), [client](const std::string&, const std::string& args, const std::string&, const std::string&){ client->setPropStringLocal(args); } },
            { std::string("testbed1/StructArrayInterface/sig/sigBool"), [client](const std::string& topic, const std::string& args, const std::string&, const std::string&){ client->onSignal(topic, args); } },
            { std::string("testbed1/StructArrayInterface/sig/sigInt"), [client](const std::string& topic, const std::string& args, const std::string&, const std::string&){ client->onSignal(topic, args); } },
            { std::string("testbed1/StructArrayInterface/sig/sigFloat"), [client](const std::string& topic, const std::string& args, const std::string&, const std::string&){ client->onSignal(topic, args); } },
            { std::string("testbed1/StructArrayInterface/sig/sigString"), [client](const std::string& topic, const std::string& args, const std::string&, const std::string&){ client->onSignal(topic, args); } },
            { std::string("testbed1/StructArrayInterface/rpc/funcBool/"+clientId+"/result"), [client](const std::string&, const std::string& args, const std::string&, const std::string& correlationData){ client->onInvokeReply(args, correlationData); } },
            { std::string("testbed1/StructArrayInterface/rpc/funcInt/"+clientId+"/result"), [client](const std::string&, const std::string& args, const std::string&, const std::string& correlationData){ client->onInvokeReply(args, correlationData); } },
            { std::string("testbed1/StructArrayInterface/rpc/funcFloat/"+clientId+"/result"), [client](const std::string&, const std::string& args, const std::string&, const std::string& correlationData){ client->onInvokeReply(args, correlationData); } },
            { std::string("testbed1/StructArrayInterface/rpc/funcString/"+clientId+"/result"), [client](const std::string&, const std::string& args, const std::string&, const std::string& correlationData){ client->onInvokeReply(args, correlationData); } },
        };
    };
}

StructArrayInterfaceClient::StructArrayInterfaceClient(std::shared_ptr<ApiGear::MQTT::Client> client)
    : m_isReady(false)
    , m_client(client)
    , m_publisher(std::make_unique<StructArrayInterfacePublisher>())
    , m_topics(createTopicMap(m_client->getClientId(), this))
{
    for (const auto& topic: m_topics)
    {
        m_client->subscribeTopic(topic. first, topic.second);
    }
}

StructArrayInterfaceClient::~StructArrayInterfaceClient()
{
    for (const auto& topic: m_topics)
    {
        m_client->unsubscribeTopic(topic. first);
    }
}

void StructArrayInterfaceClient::setPropBool(const std::list<StructBool>& propBool)
{
    if(m_client == nullptr) {
        return;
    }
    static const auto topic = std::string("testbed1/StructArrayInterface/set/propBool");
    m_client->setRemoteProperty(topic, nlohmann::json(propBool).dump());
}

void StructArrayInterfaceClient::setPropBoolLocal(const nlohmann::json& fields)
{
    if (fields.empty())
    {
        return;
    }

    const std::list<StructBool>& propBool = fields["propBool"].get<std::list<StructBool>>();
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
    static const auto topic = std::string("testbed1/StructArrayInterface/set/propInt");
    m_client->setRemoteProperty(topic, nlohmann::json(propInt).dump());
}

void StructArrayInterfaceClient::setPropIntLocal(const nlohmann::json& fields)
{
    if (fields.empty())
    {
        return;
    }

    const std::list<StructInt>& propInt = fields["propInt"].get<std::list<StructInt>>();
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
    static const auto topic = std::string("testbed1/StructArrayInterface/set/propFloat");
    m_client->setRemoteProperty(topic, nlohmann::json(propFloat).dump());
}

void StructArrayInterfaceClient::setPropFloatLocal(const nlohmann::json& fields)
{
    if (fields.empty())
    {
        return;
    }

    const std::list<StructFloat>& propFloat = fields["propFloat"].get<std::list<StructFloat>>();
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
    static const auto topic = std::string("testbed1/StructArrayInterface/set/propString");
    m_client->setRemoteProperty(topic, nlohmann::json(propString).dump());
}

void StructArrayInterfaceClient::setPropStringLocal(const nlohmann::json& fields)
{
    if (fields.empty())
    {
        return;
    }

    const std::list<StructString>& propString = fields["propString"].get<std::list<StructString>>();
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
            static const auto topic = std::string("testbed1/StructArrayInterface/rpc/funcBool");
            static const auto responseTopic = std::string(topic + "/" + m_client->getClientId() + "/result");
            ApiGear::MQTT::InvokeReplyFunc responseHandler = [&resultPromise](ApiGear::MQTT::InvokeReplyArg arg) {
                const StructBool& value = arg.value.get<StructBool>();
                resultPromise.set_value(value);
            };
            auto responseId = registerResponseHandler(responseHandler);
            m_client->invokeRemote(topic, responseTopic,
                nlohmann::json::array({paramBool}).dump(), responseId);
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
            static const auto topic = std::string("testbed1/StructArrayInterface/rpc/funcInt");
            static const auto responseTopic = std::string(topic + "/" + m_client->getClientId() + "/result");
            ApiGear::MQTT::InvokeReplyFunc responseHandler = [&resultPromise](ApiGear::MQTT::InvokeReplyArg arg) {
                const StructBool& value = arg.value.get<StructBool>();
                resultPromise.set_value(value);
            };
            auto responseId = registerResponseHandler(responseHandler);
            m_client->invokeRemote(topic, responseTopic,
                nlohmann::json::array({paramInt}).dump(), responseId);
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
            static const auto topic = std::string("testbed1/StructArrayInterface/rpc/funcFloat");
            static const auto responseTopic = std::string(topic + "/" + m_client->getClientId() + "/result");
            ApiGear::MQTT::InvokeReplyFunc responseHandler = [&resultPromise](ApiGear::MQTT::InvokeReplyArg arg) {
                const StructBool& value = arg.value.get<StructBool>();
                resultPromise.set_value(value);
            };
            auto responseId = registerResponseHandler(responseHandler);
            m_client->invokeRemote(topic, responseTopic,
                nlohmann::json::array({paramFloat}).dump(), responseId);
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
            static const auto topic = std::string("testbed1/StructArrayInterface/rpc/funcString");
            static const auto responseTopic = std::string(topic + "/" + m_client->getClientId() + "/result");
            ApiGear::MQTT::InvokeReplyFunc responseHandler = [&resultPromise](ApiGear::MQTT::InvokeReplyArg arg) {
                const StructBool& value = arg.value.get<StructBool>();
                resultPromise.set_value(value);
            };
            auto responseId = registerResponseHandler(responseHandler);
            m_client->invokeRemote(topic, responseTopic,
                nlohmann::json::array({paramString}).dump(), responseId);
            return resultPromise.get_future().get();
        }
    );
}

void StructArrayInterfaceClient::onSignal(const std::string& topic, const std::string& args)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string entityName = ApiGear::MQTT::Topic(topic).getEntityName();
    if(entityName == "sigBool") {
        m_publisher->publishSigBool(json_args[0].get<std::list<StructBool>>());
        return;
    }
    if(entityName == "sigInt") {
        m_publisher->publishSigInt(json_args[0].get<std::list<StructInt>>());
        return;
    }
    if(entityName == "sigFloat") {
        m_publisher->publishSigFloat(json_args[0].get<std::list<StructFloat>>());
        return;
    }
    if(entityName == "sigString") {
        m_publisher->publishSigString(json_args[0].get<std::list<StructString>>());
        return;
    }
}

int StructArrayInterfaceClient::registerResponseHandler(ApiGear::MQTT::InvokeReplyFunc handler)
{
    auto responseId = 0;
    std::uniform_int_distribution<> distribution (0, 100000);
    m_responseHandlerMutex.lock();
    do {
        responseId = distribution(randomNumberGenerator);
    } while (m_responseHandlerMap.find(responseId) != m_responseHandlerMap.end());
    m_responseHandlerMap.insert(std::pair<int, ApiGear::MQTT::InvokeReplyFunc>(responseId, handler));
    m_responseHandlerMutex.unlock();

    return responseId;
}

void StructArrayInterfaceClient::onInvokeReply(const std::string& args, const std::string& correlationData)
{
    const int randomId = std::stoi(correlationData);
    ApiGear::MQTT::InvokeReplyFunc responseHandler {};
    m_responseHandlerMutex.lock();
    if((m_responseHandlerMap.find(randomId) != m_responseHandlerMap.end()))
    {
        responseHandler = m_responseHandlerMap[randomId];
        m_responseHandlerMap.erase(randomId);
    }
    m_responseHandlerMutex.unlock();
    if(responseHandler) {
        const ApiGear::MQTT::InvokeReplyArg response{nlohmann::json::parse(args)};
        responseHandler(response);
    }
}

bool StructArrayInterfaceClient::isReady() const
{
    return m_isReady;
}

IStructArrayInterfacePublisher& StructArrayInterfaceClient::_getPublisher() const
{
    return *m_publisher;
}
