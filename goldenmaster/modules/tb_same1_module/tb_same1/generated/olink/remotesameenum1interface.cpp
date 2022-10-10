

#include "tb_same1/generated/olink/remotesameenum1interface.h"
#include "tb_same1/generated/core/sameenum1interface.publisher.h"
#include "tb_same1/generated/core/tb_same1.json.adapter.h"

#include "olink/iclientnode.h"
#include "apigear/olink/olinkconnection.h"

using namespace Test::TbSame1;
using namespace Test::TbSame1::olink;

namespace 
{
const std::string interfaceId = "tb.same1.SameEnum1Interface";
}

RemoteSameEnum1Interface::RemoteSameEnum1Interface(std::weak_ptr<ApiGear::PocoImpl::IOlinkConnector> olinkConnector)
    : m_olinkConnector(olinkConnector),
      m_publisher(std::make_unique<SameEnum1InterfacePublisher>())
{
    if(auto connector = m_olinkConnector.lock())
    {
        connector->connectAndLinkObject(*this);
    }
}

RemoteSameEnum1Interface::~RemoteSameEnum1Interface()
{    
    if(auto connector = m_olinkConnector.lock())
    {
        connector->disconnectAndUnlink(olinkObjectName());
    }
}

void RemoteSameEnum1Interface::applyState(const nlohmann::json& fields) 
{
    if(fields.contains("prop1")) {
        setProp1Local(fields["prop1"].get<Enum1Enum>());
    }
}

void RemoteSameEnum1Interface::setProp1(const Enum1Enum& prop1)
{
    if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to set property but " + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return;
    }
    const auto& propertyId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "prop1");
    m_node->setRemoteProperty(propertyId, prop1);
}

void RemoteSameEnum1Interface::setProp1Local(const Enum1Enum& prop1)
{
    if (m_data.m_prop1 != prop1) {
        m_data.m_prop1 = prop1;
        m_publisher->publishProp1Changed(prop1);
    }
}

const Enum1Enum& RemoteSameEnum1Interface::getProp1() const
{
    return m_data.m_prop1;
}

Enum1Enum RemoteSameEnum1Interface::func1(const Enum1Enum& param1)
{
     if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return Enum1Enum::value1;
    }
    Enum1Enum value(func1Async(param1).get());
    return value;
}

std::future<Enum1Enum> RemoteSameEnum1Interface::func1Async(const Enum1Enum& param1)
{
    if(!m_node) {
        emitLog(ApiGear::Logger::LogLevel::Warning, "Attempt to invoke method but" + olinkObjectName() +" is not linked to source . Make sure your object is linked. Check your connection to service");
        return std::future<Enum1Enum>{};
    }
    return std::async(std::launch::async, [this,
                    param1]()
        {
            std::promise<Enum1Enum> resultPromise;
            const auto& operationId = ApiGear::ObjectLink::Name::createMemberId(olinkObjectName(), "func1");
            m_node->invokeRemote(operationId,
                nlohmann::json::array({param1}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const Enum1Enum& value = arg.value.get<Enum1Enum>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

std::string RemoteSameEnum1Interface::olinkObjectName()
{
    return interfaceId;
}

void RemoteSameEnum1Interface::olinkOnSignal(const std::string& signalId, const nlohmann::json& args)
{
    const auto& signalName = ApiGear::ObjectLink::Name::getMemberName(signalId);
    if(signalName == "sig1") {
        m_publisher->publishSig1(args[0].get<Enum1Enum>());   
        return;
    }
}

void RemoteSameEnum1Interface::olinkOnPropertyChanged(const std::string& propertyId, const nlohmann::json& value)
{
    applyState({ {ApiGear::ObjectLink::Name::getMemberName(propertyId), value} });
}
void RemoteSameEnum1Interface::olinkOnInit(const std::string& /*name*/, const nlohmann::json& props, ApiGear::ObjectLink::IClientNode *node)
{
    m_node = node;
    applyState(props);
}

void RemoteSameEnum1Interface::olinkOnRelease()
{
    m_node = nullptr;
}

bool RemoteSameEnum1Interface::isReady() const
{
    return m_node != nullptr;
}

ISameEnum1InterfacePublisher& RemoteSameEnum1Interface::_getPublisher() const
{
    return *m_publisher;
}
