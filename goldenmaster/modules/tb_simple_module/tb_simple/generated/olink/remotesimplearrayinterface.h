
#pragma once

#include "tb_simple/generated/api/common.h"
#include "tb_simple/generated/api/tb_simple.h"
#include "tb_simple/generated/core/simplearrayinterface.data.h"

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
namespace TbSimple {
namespace olink {
/**
* The class for handling connetion witha a SimpleArrayInterface service implemented for OLink protocol. 
* Sends and receives data over the network with ObjectLink protocol. 
* see https://objectlinkprotocol.net for ObjectLink details.
* Use on client side to request changes of the SimpleArrayInterface on the server side 
* and to subscribe for the SimpleArrayInterface changes.
*/
class TEST_TB_SIMPLE_EXPORT RemoteSimpleArrayInterface : public ISimpleArrayInterface,
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
    explicit RemoteSimpleArrayInterface(std::weak_ptr<ApiGear::PocoImpl::IOlinkConnector> olinkConnector);
    virtual ~RemoteSimpleArrayInterface() override;
    /**
    * Property getter
    * @return Locally stored locally value for PropBool.
    */
    const std::list<bool>& getPropBool() const override;
    /**
    * Request setting a property on the SimpleArrayInterface service.
    * @param The value to which set request is send for the PropBool.
    */
    void setPropBool(const std::list<bool>& propBool) override;
    /**
    * Property getter
    * @return Locally stored locally value for PropInt.
    */
    const std::list<int>& getPropInt() const override;
    /**
    * Request setting a property on the SimpleArrayInterface service.
    * @param The value to which set request is send for the PropInt.
    */
    void setPropInt(const std::list<int>& propInt) override;
    /**
    * Property getter
    * @return Locally stored locally value for PropFloat.
    */
    const std::list<float>& getPropFloat() const override;
    /**
    * Request setting a property on the SimpleArrayInterface service.
    * @param The value to which set request is send for the PropFloat.
    */
    void setPropFloat(const std::list<float>& propFloat) override;
    /**
    * Property getter
    * @return Locally stored locally value for PropString.
    */
    const std::list<std::string>& getPropString() const override;
    /**
    * Request setting a property on the SimpleArrayInterface service.
    * @param The value to which set request is send for the PropString.
    */
    void setPropString(const std::list<std::string>& propString) override;
    /**
    * Remote call of ISimpleArrayInterface::funcBool on the SimpleArrayInterface service.
    * Uses funcBoolAsync
    */
    std::list<bool> funcBool(const std::list<bool>& paramBool) override;
    /**
    * Remote call of ISimpleArrayInterface::funcBool on the SimpleArrayInterface service.
    */
    std::future<std::list<bool>> funcBoolAsync(const std::list<bool>& paramBool) override;
    /**
    * Remote call of ISimpleArrayInterface::funcInt on the SimpleArrayInterface service.
    * Uses funcIntAsync
    */
    std::list<int> funcInt(const std::list<int>& paramInt) override;
    /**
    * Remote call of ISimpleArrayInterface::funcInt on the SimpleArrayInterface service.
    */
    std::future<std::list<int>> funcIntAsync(const std::list<int>& paramInt) override;
    /**
    * Remote call of ISimpleArrayInterface::funcFloat on the SimpleArrayInterface service.
    * Uses funcFloatAsync
    */
    std::list<float> funcFloat(const std::list<float>& paramFloat) override;
    /**
    * Remote call of ISimpleArrayInterface::funcFloat on the SimpleArrayInterface service.
    */
    std::future<std::list<float>> funcFloatAsync(const std::list<float>& paramFloat) override;
    /**
    * Remote call of ISimpleArrayInterface::funcString on the SimpleArrayInterface service.
    * Uses funcStringAsync
    */
    std::list<std::string> funcString(const std::list<std::string>& paramString) override;
    /**
    * Remote call of ISimpleArrayInterface::funcString on the SimpleArrayInterface service.
    */
    std::future<std::list<std::string>> funcStringAsync(const std::list<std::string>& paramString) override;

    /** The publisher to subscribe to. */
    ISimpleArrayInterfacePublisher& _getPublisher() const override;
    
    /**
    * Informs if the remote RemoteSimpleArrayInterface is ready to send and revice messages.
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
    * @param props Initial values obtained from the SimpleArrayInterface service
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
    * @param the data recived from SimpleArrayInterface service.
    */
    void applyState(const nlohmann::json& fields);
    /**  Updates local value for PropBool and informs subscriber about the change*/
    void setPropBoolLocal(const std::list<bool>& propBool);
    /**  Updates local value for PropInt and informs subscriber about the change*/
    void setPropIntLocal(const std::list<int>& propInt);
    /**  Updates local value for PropFloat and informs subscriber about the change*/
    void setPropFloatLocal(const std::list<float>& propFloat);
    /**  Updates local value for PropString and informs subscriber about the change*/
    void setPropStringLocal(const std::list<std::string>& propString);
    
    /** Local storage for properties values. */
    SimpleArrayInterfaceData m_data;

    /** 
    * An abstraction layer over the connection with service for the RemoteSimpleArrayInterface.
    * Handles incoming and outgoing messages.
    * Is given when object is linked with the service.
    */
    ApiGear::ObjectLink::IClientNode* m_node = nullptr;
    /**
    * A helper used to connect with a Olink SimpleArrayInterface service for object given with olinkObjectName()
    * takes care of setup and tear down linkage for this RemoteSimpleArrayInterface.
    */
    std::weak_ptr<ApiGear::PocoImpl::IOlinkConnector> m_olinkConnector;
    /** The publisher for SimpleArrayInterface */
    std::unique_ptr<ISimpleArrayInterfacePublisher> m_publisher;
};
} // namespace olink
} // namespace TbSimple
} // namespace Test
