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

#include "tb_same2/generated/api/tb_same2.h"
#include "tb_same2/generated/api/common.h"
#include "tb_same2/generated/core/samestruct2interface.data.h"

#include "olink/clientnode.h"
#include "apigear/olink/olinkclient.h"

#include <future>
#include <memory>

namespace Test {
namespace TbSame2 {
namespace olink {
/**
* Remote SameStruct2Interface implemented with OLink. 
* Handles connnectionn with SameStruct2Interface service.
* Sends and receives data over the network with ObjectLink protocol. 
* see https://objectlinkprotocol.net for ObjectLink details.
* Use on client side to request changes of the SameStruct2Interface on the server side 
* and to subscribe for the SameStruct2Interface changes.
*/
class TEST_TB_SAME2_EXPORT RemoteSameStruct2Interface : public ISameStruct2Interface, public ApiGear::ObjectLink::IObjectSink
{
public:

    /**
    * ctor
    * @param registry The global registry with the sinks and client nodes.
    * @param client Holds the socket, manages the connection and provides ClientNode
    *   which is an abstraction layer between the Client and RemoteSameStruct2Interface.
    */
    explicit RemoteSameStruct2Interface(ApiGear::ObjectLink::ClientRegistry& registry, ApiGear::PocoImpl::OLinkClient& client);
    virtual ~RemoteSameStruct2Interface() override;
    /**
    * Property getter
    * @return Locally stored locally value for Prop1.
    */
    const Struct2& prop1() const override;
    /**
    * Request setting a property on the SameStruct2Interface service.
    * @param The value to which set request is send for the Prop1.
    */
    void setProp1(const Struct2& prop1) override;
    /**
    * Property getter
    * @return Locally stored locally value for Prop2.
    */
    const Struct2& prop2() const override;
    /**
    * Request setting a property on the SameStruct2Interface service.
    * @param The value to which set request is send for the Prop2.
    */
    void setProp2(const Struct2& prop2) override;
    /**
    * Remote call of ISameStruct2Interface::func1 on the SameStruct2Interface service.
    * Uses func1Async
    */
    Struct1 func1(const Struct1& param1) override;
    /**
    * Remote call of ISameStruct2Interface::func1 on the SameStruct2Interface service.
    */
    std::future<Struct1> func1Async(const Struct1& param1) override;
    /**
    * Remote call of ISameStruct2Interface::func2 on the SameStruct2Interface service.
    * Uses func2Async
    */
    Struct1 func2(const Struct1& param1, const Struct2& param2) override;
    /**
    * Remote call of ISameStruct2Interface::func2 on the SameStruct2Interface service.
    */
    std::future<Struct1> func2Async(const Struct1& param1, const Struct2& param2) override;

    /** The publisher to subscribe to. */
    ISameStruct2InterfacePublisher& _getPublisher() const override;
    
    /**
    * Informs if the connection is established and the remote interface is operable.
    * @return true if remote interface is operable, false otherwise.
    */
    bool isReady() const;

    /**
    * The name of the object for which this sink is created, object on server side has to have the same name.
    * It serves as an identifier for the client registry, it has to be uniqe for the pair sink object - client node.
    * Passed in the olink messages as an object identifier.
    */
    std::string olinkObjectName() override;
    
    /**
    * Forwards information about singal emission to publisher.
    * @param name The name of the emited signal.
    * @param args The arguments for the signal.
    */
    void olinkOnSignal(std::string name, nlohmann::json args) override;
    
    /**
    * Forwards information about the property with the object name to publisher and updates local state.
    * @param name The name of the emited signal.
    * @param args The arguments for the signal.
    */
    void olinkOnPropertyChanged(std::string name, nlohmann::json value) override;
    
    /** Informs this object sink that connetion was is established.
    * @param name The name of the object for which link was established.
    * @param props Initial values obtained from the SameStruct2Interface service
    * @param the initialized link endpoint for this sink.
    */
    void olinkOnInit(std::string name, nlohmann::json props, ApiGear::ObjectLink::IClientNode *node) override;
    /**
    * Informs this objec source that the link was disconnected and cannot be used anymore.
    * WARNING DOROTA: it is never called.
    */
    void olinkOnRelease() override;

private:
    /**
    * Applies recived data to local state and publishes changes to subscribers.
    * @param the data recived from SameStruct2Interface service.
    */
    void applyState(const nlohmann::json& fields);
    /**  Updates local value for Prop1 and informs subscriber about the change*/
    void setProp1Local(const Struct2& prop1);
    /**  Updates local value for Prop2 and informs subscriber about the change*/
    void setProp2Local(const Struct2& prop2);
    
    /** Local storage for properties values. */
    SameStruct2InterfaceData m_data;

    /**
    * An Olink client node used to connect with a Olink SameStruct2Interface service for object given with olinkObjectName() .
    * An abstraction layer over the socket for the RemoteSameStruct2Interface.
    * WARNING DOROTA if there's a sink already in registry for same name, it is silently disconnected, without the informing
    * it may send requests as long as the pointer to node is valid, but will not receive any data the isReady will not tell the true.
    */
    ApiGear::ObjectLink::IClientNode* m_node = nullptr;
    /** 
    * Registry linking client nodes with sinks for the olinkObjectName().
    * The registerd olinkObjects name must be unique.  
    */
    ApiGear::ObjectLink::ClientRegistry& m_registry;
    /** The publisher for SameStruct2Interface */
    std::unique_ptr<ISameStruct2InterfacePublisher> m_publisher;
};
} // namespace olink
} // namespace TbSame2
} // namespace Test
