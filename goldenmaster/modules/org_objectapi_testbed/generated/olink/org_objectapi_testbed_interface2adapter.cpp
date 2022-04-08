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


#include <iostream>
#include "org_objectapi_testbed_interface2adapter.h"

//#include "../api/agent.h"
#include "generated/core/org_objectapi_testbed.json.adapter.h"

using namespace Test::OrgObjectapiTestbed;

OLinkInterface2Adapter::OLinkInterface2Adapter(IInterface2* impl, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_impl(impl)
    , m_node(nullptr)
    , m_registry(&registry)
{
    m_impl->_getPublisher()->subscribeToInterface2Interface(*this);
    m_registry->addObjectSource(this);
}

OLinkInterface2Adapter::~OLinkInterface2Adapter()
{
    m_registry->removeObjectSource(this);
    m_impl->_getPublisher()->unsubscribeFromInterface2Interface(*this);
}

nlohmann::json OLinkInterface2Adapter::captureState()
{
    return nlohmann::json::object({
        { "prop200", m_impl->prop200() },
        { "prop201", m_impl->prop201() },
        { "prop202", m_impl->prop202() },
        { "prop203", m_impl->prop203() },
        { "prop204", m_impl->prop204() },
        { "prop205", m_impl->prop205() }
    });
}

void OLinkInterface2Adapter::applyState(const nlohmann::json& state)
{
    if(state.contains("prop200")) {
        m_impl->setProp200(state["prop200"]);
    }
    if(state.contains("prop201")) {
        m_impl->setProp201(state["prop201"]);
    }
    if(state.contains("prop202")) {
        m_impl->setProp202(state["prop202"]);
    }
    if(state.contains("prop203")) {
        m_impl->setProp203(state["prop203"]);
    }
    if(state.contains("prop204")) {
        m_impl->setProp204(state["prop204"]);
    }
    if(state.contains("prop205")) {
        m_impl->setProp205(state["prop205"]);
    }
}


std::string OLinkInterface2Adapter::olinkObjectName() {
    return "org.objectapi.testbed.Interface2";
}

nlohmann::json OLinkInterface2Adapter::olinkInvoke(std::string fcnName, nlohmann::json fcnArgs) {
    std::clog << fcnName << std::endl;
    std::string path = ApiGear::ObjectLink::Name::pathFromName(fcnName);
    // no operations to invoke
    (void) fcnArgs;
    return nlohmann::json();
}

void OLinkInterface2Adapter::olinkSetProperty(std::string name, nlohmann::json value) {
    std::clog << name << std::endl;
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    if(path == "prop200") {
        int prop200 = value.get<int>();
        m_impl->setProp200(prop200);
    }
    if(path == "prop201") {
        int prop201 = value.get<int>();
        m_impl->setProp201(prop201);
    }
    if(path == "prop202") {
        int prop202 = value.get<int>();
        m_impl->setProp202(prop202);
    }
    if(path == "prop203") {
        float prop203 = value.get<float>();
        m_impl->setProp203(prop203);
    }
    if(path == "prop204") {
        float prop204 = value.get<float>();
        m_impl->setProp204(prop204);
    }
    if(path == "prop205") {
        std::string prop205 = value.get<std::string>();
        m_impl->setProp205(prop205);
    } 
}

void OLinkInterface2Adapter::olinkLinked(std::string name, ApiGear::ObjectLink::IRemoteNode *node) {
    std::clog << name << std::endl;
    m_node = node;
}

void OLinkInterface2Adapter::olinkUnlinked(std::string name)
{
    std::clog << name << std::endl;
    m_node = nullptr;
}

nlohmann::json OLinkInterface2Adapter::olinkCollectProperties()
{
    return captureState();
}
void OLinkInterface2Adapter::OnProp200Changed(int prop200)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("org.objectapi.testbed.Interface2/prop200", prop200);
    }
}
void OLinkInterface2Adapter::OnProp201Changed(int prop201)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("org.objectapi.testbed.Interface2/prop201", prop201);
    }
}
void OLinkInterface2Adapter::OnProp202Changed(int prop202)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("org.objectapi.testbed.Interface2/prop202", prop202);
    }
}
void OLinkInterface2Adapter::OnProp203Changed(float prop203)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("org.objectapi.testbed.Interface2/prop203", prop203);
    }
}
void OLinkInterface2Adapter::OnProp204Changed(float prop204)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("org.objectapi.testbed.Interface2/prop204", prop204);
    }
}
void OLinkInterface2Adapter::OnProp205Changed(std::string prop205)
{
    if(m_node != nullptr) {
        m_node->notifyPropertyChange("org.objectapi.testbed.Interface2/prop205", prop205);
    }
}

