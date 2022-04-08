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
class TEST_ORG_OBJECTAPI_TESTBED_EXPORT OLinkInterface1Adapter : public ApiGear::ObjectLink::IObjectSource, public IInterface1Subscriber
{
public:
    explicit OLinkInterface1Adapter(IInterface1* impl, ApiGear::ObjectLink::RemoteRegistry& registry);
    virtual ~OLinkInterface1Adapter() override;
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

public: // IInterface1Subscriber interface
    void OnSig1() override;
    void OnSig2(int step) override;
    void OnSig3() override;
    void OnProp1Changed(bool Value) override;
    void OnProp2Changed(int Value) override;
    void OnProp3Changed(float Value) override;
    void OnProp4Changed(std::string Value) override;
    void OnProp5Changed(const std::list<int>& Value) override;
    void OnProp6Changed(const Struct1& Value) override;
    void OnProp7Changed(int Value) override;
    void OnProp10Changed(const std::list<int>& Value) override;
    void OnProp11Changed(const std::list<Struct1>& Value) override;
    void OnProp12Changed(const std::list<Enum1Enum>& Value) override;
    void OnProp14Changed(const std::list<Struct1>& Value) override;

private:
    IInterface1* m_impl;
    ApiGear::ObjectLink::IRemoteNode *m_node;
    ApiGear::ObjectLink::RemoteRegistry* m_registry;
};
} // namespace OrgObjectapiTestbed
} // namespace Test
