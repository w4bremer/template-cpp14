

#include "tb_simple/generated/olink/remotesimpleinterface.h"
#include "tb_simple/generated/core/simpleinterface.publisher.h"
#include "tb_simple/generated/core/tb_simple.json.adapter.h"

using namespace Test::TbSimple;
using namespace Test::TbSimple::olink;

RemoteSimpleInterface::RemoteSimpleInterface(ApiGear::ObjectLink::ClientRegistry& registry, ApiGear::PocoImpl::OLinkClient& client)
    : m_registry(registry),
      m_publisher(std::make_unique<SimpleInterfacePublisher>())
{
    m_registry.addObjectSink(this);
    client.linkObjectSource("tb.simple.SimpleInterface");
}

RemoteSimpleInterface::~RemoteSimpleInterface()
{
    m_registry.removeObjectSink(this);
}

void RemoteSimpleInterface::applyState(const nlohmann::json& fields) 
{
    if(fields.contains("propBool")) {
        setPropBoolLocal(fields["propBool"].get<bool>());
    }
    if(fields.contains("propInt")) {
        setPropIntLocal(fields["propInt"].get<int>());
    }
    if(fields.contains("propFloat")) {
        setPropFloatLocal(fields["propFloat"].get<float>());
    }
    if(fields.contains("propString")) {
        setPropStringLocal(fields["propString"].get<std::string>());
    }
}

void RemoteSimpleInterface::setPropBool(bool propBool)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("tb.simple.SimpleInterface/propBool", propBool);
}

void RemoteSimpleInterface::setPropBoolLocal(bool propBool)
{
    if (m_data.m_propBool != propBool) {
        m_data.m_propBool = propBool;
        m_publisher->publishPropBoolChanged(propBool);
    }
}

bool RemoteSimpleInterface::getPropBool() const
{
    return m_data.m_propBool;
}

void RemoteSimpleInterface::setPropInt(int propInt)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("tb.simple.SimpleInterface/propInt", propInt);
}

void RemoteSimpleInterface::setPropIntLocal(int propInt)
{
    if (m_data.m_propInt != propInt) {
        m_data.m_propInt = propInt;
        m_publisher->publishPropIntChanged(propInt);
    }
}

int RemoteSimpleInterface::getPropInt() const
{
    return m_data.m_propInt;
}

void RemoteSimpleInterface::setPropFloat(float propFloat)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("tb.simple.SimpleInterface/propFloat", propFloat);
}

void RemoteSimpleInterface::setPropFloatLocal(float propFloat)
{
    if (m_data.m_propFloat != propFloat) {
        m_data.m_propFloat = propFloat;
        m_publisher->publishPropFloatChanged(propFloat);
    }
}

float RemoteSimpleInterface::getPropFloat() const
{
    return m_data.m_propFloat;
}

void RemoteSimpleInterface::setPropString(const std::string& propString)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("tb.simple.SimpleInterface/propString", propString);
}

void RemoteSimpleInterface::setPropStringLocal(const std::string& propString)
{
    if (m_data.m_propString != propString) {
        m_data.m_propString = propString;
        m_publisher->publishPropStringChanged(propString);
    }
}

std::string RemoteSimpleInterface::getPropString() const
{
    return m_data.m_propString;
}

bool RemoteSimpleInterface::funcBool(bool paramBool)
{
    if(m_node == nullptr) {
        return false;
    }
    bool value(funcBoolAsync(paramBool).get());
    return value;
}

std::future<bool> RemoteSimpleInterface::funcBoolAsync(bool paramBool)
{
    if(m_node == nullptr) {
        throw std::runtime_error("Node is not initialized");
    }
    return std::async(std::launch::async, [this,
                    paramBool]()
        {
            std::promise<bool> resultPromise;
            m_node->invokeRemote("tb.simple.SimpleInterface/funcBool",
                nlohmann::json::array({paramBool}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const bool& value = arg.value.get<bool>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

int RemoteSimpleInterface::funcInt(int paramInt)
{
    if(m_node == nullptr) {
        return 0;
    }
    int value(funcIntAsync(paramInt).get());
    return value;
}

std::future<int> RemoteSimpleInterface::funcIntAsync(int paramInt)
{
    if(m_node == nullptr) {
        throw std::runtime_error("Node is not initialized");
    }
    return std::async(std::launch::async, [this,
                    paramInt]()
        {
            std::promise<int> resultPromise;
            m_node->invokeRemote("tb.simple.SimpleInterface/funcInt",
                nlohmann::json::array({paramInt}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const int& value = arg.value.get<int>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

float RemoteSimpleInterface::funcFloat(float paramFloat)
{
    if(m_node == nullptr) {
        return 0.0f;
    }
    float value(funcFloatAsync(paramFloat).get());
    return value;
}

std::future<float> RemoteSimpleInterface::funcFloatAsync(float paramFloat)
{
    if(m_node == nullptr) {
        throw std::runtime_error("Node is not initialized");
    }
    return std::async(std::launch::async, [this,
                    paramFloat]()
        {
            std::promise<float> resultPromise;
            m_node->invokeRemote("tb.simple.SimpleInterface/funcFloat",
                nlohmann::json::array({paramFloat}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const float& value = arg.value.get<float>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

std::string RemoteSimpleInterface::funcString(const std::string& paramString)
{
    if(m_node == nullptr) {
        return std::string();
    }
    std::string value(funcStringAsync(paramString).get());
    return value;
}

std::future<std::string> RemoteSimpleInterface::funcStringAsync(const std::string& paramString)
{
    if(m_node == nullptr) {
        throw std::runtime_error("Node is not initialized");
    }
    return std::async(std::launch::async, [this,
                    paramString]()
        {
            std::promise<std::string> resultPromise;
            m_node->invokeRemote("tb.simple.SimpleInterface/funcString",
                nlohmann::json::array({paramString}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const std::string& value = arg.value.get<std::string>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

std::string RemoteSimpleInterface::olinkObjectName()
{
    return "tb.simple.SimpleInterface";
}

void RemoteSimpleInterface::olinkOnSignal(std::string name, nlohmann::json args)
{
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    if(path == "sigBool") {
        m_publisher->publishSigBool(args[0].get<bool>());   
        return;
    }
    if(path == "sigInt") {
        m_publisher->publishSigInt(args[0].get<int>());   
        return;
    }
    if(path == "sigFloat") {
        m_publisher->publishSigFloat(args[0].get<float>());   
        return;
    }
    if(path == "sigString") {
        m_publisher->publishSigString(args[0].get<std::string>());   
        return;
    }
}

void RemoteSimpleInterface::olinkOnPropertyChanged(std::string name, nlohmann::json value)
{
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    applyState({ {path, value} });
}
void RemoteSimpleInterface::olinkOnInit(std::string name, nlohmann::json props, ApiGear::ObjectLink::IClientNode *node)
{
    (void) name; //suppress the 'Unreferenced Formal Parameter' warning.
    m_node = node;
    applyState(props);
}

void RemoteSimpleInterface::olinkOnRelease()
{
    m_node = nullptr;
}

bool RemoteSimpleInterface::isReady() const
{
    return m_node != nullptr;
}

ISimpleInterfacePublisher& RemoteSimpleInterface::_getPublisher() const
{
    return *m_publisher;
}
