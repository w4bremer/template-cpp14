

#include "tb_enum/generated/olink/remoteenuminterface.h"
#include "tb_enum/generated/core/enuminterface.publisher.h"
#include "tb_enum/generated/core/tb_enum.json.adapter.h"

using namespace Test::TbEnum;
using namespace Test::TbEnum::olink;

RemoteEnumInterface::RemoteEnumInterface(ApiGear::ObjectLink::ClientRegistry& registry, ApiGear::PocoImpl::OLinkClient& client)
    : m_registry(registry),
      m_publisher(std::make_unique<EnumInterfacePublisher>())
{
    m_registry.addObjectSink(this);
    client.linkObjectSource("tb.enum.EnumInterface");
}

RemoteEnumInterface::~RemoteEnumInterface()
{
    m_registry.removeObjectSink(this);
}

void RemoteEnumInterface::applyState(const nlohmann::json& fields) 
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

void RemoteEnumInterface::setProp0(const Enum0Enum& prop0)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("tb.enum.EnumInterface/prop0", prop0);
}

void RemoteEnumInterface::setProp0Local(const Enum0Enum& prop0)
{
    if (m_data.m_prop0 != prop0) {
        m_data.m_prop0 = prop0;
        m_publisher->publishProp0Changed(prop0);
    }
}

const Enum0Enum& RemoteEnumInterface::prop0() const
{
    return m_data.m_prop0;
}

void RemoteEnumInterface::setProp1(const Enum1Enum& prop1)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("tb.enum.EnumInterface/prop1", prop1);
}

void RemoteEnumInterface::setProp1Local(const Enum1Enum& prop1)
{
    if (m_data.m_prop1 != prop1) {
        m_data.m_prop1 = prop1;
        m_publisher->publishProp1Changed(prop1);
    }
}

const Enum1Enum& RemoteEnumInterface::prop1() const
{
    return m_data.m_prop1;
}

void RemoteEnumInterface::setProp2(const Enum2Enum& prop2)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("tb.enum.EnumInterface/prop2", prop2);
}

void RemoteEnumInterface::setProp2Local(const Enum2Enum& prop2)
{
    if (m_data.m_prop2 != prop2) {
        m_data.m_prop2 = prop2;
        m_publisher->publishProp2Changed(prop2);
    }
}

const Enum2Enum& RemoteEnumInterface::prop2() const
{
    return m_data.m_prop2;
}

void RemoteEnumInterface::setProp3(const Enum3Enum& prop3)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("tb.enum.EnumInterface/prop3", prop3);
}

void RemoteEnumInterface::setProp3Local(const Enum3Enum& prop3)
{
    if (m_data.m_prop3 != prop3) {
        m_data.m_prop3 = prop3;
        m_publisher->publishProp3Changed(prop3);
    }
}

const Enum3Enum& RemoteEnumInterface::prop3() const
{
    return m_data.m_prop3;
}

Enum0Enum RemoteEnumInterface::func0(const Enum0Enum& param0)
{
    if(m_node == nullptr) {
        return Enum0Enum::value0;
    }
    Enum0Enum value(func0Async(param0).get());
    return value;
}

std::future<Enum0Enum> RemoteEnumInterface::func0Async(const Enum0Enum& param0)
{
    if(m_node == nullptr) {
        throw std::runtime_error("Node is not initialized");
    }
    return std::async(std::launch::async, [this,
                    param0]()
        {
            std::promise<Enum0Enum> resultPromise;
            m_node->invokeRemote("tb.enum.EnumInterface/func0",
                nlohmann::json::array({param0}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const Enum0Enum& value = arg.value.get<Enum0Enum>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

Enum1Enum RemoteEnumInterface::func1(const Enum1Enum& param1)
{
    if(m_node == nullptr) {
        return Enum1Enum::value1;
    }
    Enum1Enum value(func1Async(param1).get());
    return value;
}

std::future<Enum1Enum> RemoteEnumInterface::func1Async(const Enum1Enum& param1)
{
    if(m_node == nullptr) {
        throw std::runtime_error("Node is not initialized");
    }
    return std::async(std::launch::async, [this,
                    param1]()
        {
            std::promise<Enum1Enum> resultPromise;
            m_node->invokeRemote("tb.enum.EnumInterface/func1",
                nlohmann::json::array({param1}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const Enum1Enum& value = arg.value.get<Enum1Enum>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

Enum2Enum RemoteEnumInterface::func2(const Enum2Enum& param2)
{
    if(m_node == nullptr) {
        return Enum2Enum::value2;
    }
    Enum2Enum value(func2Async(param2).get());
    return value;
}

std::future<Enum2Enum> RemoteEnumInterface::func2Async(const Enum2Enum& param2)
{
    if(m_node == nullptr) {
        throw std::runtime_error("Node is not initialized");
    }
    return std::async(std::launch::async, [this,
                    param2]()
        {
            std::promise<Enum2Enum> resultPromise;
            m_node->invokeRemote("tb.enum.EnumInterface/func2",
                nlohmann::json::array({param2}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const Enum2Enum& value = arg.value.get<Enum2Enum>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

Enum3Enum RemoteEnumInterface::func3(const Enum3Enum& param3)
{
    if(m_node == nullptr) {
        return Enum3Enum::value3;
    }
    Enum3Enum value(func3Async(param3).get());
    return value;
}

std::future<Enum3Enum> RemoteEnumInterface::func3Async(const Enum3Enum& param3)
{
    if(m_node == nullptr) {
        throw std::runtime_error("Node is not initialized");
    }
    return std::async(std::launch::async, [this,
                    param3]()
        {
            std::promise<Enum3Enum> resultPromise;
            m_node->invokeRemote("tb.enum.EnumInterface/func3",
                nlohmann::json::array({param3}), [&resultPromise](ApiGear::ObjectLink::InvokeReplyArg arg) {
                    const Enum3Enum& value = arg.value.get<Enum3Enum>();
                    resultPromise.set_value(value);
                });
            return resultPromise.get_future().get();
        }
    );
}

std::string RemoteEnumInterface::olinkObjectName()
{
    return "tb.enum.EnumInterface";
}

void RemoteEnumInterface::olinkOnSignal(std::string name, nlohmann::json args)
{
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    if(path == "sig0") {
        m_publisher->publishSig0(args[0].get<Enum0Enum>());   
        return;
    }
    if(path == "sig1") {
        m_publisher->publishSig1(args[0].get<Enum1Enum>());   
        return;
    }
    if(path == "sig2") {
        m_publisher->publishSig2(args[0].get<Enum2Enum>());   
        return;
    }
    if(path == "sig3") {
        m_publisher->publishSig3(args[0].get<Enum3Enum>());   
        return;
    }
}

void RemoteEnumInterface::olinkOnPropertyChanged(std::string name, nlohmann::json value)
{
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    applyState({ {path, value} });
}
void RemoteEnumInterface::olinkOnInit(std::string name, nlohmann::json props, ApiGear::ObjectLink::IClientNode *node)
{
    (void) name; //suppress the 'Unreferenced Formal Parameter' warning.
    m_node = node;
    applyState(props);
}

void RemoteEnumInterface::olinkOnRelease()
{
    m_node = nullptr;
}

bool RemoteEnumInterface::isReady() const
{
    return m_node != nullptr;
}

IEnumInterfacePublisher& RemoteEnumInterface::_getPublisher() const
{
    return *m_publisher;
}
