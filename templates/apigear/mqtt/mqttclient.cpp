#include "mqttclient.h"
#include "private/mqttcwrapper.h"

using namespace ApiGear::MQTT;

Client::Client(const std::string& clientID)
{
    m_cwrapper = CWrapper::create(clientID);
}

Client::~Client() = default;

const std::string& Client::getClientId() const
{
    return m_cwrapper->getClientId();
}

int Client::subscribeToConnectionStatus(OnConnectionStatusChangedCallBackFunction callBack)
{
    return m_cwrapper->subscribeToConnectionStatus(callBack);
}

void Client::unsubscribeToConnectionStatus(int subscriptionID)
{
    return m_cwrapper->unsubscribeToConnectionStatus(subscriptionID);
}

void Client::connectToHost(const std::string& brokerURL)
{
    m_cwrapper->connectToHost(brokerURL);
}

void Client::disconnect() {
    m_cwrapper->disconnect();
}

void Client::invokeRemote(const std::string& topic, const std::string& responseTopic, const std::string& value, int responseId)
{
    m_cwrapper->invokeRemote(topic, responseTopic, value, responseId);
}

void Client::setRemoteProperty(const std::string& topic, const std::string& value)
{
	m_cwrapper->setRemoteProperty(topic, value);
}

void Client::subscribeTopic(const std::string& topic, CallbackFunction func)
{
    m_cwrapper->subscribeTopic(topic, func);
}

void Client::unsubscribeTopic(const std::string& topic, CallbackFunction func)
{
    m_cwrapper->unsubscribeTopic(topic, func);
}
