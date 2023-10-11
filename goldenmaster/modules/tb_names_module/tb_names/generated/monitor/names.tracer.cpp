#include "apigear/tracer/tracer.h"
#include "tb_names/generated/core/tb_names.json.adapter.h"
#include "tb_names/generated/monitor/names.tracer.h"

using namespace Test::TbNames;

NamesTracer::NamesTracer(ApiGear::PocoImpl::Tracer& tracer)
    : m_tracer(tracer)
{
}

void NamesTracer::capture_state(INames* obj)
{
    nlohmann::json fields_;
    fields_["Switch"] = obj->getSwitch();
    m_tracer.state("tb.names.Names#_state", fields_);
}