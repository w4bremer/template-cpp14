

#include "tb_simple/implementation/simpleinterface.h"
#include "tb_simple/generated/core/simpleinterface.publisher.h"
#include "tb_simple/generated/core/simpleinterface.data.h"

using namespace Test::TbSimple;

SimpleInterface::SimpleInterface()
    : m_publisher(std::make_unique<SimpleInterfacePublisher>())
{
}
SimpleInterface::~SimpleInterface()
{
}

void SimpleInterface::setPropBool(bool propBool)
{
    if (m_data.m_propBool != propBool) {
        m_data.m_propBool = propBool;
        m_publisher->publishPropBoolChanged(propBool);
    }
}

bool SimpleInterface::getPropBool() const
{
    return m_data.m_propBool;
}

void SimpleInterface::setPropInt(int propInt)
{
    if (m_data.m_propInt != propInt) {
        m_data.m_propInt = propInt;
        m_publisher->publishPropIntChanged(propInt);
    }
}

int SimpleInterface::getPropInt() const
{
    return m_data.m_propInt;
}

void SimpleInterface::setPropFloat(float propFloat)
{
    if (m_data.m_propFloat != propFloat) {
        m_data.m_propFloat = propFloat;
        m_publisher->publishPropFloatChanged(propFloat);
    }
}

float SimpleInterface::getPropFloat() const
{
    return m_data.m_propFloat;
}

void SimpleInterface::setPropString(const std::string& propString)
{
    if (m_data.m_propString != propString) {
        m_data.m_propString = propString;
        m_publisher->publishPropStringChanged(propString);
    }
}

std::string SimpleInterface::getPropString() const
{
    return m_data.m_propString;
}

bool SimpleInterface::funcBool(bool paramBool)
{
    (void) paramBool; // suppress the 'Unreferenced Formal Parameter' warning.
    // do business logic here
    return {};
}

std::future<bool> SimpleInterface::funcBoolAsync(bool paramBool)
{
    return std::async(std::launch::async, [this,
                    paramBool]()
        {
            return funcBool(paramBool);
        }
    );
}

int SimpleInterface::funcInt(int paramInt)
{
    (void) paramInt; // suppress the 'Unreferenced Formal Parameter' warning.
    // do business logic here
    return {};
}

std::future<int> SimpleInterface::funcIntAsync(int paramInt)
{
    return std::async(std::launch::async, [this,
                    paramInt]()
        {
            return funcInt(paramInt);
        }
    );
}

float SimpleInterface::funcFloat(float paramFloat)
{
    (void) paramFloat; // suppress the 'Unreferenced Formal Parameter' warning.
    // do business logic here
    return {};
}

std::future<float> SimpleInterface::funcFloatAsync(float paramFloat)
{
    return std::async(std::launch::async, [this,
                    paramFloat]()
        {
            return funcFloat(paramFloat);
        }
    );
}

std::string SimpleInterface::funcString(const std::string& paramString)
{
    (void) paramString; // suppress the 'Unreferenced Formal Parameter' warning.
    // do business logic here
    return {};
}

std::future<std::string> SimpleInterface::funcStringAsync(const std::string& paramString)
{
    return std::async(std::launch::async, [this,
                    paramString]()
        {
            return funcString(paramString);
        }
    );
}

ISimpleInterfacePublisher& SimpleInterface::_getPublisher() const
{
    return *m_publisher;
}
