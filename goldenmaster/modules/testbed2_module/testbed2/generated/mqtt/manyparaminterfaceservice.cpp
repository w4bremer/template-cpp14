#include "testbed2/generated/mqtt/manyparaminterfaceservice.h"
#include "testbed2/generated/core/testbed2.json.adapter.h"
#include <iostream>

using namespace Test::Testbed2;
using namespace Test::Testbed2::MQTT;

ManyParamInterfaceService::ManyParamInterfaceService(std::shared_ptr<IManyParamInterface> impl, std::shared_ptr<ApiGear::MQTT::Client> client)
    : m_impl(impl)
    , m_client(client)
{
    m_impl->_getPublisher().subscribeToAllChanges(*this);

    m_client->registerSink(*this);
    // subscribe to all property change request methods
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed2","ManyParamInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setprop1"), this);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed2","ManyParamInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setprop2"), this);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed2","ManyParamInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setprop3"), this);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed2","ManyParamInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setprop4"), this);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed2","ManyParamInterface",ApiGear::MQTT::Topic::TopicType::Operation,"func1"), this);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed2","ManyParamInterface",ApiGear::MQTT::Topic::TopicType::Operation,"func2"), this);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed2","ManyParamInterface",ApiGear::MQTT::Topic::TopicType::Operation,"func3"), this);
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed2","ManyParamInterface",ApiGear::MQTT::Topic::TopicType::Operation,"func4"), this);

}

ManyParamInterfaceService::~ManyParamInterfaceService()
{
    m_impl->_getPublisher().unsubscribeFromAllChanges(*this);

    m_client->unregisterSink(*this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed2","ManyParamInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setprop1"), this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed2","ManyParamInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setprop2"), this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed2","ManyParamInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setprop3"), this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed2","ManyParamInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setprop4"), this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed2","ManyParamInterface",ApiGear::MQTT::Topic::TopicType::Operation,"func1"), this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed2","ManyParamInterface",ApiGear::MQTT::Topic::TopicType::Operation,"func2"), this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed2","ManyParamInterface",ApiGear::MQTT::Topic::TopicType::Operation,"func3"), this);
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed2","ManyParamInterface",ApiGear::MQTT::Topic::TopicType::Operation,"func4"), this);
}

void ManyParamInterfaceService::onConnected()
{
    // send current values
    onProp1Changed(m_impl->getProp1());
    onProp2Changed(m_impl->getProp2());
    onProp3Changed(m_impl->getProp3());
    onProp4Changed(m_impl->getProp4());
}

void ManyParamInterfaceService::onInvoke(const ApiGear::MQTT::Topic& topic, const std::string& args, const ApiGear::MQTT::Topic& responseTopic, const std::string& correlationData)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string& name = topic.getEntityName();
    if(name == "_setprop1") {
        auto prop1 = json_args.get<int>();
        m_impl->setProp1(prop1);
        return;
    }
    if(name == "_setprop2") {
        auto prop2 = json_args.get<int>();
        m_impl->setProp2(prop2);
        return;
    }
    if(name == "_setprop3") {
        auto prop3 = json_args.get<int>();
        m_impl->setProp3(prop3);
        return;
    }
    if(name == "_setprop4") {
        auto prop4 = json_args.get<int>();
        m_impl->setProp4(prop4);
        return;
    }


    if(name == "func1") {
        const int& param1 = json_args.at(0).get<int>();
        auto result = m_impl->func1(param1);
        m_client->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
    if(name == "func2") {
        const int& param1 = json_args.at(0).get<int>();
        const int& param2 = json_args.at(1).get<int>();
        auto result = m_impl->func2(param1, param2);
        m_client->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
    if(name == "func3") {
        const int& param1 = json_args.at(0).get<int>();
        const int& param2 = json_args.at(1).get<int>();
        const int& param3 = json_args.at(2).get<int>();
        auto result = m_impl->func3(param1, param2, param3);
        m_client->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
    if(name == "func4") {
        const int& param1 = json_args.at(0).get<int>();
        const int& param2 = json_args.at(1).get<int>();
        const int& param3 = json_args.at(2).get<int>();
        const int& param4 = json_args.at(3).get<int>();
        auto result = m_impl->func4(param1, param2, param3, param4);
        m_client->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
}
void ManyParamInterfaceService::onSig1(int param1)
{
    if(m_client != nullptr) {
        const nlohmann::json& args = { param1 };
        static const auto topic = ApiGear::MQTT::Topic("testbed2","ManyParamInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sig1");
        m_client->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void ManyParamInterfaceService::onSig2(int param1, int param2)
{
    if(m_client != nullptr) {
        const nlohmann::json& args = { param1, param2 };
        static const auto topic = ApiGear::MQTT::Topic("testbed2","ManyParamInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sig2");
        m_client->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void ManyParamInterfaceService::onSig3(int param1, int param2, int param3)
{
    if(m_client != nullptr) {
        const nlohmann::json& args = { param1, param2, param3 };
        static const auto topic = ApiGear::MQTT::Topic("testbed2","ManyParamInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sig3");
        m_client->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void ManyParamInterfaceService::onSig4(int param1, int param2, int param3, int param4)
{
    if(m_client != nullptr) {
        const nlohmann::json& args = { param1, param2, param3, param4 };
        static const auto topic = ApiGear::MQTT::Topic("testbed2","ManyParamInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sig4");
        m_client->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void ManyParamInterfaceService::onProp1Changed(int prop1)
{
    if(m_client != nullptr) {
        static const auto topic = ApiGear::MQTT::Topic("testbed2","ManyParamInterface",ApiGear::MQTT::Topic::TopicType::Property,"prop1");
        m_client->notifyPropertyChange(topic, nlohmann::json(prop1).dump());
    }
}
void ManyParamInterfaceService::onProp2Changed(int prop2)
{
    if(m_client != nullptr) {
        static const auto topic = ApiGear::MQTT::Topic("testbed2","ManyParamInterface",ApiGear::MQTT::Topic::TopicType::Property,"prop2");
        m_client->notifyPropertyChange(topic, nlohmann::json(prop2).dump());
    }
}
void ManyParamInterfaceService::onProp3Changed(int prop3)
{
    if(m_client != nullptr) {
        static const auto topic = ApiGear::MQTT::Topic("testbed2","ManyParamInterface",ApiGear::MQTT::Topic::TopicType::Property,"prop3");
        m_client->notifyPropertyChange(topic, nlohmann::json(prop3).dump());
    }
}
void ManyParamInterfaceService::onProp4Changed(int prop4)
{
    if(m_client != nullptr) {
        static const auto topic = ApiGear::MQTT::Topic("testbed2","ManyParamInterface",ApiGear::MQTT::Topic::TopicType::Property,"prop4");
        m_client->notifyPropertyChange(topic, nlohmann::json(prop4).dump());
    }
}
