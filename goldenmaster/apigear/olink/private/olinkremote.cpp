
#include "Poco/Net/WebSocket.h"

#include "private/olinkremote.h"
#include "private/requesthandlerfactory.h"
#include "private/iconnectionstorage.h"

#include "olink/remotenode.h"
#include "olink/remoteregistry.h"
#include "../utilities/logger.h"

#include <iostream>

namespace ApiGear {
namespace PocoImpl {

OLinkRemote::OLinkRemote(std::unique_ptr<Poco::Net::WebSocket> socket, IConnectionStorage& connectionStorage, ApiGear::ObjectLink::RemoteRegistry& registry)
    : m_socket(*this),
     m_connectionStorage(connectionStorage),
     m_node(ApiGear::ObjectLink::RemoteNode::createRemoteNode(registry))
{
    m_node->onLog(m_log.logFunc());
    m_node->onWrite([this](std::string msg) {
        m_socket.writeMessage(msg, Poco::Net::WebSocket::FRAME_TEXT);
    });
    m_socket.changeSocket(std::move(socket));
}

OLinkRemote::~OLinkRemote()
{
    if(!m_socket.isClosed())
    {
        m_socket.close();
    }
}

void OLinkRemote::handleTextMessage(const std::string& msg)
{
    AG_LOG_DEBUG("handleTextMessage " + msg);
    if (m_node)
    {
        m_node->handleMessage(msg);
    }
}

void OLinkRemote::onConnectionClosedFromNetwork()
{
    m_connectionStorage.notifyConnectionClosed();
}

bool OLinkRemote::isClosed() const
{
    return m_socket.isClosed();
}

}}  //namespace ApiGear::PocoImpl
