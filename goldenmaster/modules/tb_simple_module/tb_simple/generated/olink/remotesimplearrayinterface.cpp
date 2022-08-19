

#include "tb_simple/generated/olink/remotesimplearrayinterface.h"
#include "tb_simple/generated/core/simplearrayinterface.publisher.h"
#include "tb_simple/generated/core/tb_simple.json.adapter.h"

using namespace Test::TbSimple;
using namespace Test::TbSimple::olink;

RemoteSimpleArrayInterface::RemoteSimpleArrayInterface(ApiGear::ObjectLink::ClientRegistry& registry, ApiGear::PocoImpl::OLinkClient& client)
    : m_registry(registry),
      m_publisher(std::make_unique<SimpleArrayInterfacePublisher>())
{
    m_registry.addObjectSink(this);
    client.linkObjectSource("tb.simple.SimpleArrayInterface");
}

RemoteSimpleArrayInterface::~RemoteSimpleArrayInterface()
{
    m_registry.removeObjectSink(this);
}

void RemoteSimpleArrayInterface::applyState(const nlohmann::json& fields) 
{
    if(fields.contains("propBool")) {
        setPropBoolLocal(fields["propBool"].get<std::list<bool>>());
    }
    if(fields.contains("propInt")) {
        setPropIntLocal(fields["propInt"].get<std::list<int>>());
    }
    if(fields.contains("propFloat")) {
        setPropFloatLocal(fields["propFloat"].get<std::list<float>>());
    }
    if(fields.contains("propString")) {
        setPropStringLocal(fields["propString"].get<std::list<std::string>>());
    }
}

void RemoteSimpleArrayInterface::setPropBool(const std::list<bool>& propBool)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("tb.simple.SimpleArrayInterface/propBool", propBool);
}

void RemoteSimpleArrayInterface::setPropBoolLocal(const std::list<bool>& propBool)
{
    if (m_data.m_propBool != propBool) {
        m_data.m_propBool = propBool;
        m_publisher->publishPropBoolChanged(propBool);
    }
}

const std::list<bool>& RemoteSimpleArrayInterface::getPropBool() const
{
    return m_data.m_propBool;
}

void RemoteSimpleArrayInterface::setPropInt(const std::list<int>& propInt)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("tb.simple.SimpleArrayInterface/propInt", propInt);
}

void RemoteSimpleArrayInterface::setPropIntLocal(const std::list<int>& propInt)
{
    if (m_data.m_propInt != propInt) {
        m_data.m_propInt = propInt;
        m_publisher->publishPropIntChanged(propInt);
    }
}

const std::list<int>& RemoteSimpleArrayInterface::getPropInt() const
{
    return m_data.m_propInt;
}

void RemoteSimpleArrayInterface::setPropFloat(const std::list<float>& propFloat)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("tb.simple.SimpleArrayInterface/propFloat", propFloat);
}

void RemoteSimpleArrayInterface::setPropFloatLocal(const std::list<float>& propFloat)
{
    if (m_data.m_propFloat != propFloat) {
        m_data.m_propFloat = propFloat;
        m_publisher->publishPropFloatChanged(propFloat);
    }
}

const std::list<float>& RemoteSimpleArrayInterface::getPropFloat() const
{
    return m_data.m_propFloat;
}

void RemoteSimpleArrayInterface::setPropString(const std::list<std::string>& propString)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("tb.simple.SimpleArrayInterface/propString", propString);
}

void RemoteSimpleArrayInterface::setPropStringLocal(const std::list<std::string>& propString)
{
    if (m_data.m_propString != propString) {
        m_data.m_propString = propString;
        m_publisher->publishPropStringChanged(propString);
    }
}

const std::list<std::string>& RemoteSimpleArrayInterface::getPropString() const
{
    return m_data.m_propString;
}

std::list<bool> RemoteSimpleArrayInterface::funcBool(const std::list<bool>& paramBool)
{
    if(m_node == nullptr) {
        return std::list<bool>();
    }
    std::list<bool> value(funcBoolAsync(paramBool).get());
    return value;
}

