#include "tb_simple/generated/mqtt/nosignalsinterfaceclient.h"
#include "tb_simple/generated/core/nosignalsinterface.publisher.h"
#include "tb_simple/generated/core/tb_simple.json.adapter.h"

using namespace Test::TbSimple;
using namespace Test::TbSimple::mqtt;

NoSignalsInterfaceClient::NoSignalsInterfaceClient(std::shared_ptr<ApiGear::MQTTImpl::Client> client)
    : m_isReady(false)
    , m_client(client)
    , m_publisher(std::make_unique<NoSignalsInterfacePublisher>())
{
    m_client->subscribeTopic(ApiGear::MQTTImpl::Topic("tb.simple","NoSignalsInterface",ApiGear::MQTTImpl::Topic::TopicType::Property,"propBool"), this);
    m_client->subscribeTopic(ApiGear::MQTTImpl::Topic("tb.simple","NoSignalsInterface",ApiGear::MQTTImpl::Topic::TopicType::Property,"propInt"), this);
    m_client->subscribeTopic(ApiGear::MQTTImpl::Topic("tb.simple","NoSignalsInterface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"funcVoid",m_client->getClientId()+"/result"), nullptr);
    m_client->subscribeTopic(ApiGear::MQTTImpl::Topic("tb.simple","NoSignalsInterface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"funcBool",m_client->getClientId()+"/result"), nullptr);
}

NoSignalsInterfaceClient::~NoSignalsInterfaceClient()
{
    m_client->unsubscribeTopic(ApiGear::MQTTImpl::Topic("tb.simple","NoSignalsInterface",ApiGear::MQTTImpl::Topic::TopicType::Property,"propBool"), this);
    m_client->unsubscribeTopic(ApiGear::MQTTImpl::Topic("tb.simple","NoSignalsInterface",ApiGear::MQTTImpl::Topic::TopicType::Property,"propInt"), this);
    m_client->unsubscribeTopic(ApiGear::MQTTImpl::Topic("tb.simple","NoSignalsInterface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"funcVoid",m_client->getClientId()+"/result"), nullptr);
    m_client->unsubscribeTopic(ApiGear::MQTTImpl::Topic("tb.simple","NoSignalsInterface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"funcBool",m_client->getClientId()+"/result"), nullptr);
}

void NoSignalsInterfaceClient::applyState(const nlohmann::json& fields) 
{
    if(fields.contains("propBool")) {
        setPropBoolLocal(fields["propBool"].get<bool>());
    }
    if(fields.contains("propInt")) {
        setPropIntLocal(fields["propInt"].get<int>());
    }
}

void NoSignalsInterfaceClient::setPropBool(bool propBool)
{
    if(m_client == nullptr) {
        return;
    }
    static const auto topic = ApiGear::MQTTImpl::Topic("tb.simple","NoSignalsInterface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"_setpropBool");
    m_client->setRemoteProperty(topic, nlohmann::json(propBool).dump());
}

void NoSignalsInterfaceClient::setPropBoolLocal(bool propBool)
{
    if (m_data.m_propBool != propBool) {
        m_data.m_propBool = propBool;
        m_publisher->publishPropBoolChanged(propBool);
    }
}

bool NoSignalsInterfaceClient::getPropBool() const
{
    return m_data.m_propBool;
}

void NoSignalsInterfaceClient::setPropInt(int propInt)
{
    if(m_client == nullptr) {
        return;
    }
    static const auto topic = ApiGear::MQTTImpl::Topic("tb.simple","NoSignalsInterface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"_setpropInt");
    m_client->setRemoteProperty(topic, nlohmann::json(propInt).dump());
}

void NoSignalsInterfaceClient::setPropIntLocal(int propInt)
{
    if (m_data.m_propInt != propInt) {
        m_data.m_propInt = propInt;
        m_publisher->publishPropIntChanged(propInt);
    }
}

int NoSignalsInterfaceClient::getPropInt() const
{
    return m_data.m_propInt;
}

void NoSignalsInterfaceClient::funcVoid()
{
    if(m_client == nullptr) {
        return;
    }
}

std::future<void> NoSignalsInterfaceClient::funcVoidAsync()
{
    if(m_client == nullptr) {
        throw std::runtime_error("Client is not initialized");
    }
    return std::async(std::launch::async, [this]()
        {
            std::promise<void> resultPromise;
            static const auto topic = ApiGear::MQTTImpl::Topic("tb.simple","NoSignalsInterface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"funcVoid");
            m_client->invokeRemote(topic,
                nlohmann::json::array({}).dump(), [&resultPromise](ApiGear::MQTTImpl::InvokeReplyArg arg) {
                    (void) arg;
                    resultPromise.set_value();
                });
            return resultPromise.get_future().get();
        }
    );
}

bool NoSignalsInterfaceClient::funcBool(bool paramBool)
{
    if(m_client == nullptr) {
        return false;
    }
    bool value(funcBoolAsync(paramBool).get());
    return value;
}

std::future<bool> NoSignalsInterfaceClient::funcBoolAsync(bool paramBool)
{
    if(m_client == nullptr) {
        throw std::runtime_error("Client is not initialized");
    }
    return std::async(std::launch::async, [this,
                    paramBool]()
        {
            std::promise<bool> resultPromise;
            static const auto topic = ApiGear::MQTTImpl::Topic("tb.simple","NoSignalsInterface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"funcBool");
            m_client->invokeRemote(topic,
                nlohmann::json::array({paramBool}).dump(), [&resultPromise](ApiGear::MQTTImpl::InvokeReplyArg arg) {
                    const bool& value = arg.value.get<bool>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

void NoSignalsInterfaceClient::onSignal(const ApiGear::MQTTImpl::Topic& topic, const std::string& args)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    (void) args;
    (void) topic;
}

void NoSignalsInterfaceClient::onPropertyChanged(const ApiGear::MQTTImpl::Topic& topic, const std::string& args)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string& name = topic.getEntityName();
    applyState({ {name, json_args} });
    return;
}

bool NoSignalsInterfaceClient::isReady() const
{
    return m_isReady;
}

INoSignalsInterfacePublisher& NoSignalsInterfaceClient::_getPublisher() const
{
    return *m_publisher;
}
