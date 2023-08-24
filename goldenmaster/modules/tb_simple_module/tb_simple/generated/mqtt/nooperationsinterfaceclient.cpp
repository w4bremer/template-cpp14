#include "tb_simple/generated/mqtt/nooperationsinterfaceclient.h"
#include "tb_simple/generated/core/nooperationsinterface.publisher.h"
#include "tb_simple/generated/core/tb_simple.json.adapter.h"
#include "apigear/mqtt/mqtttopic.h"
#include <random>

using namespace Test::TbSimple;
using namespace Test::TbSimple::MQTT;

namespace {
    std::mt19937 randomNumberGenerator (std::random_device{}());
}

NoOperationsInterfaceClient::NoOperationsInterfaceClient(std::shared_ptr<ApiGear::MQTT::Client> client)
    : m_isReady(false)
    , m_client(client)
    , m_publisher(std::make_unique<NoOperationsInterfacePublisher>())
{
    m_client->subscribeTopic(std::string("tb.simple/NoOperationsInterface/prop/propBool"), [this](const std::string& topic, const std::string& args, const std::string&, const std::string&){ onPropertyChanged(topic, args, "", ""); });
    m_client->subscribeTopic(std::string("tb.simple/NoOperationsInterface/prop/propInt"), [this](const std::string& topic, const std::string& args, const std::string&, const std::string&){ onPropertyChanged(topic, args, "", ""); });
    m_client->subscribeTopic(std::string("tb.simple/NoOperationsInterface/sig/sigVoid"), [this](const std::string& topic, const std::string& args, const std::string&, const std::string&){ onSignal(topic, args, "", ""); });
    m_client->subscribeTopic(std::string("tb.simple/NoOperationsInterface/sig/sigBool"), [this](const std::string& topic, const std::string& args, const std::string&, const std::string&){ onSignal(topic, args, "", ""); });
}

NoOperationsInterfaceClient::~NoOperationsInterfaceClient()
{
    m_client->unsubscribeTopic(std::string("tb.simple/NoOperationsInterface/prop/propBool"));
    m_client->unsubscribeTopic(std::string("tb.simple/NoOperationsInterface/prop/propInt"));
    m_client->unsubscribeTopic(std::string("tb.simple/NoOperationsInterface/sig/sigVoid"));
    m_client->unsubscribeTopic(std::string("tb.simple/NoOperationsInterface/sig/sigBool"));
}

void NoOperationsInterfaceClient::applyState(const nlohmann::json& fields) 
{
    if(fields.contains("propBool")) {
        setPropBoolLocal(fields["propBool"].get<bool>());
    }
    if(fields.contains("propInt")) {
        setPropIntLocal(fields["propInt"].get<int>());
    }
}

void NoOperationsInterfaceClient::setPropBool(bool propBool)
{
    if(m_client == nullptr) {
        return;
    }
    static const auto topic = std::string("tb.simple/NoOperationsInterface/set/propBool");
    m_client->setRemoteProperty(topic, nlohmann::json(propBool).dump());
}

void NoOperationsInterfaceClient::setPropBoolLocal(bool propBool)
{
    if (m_data.m_propBool != propBool) {
        m_data.m_propBool = propBool;
        m_publisher->publishPropBoolChanged(propBool);
    }
}

bool NoOperationsInterfaceClient::getPropBool() const
{
    return m_data.m_propBool;
}

void NoOperationsInterfaceClient::setPropInt(int propInt)
{
    if(m_client == nullptr) {
        return;
    }
    static const auto topic = std::string("tb.simple/NoOperationsInterface/set/propInt");
    m_client->setRemoteProperty(topic, nlohmann::json(propInt).dump());
}

void NoOperationsInterfaceClient::setPropIntLocal(int propInt)
{
    if (m_data.m_propInt != propInt) {
        m_data.m_propInt = propInt;
        m_publisher->publishPropIntChanged(propInt);
    }
}

int NoOperationsInterfaceClient::getPropInt() const
{
    return m_data.m_propInt;
}

void NoOperationsInterfaceClient::onSignal(const std::string& topic, const std::string& args, const std::string&, const std::string&)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string entityName = ApiGear::MQTT::Topic(topic).getEntityName();
    if(entityName == "sigVoid") {
        m_publisher->publishSigVoid();
        return;
    }
    if(entityName == "sigBool") {
        m_publisher->publishSigBool(json_args[0].get<bool>());
        return;
    }
}

void NoOperationsInterfaceClient::onPropertyChanged(const std::string& topic, const std::string& args, const std::string&, const std::string&)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string& name = ApiGear::MQTT::Topic(topic).getEntityName();
    applyState({ {name, json_args} });
    return;
}

int NoOperationsInterfaceClient::registerResponseHandler(ApiGear::MQTT::InvokeReplyFunc handler)
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

void NoOperationsInterfaceClient::onInvokeReply(const std::string& /*topic*/, const std::string& args, const std::string& /*responseTopic*/, const std::string& correlationData)
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

bool NoOperationsInterfaceClient::isReady() const
{
    return m_isReady;
}

INoOperationsInterfacePublisher& NoOperationsInterfaceClient::_getPublisher() const
{
    return *m_publisher;
}
