

#include "tb_same1/generated/olink/remotesamestruct1interface.h"
#include "tb_same1/generated/core/samestruct1interface.publisher.h"
#include "tb_same1/generated/core/tb_same1.json.adapter.h"

using namespace Test::TbSame1;
using namespace Test::TbSame1::olink;

RemoteSameStruct1Interface::RemoteSameStruct1Interface(ApiGear::ObjectLink::ClientRegistry& registry, ApiGear::PocoImpl::OLinkClient& client)
    : m_registry(registry),
      m_publisher(std::make_unique<SameStruct1InterfacePublisher>())
{
    m_registry.addObjectSink(this);
    client.linkObjectSource("tb.same1.SameStruct1Interface");
}

RemoteSameStruct1Interface::~RemoteSameStruct1Interface()
{
    m_registry.removeObjectSink(this);
}

void RemoteSameStruct1Interface::applyState(const nlohmann::json& fields) 
{
    if(fields.contains("prop1")) {
        setProp1Local(fields["prop1"].get<Struct1>());
    }
}

void RemoteSameStruct1Interface::setProp1(const Struct1& prop1)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("tb.same1.SameStruct1Interface/prop1", prop1);
}

void RemoteSameStruct1Interface::setProp1Local(const Struct1& prop1)
{
    if (m_data.m_prop1 != prop1) {
        m_data.m_prop1 = prop1;
        m_publisher->publishProp1Changed(prop1);
    }
}

const Struct1& RemoteSameStruct1Interface::getProp1() const
{
    return m_data.m_prop1;
}

Struct1 RemoteSameStruct1Interface::func1(const Struct1& param1)
{
    if(m_node == nullptr) {
        return Struct1();
    }
    Struct1 value(func1Async(param1).get());
    return value;
}

std::future<Struct1> RemoteSameStruct1Interface::func1Async(const Struct1& param1)
{
    if(m_node == nullptr) {
        throw std::runtime_error("Node is not initialized");
    }
    return std::async(std::launch::async, [this,
                    param1]()
        {
            std::promise<Struct1> resultPromise;
            m_node->invokeRemote("tb.same1.SameStruct1Interface/func1",
                nlohmann::json::array({param1}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const Struct1& value = arg.value.get<Struct1>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

std::string RemoteSameStruct1Interface::olinkObjectName()
{
    return "tb.same1.SameStruct1Interface";
}

void RemoteSameStruct1Interface::olinkOnSignal(std::string name, nlohmann::json args)
{
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    if(path == "sig1") {
        m_publisher->publishSig1(args[0].get<Struct1>());   
        return;
    }
}

void RemoteSameStruct1Interface::olinkOnPropertyChanged(std::string name, nlohmann::json value)
{
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    applyState({ {path, value} });
}
void RemoteSameStruct1Interface::olinkOnInit(std::string name, nlohmann::json props, ApiGear::ObjectLink::IClientNode *node)
{
    (void) name; //suppress the 'Unreferenced Formal Parameter' warning.
    m_node = node;
    applyState(props);
}

void RemoteSameStruct1Interface::olinkOnRelease()
{
    m_node = nullptr;
}

bool RemoteSameStruct1Interface::isReady() const
{
    return m_node != nullptr;
}

ISameStruct1InterfacePublisher& RemoteSameStruct1Interface::_getPublisher() const
{
    return *m_publisher;
}
