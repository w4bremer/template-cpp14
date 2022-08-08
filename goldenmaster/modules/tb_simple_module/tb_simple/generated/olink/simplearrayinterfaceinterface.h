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
#include "tb_simple/generated/core/simplearrayinterface.publisher.h"
#include "olink/clientnode.h"
#include "apigear/olink/olinkclient.h"

namespace Test {
namespace TbSimple {
class TEST_TB_SIMPLE_EXPORT OLinkSimpleArrayInterface : public ISimpleArrayInterface, public ApiGear::ObjectLink::IObjectSink
{
public:
    explicit OLinkSimpleArrayInterface(ApiGear::ObjectLink::ClientRegistry& registry, ApiGear::PocoImpl::OLinkClient& client);
    virtual ~OLinkSimpleArrayInterface() override;

    void applyState(const nlohmann::json& fields);
    const std::list<bool>& propBool() const override;
    void setPropbool(const std::list<bool>& propBool) override;
    void setPropboolLocal(const std::list<bool>& propBool);
    const std::list<int>& propInt() const override;
    void setPropint(const std::list<int>& propInt) override;
    void setPropintLocal(const std::list<int>& propInt);
    const std::list<float>& propFloat() const override;
    void setPropfloat(const std::list<float>& propFloat) override;
    void setPropfloatLocal(const std::list<float>& propFloat);
    const std::list<std::string>& propString() const override;
    void setPropstring(const std::list<std::string>& propString) override;
    void setPropstringLocal(const std::list<std::string>& propString);
    std::list<bool> funcBool(const std::list<bool>& paramBool) override;
    std::future<std::list<bool>> funcBoolAsync(const std::list<bool>& paramBool) override;
    std::list<int> funcInt(const std::list<int>& paramInt) override;
    std::future<std::list<int>> funcIntAsync(const std::list<int>& paramInt) override;
    std::list<float> funcFloat(const std::list<float>& paramFloat) override;
    std::future<std::list<float>> funcFloatAsync(const std::list<float>& paramFloat) override;
    std::list<std::string> funcString(const std::list<std::string>& paramString) override;
    std::future<std::list<std::string>> funcStringAsync(const std::list<std::string>& paramString) override;
    bool isReady() const;
    ISimpleArrayInterfacePublisher* _getPublisher() const override;
public:
    std::string olinkObjectName() override;
    void olinkOnSignal(std::string name, nlohmann::json args) override;
    void olinkOnPropertyChanged(std::string name, nlohmann::json value) override;
    void olinkOnInit(std::string name, nlohmann::json props, ApiGear::ObjectLink::IClientNode *node) override;
    void olinkOnRelease() override;
private:
    bool m_isReady;
    std::list<bool> m_propBool;
    std::list<int> m_propInt;
    std::list<float> m_propFloat;
    std::list<std::string> m_propString;
    ApiGear::ObjectLink::IClientNode *m_node;
    ApiGear::ObjectLink::ClientRegistry* m_registry;
    ISimpleArrayInterfacePublisher* m_publisher;
};
} // namespace TbSimple
} // namespace Test
