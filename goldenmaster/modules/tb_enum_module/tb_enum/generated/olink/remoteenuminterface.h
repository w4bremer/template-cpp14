
#pragma once

#include "tb_enum/generated/api/common.h"
#include "tb_enum/generated/api/tb_enum.h"
#include "tb_enum/generated/core/enuminterface.data.h"

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
namespace TbEnum {
namespace olink {
/**
* The class for handling connetion witha a EnumInterface service implemented for OLink protocol. 
* Sends and receives data over the network with ObjectLink protocol. 
* see https://objectlinkprotocol.net for ObjectLink details.
* Use on client side to request changes of the EnumInterface on the server side 
* and to subscribe for the EnumInterface changes.
*/
class TEST_TB_ENUM_EXPORT RemoteEnumInterface : public IEnumInterface,
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
    explicit RemoteEnumInterface(std::weak_ptr<ApiGear::PocoImpl::IOlinkConnector> olinkConnector);
    virtual ~RemoteEnumInterface() override;
    /**
    * Property getter
    * @return Locally stored locally value for Prop0.
    */
    const Enum0Enum& getProp0() const override;
    /**
    * Request setting a property on the EnumInterface service.
    * @param The value to which set request is send for the Prop0.
    */
    void setProp0(const Enum0Enum& prop0) override;
    /**
    * Property getter
    * @return Locally stored locally value for Prop1.
    */
    const Enum1Enum& getProp1() const override;
    /**
    * Request setting a property on the EnumInterface service.
    * @param The value to which set request is send for the Prop1.
    */
    void setProp1(const Enum1Enum& prop1) override;
    /**
    * Property getter
    * @return Locally stored locally value for Prop2.
    */
    const Enum2Enum& getProp2() const override;
    /**
    * Request setting a property on the EnumInterface service.
    * @param The value to which set request is send for the Prop2.
    */
    void setProp2(const Enum2Enum& prop2) override;
    /**
    * Property getter
    * @return Locally stored locally value for Prop3.
    */
    const Enum3Enum& getProp3() const override;
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
    * Informs if the remote RemoteEnumInterface is ready to send and revice messages.
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
    * @param props Initial values obtained from the EnumInterface service
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
    * An abstraction layer over the connection with service for the RemoteEnumInterface.
    * Handles incoming and outgoing messages.
    * Is given when object is linked with the service.
    */
    ApiGear::ObjectLink::IClientNode* m_node = nullptr;
    /**
    * A helper used to connect with a Olink EnumInterface service for object given with olinkObjectName()
    * takes care of setup and tear down linkage for this RemoteEnumInterface.
    */
    std::weak_ptr<ApiGear::PocoImpl::IOlinkConnector> m_olinkConnector;
    /** The publisher for EnumInterface */
    std::unique_ptr<IEnumInterfacePublisher> m_publisher;
};
} // namespace olink
} // namespace TbEnum
} // namespace Test
