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



#include "org_objectapi_testbed_interface2interface.h"

#include "generated/core/org_objectapi_testbed.json.adapter.h"

using namespace Test::OrgObjectapiTestbed;

OLinkInterface2::OLinkInterface2(ApiGear::ObjectLink::ClientRegistry& registry, ApiGear::PocoImpl::OLinkClient& client)
    : m_isReady(false)
    , m_prop200(0)
    , m_prop201(0)
    , m_prop202(0)
    , m_prop203(0.0f)
    , m_prop204(0.0f)
    , m_prop205(std::string())
    , m_node(nullptr)
    , m_registry(&registry)
    , m_publisher(new Interface2Publisher())
{
    m_node = m_registry->addObjectSink(this);
    client.linkObjectSource("org.objectapi.testbed.Interface2");
}

OLinkInterface2::~OLinkInterface2()
{
    m_registry->removeObjectSink(this);
}

void OLinkInterface2::applyState(const nlohmann::json& fields) 
{
    if(fields.contains("prop200")) {
        setProp200Local(fields["prop200"].get<int>());
    }
    if(fields.contains("prop201")) {
        setProp201Local(fields["prop201"].get<int>());
    }
    if(fields.contains("prop202")) {
        setProp202Local(fields["prop202"].get<int>());
    }
    if(fields.contains("prop203")) {
        setProp203Local(fields["prop203"].get<float>());
    }
    if(fields.contains("prop204")) {
        setProp204Local(fields["prop204"].get<float>());
    }
    if(fields.contains("prop205")) {
        setProp205Local(fields["prop205"].get<std::string>());
    }
}

void OLinkInterface2::setProp200(int prop200)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("org.objectapi.testbed.Interface2/prop200", prop200);
}

void OLinkInterface2::setProp200Local(int prop200)
{
    if (m_prop200 != prop200) {
        m_prop200 = prop200;
        m_publisher->publishProp200Changed(prop200);
    }
}

int OLinkInterface2::prop200() const
{
    return m_prop200;
}

void OLinkInterface2::setProp201(int prop201)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("org.objectapi.testbed.Interface2/prop201", prop201);
}

void OLinkInterface2::setProp201Local(int prop201)
{
    if (m_prop201 != prop201) {
        m_prop201 = prop201;
        m_publisher->publishProp201Changed(prop201);
    }
}

int OLinkInterface2::prop201() const
{
    return m_prop201;
}

void OLinkInterface2::setProp202(int prop202)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("org.objectapi.testbed.Interface2/prop202", prop202);
}

void OLinkInterface2::setProp202Local(int prop202)
{
    if (m_prop202 != prop202) {
        m_prop202 = prop202;
        m_publisher->publishProp202Changed(prop202);
    }
}

int OLinkInterface2::prop202() const
{
    return m_prop202;
}

void OLinkInterface2::setProp203(float prop203)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("org.objectapi.testbed.Interface2/prop203", prop203);
}

void OLinkInterface2::setProp203Local(float prop203)
{
    if (m_prop203 != prop203) {
        m_prop203 = prop203;
        m_publisher->publishProp203Changed(prop203);
    }
}

float OLinkInterface2::prop203() const
{
    return m_prop203;
}

void OLinkInterface2::setProp204(float prop204)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("org.objectapi.testbed.Interface2/prop204", prop204);
}

void OLinkInterface2::setProp204Local(float prop204)
{
    if (m_prop204 != prop204) {
        m_prop204 = prop204;
        m_publisher->publishProp204Changed(prop204);
    }
}

float OLinkInterface2::prop204() const
{
    return m_prop204;
}

void OLinkInterface2::setProp205(const std::string& prop205)
{
    if(m_node == nullptr) {
        return;
    }
    m_node->setRemoteProperty("org.objectapi.testbed.Interface2/prop205", prop205);
}

void OLinkInterface2::setProp205Local(const std::string& prop205)
{
    if (m_prop205 != prop205) {
        m_prop205 = prop205;
        m_publisher->publishProp205Changed(prop205);
    }
}

std::string OLinkInterface2::prop205() const
{
    return m_prop205;
}


std::string OLinkInterface2::olinkObjectName()
{
    return "org.objectapi.testbed.Interface2";
}

void OLinkInterface2::olinkOnSignal(std::string name, nlohmann::json args)
{
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    (void) args;
}

void OLinkInterface2::olinkOnPropertyChanged(std::string name, nlohmann::json value)
{
    std::string path = ApiGear::ObjectLink::Name::pathFromName(name);
    applyState({ {path, value} });
}
void OLinkInterface2::olinkOnInit(std::string name, nlohmann::json props, ApiGear::ObjectLink::IClientNode *node)
{
    (void) name;
    m_isReady = true;
    m_node = node;
    applyState(props);
}

void OLinkInterface2::olinkOnRelease()
{
    m_isReady = false;
    m_node = nullptr;
}

bool OLinkInterface2::isReady() const
{
    return m_isReady;
}

IInterface2Publisher* OLinkInterface2::_getPublisher() const
{
    return m_publisher;
}
