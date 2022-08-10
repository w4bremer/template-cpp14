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

#include "testbed2/generated/api/testbed2.h"
#include "testbed2/generated/api/common.h"
#include "olink/remotenode.h"

namespace Test {
namespace Testbed2 {
namespace olink {
/**
* Server side for NestedStruct2Interface implements the NestedStruct2Interface service.
* It is a source of data for NestedStruct2Interface clients.
* Sends and receives data over the network with ObjectLink protocol. 
* see https://objectlinkprotocol.net for Object Link Details
*/
class TEST_TESTBED2_EXPORT NestedStruct2InterfaceServiceAdapter : public ApiGear::ObjectLink::IObjectSource, public INestedStruct2InterfaceSubscriber
{
public:
    /**
    * ctor
    * @param NestedStruct2Interface The service source object, the actual NestedStruct2Interface object which is exposed for remote clients with olink.
    * @param registry The global registry that keeps track of the object source services associated with network nodes.
    */
    explicit NestedStruct2InterfaceServiceAdapter(INestedStruct2Interface& NestedStruct2Interface, ApiGear::ObjectLink::RemoteRegistry& registry);
    virtual ~NestedStruct2InterfaceServiceAdapter() override;

    /**
    * The name of the object for which this service is created, object on client side has to have the same name.
    * It serves as an identifier for the source registry, it has to be uniqe for the pair source object - remote node.
    * Passed in the olink messages as an object identifier.
    */
    std::string olinkObjectName() override;
    /**
    * Applies recived method invocation with given arguments on the NestedStruct2Interface object.
    * @param name Path of the method to invoke. Contains object name and the method name.
    * @param args Arguments required to invoke a method in json format.
    * @return the result of the invoked method (if applicable) that needs to be sent back to the clients.
    */
    nlohmann::json olinkInvoke(std::string name, nlohmann::json args) override;
    /**
    * Applies recived change property request to NestedStruct2Interface object.
    * @param name Path the property to change. Contains object name and the property name.
    * @param args Value in json format requested to set for the property.
    */
    void olinkSetProperty(std::string name, nlohmann::json value) override;
    /**
    * Informs this service source that the link was established.
    * @param name The name of the object for which link was established.
    * @param the initialized link endpoint.
    */
    void olinkLinked(std::string name, ApiGear::ObjectLink::IRemoteNode *node) override;
    /**
    * Informs this service source that the link was disconnected and cannot be used anymore.
    */
    void olinkUnlinked(std::string name) override;

    /**
    * Gets the current state of NestedStruct2Interface object.
    * @return the set of properties with their current vlues for the NestedStruct2Interface object in json format.
    */
    nlohmann::json olinkCollectProperties() override;
    /**
    * Forwards emited sig1 through network if the connection is established.
    */
    void onSig1(const NestedStruct1& param1) override;
    /**
    * Forwards emited sig2 through network if the connection is established.
    */
    void onSig2(const NestedStruct1& param1,const NestedStruct2& param2) override;
    /**
    * Forwards prop1 change through network if the connection is established.
    */
    void onProp1Changed(const NestedStruct1& Value) override;
    /**
    * Forwards prop2 change through network if the connection is established.
    */
    void onProp2Changed(const NestedStruct2& Value) override;

private:
    /**
    * The NestedStruct2Interface used for object source.
    */
    INestedStruct2Interface& m_NestedStruct2Interface;
    /**
    * The abstraction over the network layer for this object source.
    */
    ApiGear::ObjectLink::IRemoteNode* m_node;
    /**
    * A global registry that keeps track of object sources associated with their network layer nodes.
    */
    ApiGear::ObjectLink::RemoteRegistry& m_registry;
};
} // namespace olink
} // namespace Testbed2
} // namespace Test
