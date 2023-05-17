#include "testbed2/generated/mqtt/nestedstruct3interfaceservice.h"
#include "testbed2/generated/core/testbed2.json.adapter.h"
#include <iostream>

using namespace Test::Testbed2;
using namespace Test::Testbed2::MQTT;

NestedStruct3InterfaceService::NestedStruct3InterfaceService(std::shared_ptr<INestedStruct3Interface> impl, std::shared_ptr<ApiGear::MQTT::Client> client)
    : m_impl(impl)
    , m_client(client)
{
    m_impl->_getPublisher().subscribeToAllChanges(*this);

    m_client->registerSink(*this);
    // subscribe to all property change request methods
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed2","NestedStruct3Interface",ApiGear::MQTT::Topic::TopicType::Operation,"_setprop1"), this);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed2","NestedStruct3Interface",ApiGear::MQTT::Topic::TopicType::Operation,"_setprop2"), this);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed2","NestedStruct3Interface",ApiGear::MQTT::Topic::TopicType::Operation,"_setprop3"), this);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed2","NestedStruct3Interface",ApiGear::MQTT::Topic::TopicType::Operation,"func1"), this);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed2","NestedStruct3Interface",ApiGear::MQTT::Topic::TopicType::Operation,"func2"), this);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed2","NestedStruct3Interface",ApiGear::MQTT::Topic::TopicType::Operation,"func3"), this);

}

NestedStruct3InterfaceService::~NestedStruct3InterfaceService()
{
    m_impl->_getPublisher().unsubscribeFromAllChanges(*this);

    m_client->unregisterSink(*this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed2","NestedStruct3Interface",ApiGear::MQTT::Topic::TopicType::Operation,"_setprop1"), this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed2","NestedStruct3Interface",ApiGear::MQTT::Topic::TopicType::Operation,"_setprop2"), this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed2","NestedStruct3Interface",ApiGear::MQTT::Topic::TopicType::Operation,"_setprop3"), this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed2","NestedStruct3Interface",ApiGear::MQTT::Topic::TopicType::Operation,"func1"), this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed2","NestedStruct3Interface",ApiGear::MQTT::Topic::TopicType::Operation,"func2"), this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed2","NestedStruct3Interface",ApiGear::MQTT::Topic::TopicType::Operation,"func3"), this);
}

void NestedStruct3InterfaceService::onConnected()
{
    // send current values
    onProp1Changed(m_impl->getProp1());
    onProp2Changed(m_impl->getProp2());
    onProp3Changed(m_impl->getProp3());
}

void NestedStruct3InterfaceService::onInvoke(const ApiGear::MQTT::Topic& topic, const std::string& args, const ApiGear::MQTT::Topic& responseTopic, const std::string& correlationData)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string& name = topic.getEntityName();
    if(name == "_setprop1") {
        auto prop1 = json_args.get<NestedStruct1>();
        m_impl->setProp1(prop1);
        return;
    }
    if(name == "_setprop2") {
        auto prop2 = json_args.get<NestedStruct2>();
        m_impl->setProp2(prop2);
        return;
    }
    if(name == "_setprop3") {
        auto prop3 = json_args.get<NestedStruct3>();
        m_impl->setProp3(prop3);
        return;
    }


    if(name == "func1") {
        const NestedStruct1& param1 = json_args.at(0).get<NestedStruct1>();
        auto result = m_impl->func1(param1);
        m_client->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
    if(name == "func2") {
        const NestedStruct1& param1 = json_args.at(0).get<NestedStruct1>();
        const NestedStruct2& param2 = json_args.at(1).get<NestedStruct2>();
        auto result = m_impl->func2(param1, param2);
        m_client->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
    if(name == "func3") {
        const NestedStruct1& param1 = json_args.at(0).get<NestedStruct1>();
        const NestedStruct2& param2 = json_args.at(1).get<NestedStruct2>();
        const NestedStruct3& param3 = json_args.at(2).get<NestedStruct3>();
        auto result = m_impl->func3(param1, param2, param3);
        m_client->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
}
void NestedStruct3InterfaceService::onSig1(const NestedStruct1& param1)
{
    if(m_client != nullptr) {
        const nlohmann::json& args = { param1 };
        static const auto topic = ApiGear::MQTT::Topic("testbed2","NestedStruct3Interface",ApiGear::MQTT::Topic::TopicType::Signal,"sig1");
        m_client->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void NestedStruct3InterfaceService::onSig2(const NestedStruct1& param1, const NestedStruct2& param2)
{
    if(m_client != nullptr) {
        const nlohmann::json& args = { param1, param2 };
        static const auto topic = ApiGear::MQTT::Topic("testbed2","NestedStruct3Interface",ApiGear::MQTT::Topic::TopicType::Signal,"sig2");
        m_client->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void NestedStruct3InterfaceService::onSig3(const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3)
{
    if(m_client != nullptr) {
        const nlohmann::json& args = { param1, param2, param3 };
        static const auto topic = ApiGear::MQTT::Topic("testbed2","NestedStruct3Interface",ApiGear::MQTT::Topic::TopicType::Signal,"sig3");
        m_client->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void NestedStruct3InterfaceService::onProp1Changed(const NestedStruct1& prop1)
{
    if(m_client != nullptr) {
        static const auto topic = ApiGear::MQTT::Topic("testbed2","NestedStruct3Interface",ApiGear::MQTT::Topic::TopicType::Property,"prop1");
        m_client->notifyPropertyChange(topic, nlohmann::json(prop1).dump());
    }
}
void NestedStruct3InterfaceService::onProp2Changed(const NestedStruct2& prop2)
{
    if(m_client != nullptr) {
        static const auto topic = ApiGear::MQTT::Topic("testbed2","NestedStruct3Interface",ApiGear::MQTT::Topic::TopicType::Property,"prop2");
        m_client->notifyPropertyChange(topic, nlohmann::json(prop2).dump());
    }
}
void NestedStruct3InterfaceService::onProp3Changed(const NestedStruct3& prop3)
{
    if(m_client != nullptr) {
        static const auto topic = ApiGear::MQTT::Topic("testbed2","NestedStruct3Interface",ApiGear::MQTT::Topic::TopicType::Property,"prop3");
        m_client->notifyPropertyChange(topic, nlohmann::json(prop3).dump());
    }
}
