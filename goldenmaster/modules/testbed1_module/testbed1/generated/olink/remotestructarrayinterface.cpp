

#include "testbed1/generated/olink/remotestructarrayinterface.h"
#include "testbed1/generated/core/structarrayinterface.publisher.h"
#include "testbed1/generated/core/testbed1.json.adapter.h"

using namespace Test::Testbed1;
using namespace Test::Testbed1::olink;

RemoteStructArrayInterface::RemoteStructArrayInterface(ApiGear::ObjectLink::ClientRegistry& registry, ApiGear::PocoImpl::OLinkClient& client)
    : m_registry(registry),
      m_publisher(std::make_unique<StructArrayInterfacePublisher>())
{
    m_registry.addObjectSink(this);
    client.linkObjectSource("testbed1.StructArrayInterface");
}

RemoteStructArrayInterface::~RemoteStructArrayInterface()
{
    m_registry.removeObjectSink(this);
}

void RemoteStructArrayInterface::applyState(const nlohmann::json& fields) 
{
    if(fields.contains("propBool")) {
        setPropBoolLocal(fields["propBool"].get<std::list<StructBool>>());
    }
    if(fields.contains("propInt")) {
        setPropIntLocal(fields["propInt"].get<std::list<StructInt>>());
    }
    if(fields.contains("propFloat")) {
        setPropFloatLocal(fields["propFloat"].get<std::list<StructFloat>>());
    }
    if(fields.contains("propString")) {
        setPropStringLocal(fields["propString"].get<std::list<StructString>>());
    }
}

void RemoteStructArrayInterface::setPropBool(const std::list<StructBool>& propBool)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("testbed1.StructArrayInterface/propBool", propBool);
}

void RemoteStructArrayInterface::setPropBoolLocal(const std::list<StructBool>& propBool)
{
    if (m_data.m_propBool != propBool) {
        m_data.m_propBool = propBool;
        m_publisher->publishPropBoolChanged(propBool);
    }
}

const std::list<StructBool>& RemoteStructArrayInterface::getPropBool() const
{
    return m_data.m_propBool;
}

void RemoteStructArrayInterface::setPropInt(const std::list<StructInt>& propInt)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("testbed1.StructArrayInterface/propInt", propInt);
}

void RemoteStructArrayInterface::setPropIntLocal(const std::list<StructInt>& propInt)
{
    if (m_data.m_propInt != propInt) {
        m_data.m_propInt = propInt;
        m_publisher->publishPropIntChanged(propInt);
    }
}

const std::list<StructInt>& RemoteStructArrayInterface::getPropInt() const
{
    return m_data.m_propInt;
}

void RemoteStructArrayInterface::setPropFloat(const std::list<StructFloat>& propFloat)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("testbed1.StructArrayInterface/propFloat", propFloat);
}

void RemoteStructArrayInterface::setPropFloatLocal(const std::list<StructFloat>& propFloat)
{
    if (m_data.m_propFloat != propFloat) {
        m_data.m_propFloat = propFloat;
        m_publisher->publishPropFloatChanged(propFloat);
    }
}

const std::list<StructFloat>& RemoteStructArrayInterface::getPropFloat() const
{
    return m_data.m_propFloat;
}

void RemoteStructArrayInterface::setPropString(const std::list<StructString>& propString)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("testbed1.StructArrayInterface/propString", propString);
}

void RemoteStructArrayInterface::setPropStringLocal(const std::list<StructString>& propString)
{
    if (m_data.m_propString != propString) {
        m_data.m_propString = propString;
        m_publisher->publishPropStringChanged(propString);
    }
}

const std::list<StructString>& RemoteStructArrayInterface::getPropString() const
{
    return m_data.m_propString;
}

StructBool RemoteStructArrayInterface::funcBool(const std::list<StructBool>& paramBool)
{
    if(m_node == nullptr) {
        return StructBool();
    }
    StructBool value(funcBoolAsync(paramBool).get());
    return value;
}

