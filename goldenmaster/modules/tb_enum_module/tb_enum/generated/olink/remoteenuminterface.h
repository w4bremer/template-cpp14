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

#include "tb_enum/generated/api/tb_enum.h"
#include "tb_enum/generated/api/common.h"
#include "tb_enum/generated/core/enuminterface.data.h"

#include "olink/clientnode.h"
#include "apigear/olink/olinkclient.h"

#include <future>
#include <memory>

namespace Test {
namespace TbEnum {
namespace olink {
/**
* Remote EnumInterface implemented with OLink. 
* Handles connnectionn with EnumInterface service.
* Sends and receives data over the network with ObjectLink protocol. 
* see https://objectlinkprotocol.net for ObjectLink details.
* Use on client side to request changes of the EnumInterface on the server side 
* and to subscribe for the EnumInterface changes.
*/
class TEST_TB_ENUM_EXPORT RemoteEnumInterface : public IEnumInterface, public ApiGear::ObjectLink::IObjectSink
{
public:

    /**
    * ctor
    * @param registry The global registry with the sinks and client nodes.
    * @param client Holds the socket, manages the connection and provides ClientNode
    *   which is an abstraction layer between the Client and RemoteEnumInterface.
    */
    explicit RemoteEnumInterface(ApiGear::ObjectLink::ClientRegistry& registry, ApiGear::PocoImpl::OLinkClient& client);
    virtual ~RemoteEnumInterface() override;
    /**
    * Property getter
    * @return Locally stored locally value for Prop0.
    */
    const Enum0Enum& prop0() const override;
    /**
    * Request setting a property on the EnumInterface service.
    * @param The value to which set request is send for the Prop0.
    */
    void setProp0(const Enum0Enum& prop0) override;
    /**
    * Property getter
    * @return Locally stored locally value for Prop1.
    */
    const Enum1Enum& prop1() const override;
    /**
    * Request setting a property on the EnumInterface service.
    * @param The value to which set request is send for the Prop1.
    */
    void setProp1(const Enum1Enum& prop1) override;
    /**
    * Property getter
    * @return Locally stored locally value for Prop2.
    */
    const Enum2Enum& prop2() const override;
    /**
    * Request setting a property on the EnumInterface service.
    * @param The value to which set request is send for the Prop2.
    */
    void setProp2(const Enum2Enum& prop2) override;
    /**
    * Property getter
    * @return Locally stored locally value for Prop3.
    */
    const Enum3Enum& prop3() const override;
    /**
    * Request setting a property on the EnumInterface service.
    * @param The value to which set request is send for the Prop3.
    */
    void setProp3(const Enum3Enum& prop3) override;
    /**
    * Remote call of IEnumInterface::func0 on the EnumInterface service.
    * Uses func0Async
    */
    Enum0Enum func0(const Enum0Enum& param0) override;
    /**
    * Remote call of IEnumInterface::func0 on the EnumInterface service.
    */
    std::future<Enum0Enum> func0Async(const Enum0Enum& param0) override;
    /**
    * Remote call of IEnumInterface::func1 on the EnumInterface service.
    * Uses func1Async
    */
    Enum1Enum func1(const Enum1Enum& param1) override;
    /**
    * Remote call of IEnumInterface::func1 on the EnumInterface service.
    */
    std::future<Enum1Enum> func1Async(const Enum1Enum& param1) override;
    /**
    * Remote call of IEnumInterface::func2 on the EnumInterface service.
    * Uses func2Async
    */
    Enum2Enum func2(const Enum2Enum& param2) override;
    /**
    * Remote call of IEnumInterface::func2 on the EnumInterface service.
    */
    std::future<Enum2Enum> func2Async(const Enum2Enum& param2) override;
    /**
    * Remote call of IEnumInterface::func3 on the EnumInterface service.
    * Uses func3Async
    */
    Enum3Enum func3(const Enum3Enum& param3) override;
    /**
    * Remote call of IEnumInterface::func3 on the EnumInterface service.
    */
    std::future<Enum3Enum> func3Async(const Enum3Enum& param3) override;

    /** The publisher to subscribe to. */
    IEnumInterfacePublisher& _getPublisher() const override;
    
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
    * @param props Initial values obtained from the EnumInterface service
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
    * @param the data recived from EnumInterface service.
    */
    void applyState(const nlohmann::json& fields);
    /**  Updates local value for Prop0 and informs subscriber about the change*/
    void setProp0Local(const Enum0Enum& prop0);
    /**  Updates local value for Prop1 and informs subscriber about the change*/
    void setProp1Local(const Enum1Enum& prop1);
    /**  Updates local value for Prop2 and informs subscriber about the change*/
    void setProp2Local(const Enum2Enum& prop2);
    /**  Updates local value for Prop3 and informs subscriber about the change*/
    void setProp3Local(const Enum3Enum& prop3);
    
    /** Local storage for properties values. */
    EnumInterfaceData m_data;

    /**
    * An Olink client node used to connect with a Olink EnumInterface service for object given with olinkObjectName() .
    * An abstraction layer over the socket for the RemoteEnumInterface.
    * WARNING DOROTA if there's a sink already in registry for same name, it is silently disconnected, without the informing
    * it may send requests as long as the pointer to node is valid, but will not receive any data the isReady will not tell the true.
    */
    ApiGear::ObjectLink::IClientNode* m_node = nullptr;
    /** 
    * Registry linking client nodes with sinks for the olinkObjectName().
    * The registerd olinkObjects name must be unique.  
    */
    ApiGear::ObjectLink::ClientRegistry& m_registry;
    /** The publisher for EnumInterface */
    std::unique_ptr<IEnumInterfacePublisher> m_publisher;
};
} // namespace olink
} // namespace TbEnum
} // namespace Test
