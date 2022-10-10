#include "connectionstorage.h"
#include "olinkremote.h"

#include "olink/remoteregistry.h"

#include <chrono>
#include <memory>
#include <vector>
#include <iostream>

namespace ApiGear {
namespace PocoImpl {


ConnectionStorage::ConnectionStorage(ApiGear::ObjectLink::RemoteRegistry& registry)
  :m_registry(registry)
{}

void ConnectionStorage::notifyConnectionClosed()
{
	std::unique_lock<std::timed_mutex> lock(m_connectionsMutex, std::defer_lock);
	if (lock.try_lock_for(std::chrono::milliseconds(100))) {
		auto closedBegin = std::remove_if(m_connectionNodes.begin(),
												m_connectionNodes.end(),
												[](const auto& element){return element->isClosed(); });
		// Move closed connections to separate storage to first unlock the m_conectionNodes, and then
		// destroy items, which destructor may take some time to clean up connection and wait for tasks to be done.
		auto connectionNodesToRemove = std::vector<std::shared_ptr<OLinkRemote>>(closedBegin, m_connectionNodes.end());
		m_connectionNodes.erase(closedBegin, m_connectionNodes.end());
		lock.unlock();
	}
}

void ConnectionStorage::addConnection(std::unique_ptr<Poco::Net::WebSocket> connectionSocket)
{
	auto newConnection = std::make_shared<OLinkRemote>(std::move(connectionSocket), *this, m_registry);
	std::unique_lock<std::timed_mutex> lock(m_connectionsMutex, std::defer_lock);
	if (lock.try_lock_for(std::chrono::milliseconds(1000))) {
		m_connectionNodes.push_back(newConnection);
	} else {
		std::cout << "Could not add a new connection, storage was busy. \n";
	}
	lock.unlock();
}

void ConnectionStorage::closeConnections()
{
	// Try lock, to give time for ongoing actions if any
	std::unique_lock<std::timed_mutex> lock(m_connectionsMutex, std::defer_lock);
	if (!lock.try_lock_for(std::chrono::milliseconds(100))){
		std::cout << "Violation of stored connections - removing all while add or remove is performed \n";
	}
	// close connections anyway
	m_connectionNodes.clear();

}


}}   //namespace ApiGear::PocoImpl
