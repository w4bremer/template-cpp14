
#pragma once

#include "tb_simple/generated/api/common.h"
#include "tb_simple/generated/api/tb_simple.h"
#include "tb_simple/generated/core/simpleinterface.data.h"

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
* The class for handling connetion witha a SimpleInterface service implemented for OLink protocol. 
* Sends and receives data over the network with ObjectLink protocol. 
* see https://objectlinkprotocol.net for ObjectLink details.
* Use on client side to request changes of the SimpleInterface on the server side 
* and to subscribe for the SimpleInterface changes.
*/
class TEST_TB_SIMPLE_EXPORT RemoteSimpleInterface : public ISimpleInterface,
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
    explicit RemoteSimpleInterface(std::weak_ptr<ApiGear::PocoImpl::IOlinkConnector> olinkConnector);
    virtual ~RemoteSimpleInterface() override;
    /**
    * Property getter
    * @return Locally stored locally value for PropBool.
    */
    bool getPropBool() const override;
    /**
    * Request setting a property on the SimpleInterface service.
    * @param The value to which set request is send for the PropBool.
    */
    void setPropBool(bool propBool) override;
    /**
    * Property getter
    * @return Locally stored locally value for PropInt.
    */
    int getPropInt() const override;
    /**
    * Request setting a property on the SimpleInterface service.
    * @param The value to which set request is send for the PropInt.
    */
    void setPropInt(int propInt) override;
    /**
    * Property getter
    * @return Locally stored locally value for PropFloat.
    */
    float getPropFloat() const override;
    /**
    * Request setting a property on the SimpleInterface service.
    * @param The value to which set request is send for the PropFloat.
    */
    void setPropFloat(float propFloat) override;
    /**
    * Property getter
    * @return Locally stored locally value for PropString.
    */
    std::string getPropString() const override;
    /**
    * Request setting a property on the SimpleInterface service.
    * @param The value to which set request is send for the PropString.
    */
    void setPropString(const std::string& propString) override;
    /**
    * Remote call of ISimpleInterface::funcBool on the SimpleInterface service.
    * Uses funcBoolAsync
    */
    bool funcBool(bool paramBool) override;
    /**
    * Remote call of ISimpleInterface::funcBool on the SimpleInterface service.
    */
    std::future<bool> funcBoolAsync(bool paramBool) override;
    /**
    * Remote call of ISimpleInterface::funcInt on the SimpleInterface service.
    * Uses funcIntAsync
    */
    int funcInt(int paramInt) override;
    /**
    * Remote call of ISimpleInterface::funcInt on the SimpleInterface service.
    */
    std::future<int> funcIntAsync(int paramInt) override;
    /**
    * Remote call of ISimpleInterface::funcFloat on the SimpleInterface service.
    * Uses funcFloatAsync
    */
    float funcFloat(float paramFloat) override;
    /**
    * Remote call of ISimpleInterface::funcFloat on the SimpleInterface service.
    */
    std::future<float> funcFloatAsync(float paramFloat) override;
    /**
    * Remote call of ISimpleInterface::funcString on the SimpleInterface service.
    * Uses funcStringAsync
    */
    std::string funcString(const std::string& paramString) override;
    /**
    * Remote call of ISimpleInterface::funcString on the SimpleInterface service.
    */
    std::future<std::string> funcStringAsync(const std::string& paramString) override;

    /** The publisher to subscribe to. */
    ISimpleInterfacePublisher& _getPublisher() const override;
    
    /**
    * Informs if the remote RemoteSimpleInterface is ready to send and revice messages.
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
    * @param props Initial values obtained from the SimpleInterface service
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
    * @param the data recived from SimpleInterface service.
    */
    void applyState(const nlohmann::json& fields);
    /**  Updates local value for PropBool and informs subscriber about the change*/
    void setPropBoolLocal(bool propBool);
    /**  Updates local value for PropInt and informs subscriber about the change*/
    void setPropIntLocal(int propInt);
    /**  Updates local value for PropFloat and informs subscriber about the change*/
    void setPropFloatLocal(float propFloat);
    /**  Updates local value for PropString and informs subscriber about the change*/
    void setPropStringLocal(const std::string& propString);
    
    /** Local storage for properties values. */
    SimpleInterfaceData m_data;

    /** 
    * An abstraction layer over the connection with service for the RemoteSimpleInterface.
    * Handles incoming and outgoing messages.
    * Is given when object is linked with the service.
    */
    ApiGear::ObjectLink::IClientNode* m_node = nullptr;
    /**
    * A helper used to connect with a Olink SimpleInterface service for object given with olinkObjectName()
    * takes care of setup and tear down linkage for this RemoteSimpleInterface.
    */
    std::weak_ptr<ApiGear::PocoImpl::IOlinkConnector> m_olinkConnector;
    /** The publisher for SimpleInterface */
    std::unique_ptr<ISimpleInterfacePublisher> m_publisher;
};
} // namespace olink
} // namespace TbSimple
} // namespace Test
