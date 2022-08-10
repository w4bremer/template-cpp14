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

#include "testbed1/generated/api/testbed1.h"
#include "testbed1/generated/api/common.h"
#include "testbed1/generated/core/structinterface.data.h"

#include "olink/clientnode.h"
#include "apigear/olink/olinkclient.h"

#include <future>
#include <memory>

namespace Test {
namespace Testbed1 {
namespace olink {
/**
* Remote StructInterface implemented with OLink. 
* Handles connnectionn with StructInterface service.
* Sends and receives data over the network with ObjectLink protocol. 
* see https://objectlinkprotocol.net for ObjectLink details.
* Use on client side to request changes of the StructInterface on the server side 
* and to subscribe for the StructInterface changes.
*/
class TEST_TESTBED1_EXPORT RemoteStructInterface : public IStructInterface, public ApiGear::ObjectLink::IObjectSink
{
public:

    /**
    * ctor
    * @param registry The global registry with the sinks and client nodes.
    * @param client Holds the socket, manages the connection and provides ClientNode
    *   which is an abstraction layer between the Client and RemoteStructInterface.
    */
    explicit RemoteStructInterface(ApiGear::ObjectLink::ClientRegistry& registry, ApiGear::PocoImpl::OLinkClient& client);
    virtual ~RemoteStructInterface() override;
    /**
    * Property getter
    * @return Locally stored locally value for PropBool.
    */
    const StructBool& propBool() const override;
    /**
    * Request setting a property on the StructInterface service.
    * @param The value to which set request is send for the PropBool.
    */
    void setPropBool(const StructBool& propBool) override;
    /**
    * Property getter
    * @return Locally stored locally value for PropInt.
    */
    const StructInt& propInt() const override;
    /**
    * Request setting a property on the StructInterface service.
    * @param The value to which set request is send for the PropInt.
    */
    void setPropInt(const StructInt& propInt) override;
    /**
    * Property getter
    * @return Locally stored locally value for PropFloat.
    */
    const StructFloat& propFloat() const override;
    /**
    * Request setting a property on the StructInterface service.
    * @param The value to which set request is send for the PropFloat.
    */
    void setPropFloat(const StructFloat& propFloat) override;
    /**
    * Property getter
    * @return Locally stored locally value for PropString.
    */
    const StructString& propString() const override;
    /**
    * Request setting a property on the StructInterface service.
    * @param The value to which set request is send for the PropString.
    */
    void setPropString(const StructString& propString) override;
    /**
    * Remote call of IStructInterface::funcBool on the StructInterface service.
    * Uses funcBoolAsync
    */
    StructBool funcBool(const StructBool& paramBool) override;
    /**
    * Remote call of IStructInterface::funcBool on the StructInterface service.
    */
    std::future<StructBool> funcBoolAsync(const StructBool& paramBool) override;
    /**
    * Remote call of IStructInterface::funcInt on the StructInterface service.
    * Uses funcIntAsync
    */
    StructBool funcInt(const StructInt& paramInt) override;
    /**
    * Remote call of IStructInterface::funcInt on the StructInterface service.
    */
    std::future<StructBool> funcIntAsync(const StructInt& paramInt) override;
    /**
    * Remote call of IStructInterface::funcFloat on the StructInterface service.
    * Uses funcFloatAsync
    */
    StructFloat funcFloat(const StructFloat& paramFloat) override;
    /**
    * Remote call of IStructInterface::funcFloat on the StructInterface service.
    */
    std::future<StructFloat> funcFloatAsync(const StructFloat& paramFloat) override;
    /**
    * Remote call of IStructInterface::funcString on the StructInterface service.
    * Uses funcStringAsync
    */
    StructString funcString(const StructString& paramString) override;
    /**
    * Remote call of IStructInterface::funcString on the StructInterface service.
    */
    std::future<StructString> funcStringAsync(const StructString& paramString) override;

    /** The publisher to subscribe to. */
    IStructInterfacePublisher& _getPublisher() const override;
    
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
    * @param props Initial values obtained from the StructInterface service
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
    * @param the data recived from StructInterface service.
    */
    void applyState(const nlohmann::json& fields);
    /**  Updates local value for PropBool and informs subscriber about the change*/
    void setPropBoolLocal(const StructBool& propBool);
    /**  Updates local value for PropInt and informs subscriber about the change*/
    void setPropIntLocal(const StructInt& propInt);
    /**  Updates local value for PropFloat and informs subscriber about the change*/
    void setPropFloatLocal(const StructFloat& propFloat);
    /**  Updates local value for PropString and informs subscriber about the change*/
    void setPropStringLocal(const StructString& propString);
    
    /** Local storage for properties values. */
    StructInterfaceData m_data;

    /**
    * An Olink client node used to connect with a Olink StructInterface service for object given with olinkObjectName() .
    * An abstraction layer over the socket for the RemoteStructInterface.
    * WARNING DOROTA if there's a sink already in registry for same name, it is silently disconnected, without the informing
    * it may send requests as long as the pointer to node is valid, but will not receive any data the isReady will not tell the true.
    */
    ApiGear::ObjectLink::IClientNode* m_node = nullptr;
    /** 
    * Registry linking client nodes with sinks for the olinkObjectName().
    * The registerd olinkObjects name must be unique.  
    */
    ApiGear::ObjectLink::ClientRegistry& m_registry;
    /** The publisher for StructInterface */
    std::unique_ptr<IStructInterfacePublisher> m_publisher;
};
} // namespace olink
} // namespace Testbed1
} // namespace Test
