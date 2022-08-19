
#pragma once

#include "testbed2/generated/api/testbed2.h"
#include "testbed2/generated/api/common.h"
#include "testbed2/generated/core/manyparaminterface.data.h"

#include "olink/clientnode.h"
#include "apigear/olink/olinkclient.h"

#include <future>
#include <memory>

namespace Test {
namespace Testbed2 {
namespace olink {
/**
* Remote ManyParamInterface implemented with OLink. 
* Handles connnectionn with ManyParamInterface service.
* Sends and receives data over the network with ObjectLink protocol. 
* see https://objectlinkprotocol.net for ObjectLink details.
* Use on client side to request changes of the ManyParamInterface on the server side 
* and to subscribe for the ManyParamInterface changes.
*/
class TEST_TESTBED2_EXPORT RemoteManyParamInterface : public IManyParamInterface, public ApiGear::ObjectLink::IObjectSink
{
public:

    /**
    * ctor
    * @param registry The global registry with the sinks and client nodes.
    * @param client Holds the socket, manages the connection and provides ClientNode
    *   which is an abstraction layer between the Client and RemoteManyParamInterface.
    */
    explicit RemoteManyParamInterface(ApiGear::ObjectLink::ClientRegistry& registry, ApiGear::PocoImpl::OLinkClient& client);
    virtual ~RemoteManyParamInterface() override;
    /**
    * Property getter
    * @return Locally stored locally value for Prop1.
    */
    int prop1() const override;
    /**
    * Request setting a property on the ManyParamInterface service.
    * @param The value to which set request is send for the Prop1.
    */
    void setProp1(int prop1) override;
    /**
    * Property getter
    * @return Locally stored locally value for Prop2.
    */
    int prop2() const override;
    /**
    * Request setting a property on the ManyParamInterface service.
    * @param The value to which set request is send for the Prop2.
    */
    void setProp2(int prop2) override;
    /**
    * Property getter
    * @return Locally stored locally value for Prop3.
    */
    int prop3() const override;
    /**
    * Request setting a property on the ManyParamInterface service.
    * @param The value to which set request is send for the Prop3.
    */
    void setProp3(int prop3) override;
    /**
    * Property getter
    * @return Locally stored locally value for Prop4.
    */
    int prop4() const override;
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
    * @param props Initial values obtained from the ManyParamInterface service
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
    * An Olink client node used to connect with a Olink ManyParamInterface service for object given with olinkObjectName() .
    * An abstraction layer over the socket for the RemoteManyParamInterface.
    * WARNING DOROTA if there's a sink already in registry for same name, it is silently disconnected, without the informing
    * it may send requests as long as the pointer to node is valid, but will not receive any data the isReady will not tell the true.
    */
    ApiGear::ObjectLink::IClientNode* m_node = nullptr;
    /** 
    * Registry linking client nodes with sinks for the olinkObjectName().
    * The registerd olinkObjects name must be unique.  
    */
    ApiGear::ObjectLink::ClientRegistry& m_registry;
    /** The publisher for ManyParamInterface */
    std::unique_ptr<IManyParamInterfacePublisher> m_publisher;
};
} // namespace olink
} // namespace Testbed2
} // namespace Test
