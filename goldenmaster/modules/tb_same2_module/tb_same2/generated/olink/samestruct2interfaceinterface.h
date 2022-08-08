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

#include <future>
#include "tb_same2/generated/api/tb_same2.h"
#include "tb_same2/generated/api/common.h"
#include "tb_same2/generated/core/samestruct2interface.publisher.h"
#include "olink/clientnode.h"
#include "apigear/olink/olinkclient.h"

namespace Test {
namespace TbSame2 {
class TEST_TB_SAME2_EXPORT OLinkSameStruct2Interface : public ISameStruct2Interface, public ApiGear::ObjectLink::IObjectSink
{
public:
    explicit OLinkSameStruct2Interface(ApiGear::ObjectLink::ClientRegistry& registry, ApiGear::PocoImpl::OLinkClient& client);
    virtual ~OLinkSameStruct2Interface() override;

    void applyState(const nlohmann::json& fields);
    const Struct2& prop1() const override;
    void setProp1(const Struct2& prop1) override;
    void setProp1Local(const Struct2& prop1);
    const Struct2& prop2() const override;
    void setProp2(const Struct2& prop2) override;
    void setProp2Local(const Struct2& prop2);
    Struct1 func1(const Struct1& param1) override;
    std::future<Struct1> func1Async(const Struct1& param1) override;
    Struct1 func2(const Struct1& param1, const Struct2& param2) override;
    std::future<Struct1> func2Async(const Struct1& param1, const Struct2& param2) override;
    bool isReady() const;
    ISameStruct2InterfacePublisher* _getPublisher() const override;
public:
    std::string olinkObjectName() override;
    void olinkOnSignal(std::string name, nlohmann::json args) override;
    void olinkOnPropertyChanged(std::string name, nlohmann::json value) override;
    void olinkOnInit(std::string name, nlohmann::json props, ApiGear::ObjectLink::IClientNode *node) override;
    void olinkOnRelease() override;
private:
    bool m_isReady;
    Struct2 m_prop1;
    Struct2 m_prop2;
    ApiGear::ObjectLink::IClientNode *m_node;
    ApiGear::ObjectLink::ClientRegistry* m_registry;
    ISameStruct2InterfacePublisher* m_publisher;
};
} // namespace TbSame2
} // namespace Test
