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
#include "testbed2/generated/api/testbed2.h"
#include "testbed2/generated/api/common.h"
#include "testbed2/generated/core/nestedstruct2interface.publisher.h"
#include "olink/clientnode.h"
#include "apigear/olink/olinkclient.h"

namespace Test {
namespace Testbed2 {
class TEST_TESTBED2_EXPORT OLinkNestedStruct2Interface : public INestedStruct2Interface, public ApiGear::ObjectLink::IObjectSink
{
public:
    explicit OLinkNestedStruct2Interface(ApiGear::ObjectLink::ClientRegistry& registry, ApiGear::PocoImpl::OLinkClient& client);
    virtual ~OLinkNestedStruct2Interface() override;

    void applyState(const nlohmann::json& fields);
    const NestedStruct1& prop1() const override;
    void setProp1(const NestedStruct1& prop1) override;
    void setProp1Local(const NestedStruct1& prop1);
    const NestedStruct2& prop2() const override;
    void setProp2(const NestedStruct2& prop2) override;
    void setProp2Local(const NestedStruct2& prop2);
    NestedStruct1 func1(const NestedStruct1& param1) override;
    std::future<NestedStruct1> func1Async(const NestedStruct1& param1) override;
    NestedStruct1 func2(const NestedStruct1& param1, const NestedStruct2& param2) override;
    std::future<NestedStruct1> func2Async(const NestedStruct1& param1, const NestedStruct2& param2) override;
    bool isReady() const;
    INestedStruct2InterfacePublisher* _getPublisher() const override;
public:
    std::string olinkObjectName() override;
    void olinkOnSignal(std::string name, nlohmann::json args) override;
    void olinkOnPropertyChanged(std::string name, nlohmann::json value) override;
    void olinkOnInit(std::string name, nlohmann::json props, ApiGear::ObjectLink::IClientNode *node) override;
    void olinkOnRelease() override;
private:
    bool m_isReady;
    NestedStruct1 m_prop1;
    NestedStruct2 m_prop2;
    ApiGear::ObjectLink::IClientNode *m_node;
    ApiGear::ObjectLink::ClientRegistry* m_registry;
    INestedStruct2InterfacePublisher* m_publisher;
};
} // namespace Testbed2
} // namespace Test
