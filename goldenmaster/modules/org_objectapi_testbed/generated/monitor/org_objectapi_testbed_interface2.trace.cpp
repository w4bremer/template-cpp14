/**
NO TITLE
Copyright (C) 2020 ApiGear UG

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/


#include "org_objectapi_testbed_interface2.trace.h"
#include "org_objectapi_testbed.trace.h"

using namespace Test::OrgObjectapiTestbed;
Interface2TracerDecorator::Interface2TracerDecorator(IInterface2* impl, ApiGear::PocoImpl::Tracer* tracer)
    : AbstractInterface2Decorator(impl)
    , m_tracer(std::make_unique<Interface2Tracer>(tracer))
{
}
Interface2TracerDecorator::~Interface2TracerDecorator() = default;
Interface2TracerDecorator* Interface2TracerDecorator::connect(IInterface2* impl, ApiGear::PocoImpl::Tracer* tracer)
{
    return new Interface2TracerDecorator(impl, tracer);
}
void Interface2TracerDecorator::OnProp200Changed(int)
{
    m_tracer->capture_state(this);
}
void Interface2TracerDecorator::OnProp201Changed(int)
{
    m_tracer->capture_state(this);
}
void Interface2TracerDecorator::OnProp202Changed(int)
{
    m_tracer->capture_state(this);
}
void Interface2TracerDecorator::OnProp203Changed(float)
{
    m_tracer->capture_state(this);
}
void Interface2TracerDecorator::OnProp204Changed(float)
{
    m_tracer->capture_state(this);
}
void Interface2TracerDecorator::OnProp205Changed(std::string)
{
    m_tracer->capture_state(this);
}
