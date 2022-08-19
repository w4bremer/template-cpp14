

#include "testbed2/generated/olink/remotenestedstruct1interface.h"
#include "testbed2/generated/core/nestedstruct1interface.publisher.h"
#include "testbed2/generated/core/testbed2.json.adapter.h"

using namespace Test::Testbed2;
using namespace Test::Testbed2::olink;

RemoteNestedStruct1Interface::RemoteNestedStruct1Interface(ApiGear::ObjectLink::ClientRegistry& registry, ApiGear::PocoImpl::OLinkClient& client)
    : m_registry(registry),
      m_publisher(std::make_unique<NestedStruct1InterfacePublisher>())
{
    m_registry.addObjectSink(this);
    client.linkObjectSource("testbed2.NestedStruct1Interface");
}

RemoteNestedStruct1Interface::~RemoteNestedStruct1Interface()
{
    m_registry.removeObjectSink(this);
}

void RemoteNestedStruct1Interface::applyState(const nlohmann::json& fields) 
{
    if(fields.contains("prop1")) {
        setProp1Local(fields["prop1"].get<NestedStruct1>());
    }
}

void RemoteNestedStruct1Interface::setProp1(const NestedStruct1& prop1)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("testbed2.NestedStruct1Interface/prop1", prop1);
}

void RemoteNestedStruct1Interface::setProp1Local(const NestedStruct1& prop1)
{
    if (m_data.m_prop1 != prop1) {
        m_data.m_prop1 = prop1;
        m_publisher->publishProp1Changed(prop1);
    }
}

const NestedStruct1& RemoteNestedStruct1Interface::getProp1() const
{
    return m_data.m_prop1;
}

NestedStruct1 RemoteNestedStruct1Interface::func1(const NestedStruct1& param1)
{
    if(m_node == nullptr) {
        return NestedStruct1();
    }
    NestedStruct1 value(func1Async(param1).get());
    return value;
}

std::future<NestedStruct1> RemoteNestedStruct1Interface::func1Async(const NestedStruct1& param1)
{
    if(m_node == nullptr) {
        throw std::runtime_error("Node is not initialized");
    }
    return std::async(std::launch::async, [this,
                    param1]()
        {
            std::promise<NestedStruct1> resultPromise;
            m_node->invokeRemote("testbed2.NestedStruct1Interface/func1",
                nlohmann::json::array({param1}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const NestedStruct1& value = arg.value.get<NestedStruct1>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

std::string RemoteNestedStruct1Interface::olinkObjectName()
{
    return "testbed2.NestedStruct1Interface";
}

void RemoteNestedStruct1Interface::olinkOnSignal(std::string name, nlohmann::json args)
{
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    if(path == "sig1") {
        m_publisher->publishSig1(args[0].get<NestedStruct1>());   
        return;
    }
}

void RemoteNestedStruct1Interface::olinkOnPropertyChanged(std::string name, nlohmann::json value)
{
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    applyState({ {path, value} });
}
void RemoteNestedStruct1Interface::olinkOnInit(std::string name, nlohmann::json props, ApiGear::ObjectLink::IClientNode *node)
{
    (void) name; //suppress the 'Unreferenced Formal Parameter' warning.
    m_node = node;
    applyState(props);
}

void RemoteNestedStruct1Interface::olinkOnRelease()
{
    m_node = nullptr;
}

bool RemoteNestedStruct1Interface::isReady() const
{
    return m_node != nullptr;
}

INestedStruct1InterfacePublisher& RemoteNestedStruct1Interface::_getPublisher() const
{
    return *m_publisher;
}
