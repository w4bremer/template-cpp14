

#include "tb_names/generated/monitor/names.tracedecorator.h"
#include "tb_names/generated/monitor/names.tracer.h"

using namespace Test::TbNames;
NamesTraceDecorator::NamesTraceDecorator(INames& impl, ApiGear::PocoImpl::Tracer& tracer)
    : m_tracer(std::make_unique<NamesTracer>(tracer))
    , m_impl(impl)
{
        m_impl._getPublisher().subscribeToAllChanges(*this);
}
NamesTraceDecorator::~NamesTraceDecorator()
{
    m_impl._getPublisher().unsubscribeFromAllChanges(*this);
}

std::unique_ptr<NamesTraceDecorator> NamesTraceDecorator::connect(INames& impl, ApiGear::PocoImpl::Tracer& tracer)
{
    return std::unique_ptr<NamesTraceDecorator>(new NamesTraceDecorator(impl, tracer));
}
void NamesTraceDecorator::setSwitch(bool Switch)
{
    m_impl.setSwitch(Switch);
}

bool NamesTraceDecorator::getSwitch() const
{
    return m_impl.getSwitch();
}
void NamesTraceDecorator::onSwitchChanged(bool Switch)
{
    (void) Switch; // suppress the 'Unreferenced Formal Parameter' warning.
    m_tracer->capture_state(this);
}



INamesPublisher& NamesTraceDecorator::_getPublisher() const
{
    return m_impl._getPublisher();
}