std::future<StructBool> RemoteStructArrayInterface::funcBoolAsync(const std::list<StructBool>& paramBool)
{
    if(m_node == nullptr) {
        throw std::runtime_error("Node is not initialized");
    }
    return std::async(std::launch::async, [this,
                    paramBool]()
        {
            std::promise<StructBool> resultPromise;
            m_node->invokeRemote("testbed1.StructArrayInterface/funcBool",
                nlohmann::json::array({paramBool}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const StructBool& value = arg.value.get<StructBool>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

StructBool RemoteStructArrayInterface::funcInt(const std::list<StructInt>& paramInt)
{
    if(m_node == nullptr) {
        return StructBool();
    }
    StructBool value(funcIntAsync(paramInt).get());
    return value;
}

std::future<StructBool> RemoteStructArrayInterface::funcIntAsync(const std::list<StructInt>& paramInt)
{
    if(m_node == nullptr) {
        throw std::runtime_error("Node is not initialized");
    }
    return std::async(std::launch::async, [this,
                    paramInt]()
        {
            std::promise<StructBool> resultPromise;
            m_node->invokeRemote("testbed1.StructArrayInterface/funcInt",
                nlohmann::json::array({paramInt}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const StructBool& value = arg.value.get<StructBool>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

StructBool RemoteStructArrayInterface::funcFloat(const std::list<StructFloat>& paramFloat)
{
    if(m_node == nullptr) {
        return StructBool();
    }
    StructBool value(funcFloatAsync(paramFloat).get());
    return value;
}

std::future<StructBool> RemoteStructArrayInterface::funcFloatAsync(const std::list<StructFloat>& paramFloat)
{
    if(m_node == nullptr) {
        throw std::runtime_error("Node is not initialized");
    }
    return std::async(std::launch::async, [this,
                    paramFloat]()
        {
            std::promise<StructBool> resultPromise;
            m_node->invokeRemote("testbed1.StructArrayInterface/funcFloat",
                nlohmann::json::array({paramFloat}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const StructBool& value = arg.value.get<StructBool>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

StructBool RemoteStructArrayInterface::funcString(const std::list<StructString>& paramString)
{
    if(m_node == nullptr) {
        return StructBool();
    }
    StructBool value(funcStringAsync(paramString).get());
    return value;
}

std::future<StructBool> RemoteStructArrayInterface::funcStringAsync(const std::list<StructString>& paramString)
{
    if(m_node == nullptr) {
        throw std::runtime_error("Node is not initialized");
    }
    return std::async(std::launch::async, [this,
                    paramString]()
        {
            std::promise<StructBool> resultPromise;
            m_node->invokeRemote("testbed1.StructArrayInterface/funcString",
                nlohmann::json::array({paramString}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const StructBool& value = arg.value.get<StructBool>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

std::string RemoteStructArrayInterface::olinkObjectName()
{
    return "testbed1.StructArrayInterface";
}

void RemoteStructArrayInterface::olinkOnSignal(std::string name, nlohmann::json args)
{
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    if(path == "sigBool") {
        m_publisher->publishSigBool(args[0].get<std::list<StructBool>>());   
        return;
    }
    if(path == "sigInt") {
        m_publisher->publishSigInt(args[0].get<std::list<StructInt>>());   
        return;
    }
    if(path == "sigFloat") {
        m_publisher->publishSigFloat(args[0].get<std::list<StructFloat>>());   
        return;
    }
    if(path == "sigString") {
        m_publisher->publishSigString(args[0].get<std::list<StructString>>());   
        return;
    }
}

void RemoteStructArrayInterface::olinkOnPropertyChanged(std::string name, nlohmann::json value)
{
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    applyState({ {path, value} });
}
void RemoteStructArrayInterface::olinkOnInit(std::string name, nlohmann::json props, ApiGear::ObjectLink::IClientNode *node)
{
    (void) name; //suppress the 'Unreferenced Formal Parameter' warning.
    m_node = node;
    applyState(props);
}

void RemoteStructArrayInterface::olinkOnRelease()
{
    m_node = nullptr;
}

bool RemoteStructArrayInterface::isReady() const
{
    return m_node != nullptr;
}

IStructArrayInterfacePublisher& RemoteStructArrayInterface::_getPublisher() const
{
    return *m_publisher;
}
