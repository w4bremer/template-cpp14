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

#include "testbed2/generated/api/testbed2.h"
#include "testbed2/generated/api/common.h"
#include "olink/remotenode.h"

// using namespace ApiGear;
// using namespace ApiGear::ObjectLink;
namespace Test {
namespace Testbed2 {
class TEST_TESTBED2_EXPORT OLinkManyParamInterfaceAdapter : public ApiGear::ObjectLink::IObjectSource, public IManyParamInterfaceSubscriber
{
public:
    explicit OLinkManyParamInterfaceAdapter(IManyParamInterface* impl, ApiGear::ObjectLink::RemoteRegistry& registry);
    virtual ~OLinkManyParamInterfaceAdapter() override;
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

public: // IManyParamInterfaceSubscriber interface
    void OnSig1(int param1) override;
    void OnSig2(int param1,int param2) override;
    void OnSig3(int param1,int param2,int param3) override;
    void OnSig4(int param1,int param2,int param3,int param4) override;
    void OnProp1Changed(int Value) override;
    void OnProp2Changed(int Value) override;
    void OnProp3Changed(int Value) override;
    void OnProp4Changed(int Value) override;

private:
    IManyParamInterface* m_impl;
    ApiGear::ObjectLink::IRemoteNode *m_node;
    ApiGear::ObjectLink::RemoteRegistry* m_registry;
};
} // namespace Testbed2
} // namespace Test
