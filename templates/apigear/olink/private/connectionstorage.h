#pragma once

#include "iconnectionstorage.h"
#include <mutex>
#include <memory>
#include <vector>

namespace ApiGear
{

// Remote registry forward declaration.
namespace ObjectLink
{
class RemoteRegistry;
}

namespace PocoImpl
{

// OlinkRemote forward declaration
class OLinkRemote;

/**
* Implementation of IConnectionStorage, a class for OLinkHost to store connections.
*/
class ConnectionStorage : public IConnectionStorage
{
public:
	/**ctor
	* @param registry A global registry to which network endpoints are added for olink objects.
	*/
	ConnectionStorage(ApiGear::ObjectLink::RemoteRegistry& registry);
	/** Close all connections.*/
	void closeConnections();

	/**IConnectionStorage::addConnection implementation*/
	void addConnection(std::unique_ptr<Poco::Net::WebSocket> connectionSocket) override;
	/**IConnectionStorage::notifyConnectionClosed implementation*/
	void notifyConnectionClosed() override;
private:
	/**A global registry to which network endpoints will be added for olink objects.*/
	ApiGear::ObjectLink::RemoteRegistry& m_registry;
	/** Collection of server connections*/
	std::vector<std::shared_ptr<OLinkRemote>> m_connectionNodes;
	/** Mutex for connection storage*/
	std::timed_mutex m_connectionsMutex;
};

}}   //namespace ApiGear::PocoImpl
