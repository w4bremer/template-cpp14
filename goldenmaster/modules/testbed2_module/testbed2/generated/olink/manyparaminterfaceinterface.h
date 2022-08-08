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
#include "testbed2/generated/core/manyparaminterface.publisher.h"
#include "olink/clientnode.h"
#include "apigear/olink/olinkclient.h"

namespace Test {
namespace Testbed2 {
class TEST_TESTBED2_EXPORT OLinkManyParamInterface : public IManyParamInterface, public ApiGear::ObjectLink::IObjectSink
{
public:
    explicit OLinkManyParamInterface(ApiGear::ObjectLink::ClientRegistry& registry, ApiGear::PocoImpl::OLinkClient& client);
    virtual ~OLinkManyParamInterface() override;

    void applyState(const nlohmann::json& fields);
    int prop1() const override;
    void setProp1(int prop1) override;
    void setProp1Local(int prop1);
    int prop2() const override;
    void setProp2(int prop2) override;
    void setProp2Local(int prop2);
    int prop3() const override;
    void setProp3(int prop3) override;
    void setProp3Local(int prop3);
    int prop4() const override;
    void setProp4(int prop4) override;
    void setProp4Local(int prop4);
    int func1(int param1) override;
    std::future<int> func1Async(int param1) override;
    int func2(int param1, int param2) override;
    std::future<int> func2Async(int param1, int param2) override;
    int func3(int param1, int param2, int param3) override;
    std::future<int> func3Async(int param1, int param2, int param3) override;
    int func4(int param1, int param2, int param3, int param4) override;
    std::future<int> func4Async(int param1, int param2, int param3, int param4) override;
    bool isReady() const;
    IManyParamInterfacePublisher* _getPublisher() const override;
public:
    std::string olinkObjectName() override;
    void olinkOnSignal(std::string name, nlohmann::json args) override;
    void olinkOnPropertyChanged(std::string name, nlohmann::json value) override;
    void olinkOnInit(std::string name, nlohmann::json props, ApiGear::ObjectLink::IClientNode *node) override;
    void olinkOnRelease() override;
private:
    bool m_isReady;
    int m_prop1;
    int m_prop2;
    int m_prop3;
    int m_prop4;
    ApiGear::ObjectLink::IClientNode *m_node;
    ApiGear::ObjectLink::ClientRegistry* m_registry;
    IManyParamInterfacePublisher* m_publisher;
};
} // namespace Testbed2
} // namespace Test
