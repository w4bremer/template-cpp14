

#include "tb_names/generated/core/names.threadsafedecorator.h"

using namespace Test::TbNames;
NamesThreadSafeDecorator::NamesThreadSafeDecorator(std::shared_ptr<INames> impl)
    : m_impl(impl)
{
}
void NamesThreadSafeDecorator::setSwitch(bool Switch)
{
    std::unique_lock<std::shared_timed_mutex> lock(m_switchMutex);
    m_impl->setSwitch(Switch);
}

bool NamesThreadSafeDecorator::getSwitch() const
{
    std::shared_lock<std::shared_timed_mutex> lock(m_switchMutex);
    return m_impl->getSwitch();
}

INamesPublisher& NamesThreadSafeDecorator::_getPublisher() const
{
    return m_impl->_getPublisher();
}