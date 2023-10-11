

#include "tb_names/implementation/names.h"
#include "tb_names/generated/core/names.publisher.h"
#include "tb_names/generated/core/names.data.h"

using namespace Test::TbNames;

Names::Names()
    : m_publisher(std::make_unique<NamesPublisher>())
{
}
Names::~Names()
{
}

void Names::setSwitch(bool Switch)
{
    if (m_data.m_Switch != Switch) {
        m_data.m_Switch = Switch;
        m_publisher->publishSwitchChanged(Switch);
    }
}

bool Names::getSwitch() const
{
    return m_data.m_Switch;
}

INamesPublisher& Names::_getPublisher() const
{
    return *m_publisher;
}
