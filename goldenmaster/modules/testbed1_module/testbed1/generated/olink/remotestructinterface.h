
#pragma once

#include "testbed1/generated/api/common.h"
#include "testbed1/generated/api/testbed1.h"
#include "testbed1/generated/core/structinterface.data.h"

#include "apigear/olink/iolinkconnector.h"
#include "apigear/olink/logger/logger.h"
#include "olink/iobjectsink.h"

#include <future>
#include <memory>

namespace ApiGear{
namespace ObjectLink{
class IClientNode;
class ClientRegistry;
}
}

namespace Test {
namespace Testbed1 {
namespace olink {
/**
* The class for handling connetion witha a StructInterface service implemented for OLink protocol. 
* Sends and receives data over the network with ObjectLink protocol. 
* see https://objectlinkprotocol.net for ObjectLink details.
* Use on client side to request changes of the StructInterface on the server side 
* and to subscribe for the StructInterface changes.
*/
class TEST_TESTBED1_EXPORT RemoteStructInterface : public IStructInterface,
    public ApiGear::ObjectLink::IObjectSink,
    public ApiGear::Logger::Logger
{
public:

    /**
    * ctor
    * @param olinkConnector An object, that sets up connection of this object sink to the service on server side. 
    *        It manages the connection and a client node associated to it and is responsible for linking the object
    *        depending on connection state.
    */
    explicit RemoteStructInterface(std::weak_ptr<ApiGear::PocoImpl::IOlinkConnector> olinkConnector);
    virtual ~RemoteStructInterface() override;
    /**
    * Property getter
    * @return Locally stored locally value for PropBool.
    */
    const StructBool& getPropBool() const override;
    /**
    * Request setting a property on the StructInterface service.
    * @param The value to which set request is send for the PropBool.
    */
    void setPropBool(const StructBool& propBool) override;
    /**
    * Property getter
    * @return Locally stored locally value for PropInt.
    */
    const StructInt& getPropInt() const override;
    /**
    * Request setting a property on the StructInterface service.
    * @param The value to which set request is send for the PropInt.
    */
    void setPropInt(const StructInt& propInt) override;
    /**
    * Property getter
    * @return Locally stored locally value for PropFloat.
    */
    const StructFloat& getPropFloat() const override;
    /**
    * Request setting a property on the StructInterface service.
    * @param The value to which set request is send for the PropFloat.
    */
    void setPropFloat(const StructFloat& propFloat) override;
    /**
    * Property getter
    * @return Locally stored locally value for PropString.
    */
    const StructString& getPropString() const override;
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
    * Informs if the remote RemoteStructInterface is ready to send and revice messages.
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
    * Information about singal emission on a server side to all subscribers.
    * @param signalId Unique identifier for the singal emited from object.
    * @param args The arguments for the signal.
    */
    void olinkOnSignal(const std::string& signalId, const nlohmann::json& args) override;
    
    /**
    * Applies the information about the property changed on server side.
    * @param propertyId Unique identifier of a changed property in object .
    * @param value The value of the property.
    */
    void olinkOnPropertyChanged(const std::string& propertyId, const nlohmann::json& value) override;
    
    /** Informs this object sink that connetion was is established.
    * @param interfaceId The name of the object for which link was established.
    * @param props Initial values obtained from the StructInterface service
    * @param the initialized link endpoint for this sink.
    */
    void olinkOnInit(const std::string& interfaceId, const nlohmann::json& props, ApiGear::ObjectLink::IClientNode *node) override;
    /**
    * Informs this object source that the link was disconnected and cannot be used anymore.
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
    * An abstraction layer over the connection with service for the RemoteStructInterface.
    * Handles incoming and outgoing messages.
    * Is given when object is linked with the service.
    */
    ApiGear::ObjectLink::IClientNode* m_node = nullptr;
    /**
    * A helper used to connect with a Olink StructInterface service for object given with olinkObjectName()
    * takes care of setup and tear down linkage for this RemoteStructInterface.
    */
    std::weak_ptr<ApiGear::PocoImpl::IOlinkConnector> m_olinkConnector;
    /** The publisher for StructInterface */
    std::unique_ptr<IStructInterfacePublisher> m_publisher;
};
} // namespace olink
} // namespace Testbed1
} // namespace Test
