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
#include "tb_simple/generated/api/tb_simple.h"
#include "tb_simple/generated/api/common.h"
#include "tb_simple/generated/core/simpleinterface.publisher.h"
#include "olink/clientnode.h"
#include "apigear/olink/olinkclient.h"

namespace Test {
namespace TbSimple {
class TEST_TB_SIMPLE_EXPORT OLinkSimpleInterface : public ISimpleInterface, public ApiGear::ObjectLink::IObjectSink
{
public:
    explicit OLinkSimpleInterface(ApiGear::ObjectLink::ClientRegistry& registry, ApiGear::PocoImpl::OLinkClient& client);
    virtual ~OLinkSimpleInterface() override;

    void applyState(const nlohmann::json& fields);
    bool propBool() const override;
    void setPropbool(bool propBool) override;
    void setPropboolLocal(bool propBool);
    int propInt() const override;
    void setPropint(int propInt) override;
    void setPropintLocal(int propInt);
    float propFloat() const override;
    void setPropfloat(float propFloat) override;
    void setPropfloatLocal(float propFloat);
    std::string propString() const override;
    void setPropstring(const std::string& propString) override;
    void setPropstringLocal(const std::string& propString);
    bool funcBool(bool paramBool) override;
    std::future<bool> funcBoolAsync(bool paramBool) override;
    int funcInt(int paramInt) override;
    std::future<int> funcIntAsync(int paramInt) override;
    float funcFloat(float paramFloat) override;
    std::future<float> funcFloatAsync(float paramFloat) override;
    std::string funcString(const std::string& paramString) override;
    std::future<std::string> funcStringAsync(const std::string& paramString) override;
    bool isReady() const;
    ISimpleInterfacePublisher* _getPublisher() const override;
public:
    std::string olinkObjectName() override;
    void olinkOnSignal(std::string name, nlohmann::json args) override;
    void olinkOnPropertyChanged(std::string name, nlohmann::json value) override;
    void olinkOnInit(std::string name, nlohmann::json props, ApiGear::ObjectLink::IClientNode *node) override;
    void olinkOnRelease() override;
private:
    bool m_isReady;
    bool m_propBool;
    int m_propInt;
    float m_propFloat;
    std::string m_propString;
    ApiGear::ObjectLink::IClientNode *m_node;
    ApiGear::ObjectLink::ClientRegistry* m_registry;
    ISimpleInterfacePublisher* m_publisher;
};
} // namespace TbSimple
} // namespace Test
