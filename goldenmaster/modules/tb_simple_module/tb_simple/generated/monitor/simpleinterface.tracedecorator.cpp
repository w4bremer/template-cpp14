

#include "tb_simple/generated/monitor/simpleinterface.tracedecorator.h"
#include "tb_simple/generated/monitor/simpleinterface.tracer.h"

using namespace Test::TbSimple;
SimpleInterfaceTraceDecorator::SimpleInterfaceTraceDecorator(ISimpleInterface& impl, ApiGear::PocoImpl::Tracer& tracer)
    : m_tracer(std::make_unique<SimpleInterfaceTracer>(tracer))
    , m_impl(impl)
{
        m_impl._getPublisher().subscribeToAllChanges(*this);
}
SimpleInterfaceTraceDecorator::~SimpleInterfaceTraceDecorator()
{
    m_impl._getPublisher().unsubscribeFromAllChanges(*this);
}

std::unique_ptr<SimpleInterfaceTraceDecorator> SimpleInterfaceTraceDecorator::connect(ISimpleInterface& impl, ApiGear::PocoImpl::Tracer& tracer)
{
    return std::unique_ptr<SimpleInterfaceTraceDecorator>(new SimpleInterfaceTraceDecorator(impl, tracer));
}
bool SimpleInterfaceTraceDecorator::funcBool(bool paramBool)
{
    m_tracer->trace_funcBool(paramBool);
    return m_impl.funcBool(paramBool);
}
std::future<bool> SimpleInterfaceTraceDecorator::funcBoolAsync(bool paramBool)
{
    m_tracer->trace_funcBool(paramBool);
    return m_impl.funcBoolAsync(paramBool);
}
int SimpleInterfaceTraceDecorator::funcInt(int paramInt)
{
    m_tracer->trace_funcInt(paramInt);
    return m_impl.funcInt(paramInt);
}
std::future<int> SimpleInterfaceTraceDecorator::funcIntAsync(int paramInt)
{
    m_tracer->trace_funcInt(paramInt);
    return m_impl.funcIntAsync(paramInt);
}
float SimpleInterfaceTraceDecorator::funcFloat(float paramFloat)
{
    m_tracer->trace_funcFloat(paramFloat);
    return m_impl.funcFloat(paramFloat);
}
std::future<float> SimpleInterfaceTraceDecorator::funcFloatAsync(float paramFloat)
{
    m_tracer->trace_funcFloat(paramFloat);
    return m_impl.funcFloatAsync(paramFloat);
}
std::string SimpleInterfaceTraceDecorator::funcString(const std::string& paramString)
{
    m_tracer->trace_funcString(paramString);
    return m_impl.funcString(paramString);
}
std::future<std::string> SimpleInterfaceTraceDecorator::funcStringAsync(const std::string& paramString)
{
    m_tracer->trace_funcString(paramString);
    return m_impl.funcStringAsync(paramString);
}
void SimpleInterfaceTraceDecorator::setPropBool(bool propBool)
{
    m_impl.setPropBool(propBool);
}

bool SimpleInterfaceTraceDecorator::getPropBool() const
{
    return m_impl.getPropBool();
}
void SimpleInterfaceTraceDecorator::setPropInt(int propInt)
{
    m_impl.setPropInt(propInt);
}

int SimpleInterfaceTraceDecorator::getPropInt() const
{
    return m_impl.getPropInt();
}
void SimpleInterfaceTraceDecorator::setPropFloat(float propFloat)
{
    m_impl.setPropFloat(propFloat);
}

float SimpleInterfaceTraceDecorator::getPropFloat() const
{
    return m_impl.getPropFloat();
}
void SimpleInterfaceTraceDecorator::setPropString(const std::string& propString)
{
    m_impl.setPropString(propString);
}

const std::string& SimpleInterfaceTraceDecorator::getPropString() const
{
    return m_impl.getPropString();
}
void SimpleInterfaceTraceDecorator::onSigBool(bool paramBool)
{
    m_tracer->trace_sigBool(paramBool);
}

void SimpleInterfaceTraceDecorator::onSigInt(int paramInt)
{
    m_tracer->trace_sigInt(paramInt);
}

void SimpleInterfaceTraceDecorator::onSigFloat(float paramFloat)
{
    m_tracer->trace_sigFloat(paramFloat);
}

void SimpleInterfaceTraceDecorator::onSigString(const std::string& paramString)
{
    m_tracer->trace_sigString(paramString);
}

void SimpleInterfaceTraceDecorator::onPropBoolChanged(bool propBool)
{
    (void) propBool; // suppress the 'Unreferenced Formal Parameter' warning.
    m_tracer->capture_state(this);
}

void SimpleInterfaceTraceDecorator::onPropIntChanged(int propInt)
{
    (void) propInt; // suppress the 'Unreferenced Formal Parameter' warning.
    m_tracer->capture_state(this);
}

void SimpleInterfaceTraceDecorator::onPropFloatChanged(float propFloat)
{
    (void) propFloat; // suppress the 'Unreferenced Formal Parameter' warning.
    m_tracer->capture_state(this);
}

void SimpleInterfaceTraceDecorator::onPropStringChanged(const std::string& propString)
{
    (void) propString; // suppress the 'Unreferenced Formal Parameter' warning.
    m_tracer->capture_state(this);
}



ISimpleInterfacePublisher& SimpleInterfaceTraceDecorator::_getPublisher() const
{
    return m_impl._getPublisher();
}
