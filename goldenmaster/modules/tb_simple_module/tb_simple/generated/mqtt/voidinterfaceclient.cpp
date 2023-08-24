#include "tb_simple/generated/mqtt/voidinterfaceclient.h"
#include "tb_simple/generated/core/voidinterface.publisher.h"
#include "tb_simple/generated/core/tb_simple.json.adapter.h"
#include "apigear/mqtt/mqtttopic.h"
#include <random>

using namespace Test::TbSimple;
using namespace Test::TbSimple::MQTT;

namespace {
    std::mt19937 randomNumberGenerator (std::random_device{}());
}

VoidInterfaceClient::VoidInterfaceClient(std::shared_ptr<ApiGear::MQTT::Client> client)
    : m_isReady(false)
    , m_client(client)
    , m_publisher(std::make_unique<VoidInterfacePublisher>())
{
    m_client->subscribeTopic(std::string("tb.simple/VoidInterface/sig/sigVoid"), std::bind(&VoidInterfaceClient::onSignal, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->subscribeTopic(std::string("tb.simple/VoidInterface/rpc/funcVoid/"+m_client->getClientId()+"/result"), std::bind(&VoidInterfaceClient::onInvokeReply, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
}

VoidInterfaceClient::~VoidInterfaceClient()
{
    m_client->unsubscribeTopic(std::string("tb.simple/VoidInterface/sig/sigVoid"));
    m_client->unsubscribeTopic(std::string("tb.simple/VoidInterface/rpc/funcVoid/"+m_client->getClientId()+"/result"));
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
            static const auto topic = std::string("tb.simple/VoidInterface/rpc/funcVoid");
            static const auto responseTopic = std::string(topic + "/" + m_client->getClientId() + "/result");
            ApiGear::MQTT::InvokeReplyFunc responseHandler = [&resultPromise](ApiGear::MQTT::InvokeReplyArg arg) {
                (void) arg;
                resultPromise.set_value();
            };
            auto responseId = registerResponseHandler(responseHandler);
            m_client->invokeRemote(topic, responseTopic,
                nlohmann::json::array({}).dump(), responseId);
            return resultPromise.get_future().get();
        }
    );
}

void VoidInterfaceClient::onSignal(const std::string& topic, const std::string& args, const std::string&, const std::string&)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string entityName = ApiGear::MQTT::Topic(topic).getEntityName();
    if(entityName == "sigVoid") {
        m_publisher->publishSigVoid();
        return;
    }
}

void VoidInterfaceClient::onPropertyChanged(const std::string& topic, const std::string& args, const std::string&, const std::string&)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string& name = ApiGear::MQTT::Topic(topic).getEntityName();
    applyState({ {name, json_args} });
    return;
}

int VoidInterfaceClient::registerResponseHandler(ApiGear::MQTT::InvokeReplyFunc handler)
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

void VoidInterfaceClient::onInvokeReply(const std::string& /*topic*/, const std::string& args, const std::string& /*responseTopic*/, const std::string& correlationData)
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

bool VoidInterfaceClient::isReady() const
{
    return m_isReady;
}

IVoidInterfacePublisher& VoidInterfaceClient::_getPublisher() const
{
    return *m_publisher;
}
