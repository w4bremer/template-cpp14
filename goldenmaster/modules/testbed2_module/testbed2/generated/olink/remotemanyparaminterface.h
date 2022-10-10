
#pragma once

#include "testbed2/generated/api/common.h"
#include "testbed2/generated/api/testbed2.h"
#include "testbed2/generated/core/manyparaminterface.data.h"

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
namespace Testbed2 {
namespace olink {
/**
* The class for handling connetion witha a ManyParamInterface service implemented for OLink protocol. 
* Sends and receives data over the network with ObjectLink protocol. 
* see https://objectlinkprotocol.net for ObjectLink details.
* Use on client side to request changes of the ManyParamInterface on the server side 
* and to subscribe for the ManyParamInterface changes.
*/
class TEST_TESTBED2_EXPORT RemoteManyParamInterface : public IManyParamInterface,
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
    explicit RemoteManyParamInterface(std::weak_ptr<ApiGear::PocoImpl::IOlinkConnector> olinkConnector);
    virtual ~RemoteManyParamInterface() override;
    /**
    * Property getter
    * @return Locally stored locally value for Prop1.
    */
    int getProp1() const override;
    /**
    * Request setting a property on the ManyParamInterface service.
    * @param The value to which set request is send for the Prop1.
    */
    void setProp1(int prop1) override;
    /**
    * Property getter
    * @return Locally stored locally value for Prop2.
    */
    int getProp2() const override;
    /**
    * Request setting a property on the ManyParamInterface service.
    * @param The value to which set request is send for the Prop2.
    */
    void setProp2(int prop2) override;
    /**
    * Property getter
    * @return Locally stored locally value for Prop3.
    */
    int getProp3() const override;
    /**
    * Request setting a property on the ManyParamInterface service.
    * @param The value to which set request is send for the Prop3.
    */
    void setProp3(int prop3) override;
    /**
    * Property getter
    * @return Locally stored locally value for Prop4.
    */
    int getProp4() const override;
    /**
    * Request setting a property on the ManyParamInterface service.
    * @param The value to which set request is send for the Prop4.
    */
    void setProp4(int prop4) override;
    /**
    * Remote call of IManyParamInterface::func1 on the ManyParamInterface service.
    * Uses func1Async
    */
    int func1(int param1) override;
    /**
    * Remote call of IManyParamInterface::func1 on the ManyParamInterface service.
    */
    std::future<int> func1Async(int param1) override;
    /**
    * Remote call of IManyParamInterface::func2 on the ManyParamInterface service.
    * Uses func2Async
    */
    int func2(int param1, int param2) override;
    /**
    * Remote call of IManyParamInterface::func2 on the ManyParamInterface service.
    */
    std::future<int> func2Async(int param1, int param2) override;
    /**
    * Remote call of IManyParamInterface::func3 on the ManyParamInterface service.
    * Uses func3Async
    */
    int func3(int param1, int param2, int param3) override;
    /**
    * Remote call of IManyParamInterface::func3 on the ManyParamInterface service.
    */
    std::future<int> func3Async(int param1, int param2, int param3) override;
    /**
    * Remote call of IManyParamInterface::func4 on the ManyParamInterface service.
    * Uses func4Async
    */
    int func4(int param1, int param2, int param3, int param4) override;
    /**
    * Remote call of IManyParamInterface::func4 on the ManyParamInterface service.
    */
    std::future<int> func4Async(int param1, int param2, int param3, int param4) override;

    /** The publisher to subscribe to. */
    IManyParamInterfacePublisher& _getPublisher() const override;
    
    /**
    * Informs if the remote RemoteManyParamInterface is ready to send and revice messages.
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
    * @param props Initial values obtained from the ManyParamInterface service
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
    * @param the data recived from ManyParamInterface service.
    */
    void applyState(const nlohmann::json& fields);
    /**  Updates local value for Prop1 and informs subscriber about the change*/
    void setProp1Local(int prop1);
    /**  Updates local value for Prop2 and informs subscriber about the change*/
    void setProp2Local(int prop2);
    /**  Updates local value for Prop3 and informs subscriber about the change*/
    void setProp3Local(int prop3);
    /**  Updates local value for Prop4 and informs subscriber about the change*/
    void setProp4Local(int prop4);
    
    /** Local storage for properties values. */
    ManyParamInterfaceData m_data;

    /** 
    * An abstraction layer over the connection with service for the RemoteManyParamInterface.
    * Handles incoming and outgoing messages.
    * Is given when object is linked with the service.
    */
    ApiGear::ObjectLink::IClientNode* m_node = nullptr;
    /**
    * A helper used to connect with a Olink ManyParamInterface service for object given with olinkObjectName()
    * takes care of setup and tear down linkage for this RemoteManyParamInterface.
    */
    std::weak_ptr<ApiGear::PocoImpl::IOlinkConnector> m_olinkConnector;
    /** The publisher for ManyParamInterface */
    std::unique_ptr<IManyParamInterfacePublisher> m_publisher;
};
} // namespace olink
} // namespace Testbed2
} // namespace Test
