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
#include "generated/api/tb_same2.h"
#include "generated/api/tb_same2_common.h"
#include "generated/core/tb_same2_samestruct1interface.publisher.h"
#include "olink/clientnode.h"
#include "apigear/olink/olinkclient.h"

namespace Test {
namespace TbSame2 {
class TEST_TB_SAME2_EXPORT OLinkSameStruct1Interface : public ISameStruct1Interface, public ApiGear::ObjectLink::IObjectSink
{
public:
    explicit OLinkSameStruct1Interface(ApiGear::ObjectLink::ClientRegistry& registry, ApiGear::PocoImpl::OLinkClient& client);
    virtual ~OLinkSameStruct1Interface() override;

    void applyState(const nlohmann::json& fields);
    const Struct1& prop1() const override;
    void setProp1(const Struct1& prop1) override;
    void setProp1Local(const Struct1& prop1);
    Struct1 func1(const Struct1& param1) override;
    std::future<Struct1> func1Async(const Struct1& param1) override;
    bool isReady() const;
    ISameStruct1InterfacePublisher* _getPublisher() const override;
public:
    std::string olinkObjectName() override;
    void olinkOnSignal(std::string name, nlohmann::json args) override;
    void olinkOnPropertyChanged(std::string name, nlohmann::json value) override;
    void olinkOnInit(std::string name, nlohmann::json props, ApiGear::ObjectLink::IClientNode *node) override;
    void olinkOnRelease() override;
private:
    bool m_isReady;
    Struct1 m_prop1;
    ApiGear::ObjectLink::IClientNode *m_node;
    ApiGear::ObjectLink::ClientRegistry* m_registry;
    ISameStruct1InterfacePublisher* m_publisher;
};
} // namespace TbSame2
} // namespace Test
