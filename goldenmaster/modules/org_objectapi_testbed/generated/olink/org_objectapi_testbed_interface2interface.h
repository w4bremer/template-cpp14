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
#include "generated/api/org_objectapi_testbed.h"
#include "generated/api/org_objectapi_testbed_common.h"
#include "generated/core/org_objectapi_testbed_interface2.publisher.h"
#include "olink/clientnode.h"
#include "apigear/olink/olinkclient.h"

namespace Test {
namespace OrgObjectapiTestbed {
class TEST_ORG_OBJECTAPI_TESTBED_EXPORT OLinkInterface2 : public IInterface2, public ApiGear::ObjectLink::IObjectSink
{
public:
    explicit OLinkInterface2(ApiGear::ObjectLink::ClientRegistry& registry, ApiGear::PocoImpl::OLinkClient& client);
    virtual ~OLinkInterface2() override;

    void applyState(const nlohmann::json& fields);
    int prop200() const override;
    void setProp200(int prop200) override;
    void setProp200Local(int prop200);
    int prop201() const override;
    void setProp201(int prop201) override;
    void setProp201Local(int prop201);
    int prop202() const override;
    void setProp202(int prop202) override;
    void setProp202Local(int prop202);
    float prop203() const override;
    void setProp203(float prop203) override;
    void setProp203Local(float prop203);
    float prop204() const override;
    void setProp204(float prop204) override;
    void setProp204Local(float prop204);
    std::string prop205() const override;
    void setProp205(const std::string& prop205) override;
    void setProp205Local(const std::string& prop205);
    bool isReady() const;
    IInterface2Publisher* _getPublisher() const override;
public:
    std::string olinkObjectName() override;
    void olinkOnSignal(std::string name, nlohmann::json args) override;
    void olinkOnPropertyChanged(std::string name, nlohmann::json value) override;
    void olinkOnInit(std::string name, nlohmann::json props, ApiGear::ObjectLink::IClientNode *node) override;
    void olinkOnRelease() override;
private:
    bool m_isReady;
    int m_prop200;
    int m_prop201;
    int m_prop202;
    float m_prop203;
    float m_prop204;
    std::string m_prop205;
    ApiGear::ObjectLink::IClientNode *m_node;
    ApiGear::ObjectLink::ClientRegistry* m_registry;
    IInterface2Publisher* m_publisher;
};
} // namespace OrgObjectapiTestbed
} // namespace Test
