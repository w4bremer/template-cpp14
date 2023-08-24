#include "tb_enum/generated/mqtt/enuminterfaceclient.h"
#include "tb_enum/generated/core/enuminterface.publisher.h"
#include "tb_enum/generated/core/tb_enum.json.adapter.h"
#include "apigear/mqtt/mqtttopic.h"
#include <random>

using namespace Test::TbEnum;
using namespace Test::TbEnum::MQTT;

namespace {
    std::mt19937 randomNumberGenerator (std::random_device{}());
}

EnumInterfaceClient::EnumInterfaceClient(std::shared_ptr<ApiGear::MQTT::Client> client)
    : m_isReady(false)
    , m_client(client)
    , m_publisher(std::make_unique<EnumInterfacePublisher>())
{
    m_client->subscribeTopic(std::string("tb.enum/EnumInterface/prop/prop0"), std::bind(&EnumInterfaceClient::onPropertyChanged, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->subscribeTopic(std::string("tb.enum/EnumInterface/prop/prop1"), std::bind(&EnumInterfaceClient::onPropertyChanged, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->subscribeTopic(std::string("tb.enum/EnumInterface/prop/prop2"), std::bind(&EnumInterfaceClient::onPropertyChanged, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->subscribeTopic(std::string("tb.enum/EnumInterface/prop/prop3"), std::bind(&EnumInterfaceClient::onPropertyChanged, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->subscribeTopic(std::string("tb.enum/EnumInterface/sig/sig0"), std::bind(&EnumInterfaceClient::onSignal, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->subscribeTopic(std::string("tb.enum/EnumInterface/sig/sig1"), std::bind(&EnumInterfaceClient::onSignal, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->subscribeTopic(std::string("tb.enum/EnumInterface/sig/sig2"), std::bind(&EnumInterfaceClient::onSignal, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->subscribeTopic(std::string("tb.enum/EnumInterface/sig/sig3"), std::bind(&EnumInterfaceClient::onSignal, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->subscribeTopic(std::string("tb.enum/EnumInterface/rpc/func0/"+m_client->getClientId()+"/result"), std::bind(&EnumInterfaceClient::onInvokeReply, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->subscribeTopic(std::string("tb.enum/EnumInterface/rpc/func1/"+m_client->getClientId()+"/result"), std::bind(&EnumInterfaceClient::onInvokeReply, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->subscribeTopic(std::string("tb.enum/EnumInterface/rpc/func2/"+m_client->getClientId()+"/result"), std::bind(&EnumInterfaceClient::onInvokeReply, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->subscribeTopic(std::string("tb.enum/EnumInterface/rpc/func3/"+m_client->getClientId()+"/result"), std::bind(&EnumInterfaceClient::onInvokeReply, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
}

EnumInterfaceClient::~EnumInterfaceClient()
{
    m_client->unsubscribeTopic(std::string("tb.enum/EnumInterface/prop/prop0"), std::bind(&EnumInterfaceClient::onPropertyChanged, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->unsubscribeTopic(std::string("tb.enum/EnumInterface/prop/prop1"), std::bind(&EnumInterfaceClient::onPropertyChanged, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->unsubscribeTopic(std::string("tb.enum/EnumInterface/prop/prop2"), std::bind(&EnumInterfaceClient::onPropertyChanged, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->unsubscribeTopic(std::string("tb.enum/EnumInterface/prop/prop3"), std::bind(&EnumInterfaceClient::onPropertyChanged, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->unsubscribeTopic(std::string("tb.enum/EnumInterface/sig/sig0"), std::bind(&EnumInterfaceClient::onSignal, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->unsubscribeTopic(std::string("tb.enum/EnumInterface/sig/sig1"), std::bind(&EnumInterfaceClient::onSignal, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->unsubscribeTopic(std::string("tb.enum/EnumInterface/sig/sig2"), std::bind(&EnumInterfaceClient::onSignal, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->unsubscribeTopic(std::string("tb.enum/EnumInterface/sig/sig3"), std::bind(&EnumInterfaceClient::onSignal, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->unsubscribeTopic(std::string("tb.enum/EnumInterface/rpc/func0/"+m_client->getClientId()+"/result"), std::bind(&EnumInterfaceClient::onInvokeReply, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->unsubscribeTopic(std::string("tb.enum/EnumInterface/rpc/func1/"+m_client->getClientId()+"/result"), std::bind(&EnumInterfaceClient::onInvokeReply, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->unsubscribeTopic(std::string("tb.enum/EnumInterface/rpc/func2/"+m_client->getClientId()+"/result"), std::bind(&EnumInterfaceClient::onInvokeReply, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->unsubscribeTopic(std::string("tb.enum/EnumInterface/rpc/func3/"+m_client->getClientId()+"/result"), std::bind(&EnumInterfaceClient::onInvokeReply, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
}

void EnumInterfaceClient::applyState(const nlohmann::json& fields) 
{
    if(fields.contains("prop0")) {
        setProp0Local(fields["prop0"].get<Enum0Enum>());
    }
    if(fields.contains("prop1")) {
        setProp1Local(fields["prop1"].get<Enum1Enum>());
    }
    if(fields.contains("prop2")) {
        setProp2Local(fields["prop2"].get<Enum2Enum>());
    }
    if(fields.contains("prop3")) {
        setProp3Local(fields["prop3"].get<Enum3Enum>());
    }
}

void EnumInterfaceClient::setProp0(Enum0Enum prop0)
{
    if(m_client == nullptr) {
        return;
    }
    static const auto topic = std::string("tb.enum/EnumInterface/set/prop0");
    m_client->setRemoteProperty(topic, nlohmann::json(prop0).dump());
}

void EnumInterfaceClient::setProp0Local(Enum0Enum prop0)
{
    if (m_data.m_prop0 != prop0) {
        m_data.m_prop0 = prop0;
        m_publisher->publishProp0Changed(prop0);
    }
}

Enum0Enum EnumInterfaceClient::getProp0() const
{
    return m_data.m_prop0;
}

void EnumInterfaceClient::setProp1(Enum1Enum prop1)
{
    if(m_client == nullptr) {
        return;
    }
    static const auto topic = std::string("tb.enum/EnumInterface/set/prop1");
    m_client->setRemoteProperty(topic, nlohmann::json(prop1).dump());
}

void EnumInterfaceClient::setProp1Local(Enum1Enum prop1)
{
    if (m_data.m_prop1 != prop1) {
        m_data.m_prop1 = prop1;
        m_publisher->publishProp1Changed(prop1);
    }
}

Enum1Enum EnumInterfaceClient::getProp1() const
{
    return m_data.m_prop1;
}

void EnumInterfaceClient::setProp2(Enum2Enum prop2)
{
    if(m_client == nullptr) {
        return;
    }
    static const auto topic = std::string("tb.enum/EnumInterface/set/prop2");
    m_client->setRemoteProperty(topic, nlohmann::json(prop2).dump());
}

void EnumInterfaceClient::setProp2Local(Enum2Enum prop2)
{
    if (m_data.m_prop2 != prop2) {
        m_data.m_prop2 = prop2;
        m_publisher->publishProp2Changed(prop2);
    }
}

Enum2Enum EnumInterfaceClient::getProp2() const
{
    return m_data.m_prop2;
}

void EnumInterfaceClient::setProp3(Enum3Enum prop3)
{
    if(m_client == nullptr) {
        return;
    }
    static const auto topic = std::string("tb.enum/EnumInterface/set/prop3");
    m_client->setRemoteProperty(topic, nlohmann::json(prop3).dump());
}

void EnumInterfaceClient::setProp3Local(Enum3Enum prop3)
{
    if (m_data.m_prop3 != prop3) {
        m_data.m_prop3 = prop3;
        m_publisher->publishProp3Changed(prop3);
    }
}

Enum3Enum EnumInterfaceClient::getProp3() const
{
    return m_data.m_prop3;
}

Enum0Enum EnumInterfaceClient::func0(Enum0Enum param0)
{
    if(m_client == nullptr) {
        return Enum0Enum::value0;
    }
    Enum0Enum value(func0Async(param0).get());
    return value;
}

std::future<Enum0Enum> EnumInterfaceClient::func0Async(Enum0Enum param0)
{
    if(m_client == nullptr) {
        throw std::runtime_error("Client is not initialized");
    }
    return std::async(std::launch::async, [this,
                    param0]()
        {
            std::promise<Enum0Enum> resultPromise;
            static const auto topic = std::string("tb.enum/EnumInterface/rpc/func0");
            static const auto responseTopic = std::string(topic + "/" + m_client->getClientId() + "/result");
            ApiGear::MQTT::InvokeReplyFunc responseHandler = [&resultPromise](ApiGear::MQTT::InvokeReplyArg arg) {
                const Enum0Enum& value = arg.value.get<Enum0Enum>();
                resultPromise.set_value(value);
            };
            auto responseId = registerResponseHandler(responseHandler);
            m_client->invokeRemote(topic, responseTopic,
                nlohmann::json::array({param0}).dump(), responseId);
            return resultPromise.get_future().get();
        }
    );
}

Enum1Enum EnumInterfaceClient::func1(Enum1Enum param1)
{
    if(m_client == nullptr) {
        return Enum1Enum::value1;
    }
    Enum1Enum value(func1Async(param1).get());
    return value;
}

std::future<Enum1Enum> EnumInterfaceClient::func1Async(Enum1Enum param1)
{
    if(m_client == nullptr) {
        throw std::runtime_error("Client is not initialized");
    }
    return std::async(std::launch::async, [this,
                    param1]()
        {
            std::promise<Enum1Enum> resultPromise;
            static const auto topic = std::string("tb.enum/EnumInterface/rpc/func1");
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

Enum2Enum EnumInterfaceClient::func2(Enum2Enum param2)
{
    if(m_client == nullptr) {
        return Enum2Enum::value2;
    }
    Enum2Enum value(func2Async(param2).get());
    return value;
}

std::future<Enum2Enum> EnumInterfaceClient::func2Async(Enum2Enum param2)
{
    if(m_client == nullptr) {
        throw std::runtime_error("Client is not initialized");
    }
    return std::async(std::launch::async, [this,
                    param2]()
        {
            std::promise<Enum2Enum> resultPromise;
            static const auto topic = std::string("tb.enum/EnumInterface/rpc/func2");
            static const auto responseTopic = std::string(topic + "/" + m_client->getClientId() + "/result");
            ApiGear::MQTT::InvokeReplyFunc responseHandler = [&resultPromise](ApiGear::MQTT::InvokeReplyArg arg) {
                const Enum2Enum& value = arg.value.get<Enum2Enum>();
                resultPromise.set_value(value);
            };
            auto responseId = registerResponseHandler(responseHandler);
            m_client->invokeRemote(topic, responseTopic,
                nlohmann::json::array({param2}).dump(), responseId);
            return resultPromise.get_future().get();
        }
    );
}

Enum3Enum EnumInterfaceClient::func3(Enum3Enum param3)
{
    if(m_client == nullptr) {
        return Enum3Enum::value3;
    }
    Enum3Enum value(func3Async(param3).get());
    return value;
}

std::future<Enum3Enum> EnumInterfaceClient::func3Async(Enum3Enum param3)
{
    if(m_client == nullptr) {
        throw std::runtime_error("Client is not initialized");
    }
    return std::async(std::launch::async, [this,
                    param3]()
        {
            std::promise<Enum3Enum> resultPromise;
            static const auto topic = std::string("tb.enum/EnumInterface/rpc/func3");
            static const auto responseTopic = std::string(topic + "/" + m_client->getClientId() + "/result");
            ApiGear::MQTT::InvokeReplyFunc responseHandler = [&resultPromise](ApiGear::MQTT::InvokeReplyArg arg) {
                const Enum3Enum& value = arg.value.get<Enum3Enum>();
                resultPromise.set_value(value);
            };
            auto responseId = registerResponseHandler(responseHandler);
            m_client->invokeRemote(topic, responseTopic,
                nlohmann::json::array({param3}).dump(), responseId);
            return resultPromise.get_future().get();
        }
    );
}

void EnumInterfaceClient::onSignal(const std::string& topic, const std::string& args, const std::string&, const std::string&)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string entityName = ApiGear::MQTT::Topic(topic).getEntityName();
    if(entityName == "sig0") {
        m_publisher->publishSig0(json_args[0].get<Enum0Enum>());
        return;
    }
    if(entityName == "sig1") {
        m_publisher->publishSig1(json_args[0].get<Enum1Enum>());
        return;
    }
    if(entityName == "sig2") {
        m_publisher->publishSig2(json_args[0].get<Enum2Enum>());
        return;
    }
    if(entityName == "sig3") {
        m_publisher->publishSig3(json_args[0].get<Enum3Enum>());
        return;
    }
}

void EnumInterfaceClient::onPropertyChanged(const std::string& topic, const std::string& args, const std::string&, const std::string&)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string& name = ApiGear::MQTT::Topic(topic).getEntityName();
    applyState({ {name, json_args} });
    return;
}

int EnumInterfaceClient::registerResponseHandler(ApiGear::MQTT::InvokeReplyFunc handler)
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

void EnumInterfaceClient::onInvokeReply(const std::string& /*topic*/, const std::string& args, const std::string& /*responseTopic*/, const std::string& correlationData)
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

bool EnumInterfaceClient::isReady() const
{
    return m_isReady;
}

IEnumInterfacePublisher& EnumInterfaceClient::_getPublisher() const
{
    return *m_publisher;
}
