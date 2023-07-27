

#include "testbed2/implementation/nestedstruct2interface.h"
#include "testbed2/generated/core/nestedstruct2interface.publisher.h"
#include "testbed2/generated/core/nestedstruct2interface.data.h"

using namespace Test::Testbed2;

NestedStruct2Interface::NestedStruct2Interface()
    : m_publisher(std::make_unique<NestedStruct2InterfacePublisher>())
{
}
NestedStruct2Interface::~NestedStruct2Interface()
{
}

void NestedStruct2Interface::setProp1(const NestedStruct1& prop1)
{
    if (m_data.m_prop1 != prop1) {
        m_data.m_prop1 = prop1;
        m_publisher->publishProp1Changed(prop1);
    }
}

const NestedStruct1& NestedStruct2Interface::getProp1() const
{
    return m_data.m_prop1;
}

void NestedStruct2Interface::setProp2(const NestedStruct2& prop2)
{
    if (m_data.m_prop2 != prop2) {
        m_data.m_prop2 = prop2;
        m_publisher->publishProp2Changed(prop2);
    }
}

const NestedStruct2& NestedStruct2Interface::getProp2() const
{
    return m_data.m_prop2;
}

NestedStruct1 NestedStruct2Interface::func1(const NestedStruct1& param1)
{
    NestedStruct1 out = param1;
    // do business logic here
    out.field1.field1 += 1;
    return out;
}

std::future<NestedStruct1> NestedStruct2Interface::func1Async(const NestedStruct1& param1)
{
    return std::async(std::launch::async, [this,
                    param1]()
        {
            return func1(param1);
        }
    );
}

NestedStruct1 NestedStruct2Interface::func2(const NestedStruct1& param1, const NestedStruct2& param2)
{
    (void) param1; // suppress the 'Unreferenced Formal Parameter' warning.
    (void) param2; // suppress the 'Unreferenced Formal Parameter' warning.
    // do business logic here
    return NestedStruct1();
}

std::future<NestedStruct1> NestedStruct2Interface::func2Async(const NestedStruct1& param1, const NestedStruct2& param2)
{
    return std::async(std::launch::async, [this,
                    param1,
                    param2]()
        {
            return func2(param1, param2);
        }
    );
}

INestedStruct2InterfacePublisher& NestedStruct2Interface::_getPublisher() const
{
    return *m_publisher;
}
