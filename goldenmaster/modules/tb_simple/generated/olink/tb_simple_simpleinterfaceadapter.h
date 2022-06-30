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

#include "generated/api/tb_simple.h"
#include "generated/api/tb_simple_common.h"
#include "olink/remotenode.h"

// using namespace ApiGear;
// using namespace ApiGear::ObjectLink;
namespace Test {
namespace TbSimple {
class TEST_TB_SIMPLE_EXPORT OLinkSimpleInterfaceAdapter : public ApiGear::ObjectLink::IObjectSource, public ISimpleInterfaceSubscriber
{
public:
    explicit OLinkSimpleInterfaceAdapter(ISimpleInterface* impl, ApiGear::ObjectLink::RemoteRegistry& registry);
    virtual ~OLinkSimpleInterfaceAdapter() override;
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

public: // ISimpleInterfaceSubscriber interface
    void OnSigBool(bool paramBool) override;
    void OnSigInt(int paramInt) override;
    void OnSigFloat(float paramFloat) override;
    void OnSigString(const std::string& paramString) override;
    void OnPropBoolChanged(bool Value) override;
    void OnPropIntChanged(int Value) override;
    void OnPropFloatChanged(float Value) override;
    void OnPropStringChanged(std::string Value) override;

private:
    ISimpleInterface* m_impl;
    ApiGear::ObjectLink::IRemoteNode *m_node;
    ApiGear::ObjectLink::RemoteRegistry* m_registry;
};
} // namespace TbSimple
} // namespace Test