std::future<std::list<bool>> RemoteSimpleArrayInterface::funcBoolAsync(const std::list<bool>& paramBool)
{
    if(m_node == nullptr) {
        throw std::runtime_error("Node is not initialized");
    }
    return std::async(std::launch::async, [this,
                    paramBool]()
        {
            std::promise<std::list<bool>> resultPromise;
            m_node->invokeRemote("tb.simple.SimpleArrayInterface/funcBool",
                nlohmann::json::array({paramBool}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const std::list<bool>& value = arg.value.get<std::list<bool>>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

std::list<int> RemoteSimpleArrayInterface::funcInt(const std::list<int>& paramInt)
{
    if(m_node == nullptr) {
        return std::list<int>();
    }
    std::list<int> value(funcIntAsync(paramInt).get());
    return value;
}

std::future<std::list<int>> RemoteSimpleArrayInterface::funcIntAsync(const std::list<int>& paramInt)
{
    if(m_node == nullptr) {
        throw std::runtime_error("Node is not initialized");
    }
    return std::async(std::launch::async, [this,
                    paramInt]()
        {
            std::promise<std::list<int>> resultPromise;
            m_node->invokeRemote("tb.simple.SimpleArrayInterface/funcInt",
                nlohmann::json::array({paramInt}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const std::list<int>& value = arg.value.get<std::list<int>>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

std::list<float> RemoteSimpleArrayInterface::funcFloat(const std::list<float>& paramFloat)
{
    if(m_node == nullptr) {
        return std::list<float>();
    }
    std::list<float> value(funcFloatAsync(paramFloat).get());
    return value;
}

std::future<std::list<float>> RemoteSimpleArrayInterface::funcFloatAsync(const std::list<float>& paramFloat)
{
    if(m_node == nullptr) {
        throw std::runtime_error("Node is not initialized");
    }
    return std::async(std::launch::async, [this,
                    paramFloat]()
        {
            std::promise<std::list<float>> resultPromise;
            m_node->invokeRemote("tb.simple.SimpleArrayInterface/funcFloat",
                nlohmann::json::array({paramFloat}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const std::list<float>& value = arg.value.get<std::list<float>>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

std::list<std::string> RemoteSimpleArrayInterface::funcString(const std::list<std::string>& paramString)
{
    if(m_node == nullptr) {
        return std::list<std::string>();
    }
    std::list<std::string> value(funcStringAsync(paramString).get());
    return value;
}

std::future<std::list<std::string>> RemoteSimpleArrayInterface::funcStringAsync(const std::list<std::string>& paramString)
{
    if(m_node == nullptr) {
        throw std::runtime_error("Node is not initialized");
    }
    return std::async(std::launch::async, [this,
                    paramString]()
        {
            std::promise<std::list<std::string>> resultPromise;
            m_node->invokeRemote("tb.simple.SimpleArrayInterface/funcString",
                nlohmann::json::array({paramString}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const std::list<std::string>& value = arg.value.get<std::list<std::string>>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

std::string RemoteSimpleArrayInterface::olinkObjectName()
{
    return "tb.simple.SimpleArrayInterface";
}

void RemoteSimpleArrayInterface::olinkOnSignal(std::string name, nlohmann::json args)
{
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    if(path == "sigBool") {
        m_publisher->publishSigBool(args[0].get<std::list<bool>>());   
        return;
    }
    if(path == "sigInt") {
        m_publisher->publishSigInt(args[0].get<std::list<int>>());   
        return;
    }
    if(path == "sigFloat") {
        m_publisher->publishSigFloat(args[0].get<std::list<float>>());   
        return;
    }
    if(path == "sigString") {
        m_publisher->publishSigString(args[0].get<std::list<std::string>>());   
        return;
    }
}

void RemoteSimpleArrayInterface::olinkOnPropertyChanged(std::string name, nlohmann::json value)
{
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    applyState({ {path, value} });
}
void RemoteSimpleArrayInterface::olinkOnInit(std::string name, nlohmann::json props, ApiGear::ObjectLink::IClientNode *node)
{
    (void) name; //suppress the 'Unreferenced Formal Parameter' warning.
    m_node = node;
    applyState(props);
}

void RemoteSimpleArrayInterface::olinkOnRelease()
{
    m_node = nullptr;
}

bool RemoteSimpleArrayInterface::isReady() const
{
    return m_node != nullptr;
}

ISimpleArrayInterfacePublisher& RemoteSimpleArrayInterface::_getPublisher() const
{
    return *m_publisher;
}
