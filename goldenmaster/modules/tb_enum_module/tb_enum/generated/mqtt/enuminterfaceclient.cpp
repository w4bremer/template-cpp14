#include "tb_enum/generated/mqtt/enuminterfaceclient.h"
#include "tb_enum/generated/core/enuminterface.publisher.h"
#include "tb_enum/generated/core/tb_enum.json.adapter.h"

using namespace Test::TbEnum;
using namespace Test::TbEnum::MQTT;

EnumInterfaceClient::EnumInterfaceClient(std::shared_ptr<ApiGear::MQTT::Client> client)
    : m_isReady(false)
    , m_client(client)
    , m_publisher(std::make_unique<EnumInterfacePublisher>())
{
    m_client->subscribeTopic(ApiGear::MQTT::Topic("tb.enum","EnumInterface",ApiGear::MQTT::Topic::TopicType::Property,"prop0"), std::bind(&EnumInterfaceClient::onPropertyChanged, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->subscribeTopic(ApiGear::MQTT::Topic("tb.enum","EnumInterface",ApiGear::MQTT::Topic::TopicType::Property,"prop1"), std::bind(&EnumInterfaceClient::onPropertyChanged, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->subscribeTopic(ApiGear::MQTT::Topic("tb.enum","EnumInterface",ApiGear::MQTT::Topic::TopicType::Property,"prop2"), std::bind(&EnumInterfaceClient::onPropertyChanged, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->subscribeTopic(ApiGear::MQTT::Topic("tb.enum","EnumInterface",ApiGear::MQTT::Topic::TopicType::Property,"prop3"), std::bind(&EnumInterfaceClient::onPropertyChanged, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->subscribeTopic(ApiGear::MQTT::Topic("tb.enum","EnumInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sig0"), std::bind(&EnumInterfaceClient::onSignal, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->subscribeTopic(ApiGear::MQTT::Topic("tb.enum","EnumInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sig1"), std::bind(&EnumInterfaceClient::onSignal, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->subscribeTopic(ApiGear::MQTT::Topic("tb.enum","EnumInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sig2"), std::bind(&EnumInterfaceClient::onSignal, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->subscribeTopic(ApiGear::MQTT::Topic("tb.enum","EnumInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sig3"), std::bind(&EnumInterfaceClient::onSignal, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->subscribeTopic(ApiGear::MQTT::Topic("tb.enum","EnumInterface",ApiGear::MQTT::Topic::TopicType::Operation,"func0",m_client->getClientId()+"/result"), nullptr);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("tb.enum","EnumInterface",ApiGear::MQTT::Topic::TopicType::Operation,"func1",m_client->getClientId()+"/result"), nullptr);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("tb.enum","EnumInterface",ApiGear::MQTT::Topic::TopicType::Operation,"func2",m_client->getClientId()+"/result"), nullptr);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("tb.enum","EnumInterface",ApiGear::MQTT::Topic::TopicType::Operation,"func3",m_client->getClientId()+"/result"), nullptr);
}

EnumInterfaceClient::~EnumInterfaceClient()
{
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("tb.enum","EnumInterface",ApiGear::MQTT::Topic::TopicType::Property,"prop0"), std::bind(&EnumInterfaceClient::onPropertyChanged, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("tb.enum","EnumInterface",ApiGear::MQTT::Topic::TopicType::Property,"prop1"), std::bind(&EnumInterfaceClient::onPropertyChanged, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("tb.enum","EnumInterface",ApiGear::MQTT::Topic::TopicType::Property,"prop2"), std::bind(&EnumInterfaceClient::onPropertyChanged, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("tb.enum","EnumInterface",ApiGear::MQTT::Topic::TopicType::Property,"prop3"), std::bind(&EnumInterfaceClient::onPropertyChanged, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("tb.enum","EnumInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sig0"), std::bind(&EnumInterfaceClient::onSignal, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("tb.enum","EnumInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sig1"), std::bind(&EnumInterfaceClient::onSignal, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("tb.enum","EnumInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sig2"), std::bind(&EnumInterfaceClient::onSignal, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("tb.enum","EnumInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sig3"), std::bind(&EnumInterfaceClient::onSignal, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("tb.enum","EnumInterface",ApiGear::MQTT::Topic::TopicType::Operation,"func0",m_client->getClientId()+"/result"), nullptr);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("tb.enum","EnumInterface",ApiGear::MQTT::Topic::TopicType::Operation,"func1",m_client->getClientId()+"/result"), nullptr);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("tb.enum","EnumInterface",ApiGear::MQTT::Topic::TopicType::Operation,"func2",m_client->getClientId()+"/result"), nullptr);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("tb.enum","EnumInterface",ApiGear::MQTT::Topic::TopicType::Operation,"func3",m_client->getClientId()+"/result"), nullptr);
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
    static const auto topic = ApiGear::MQTT::Topic("tb.enum","EnumInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setprop0");
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
    static const auto topic = ApiGear::MQTT::Topic("tb.enum","EnumInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setprop1");
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
    static const auto topic = ApiGear::MQTT::Topic("tb.enum","EnumInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setprop2");
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
    static const auto topic = ApiGear::MQTT::Topic("tb.enum","EnumInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setprop3");
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
            static const auto topic = ApiGear::MQTT::Topic("tb.enum","EnumInterface",ApiGear::MQTT::Topic::TopicType::Operation,"func0");
            m_client->invokeRemote(topic,
                nlohmann::json::array({param0}).dump(), [&resultPromise](ApiGear::MQTT::InvokeReplyArg arg) {
                    const Enum0Enum& value = arg.value.get<Enum0Enum>();
                    resultPromise.set_value(value);
                });
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
            static const auto topic = ApiGear::MQTT::Topic("tb.enum","EnumInterface",ApiGear::MQTT::Topic::TopicType::Operation,"func1");
            m_client->invokeRemote(topic,
                nlohmann::json::array({param1}).dump(), [&resultPromise](ApiGear::MQTT::InvokeReplyArg arg) {
                    const Enum1Enum& value = arg.value.get<Enum1Enum>();
                    resultPromise.set_value(value);
                });
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
            static const auto topic = ApiGear::MQTT::Topic("tb.enum","EnumInterface",ApiGear::MQTT::Topic::TopicType::Operation,"func2");
            m_client->invokeRemote(topic,
                nlohmann::json::array({param2}).dump(), [&resultPromise](ApiGear::MQTT::InvokeReplyArg arg) {
                    const Enum2Enum& value = arg.value.get<Enum2Enum>();
                    resultPromise.set_value(value);
                });
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
            static const auto topic = ApiGear::MQTT::Topic("tb.enum","EnumInterface",ApiGear::MQTT::Topic::TopicType::Operation,"func3");
            m_client->invokeRemote(topic,
                nlohmann::json::array({param3}).dump(), [&resultPromise](ApiGear::MQTT::InvokeReplyArg arg) {
                    const Enum3Enum& value = arg.value.get<Enum3Enum>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

void EnumInterfaceClient::onSignal(const ApiGear::MQTT::Topic& topic, const std::string& args, const ApiGear::MQTT::Topic&, const std::string&)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    if(topic.getEntityName() == "sig0") {
        m_publisher->publishSig0(json_args[0].get<Enum0Enum>());
        return;
    }
    if(topic.getEntityName() == "sig1") {
        m_publisher->publishSig1(json_args[0].get<Enum1Enum>());
        return;
    }
    if(topic.getEntityName() == "sig2") {
        m_publisher->publishSig2(json_args[0].get<Enum2Enum>());
        return;
    }
    if(topic.getEntityName() == "sig3") {
        m_publisher->publishSig3(json_args[0].get<Enum3Enum>());
        return;
    }
}

void EnumInterfaceClient::onPropertyChanged(const ApiGear::MQTT::Topic& topic, const std::string& args, const ApiGear::MQTT::Topic&, const std::string&)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string& name = topic.getEntityName();
    applyState({ {name, json_args} });
    return;
}

bool EnumInterfaceClient::isReady() const
{
    return m_isReady;
}

IEnumInterfacePublisher& EnumInterfaceClient::_getPublisher() const
{
    return *m_publisher;
}
