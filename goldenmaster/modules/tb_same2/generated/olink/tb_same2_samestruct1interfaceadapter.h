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

#include "generated/api/tb_same2.h"
#include "generated/api/tb_same2_common.h"
#include "olink/remotenode.h"

// using namespace ApiGear;
// using namespace ApiGear::ObjectLink;
namespace Test {
namespace TbSame2 {
class TEST_TB_SAME2_EXPORT OLinkSameStruct1InterfaceAdapter : public ApiGear::ObjectLink::IObjectSource, public ISameStruct1InterfaceSubscriber
{
public:
    explicit OLinkSameStruct1InterfaceAdapter(ISameStruct1Interface* impl, ApiGear::ObjectLink::RemoteRegistry& registry);
    virtual ~OLinkSameStruct1InterfaceAdapter() override;
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

public: // ISameStruct1InterfaceSubscriber interface
    void OnSig1(const Struct1& param1) override;
    void OnProp1Changed(const Struct1& Value) override;

private:
    ISameStruct1Interface* m_impl;
    ApiGear::ObjectLink::IRemoteNode *m_node;
    ApiGear::ObjectLink::RemoteRegistry* m_registry;
};
} // namespace TbSame2
} // namespace Test
