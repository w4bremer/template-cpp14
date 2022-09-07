#include "tb_simple/generated/mqtt/voidinterfaceclient.h"
#include "tb_simple/generated/core/voidinterface.publisher.h"
#include "tb_simple/generated/core/tb_simple.json.adapter.h"

using namespace Test::TbSimple;
using namespace Test::TbSimple::mqtt;

VoidInterfaceClient::VoidInterfaceClient(std::shared_ptr<ApiGear::MQTTImpl::Client> client)
    : m_isReady(false)
    , m_client(client)
    , m_publisher(std::make_unique<VoidInterfacePublisher>())
{
    m_client->subscribeTopic(ApiGear::MQTTImpl::Topic("tb.simple","VoidInterface",ApiGear::MQTTImpl::Topic::TopicType::Signal,"sigVoid"), this);
    m_client->subscribeTopic(ApiGear::MQTTImpl::Topic("tb.simple","VoidInterface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"funcVoid",m_client->getClientId()+"/result"), nullptr);
}

VoidInterfaceClient::~VoidInterfaceClient()
{
    m_client->unsubscribeTopic(ApiGear::MQTTImpl::Topic("tb.simple","VoidInterface",ApiGear::MQTTImpl::Topic::TopicType::Signal,"sigVoid"), this);
    m_client->unsubscribeTopic(ApiGear::MQTTImpl::Topic("tb.simple","VoidInterface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"funcVoid",m_client->getClientId()+"/result"), nullptr);
}

void VoidInterfaceClient::applyState(const nlohmann::json& fields) 
{// no properties to apply state
    (void) fields;
}

void VoidInterfaceClient::funcVoid()
{
    if(m_client == nullptr) {
        return;
    }
}

std::future<void> VoidInterfaceClient::funcVoidAsync()
{
    if(m_client == nullptr) {
        throw std::runtime_error("Client is not initialized");
    }
    return std::async(std::launch::async, [this]()
        {
            std::promise<void> resultPromise;
            static const auto topic = ApiGear::MQTTImpl::Topic("tb.simple","VoidInterface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"funcVoid");
            m_client->invokeRemote(topic,
                nlohmann::json::array({}).dump(), [&resultPromise](ApiGear::MQTTImpl::InvokeReplyArg arg) {
                    (void) arg;
                    resultPromise.set_value();
                });
            return resultPromise.get_future().get();
        }
    );
}

void VoidInterfaceClient::onSignal(const ApiGear::MQTTImpl::Topic& topic, const std::string& args)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    if(topic.getEntityName() == "sigVoid") {
        m_publisher->publishSigVoid();
        return;
    }
}

void VoidInterfaceClient::onPropertyChanged(const ApiGear::MQTTImpl::Topic& topic, const std::string& args)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string& name = topic.getEntityName();
    applyState({ {name, json_args} });
    return;
}

bool VoidInterfaceClient::isReady() const
{
    return m_isReady;
}

IVoidInterfacePublisher& VoidInterfaceClient::_getPublisher() const
{
    return *m_publisher;
}
