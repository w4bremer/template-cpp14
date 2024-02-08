

#include "tb_simple/generated/monitor/nooperationsinterface.tracedecorator.h"
#include "tb_simple/generated/monitor/nooperationsinterface.tracer.h"

using namespace Test::TbSimple;
NoOperationsInterfaceTraceDecorator::NoOperationsInterfaceTraceDecorator(INoOperationsInterface& impl, ApiGear::PocoImpl::Tracer& tracer)
    : m_tracer(std::make_unique<NoOperationsInterfaceTracer>(tracer))
    , m_impl(impl)
{
        m_impl._getPublisher().subscribeToAllChanges(*this);
}
NoOperationsInterfaceTraceDecorator::~NoOperationsInterfaceTraceDecorator()
{
    m_impl._getPublisher().unsubscribeFromAllChanges(*this);
}

std::unique_ptr<NoOperationsInterfaceTraceDecorator> NoOperationsInterfaceTraceDecorator::connect(INoOperationsInterface& impl, ApiGear::PocoImpl::Tracer& tracer)
{
    return std::unique_ptr<NoOperationsInterfaceTraceDecorator>(new NoOperationsInterfaceTraceDecorator(impl, tracer));
}
void NoOperationsInterfaceTraceDecorator::setPropBool(bool propBool)
{
    m_impl.setPropBool(propBool);
}

bool NoOperationsInterfaceTraceDecorator::getPropBool() const
{
    return m_impl.getPropBool();
}
void NoOperationsInterfaceTraceDecorator::setPropInt(int propInt)
{
    m_impl.setPropInt(propInt);
}

int NoOperationsInterfaceTraceDecorator::getPropInt() const
{
    return m_impl.getPropInt();
}
void NoOperationsInterfaceTraceDecorator::onSigVoid()
{
    m_tracer->trace_sigVoid();
}

void NoOperationsInterfaceTraceDecorator::onSigBool(bool paramBool)
{
    m_tracer->trace_sigBool(paramBool);
}

void NoOperationsInterfaceTraceDecorator::onPropBoolChanged(bool propBool)
{
    (void) propBool; // suppress the 'Unreferenced Formal Parameter' warning.
    m_tracer->capture_state(this);
}

void NoOperationsInterfaceTraceDecorator::onPropIntChanged(int propInt)
{
    (void) propInt; // suppress the 'Unreferenced Formal Parameter' warning.
    m_tracer->capture_state(this);
}



INoOperationsInterfacePublisher& NoOperationsInterfaceTraceDecorator::_getPublisher() const
{
    return m_impl._getPublisher();
}
