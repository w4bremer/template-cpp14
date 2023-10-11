#include "tb_names/generated/mqtt/namesclient.h"
#include "tb_names/generated/core/names.publisher.h"
#include "tb_names/generated/core/tb_names.json.adapter.h"
#include <random>

using namespace Test::TbNames;
using namespace Test::TbNames::MQTT;

namespace {
    std::mt19937 randomNumberGenerator (std::random_device{}());
}

NamesClient::NamesClient(std::shared_ptr<ApiGear::MQTT::Client> client)
    : m_isReady(false)
    , m_client(client)
    , m_publisher(std::make_unique<NamesPublisher>())
    , m_topics(createTopicMap(m_client->getClientId()))
{
}

NamesClient::~NamesClient()
{
    for (const auto& topic: m_topics)
    {
        m_client->unsubscribeTopic(topic. first);
    }
}

std::map<std::string, ApiGear::MQTT::CallbackFunction> NamesClient::createTopicMap(const std::string&)
{
    return {
        { std::string("tb.names/Names/prop/Switch"), [this](const std::string& args, const std::string&, const std::string&){ this->setSwitchLocal(args); } },
    };
};

void NamesClient::onConnectionStatusChanged(bool connectionStatus)
{
    m_isReady = connectionStatus;
    if(!connectionStatus)
    {
        return;
    }

    for (const auto& topic: m_topics)
    {
        m_client->subscribeTopic(topic. first, topic.second);
    }
}

void NamesClient::setSwitch(bool Switch)
{
    if(m_client == nullptr) {
        return;
    }
    static const auto topic = std::string("tb.names/Names/set/Switch");
    m_client->setRemoteProperty(topic, nlohmann::json(Switch).dump());
}

void NamesClient::setSwitchLocal(const std::string& args)
{
    nlohmann::json fields = nlohmann::json::parse(args);
    if (fields.empty())
    {
        return;
    }

    bool Switch = fields.get<bool>();
    if (m_data.m_Switch != Switch) {
        m_data.m_Switch = Switch;
        m_publisher->publishSwitchChanged(Switch);
    }
}

bool NamesClient::getSwitch() const
{
    return m_data.m_Switch;
}

int NamesClient::registerResponseHandler(ApiGear::MQTT::InvokeReplyFunc handler)
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

void NamesClient::onInvokeReply(const std::string& args, const std::string& correlationData)
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

bool NamesClient::isReady() const
{
    return m_isReady;
}

INamesPublisher& NamesClient::_getPublisher() const
{
    return *m_publisher;
}
