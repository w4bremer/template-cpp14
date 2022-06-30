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
class TEST_TB_SIMPLE_EXPORT OLinkSimpleArrayInterfaceAdapter : public ApiGear::ObjectLink::IObjectSource, public ISimpleArrayInterfaceSubscriber
{
public:
    explicit OLinkSimpleArrayInterfaceAdapter(ISimpleArrayInterface* impl, ApiGear::ObjectLink::RemoteRegistry& registry);
    virtual ~OLinkSimpleArrayInterfaceAdapter() override;
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

public: // ISimpleArrayInterfaceSubscriber interface
    void OnSigBool(const std::list<bool>& paramBool) override;
    void OnSigInt(const std::list<int>& paramInt) override;
    void OnSigFloat(const std::list<float>& paramFloat) override;
    void OnSigString(const std::list<std::string>& paramString) override;
    void OnPropBoolChanged(const std::list<bool>& Value) override;
    void OnPropIntChanged(const std::list<int>& Value) override;
    void OnPropFloatChanged(const std::list<float>& Value) override;
    void OnPropStringChanged(const std::list<std::string>& Value) override;

private:
    ISimpleArrayInterface* m_impl;
    ApiGear::ObjectLink::IRemoteNode *m_node;
    ApiGear::ObjectLink::RemoteRegistry* m_registry;
};
} // namespace TbSimple
} // namespace Test
