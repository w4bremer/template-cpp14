#include "testbed2/generated/mqtt/nestedstruct2interfaceclient.h"
#include "testbed2/generated/core/nestedstruct2interface.publisher.h"
#include "testbed2/generated/core/testbed2.json.adapter.h"
#include "apigear/mqtt/mqtttopic.h"
#include <random>

using namespace Test::Testbed2;
using namespace Test::Testbed2::MQTT;

namespace {
    std::mt19937 randomNumberGenerator (std::random_device{}());
}

NestedStruct2InterfaceClient::NestedStruct2InterfaceClient(std::shared_ptr<ApiGear::MQTT::Client> client)
    : m_isReady(false)
    , m_client(client)
    , m_publisher(std::make_unique<NestedStruct2InterfacePublisher>())
{
    m_client->subscribeTopic(std::string("testbed2/NestedStruct2Interface/prop/prop1"), std::bind(&NestedStruct2InterfaceClient::onPropertyChanged, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->subscribeTopic(std::string("testbed2/NestedStruct2Interface/prop/prop2"), std::bind(&NestedStruct2InterfaceClient::onPropertyChanged, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->subscribeTopic(std::string("testbed2/NestedStruct2Interface/sig/sig1"), std::bind(&NestedStruct2InterfaceClient::onSignal, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->subscribeTopic(std::string("testbed2/NestedStruct2Interface/sig/sig2"), std::bind(&NestedStruct2InterfaceClient::onSignal, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->subscribeTopic(std::string("testbed2/NestedStruct2Interface/rpc/func1/"+m_client->getClientId()+"/result"), std::bind(&NestedStruct2InterfaceClient::onInvokeReply, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->subscribeTopic(std::string("testbed2/NestedStruct2Interface/rpc/func2/"+m_client->getClientId()+"/result"), std::bind(&NestedStruct2InterfaceClient::onInvokeReply, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
}

NestedStruct2InterfaceClient::~NestedStruct2InterfaceClient()
{
    m_client->unsubscribeTopic(std::string("testbed2/NestedStruct2Interface/prop/prop1"));
    m_client->unsubscribeTopic(std::string("testbed2/NestedStruct2Interface/prop/prop2"));
    m_client->unsubscribeTopic(std::string("testbed2/NestedStruct2Interface/sig/sig1"));
    m_client->unsubscribeTopic(std::string("testbed2/NestedStruct2Interface/sig/sig2"));
    m_client->unsubscribeTopic(std::string("testbed2/NestedStruct2Interface/rpc/func1/"+m_client->getClientId()+"/result"));
    m_client->unsubscribeTopic(std::string("testbed2/NestedStruct2Interface/rpc/func2/"+m_client->getClientId()+"/result"));
}

void NestedStruct2InterfaceClient::applyState(const nlohmann::json& fields) 
{
    if(fields.contains("prop1")) {
        setProp1Local(fields["prop1"].get<NestedStruct1>());
    }
    if(fields.contains("prop2")) {
        setProp2Local(fields["prop2"].get<NestedStruct2>());
    }
}

void NestedStruct2InterfaceClient::setProp1(const NestedStruct1& prop1)
{
    if(m_client == nullptr) {
        return;
    }
    static const auto topic = std::string("testbed2/NestedStruct2Interface/set/prop1");
    m_client->setRemoteProperty(topic, nlohmann::json(prop1).dump());
}

void NestedStruct2InterfaceClient::setProp1Local(const NestedStruct1& prop1)
{
    if (m_data.m_prop1 != prop1) {
        m_data.m_prop1 = prop1;
        m_publisher->publishProp1Changed(prop1);
    }
}

const NestedStruct1& NestedStruct2InterfaceClient::getProp1() const
{
    return m_data.m_prop1;
}

void NestedStruct2InterfaceClient::setProp2(const NestedStruct2& prop2)
{
    if(m_client == nullptr) {
        return;
    }
    static const auto topic = std::string("testbed2/NestedStruct2Interface/set/prop2");
    m_client->setRemoteProperty(topic, nlohmann::json(prop2).dump());
}

void NestedStruct2InterfaceClient::setProp2Local(const NestedStruct2& prop2)
{
    if (m_data.m_prop2 != prop2) {
        m_data.m_prop2 = prop2;
        m_publisher->publishProp2Changed(prop2);
    }
}

const NestedStruct2& NestedStruct2InterfaceClient::getProp2() const
{
    return m_data.m_prop2;
}

NestedStruct1 NestedStruct2InterfaceClient::func1(const NestedStruct1& param1)
{
    if(m_client == nullptr) {
        return NestedStruct1();
    }
    NestedStruct1 value(func1Async(param1).get());
    return value;
}

std::future<NestedStruct1> NestedStruct2InterfaceClient::func1Async(const NestedStruct1& param1)
{
    if(m_client == nullptr) {
        throw std::runtime_error("Client is not initialized");
    }
    return std::async(std::launch::async, [this,
                    param1]()
        {
            std::promise<NestedStruct1> resultPromise;
            static const auto topic = std::string("testbed2/NestedStruct2Interface/rpc/func1");
            static const auto responseTopic = std::string(topic + "/" + m_client->getClientId() + "/result");
            ApiGear::MQTT::InvokeReplyFunc responseHandler = [&resultPromise](ApiGear::MQTT::InvokeReplyArg arg) {
                const NestedStruct1& value = arg.value.get<NestedStruct1>();
                resultPromise.set_value(value);
            };
            auto responseId = registerResponseHandler(responseHandler);
            m_client->invokeRemote(topic, responseTopic,
                nlohmann::json::array({param1}).dump(), responseId);
            return resultPromise.get_future().get();
        }
    );
}

NestedStruct1 NestedStruct2InterfaceClient::func2(const NestedStruct1& param1, const NestedStruct2& param2)
{
    if(m_client == nullptr) {
        return NestedStruct1();
    }
    NestedStruct1 value(func2Async(param1, param2).get());
    return value;
}

std::future<NestedStruct1> NestedStruct2InterfaceClient::func2Async(const NestedStruct1& param1, const NestedStruct2& param2)
{
    if(m_client == nullptr) {
        throw std::runtime_error("Client is not initialized");
    }
    return std::async(std::launch::async, [this,
                    param1,
                    param2]()
        {
            std::promise<NestedStruct1> resultPromise;
            static const auto topic = std::string("testbed2/NestedStruct2Interface/rpc/func2");
            static const auto responseTopic = std::string(topic + "/" + m_client->getClientId() + "/result");
            ApiGear::MQTT::InvokeReplyFunc responseHandler = [&resultPromise](ApiGear::MQTT::InvokeReplyArg arg) {
                const NestedStruct1& value = arg.value.get<NestedStruct1>();
                resultPromise.set_value(value);
            };
            auto responseId = registerResponseHandler(responseHandler);
            m_client->invokeRemote(topic, responseTopic,
                nlohmann::json::array({param1, param2}).dump(), responseId);
            return resultPromise.get_future().get();
        }
    );
}

void NestedStruct2InterfaceClient::onSignal(const std::string& topic, const std::string& args, const std::string&, const std::string&)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string entityName = ApiGear::MQTT::Topic(topic).getEntityName();
    if(entityName == "sig1") {
        m_publisher->publishSig1(json_args[0].get<NestedStruct1>());
        return;
    }
    if(entityName == "sig2") {
        m_publisher->publishSig2(json_args[0].get<NestedStruct1>(),json_args[1].get<NestedStruct2>());
        return;
    }
}

void NestedStruct2InterfaceClient::onPropertyChanged(const std::string& topic, const std::string& args, const std::string&, const std::string&)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string& name = ApiGear::MQTT::Topic(topic).getEntityName();
    applyState({ {name, json_args} });
    return;
}

int NestedStruct2InterfaceClient::registerResponseHandler(ApiGear::MQTT::InvokeReplyFunc handler)
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

void NestedStruct2InterfaceClient::onInvokeReply(const std::string& /*topic*/, const std::string& args, const std::string& /*responseTopic*/, const std::string& correlationData)
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

bool NestedStruct2InterfaceClient::isReady() const
{
    return m_isReady;
}

INestedStruct2InterfacePublisher& NestedStruct2InterfaceClient::_getPublisher() const
{
    return *m_publisher;
}
