#include "tb_same2/generated/mqtt/sameenum2interfaceclient.h"
#include "tb_same2/generated/core/sameenum2interface.publisher.h"
#include "tb_same2/generated/core/tb_same2.json.adapter.h"
#include "apigear/mqtt/mqtttopic.h"
#include <random>

using namespace Test::TbSame2;
using namespace Test::TbSame2::MQTT;

namespace {
    std::mt19937 randomNumberGenerator (std::random_device{}());
}

SameEnum2InterfaceClient::SameEnum2InterfaceClient(std::shared_ptr<ApiGear::MQTT::Client> client)
    : m_isReady(false)
    , m_client(client)
    , m_publisher(std::make_unique<SameEnum2InterfacePublisher>())
{
    m_client->subscribeTopic(std::string("tb.same2/SameEnum2Interface/prop/prop1"), [this](const std::string& topic, const std::string& args, const std::string&, const std::string&){ onPropertyChanged(topic, args); });
    m_client->subscribeTopic(std::string("tb.same2/SameEnum2Interface/prop/prop2"), [this](const std::string& topic, const std::string& args, const std::string&, const std::string&){ onPropertyChanged(topic, args); });
    m_client->subscribeTopic(std::string("tb.same2/SameEnum2Interface/sig/sig1"), [this](const std::string& topic, const std::string& args, const std::string&, const std::string&){ onSignal(topic, args); });
    m_client->subscribeTopic(std::string("tb.same2/SameEnum2Interface/sig/sig2"), [this](const std::string& topic, const std::string& args, const std::string&, const std::string&){ onSignal(topic, args); });
    m_client->subscribeTopic(std::string("tb.same2/SameEnum2Interface/rpc/func1/"+m_client->getClientId()+"/result"), [this](const std::string&, const std::string& args, const std::string&, const std::string& correlationData){ onInvokeReply(args, correlationData); });
    m_client->subscribeTopic(std::string("tb.same2/SameEnum2Interface/rpc/func2/"+m_client->getClientId()+"/result"), [this](const std::string&, const std::string& args, const std::string&, const std::string& correlationData){ onInvokeReply(args, correlationData); });
}

SameEnum2InterfaceClient::~SameEnum2InterfaceClient()
{
    m_client->unsubscribeTopic(std::string("tb.same2/SameEnum2Interface/prop/prop1"));
    m_client->unsubscribeTopic(std::string("tb.same2/SameEnum2Interface/prop/prop2"));
    m_client->unsubscribeTopic(std::string("tb.same2/SameEnum2Interface/sig/sig1"));
    m_client->unsubscribeTopic(std::string("tb.same2/SameEnum2Interface/sig/sig2"));
    m_client->unsubscribeTopic(std::string("tb.same2/SameEnum2Interface/rpc/func1/"+m_client->getClientId()+"/result"));
    m_client->unsubscribeTopic(std::string("tb.same2/SameEnum2Interface/rpc/func2/"+m_client->getClientId()+"/result"));
}

void SameEnum2InterfaceClient::applyState(const nlohmann::json& fields) 
{
    if(fields.contains("prop1")) {
        setProp1Local(fields["prop1"].get<Enum1Enum>());
    }
    if(fields.contains("prop2")) {
        setProp2Local(fields["prop2"].get<Enum2Enum>());
    }
}

void SameEnum2InterfaceClient::setProp1(Enum1Enum prop1)
{
    if(m_client == nullptr) {
        return;
    }
    static const auto topic = std::string("tb.same2/SameEnum2Interface/set/prop1");
    m_client->setRemoteProperty(topic, nlohmann::json(prop1).dump());
}

void SameEnum2InterfaceClient::setProp1Local(Enum1Enum prop1)
{
    if (m_data.m_prop1 != prop1) {
        m_data.m_prop1 = prop1;
        m_publisher->publishProp1Changed(prop1);
    }
}

Enum1Enum SameEnum2InterfaceClient::getProp1() const
{
    return m_data.m_prop1;
}

void SameEnum2InterfaceClient::setProp2(Enum2Enum prop2)
{
    if(m_client == nullptr) {
        return;
    }
    static const auto topic = std::string("tb.same2/SameEnum2Interface/set/prop2");
    m_client->setRemoteProperty(topic, nlohmann::json(prop2).dump());
}

