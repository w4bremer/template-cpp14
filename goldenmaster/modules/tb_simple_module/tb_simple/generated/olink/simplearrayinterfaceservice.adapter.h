
#pragma once

#include "tb_simple/generated/api/tb_simple.h"
#include "tb_simple/generated/api/common.h"
#include "olink/remotenode.h"

namespace Test {
namespace TbSimple {
namespace olink {
/**
* Server side for SimpleArrayInterface implements the SimpleArrayInterface service.
* It is a source of data for SimpleArrayInterface clients.
* Sends and receives data over the network with ObjectLink protocol. 
* see https://objectlinkprotocol.net for Object Link Details
*/
class TEST_TB_SIMPLE_EXPORT SimpleArrayInterfaceServiceAdapter : public ApiGear::ObjectLink::IObjectSource, public ISimpleArrayInterfaceSubscriber
{
public:
    /**
    * ctor
    * @param SimpleArrayInterface The service source object, the actual SimpleArrayInterface object which is exposed for remote clients with olink.
    * @param registry The global registry that keeps track of the object source services associated with network nodes.
    */
    explicit SimpleArrayInterfaceServiceAdapter(ISimpleArrayInterface& SimpleArrayInterface, ApiGear::ObjectLink::RemoteRegistry& registry);
    virtual ~SimpleArrayInterfaceServiceAdapter() override;

    /**
    * The name of the object for which this service is created, object on client side has to have the same name.
    * It serves as an identifier for the source registry, it has to be uniqe for the pair source object - remote node.
    * Passed in the olink messages as an object identifier.
    */
    std::string olinkObjectName() override;
    /**
    * Applies recived method invocation with given arguments on the SimpleArrayInterface object.
    * @param name Path of the method to invoke. Contains object name and the method name.
    * @param args Arguments required to invoke a method in json format.
    * @return the result of the invoked method (if applicable) that needs to be sent back to the clients.
    */
    nlohmann::json olinkInvoke(std::string name, nlohmann::json args) override;
    /**
    * Applies recived change property request to SimpleArrayInterface object.
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
    * Gets the current state of SimpleArrayInterface object.
    * @return the set of properties with their current vlues for the SimpleArrayInterface object in json format.
    */
    nlohmann::json olinkCollectProperties() override;
    /**
    * Forwards emited sigBool through network if the connection is established.
    */
    void onSigBool(const std::list<bool>& paramBool) override;
    /**
    * Forwards emited sigInt through network if the connection is established.
    */
    void onSigInt(const std::list<int>& paramInt) override;
    /**
    * Forwards emited sigFloat through network if the connection is established.
    */
    void onSigFloat(const std::list<float>& paramFloat) override;
    /**
    * Forwards emited sigString through network if the connection is established.
    */
    void onSigString(const std::list<std::string>& paramString) override;
    /**
    * Forwards propBool change through network if the connection is established.
    */
    void onPropBoolChanged(const std::list<bool>& Value) override;
    /**
    * Forwards propInt change through network if the connection is established.
    */
    void onPropIntChanged(const std::list<int>& Value) override;
    /**
    * Forwards propFloat change through network if the connection is established.
    */
    void onPropFloatChanged(const std::list<float>& Value) override;
    /**
    * Forwards propString change through network if the connection is established.
    */
    void onPropStringChanged(const std::list<std::string>& Value) override;

private:
    /**
    * The SimpleArrayInterface used for object source.
    */
    ISimpleArrayInterface& m_SimpleArrayInterface;
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
} // namespace TbSimple
} // namespace Test
