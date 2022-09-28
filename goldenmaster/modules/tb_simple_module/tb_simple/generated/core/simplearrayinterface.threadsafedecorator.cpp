

#include "tb_simple/generated/core/simplearrayinterface.threadsafedecorator.h"

using namespace Test::TbSimple;
SimpleArrayInterfaceThreadSafeDecorator::SimpleArrayInterfaceThreadSafeDecorator(std::shared_ptr<ISimpleArrayInterface> impl)
    : m_impl(impl)
{
}
std::list<bool> SimpleArrayInterfaceThreadSafeDecorator::funcBool(const std::list<bool>& paramBool)
{
    return m_impl->funcBool(paramBool);
}

std::future<std::list<bool>> SimpleArrayInterfaceThreadSafeDecorator::funcBoolAsync(const std::list<bool>& paramBool)
{
    return m_impl->funcBoolAsync(paramBool);
}
std::list<int> SimpleArrayInterfaceThreadSafeDecorator::funcInt(const std::list<int>& paramInt)
{
    return m_impl->funcInt(paramInt);
}

std::future<std::list<int>> SimpleArrayInterfaceThreadSafeDecorator::funcIntAsync(const std::list<int>& paramInt)
{
    return m_impl->funcIntAsync(paramInt);
}
std::list<float> SimpleArrayInterfaceThreadSafeDecorator::funcFloat(const std::list<float>& paramFloat)
{
    return m_impl->funcFloat(paramFloat);
}

std::future<std::list<float>> SimpleArrayInterfaceThreadSafeDecorator::funcFloatAsync(const std::list<float>& paramFloat)
{
    return m_impl->funcFloatAsync(paramFloat);
}
std::list<std::string> SimpleArrayInterfaceThreadSafeDecorator::funcString(const std::list<std::string>& paramString)
{
    return m_impl->funcString(paramString);
}

std::future<std::list<std::string>> SimpleArrayInterfaceThreadSafeDecorator::funcStringAsync(const std::list<std::string>& paramString)
{
    return m_impl->funcStringAsync(paramString);
}
void SimpleArrayInterfaceThreadSafeDecorator::setPropBool(const std::list<bool>& propBool)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_propBoolMutex);
    m_impl->setPropBool(propBool);
}

const std::list<bool>& SimpleArrayInterfaceThreadSafeDecorator::getPropBool() const
{
    std::shared_lock<std::shared_timed_mutex> lock(m_propBoolMutex);
    return m_impl->getPropBool();
}
void SimpleArrayInterfaceThreadSafeDecorator::setPropInt(const std::list<int>& propInt)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_propIntMutex);
    m_impl->setPropInt(propInt);
}

const std::list<int>& SimpleArrayInterfaceThreadSafeDecorator::getPropInt() const
{
    std::shared_lock<std::shared_timed_mutex> lock(m_propIntMutex);
    return m_impl->getPropInt();
}
void SimpleArrayInterfaceThreadSafeDecorator::setPropFloat(const std::list<float>& propFloat)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_propFloatMutex);
    m_impl->setPropFloat(propFloat);
}

const std::list<float>& SimpleArrayInterfaceThreadSafeDecorator::getPropFloat() const
{
    std::shared_lock<std::shared_timed_mutex> lock(m_propFloatMutex);
    return m_impl->getPropFloat();
}
void SimpleArrayInterfaceThreadSafeDecorator::setPropString(const std::list<std::string>& propString)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_propStringMutex);
    m_impl->setPropString(propString);
}

const std::list<std::string>& SimpleArrayInterfaceThreadSafeDecorator::getPropString() const
{
    std::shared_lock<std::shared_timed_mutex> lock(m_propStringMutex);
    return m_impl->getPropString();
}

ISimpleArrayInterfacePublisher& SimpleArrayInterfaceThreadSafeDecorator::_getPublisher() const
{
    return m_impl->_getPublisher();
}