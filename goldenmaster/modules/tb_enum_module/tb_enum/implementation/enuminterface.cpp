

#include "tb_enum/implementation/enuminterface.h"
#include "tb_enum/generated/core/enuminterface.publisher.h"
#include "tb_enum/generated/core/enuminterface.data.h"

using namespace Test::TbEnum;

EnumInterface::EnumInterface()
    : m_publisher(std::make_unique<EnumInterfacePublisher>())
{
}
EnumInterface::~EnumInterface()
{
}

void EnumInterface::setProp0(const Enum0Enum& prop0)
{
    if (m_data.m_prop0 != prop0) {
        m_data.m_prop0 = prop0;
        m_publisher->publishProp0Changed(prop0);
    }
}

const Enum0Enum& EnumInterface::getProp0() const
{
    return m_data.m_prop0;
}

void EnumInterface::setProp1(const Enum1Enum& prop1)
{
    if (m_data.m_prop1 != prop1) {
        m_data.m_prop1 = prop1;
        m_publisher->publishProp1Changed(prop1);
    }
}

const Enum1Enum& EnumInterface::getProp1() const
{
    return m_data.m_prop1;
}

void EnumInterface::setProp2(const Enum2Enum& prop2)
{
    if (m_data.m_prop2 != prop2) {
        m_data.m_prop2 = prop2;
        m_publisher->publishProp2Changed(prop2);
    }
}

const Enum2Enum& EnumInterface::getProp2() const
{
    return m_data.m_prop2;
}

void EnumInterface::setProp3(const Enum3Enum& prop3)
{
    if (m_data.m_prop3 != prop3) {
        m_data.m_prop3 = prop3;
        m_publisher->publishProp3Changed(prop3);
    }
}

const Enum3Enum& EnumInterface::getProp3() const
{
    return m_data.m_prop3;
}

Enum0Enum EnumInterface::func0(const Enum0Enum& param0)
{
    (void) param0; // suppress the 'Unreferenced Formal Parameter' warning.
    // do business logic here
    return {};
}

std::future<Enum0Enum> EnumInterface::func0Async(const Enum0Enum& param0)
{
    return std::async(std::launch::async, [this,
                    param0]()
        {
            return func0(param0);
        }
    );
}

Enum1Enum EnumInterface::func1(const Enum1Enum& param1)
{
    (void) param1; // suppress the 'Unreferenced Formal Parameter' warning.
    // do business logic here
    return {};
}

std::future<Enum1Enum> EnumInterface::func1Async(const Enum1Enum& param1)
{
    return std::async(std::launch::async, [this,
                    param1]()
        {
            return func1(param1);
        }
    );
}

Enum2Enum EnumInterface::func2(const Enum2Enum& param2)
{
    (void) param2; // suppress the 'Unreferenced Formal Parameter' warning.
    // do business logic here
    return {};
}

std::future<Enum2Enum> EnumInterface::func2Async(const Enum2Enum& param2)
{
    return std::async(std::launch::async, [this,
                    param2]()
        {
            return func2(param2);
        }
    );
}

Enum3Enum EnumInterface::func3(const Enum3Enum& param3)
{
    (void) param3; // suppress the 'Unreferenced Formal Parameter' warning.
    // do business logic here
    return {};
}

std::future<Enum3Enum> EnumInterface::func3Async(const Enum3Enum& param3)
{
    return std::async(std::launch::async, [this,
                    param3]()
        {
            return func3(param3);
        }
    );
}

IEnumInterfacePublisher& EnumInterface::_getPublisher() const
{
    return *m_publisher;
}
