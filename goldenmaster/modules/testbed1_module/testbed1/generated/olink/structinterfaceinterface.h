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
#include "testbed1/generated/core/structinterface.publisher.h"
#include "olink/clientnode.h"
#include "apigear/olink/olinkclient.h"

namespace Test {
namespace Testbed1 {
class TEST_TESTBED1_EXPORT OLinkStructInterface : public IStructInterface, public ApiGear::ObjectLink::IObjectSink
{
public:
    explicit OLinkStructInterface(ApiGear::ObjectLink::ClientRegistry& registry, ApiGear::PocoImpl::OLinkClient& client);
    virtual ~OLinkStructInterface() override;

    void applyState(const nlohmann::json& fields);
    const StructBool& propBool() const override;
    void setPropbool(const StructBool& propBool) override;
    void setPropboolLocal(const StructBool& propBool);
    const StructInt& propInt() const override;
    void setPropint(const StructInt& propInt) override;
    void setPropintLocal(const StructInt& propInt);
    const StructFloat& propFloat() const override;
    void setPropfloat(const StructFloat& propFloat) override;
    void setPropfloatLocal(const StructFloat& propFloat);
    const StructString& propString() const override;
    void setPropstring(const StructString& propString) override;
    void setPropstringLocal(const StructString& propString);
    StructBool funcBool(const StructBool& paramBool) override;
    std::future<StructBool> funcBoolAsync(const StructBool& paramBool) override;
    StructBool funcInt(const StructInt& paramInt) override;
    std::future<StructBool> funcIntAsync(const StructInt& paramInt) override;
    StructFloat funcFloat(const StructFloat& paramFloat) override;
    std::future<StructFloat> funcFloatAsync(const StructFloat& paramFloat) override;
    StructString funcString(const StructString& paramString) override;
    std::future<StructString> funcStringAsync(const StructString& paramString) override;
    bool isReady() const;
    IStructInterfacePublisher* _getPublisher() const override;
public:
    std::string olinkObjectName() override;
    void olinkOnSignal(std::string name, nlohmann::json args) override;
    void olinkOnPropertyChanged(std::string name, nlohmann::json value) override;
    void olinkOnInit(std::string name, nlohmann::json props, ApiGear::ObjectLink::IClientNode *node) override;
    void olinkOnRelease() override;
private:
    bool m_isReady;
    StructBool m_propBool;
    StructInt m_propInt;
    StructFloat m_propFloat;
    StructString m_propString;
    ApiGear::ObjectLink::IClientNode *m_node;
    ApiGear::ObjectLink::ClientRegistry* m_registry;
    IStructInterfacePublisher* m_publisher;
};
} // namespace Testbed1
} // namespace Test