void SameEnum2InterfaceClient::setProp2Local(Enum2Enum prop2)
{
    if (m_data.m_prop2 != prop2) {
        m_data.m_prop2 = prop2;
        m_publisher->publishProp2Changed(prop2);
    }
}

Enum2Enum SameEnum2InterfaceClient::getProp2() const
{
    return m_data.m_prop2;
}

Enum1Enum SameEnum2InterfaceClient::func1(Enum1Enum param1)
{
    if(m_client == nullptr) {
        return Enum1Enum::value1;
    }
    Enum1Enum value(func1Async(param1).get());
    return value;
}

std::future<Enum1Enum> SameEnum2InterfaceClient::func1Async(Enum1Enum param1)
{
    if(m_client == nullptr) {
        throw std::runtime_error("Client is not initialized");
    }
    return std::async(std::launch::async, [this,
                    param1]()
        {
            std::promise<Enum1Enum> resultPromise;
            static const auto topic = std::string("tb.same2/SameEnum2Interface/rpc/func1");
            static const auto responseTopic = std::string(topic + "/" + m_client->getClientId() + "/result");
            ApiGear::MQTT::InvokeReplyFunc responseHandler = [&resultPromise](ApiGear::MQTT::InvokeReplyArg arg) {
                const Enum1Enum& value = arg.value.get<Enum1Enum>();
                resultPromise.set_value(value);
            };
            auto responseId = registerResponseHandler(responseHandler);
            m_client->invokeRemote(topic, responseTopic,
                nlohmann::json::array({param1}).dump(), responseId);
            return resultPromise.get_future().get();
        }
    );
}

Enum1Enum SameEnum2InterfaceClient::func2(Enum1Enum param1, Enum2Enum param2)
{
    if(m_client == nullptr) {
        return Enum1Enum::value1;
    }
    Enum1Enum value(func2Async(param1, param2).get());
    return value;
}

std::future<Enum1Enum> SameEnum2InterfaceClient::func2Async(Enum1Enum param1, Enum2Enum param2)
{
    if(m_client == nullptr) {
        throw std::runtime_error("Client is not initialized");
    }
    return std::async(std::launch::async, [this,
                    param1,
                    param2]()
        {
            std::promise<Enum1Enum> resultPromise;
            static const auto topic = std::string("tb.same2/SameEnum2Interface/rpc/func2");
            static const auto responseTopic = std::string(topic + "/" + m_client->getClientId() + "/result");
            ApiGear::MQTT::InvokeReplyFunc responseHandler = [&resultPromise](ApiGear::MQTT::InvokeReplyArg arg) {
                const Enum1Enum& value = arg.value.get<Enum1Enum>();
                resultPromise.set_value(value);
            };
            auto responseId = registerResponseHandler(responseHandler);
            m_client->invokeRemote(topic, responseTopic,
                nlohmann::json::array({param1, param2}).dump(), responseId);
            return resultPromise.get_future().get();
        }
    );
}

void SameEnum2InterfaceClient::onSignal(const std::string& topic, const std::string& args)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string entityName = ApiGear::MQTT::Topic(topic).getEntityName();
    if(entityName == "sig1") {
        m_publisher->publishSig1(json_args[0].get<Enum1Enum>());
        return;
    }
    if(entityName == "sig2") {
        m_publisher->publishSig2(json_args[0].get<Enum1Enum>(),json_args[1].get<Enum2Enum>());
        return;
    }
}

void SameEnum2InterfaceClient::onPropertyChanged(const std::string& topic, const std::string& args)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string& name = ApiGear::MQTT::Topic(topic).getEntityName();
    applyState({ {name, json_args} });
    return;
}

int SameEnum2InterfaceClient::registerResponseHandler(ApiGear::MQTT::InvokeReplyFunc handler)
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

void SameEnum2InterfaceClient::onInvokeReply(const std::string& args, const std::string& correlationData)
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

bool SameEnum2InterfaceClient::isReady() const
{
    return m_isReady;
}

ISameEnum2InterfacePublisher& SameEnum2InterfaceClient::_getPublisher() const
{
    return *m_publisher;
}
