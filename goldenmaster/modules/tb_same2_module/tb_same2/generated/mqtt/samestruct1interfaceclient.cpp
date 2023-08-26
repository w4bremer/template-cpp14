#include "tb_same2/generated/mqtt/samestruct1interfaceclient.h"
#include "tb_same2/generated/core/samestruct1interface.publisher.h"
#include "tb_same2/generated/core/tb_same2.json.adapter.h"
#include "apigear/mqtt/mqtttopic.h"
#include <random>

using namespace Test::TbSame2;
using namespace Test::TbSame2::MQTT;

namespace {
    std::mt19937 randomNumberGenerator (std::random_device{}());

    std::map<std::string, ApiGear::MQTT::CallbackFunction> createTopicMap(const std::string&clientId, SameStruct1InterfaceClient* client)
    {
        return {
            { std::string("tb.same2/SameStruct1Interface/prop/prop1"), [client](const std::string&, const std::string& args, const std::string&, const std::string&){ client->setProp1Local(args); } },
            { std::string("tb.same2/SameStruct1Interface/sig/sig1"), [client](const std::string& topic, const std::string& args, const std::string&, const std::string&){ client->onSignal(topic, args); } },
            { std::string("tb.same2/SameStruct1Interface/rpc/func1/"+clientId+"/result"), [client](const std::string&, const std::string& args, const std::string&, const std::string& correlationData){ client->onInvokeReply(args, correlationData); } },
        };
    };
}

SameStruct1InterfaceClient::SameStruct1InterfaceClient(std::shared_ptr<ApiGear::MQTT::Client> client)
    : m_isReady(false)
    , m_client(client)
    , m_publisher(std::make_unique<SameStruct1InterfacePublisher>())
    , m_topics(createTopicMap(m_client->getClientId(), this))
{
    for (const auto& topic: m_topics)
    {
        m_client->subscribeTopic(topic. first, topic.second);
    }
}

SameStruct1InterfaceClient::~SameStruct1InterfaceClient()
{
    for (const auto& topic: m_topics)
    {
        m_client->unsubscribeTopic(topic. first);
    }
}

void SameStruct1InterfaceClient::setProp1(const Struct1& prop1)
{
    if(m_client == nullptr) {
        return;
    }
    static const auto topic = std::string("tb.same2/SameStruct1Interface/set/prop1");
    m_client->setRemoteProperty(topic, nlohmann::json(prop1).dump());
}

void SameStruct1InterfaceClient::setProp1Local(const nlohmann::json& fields)
{
    if (fields.empty())
    {
        return;
    }

    const Struct1& prop1 = fields["prop1"].get<Struct1>();
    if (m_data.m_prop1 != prop1) {
        m_data.m_prop1 = prop1;
        m_publisher->publishProp1Changed(prop1);
    }
}

const Struct1& SameStruct1InterfaceClient::getProp1() const
{
    return m_data.m_prop1;
}

Struct1 SameStruct1InterfaceClient::func1(const Struct1& param1)
{
    if(m_client == nullptr) {
        return Struct1();
    }
    Struct1 value(func1Async(param1).get());
    return value;
}

std::future<Struct1> SameStruct1InterfaceClient::func1Async(const Struct1& param1)
{
    if(m_client == nullptr) {
        throw std::runtime_error("Client is not initialized");
    }
    return std::async(std::launch::async, [this,
                    param1]()
        {
            std::promise<Struct1> resultPromise;
            static const auto topic = std::string("tb.same2/SameStruct1Interface/rpc/func1");
            static const auto responseTopic = std::string(topic + "/" + m_client->getClientId() + "/result");
            ApiGear::MQTT::InvokeReplyFunc responseHandler = [&resultPromise](ApiGear::MQTT::InvokeReplyArg arg) {
                const Struct1& value = arg.value.get<Struct1>();
                resultPromise.set_value(value);
            };
            auto responseId = registerResponseHandler(responseHandler);
            m_client->invokeRemote(topic, responseTopic,
                nlohmann::json::array({param1}).dump(), responseId);
            return resultPromise.get_future().get();
        }
    );
}

void SameStruct1InterfaceClient::onSignal(const std::string& topic, const std::string& args)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string entityName = ApiGear::MQTT::Topic(topic).getEntityName();
    if(entityName == "sig1") {
        m_publisher->publishSig1(json_args[0].get<Struct1>());
        return;
    }
}

int SameStruct1InterfaceClient::registerResponseHandler(ApiGear::MQTT::InvokeReplyFunc handler)
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

void SameStruct1InterfaceClient::onInvokeReply(const std::string& args, const std::string& correlationData)
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

bool SameStruct1InterfaceClient::isReady() const
{
    return m_isReady;
}

ISameStruct1InterfacePublisher& SameStruct1InterfaceClient::_getPublisher() const
{
    return *m_publisher;
}
