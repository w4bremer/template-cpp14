
#pragma once

#include "tb_names/generated/api/tb_names.h"
#include "tb_names/generated/api/common.h"
#include "olink/iobjectsource.h"


namespace ApiGear {
namespace ObjectLink {

class RemoteRegistry;
class IRemoteNode;

}} //namespace ApiGear::ObjectLink

namespace Test {
namespace TbNames {
namespace olink {
/**
* Server side for Names implements the Names service.
* It is a source of data for Names clients.
* Sends and receives data over the network with ObjectLink protocol. 
* see https://objectlinkprotocol.net for Object Link Details
*/
class TEST_TB_NAMES_EXPORT NamesService : public ApiGear::ObjectLink::IObjectSource, public INamesSubscriber
{
public:
    /**
    * ctor
    * @param Names The service source object, the actual Names object which is exposed for remote clients with olink.
    * @param registry The global registry that keeps track of the object source services associated with network nodes.
    */
    explicit NamesService(std::shared_ptr<INames> Names, ApiGear::ObjectLink::RemoteRegistry& registry);
    virtual ~NamesService() override;

    /**
    * The name of the object for which this service is created, object on client side has to have the same name.
    * It serves as an identifier for the source registry, it has to be unique for the pair source object - remote node.
    * Passed in the olink messages as an object identifier.
    */
    std::string olinkObjectName() override;
    /**
    * Applies received method invocation with given arguments on the Names object.
    * @param name Path of the method to invoke. Contains object name and the method name.
    * @param args Arguments required to invoke a method in json format.
    * @return the result of the invoked method (if applicable) that needs to be sent back to the clients.
    */
    nlohmann::json olinkInvoke(const std::string& methodId, const nlohmann::json& args) override;
    /**
    * Applies received change property request to Names object.
    * @param name Path the property to change. Contains object name and the property name.
    * @param args Value in json format requested to set for the property.
    */
    void olinkSetProperty(const std::string& propertyId, const nlohmann::json& value) override;
    /**
    * Informs this service source that the link was established.
    * @param name The name of the object for which link was established.
    * @param the initialized link endpoint.
    */
    void olinkLinked(const std::string& objectId, ApiGear::ObjectLink::IRemoteNode *node) override;
    /**
    * Informs this service source that the link was disconnected and cannot be used anymore.
    */
    void olinkUnlinked(const std::string& objectId) override;

    /**
    * Gets the current state of Names object.
    * @return the set of properties with their current values for the Names object in json format.
    */
    nlohmann::json olinkCollectProperties() override;
    /**
    * Forwards Switch change through network if the connection is established.
    */
    void onSwitchChanged(bool Switch) override;

private:
    /**
    * The Names used for object source.
    */
    std::shared_ptr<INames> m_Names;
    /**
    * A global registry that keeps track of object sources associated with their network layer nodes.
    */
    ApiGear::ObjectLink::RemoteRegistry& m_registry;
};
} // namespace olink
} // namespace TbNames
} // namespace Test
