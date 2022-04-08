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

#pragma once

#include "generated/api/org_objectapi_testbed.h"
#include "generated/api/org_objectapi_testbed_common.h"
#include "olink/remotenode.h"

// using namespace ApiGear;
// using namespace ApiGear::ObjectLink;
namespace Test {
namespace OrgObjectapiTestbed {
class TEST_ORG_OBJECTAPI_TESTBED_EXPORT OLinkInterface2Adapter : public ApiGear::ObjectLink::IObjectSource, public IInterface2Subscriber
{
public:
    explicit OLinkInterface2Adapter(IInterface2* impl, ApiGear::ObjectLink::RemoteRegistry& registry);
    virtual ~OLinkInterface2Adapter() override;
public:
    void publishState();
    nlohmann::json captureState();
    void applyState(const nlohmann::json& state);
    
public: // IObjectSource interface
    std::string olinkObjectName() override;
    nlohmann::json olinkInvoke(std::string name, nlohmann::json args) override;
    void olinkSetProperty(std::string name, nlohmann::json value) override;
    void olinkLinked(std::string name, ApiGear::ObjectLink::IRemoteNode *node) override;
    void olinkUnlinked(std::string name) override;
    nlohmann::json olinkCollectProperties() override;

public: // IInterface2Subscriber interface
    void OnProp200Changed(int Value) override;
    void OnProp201Changed(int Value) override;
    void OnProp202Changed(int Value) override;
    void OnProp203Changed(float Value) override;
    void OnProp204Changed(float Value) override;
    void OnProp205Changed(std::string Value) override;

private:
    IInterface2* m_impl;
    ApiGear::ObjectLink::IRemoteNode *m_node;
    ApiGear::ObjectLink::RemoteRegistry* m_registry;
};
} // namespace OrgObjectapiTestbed
} // namespace Test
