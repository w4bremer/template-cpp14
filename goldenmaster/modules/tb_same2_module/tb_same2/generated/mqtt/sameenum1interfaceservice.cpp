#include "tb_same2/generated/mqtt/sameenum1interfaceservice.h"
#include "tb_same2/generated/core/tb_same2.json.adapter.h"
#include <iostream>

using namespace Test::TbSame2;
using namespace Test::TbSame2::mqtt;

SameEnum1InterfaceService::SameEnum1InterfaceService(std::shared_ptr<ISameEnum1Interface> impl, std::shared_ptr<ApiGear::MQTTImpl::Client> client)
    : m_impl(impl)
    , m_client(client)
{
    m_impl->_getPublisher().subscribeToAllChanges(*this);

    m_client->registerSink(*this);
    // subscribe to all property change request methods
    m_client->subscribeTopic(ApiGear::MQTTImpl::Topic("tb.same2","SameEnum1Interface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"_setprop1"), this);
    m_client->subscribeTopic(ApiGear::MQTTImpl::Topic("tb.same2","SameEnum1Interface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"func1"), this);

}

SameEnum1InterfaceService::~SameEnum1InterfaceService()
{
    m_impl->_getPublisher().unsubscribeFromAllChanges(*this);

    m_client->unregisterSink(*this);
    m_client->unsubscribeTopic(ApiGear::MQTTImpl::Topic("tb.same2","SameEnum1Interface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"_setprop1"), this);
    m_client->unsubscribeTopic(ApiGear::MQTTImpl::Topic("tb.same2","SameEnum1Interface",ApiGear::MQTTImpl::Topic::TopicType::Operation,"func1"), this);
}

void SameEnum1InterfaceService::onConnected()
{
    // send current values
    onProp1Changed(m_impl->getProp1());
}

void SameEnum1InterfaceService::onInvoke(const ApiGear::MQTTImpl::Topic& topic, const std::string& args, const ApiGear::MQTTImpl::Topic& responseTopic, const std::string& correlationData)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string& name = topic.getEntityName();
    if(name == "_setprop1") {
        auto prop1 = json_args.get<Enum1Enum>();
        m_impl->setProp1(prop1);
        return;
    }


    if(name == "func1") {
        const Enum1Enum& param1 = json_args.at(0).get<Enum1Enum>();
        auto result = m_impl->func1(param1);
        m_client->notifyInvokeResponse(responseTopic, nlohmann::json(result).dump(), correlationData);
        return;
    }
}
void SameEnum1InterfaceService::onSig1(Enum1Enum param1)
{
    if(m_client != nullptr) {
        const nlohmann::json& args = { param1 };
        static const auto topic = ApiGear::MQTTImpl::Topic("tb.same2","SameEnum1Interface",ApiGear::MQTTImpl::Topic::TopicType::Signal,"sig1");
        m_client->notifySignal(topic, nlohmann::json(args).dump());
    }
}
void SameEnum1InterfaceService::onProp1Changed(Enum1Enum prop1)
{
    if(m_client != nullptr) {
        static const auto topic = ApiGear::MQTTImpl::Topic("tb.same2","SameEnum1Interface",ApiGear::MQTTImpl::Topic::TopicType::Property,"prop1");
        m_client->notifyPropertyChange(topic, nlohmann::json(prop1).dump());
    }
}
