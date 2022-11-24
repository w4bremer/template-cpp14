

#include "tb_simple/generated/core/nosignalsinterface.threadsafedecorator.h"

using namespace Test::TbSimple;
NoSignalsInterfaceThreadSafeDecorator::NoSignalsInterfaceThreadSafeDecorator(std::shared_ptr<INoSignalsInterface> impl)
    : m_impl(impl)
{
}
void NoSignalsInterfaceThreadSafeDecorator::funcVoid()
{
    return m_impl->funcVoid();
}

std::future<void> NoSignalsInterfaceThreadSafeDecorator::funcVoidAsync()
{
    return m_impl->funcVoidAsync();
}
bool NoSignalsInterfaceThreadSafeDecorator::funcBool(bool paramBool)
{
    return m_impl->funcBool(paramBool);
}

std::future<bool> NoSignalsInterfaceThreadSafeDecorator::funcBoolAsync(bool paramBool)
{
    return m_impl->funcBoolAsync(paramBool);
}
void NoSignalsInterfaceThreadSafeDecorator::setPropBool(bool propBool)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_propBoolMutex);
    m_impl->setPropBool(propBool);
}

bool NoSignalsInterfaceThreadSafeDecorator::getPropBool() const
{
    std::shared_lock<std::shared_timed_mutex> lock(m_propBoolMutex);
    return m_impl->getPropBool();
}
void NoSignalsInterfaceThreadSafeDecorator::setPropInt(int propInt)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_propIntMutex);
    m_impl->setPropInt(propInt);
}

int NoSignalsInterfaceThreadSafeDecorator::getPropInt() const
{
    std::shared_lock<std::shared_timed_mutex> lock(m_propIntMutex);
    return m_impl->getPropInt();
}

INoSignalsInterfacePublisher& NoSignalsInterfaceThreadSafeDecorator::_getPublisher() const
{
    return m_impl->_getPublisher();
}