

#include "tb_simple/generated/monitor/simplearrayinterface.tracedecorator.h"
#include "tb_simple/generated/monitor/simplearrayinterface.tracer.h"

using namespace Test::TbSimple;
SimpleArrayInterfaceTraceDecorator::SimpleArrayInterfaceTraceDecorator(ISimpleArrayInterface& impl, ApiGear::PocoImpl::Tracer& tracer)
    : m_tracer(std::make_unique<SimpleArrayInterfaceTracer>(tracer))
    , m_impl(impl)
{
        m_impl._getPublisher().subscribeToAllChanges(*this);
}
SimpleArrayInterfaceTraceDecorator::~SimpleArrayInterfaceTraceDecorator()
{
    m_impl._getPublisher().unsubscribeFromAllChanges(*this);
}

std::unique_ptr<SimpleArrayInterfaceTraceDecorator> SimpleArrayInterfaceTraceDecorator::connect(ISimpleArrayInterface& impl, ApiGear::PocoImpl::Tracer& tracer)
{
    return std::unique_ptr<SimpleArrayInterfaceTraceDecorator>(new SimpleArrayInterfaceTraceDecorator(impl, tracer));
}
std::list<bool> SimpleArrayInterfaceTraceDecorator::funcBool(const std::list<bool>& paramBool)
{
    m_tracer->trace_funcBool(paramBool);
    return m_impl.funcBool(paramBool);
}
std::future<std::list<bool>> SimpleArrayInterfaceTraceDecorator::funcBoolAsync(const std::list<bool>& paramBool)
{
    m_tracer->trace_funcBool(paramBool);
    return m_impl.funcBoolAsync(paramBool);
}
std::list<int> SimpleArrayInterfaceTraceDecorator::funcInt(const std::list<int>& paramInt)
{
    m_tracer->trace_funcInt(paramInt);
    return m_impl.funcInt(paramInt);
}
std::future<std::list<int>> SimpleArrayInterfaceTraceDecorator::funcIntAsync(const std::list<int>& paramInt)
{
    m_tracer->trace_funcInt(paramInt);
    return m_impl.funcIntAsync(paramInt);
}
std::list<float> SimpleArrayInterfaceTraceDecorator::funcFloat(const std::list<float>& paramFloat)
{
    m_tracer->trace_funcFloat(paramFloat);
    return m_impl.funcFloat(paramFloat);
}
std::future<std::list<float>> SimpleArrayInterfaceTraceDecorator::funcFloatAsync(const std::list<float>& paramFloat)
{
    m_tracer->trace_funcFloat(paramFloat);
    return m_impl.funcFloatAsync(paramFloat);
}
std::list<std::string> SimpleArrayInterfaceTraceDecorator::funcString(const std::list<std::string>& paramString)
{
    m_tracer->trace_funcString(paramString);
    return m_impl.funcString(paramString);
}
std::future<std::list<std::string>> SimpleArrayInterfaceTraceDecorator::funcStringAsync(const std::list<std::string>& paramString)
{
    m_tracer->trace_funcString(paramString);
    return m_impl.funcStringAsync(paramString);
}
void SimpleArrayInterfaceTraceDecorator::setPropBool(const std::list<bool>& propBool)
{
    m_impl.setPropBool(propBool);
}

const std::list<bool>& SimpleArrayInterfaceTraceDecorator::getPropBool() const
{
    return m_impl.getPropBool();
}
void SimpleArrayInterfaceTraceDecorator::setPropInt(const std::list<int>& propInt)
{
    m_impl.setPropInt(propInt);
}

const std::list<int>& SimpleArrayInterfaceTraceDecorator::getPropInt() const
{
    return m_impl.getPropInt();
}
void SimpleArrayInterfaceTraceDecorator::setPropFloat(const std::list<float>& propFloat)
{
    m_impl.setPropFloat(propFloat);
}

const std::list<float>& SimpleArrayInterfaceTraceDecorator::getPropFloat() const
{
    return m_impl.getPropFloat();
}
void SimpleArrayInterfaceTraceDecorator::setPropString(const std::list<std::string>& propString)
{
    m_impl.setPropString(propString);
}

const std::list<std::string>& SimpleArrayInterfaceTraceDecorator::getPropString() const
{
    return m_impl.getPropString();
}
void SimpleArrayInterfaceTraceDecorator::onSigBool(const std::list<bool>& paramBool)
{
    m_tracer->trace_sigBool(paramBool);
}

void SimpleArrayInterfaceTraceDecorator::onSigInt(const std::list<int>& paramInt)
{
    m_tracer->trace_sigInt(paramInt);
}

void SimpleArrayInterfaceTraceDecorator::onSigFloat(const std::list<float>& paramFloat)
{
    m_tracer->trace_sigFloat(paramFloat);
}

void SimpleArrayInterfaceTraceDecorator::onSigString(const std::list<std::string>& paramString)
{
    m_tracer->trace_sigString(paramString);
}

void SimpleArrayInterfaceTraceDecorator::onPropBoolChanged(const std::list<bool>& propBool)
{
    (void) propBool; // suppress the 'Unreferenced Formal Parameter' warning.
    m_tracer->capture_state(this);
}

void SimpleArrayInterfaceTraceDecorator::onPropIntChanged(const std::list<int>& propInt)
{
    (void) propInt; // suppress the 'Unreferenced Formal Parameter' warning.
    m_tracer->capture_state(this);
}

void SimpleArrayInterfaceTraceDecorator::onPropFloatChanged(const std::list<float>& propFloat)
{
    (void) propFloat; // suppress the 'Unreferenced Formal Parameter' warning.
    m_tracer->capture_state(this);
}

void SimpleArrayInterfaceTraceDecorator::onPropStringChanged(const std::list<std::string>& propString)
{
    (void) propString; // suppress the 'Unreferenced Formal Parameter' warning.
    m_tracer->capture_state(this);
}



ISimpleArrayInterfacePublisher& SimpleArrayInterfaceTraceDecorator::_getPublisher() const
{
    return m_impl._getPublisher();
}
