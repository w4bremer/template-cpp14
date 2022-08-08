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
#include "testbed1/generated/api/testbed1.h"
#include "testbed1/generated/api/common.h"
#include "testbed1/generated/core/structarrayinterface.publisher.h"
#include "olink/clientnode.h"
#include "apigear/olink/olinkclient.h"

namespace Test {
namespace Testbed1 {
class TEST_TESTBED1_EXPORT OLinkStructArrayInterface : public IStructArrayInterface, public ApiGear::ObjectLink::IObjectSink
{
public:
    explicit OLinkStructArrayInterface(ApiGear::ObjectLink::ClientRegistry& registry, ApiGear::PocoImpl::OLinkClient& client);
    virtual ~OLinkStructArrayInterface() override;

    void applyState(const nlohmann::json& fields);
    const std::list<StructBool>& propBool() const override;
    void setPropbool(const std::list<StructBool>& propBool) override;
    void setPropboolLocal(const std::list<StructBool>& propBool);
    const std::list<StructInt>& propInt() const override;
    void setPropint(const std::list<StructInt>& propInt) override;
    void setPropintLocal(const std::list<StructInt>& propInt);
    const std::list<StructFloat>& propFloat() const override;
    void setPropfloat(const std::list<StructFloat>& propFloat) override;
    void setPropfloatLocal(const std::list<StructFloat>& propFloat);
    const std::list<StructString>& propString() const override;
    void setPropstring(const std::list<StructString>& propString) override;
    void setPropstringLocal(const std::list<StructString>& propString);
    StructBool funcBool(const std::list<StructBool>& paramBool) override;
    std::future<StructBool> funcBoolAsync(const std::list<StructBool>& paramBool) override;
    StructBool funcInt(const std::list<StructInt>& paramInt) override;
    std::future<StructBool> funcIntAsync(const std::list<StructInt>& paramInt) override;
    StructBool funcFloat(const std::list<StructFloat>& paramFloat) override;
    std::future<StructBool> funcFloatAsync(const std::list<StructFloat>& paramFloat) override;
    StructBool funcString(const std::list<StructString>& paramString) override;
    std::future<StructBool> funcStringAsync(const std::list<StructString>& paramString) override;
    bool isReady() const;
    IStructArrayInterfacePublisher* _getPublisher() const override;
public:
    std::string olinkObjectName() override;
    void olinkOnSignal(std::string name, nlohmann::json args) override;
    void olinkOnPropertyChanged(std::string name, nlohmann::json value) override;
    void olinkOnInit(std::string name, nlohmann::json props, ApiGear::ObjectLink::IClientNode *node) override;
    void olinkOnRelease() override;
private:
    bool m_isReady;
    std::list<StructBool> m_propBool;
    std::list<StructInt> m_propInt;
    std::list<StructFloat> m_propFloat;
    std::list<StructString> m_propString;
    ApiGear::ObjectLink::IClientNode *m_node;
    ApiGear::ObjectLink::ClientRegistry* m_registry;
    IStructArrayInterfacePublisher* m_publisher;
};
} // namespace Testbed1
} // namespace Test
