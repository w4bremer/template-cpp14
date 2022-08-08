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

#include "tb_enum/generated/api/tb_enum.h"
#include "tb_enum/generated/api/common.h"
#include "olink/remotenode.h"

// using namespace ApiGear;
// using namespace ApiGear::ObjectLink;
namespace Test {
namespace TbEnum {
class TEST_TB_ENUM_EXPORT OLinkEnumInterfaceAdapter : public ApiGear::ObjectLink::IObjectSource, public IEnumInterfaceSubscriber
{
public:
    explicit OLinkEnumInterfaceAdapter(IEnumInterface* impl, ApiGear::ObjectLink::RemoteRegistry& registry);
    virtual ~OLinkEnumInterfaceAdapter() override;
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

public: // IEnumInterfaceSubscriber interface
    void OnSig0(const Enum0Enum& param0) override;
    void OnSig1(const Enum1Enum& param1) override;
    void OnSig2(const Enum2Enum& param2) override;
    void OnSig3(const Enum3Enum& param3) override;
    void OnProp0Changed(const Enum0Enum& Value) override;
    void OnProp1Changed(const Enum1Enum& Value) override;
    void OnProp2Changed(const Enum2Enum& Value) override;
    void OnProp3Changed(const Enum3Enum& Value) override;

private:
    IEnumInterface* m_impl;
    ApiGear::ObjectLink::IRemoteNode *m_node;
    ApiGear::ObjectLink::RemoteRegistry* m_registry;
};
} // namespace TbEnum
} // namespace Test
