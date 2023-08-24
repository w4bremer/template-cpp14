#include "mqttservice.h"
#include "private/mqttcwrapper.h"

using namespace ApiGear::MQTT;

Service::Service(const std::string& clientID)
{
    m_cwrapper = CWrapper::create(clientID);
}

Service::~Service() = default;

const std::string& Service::getClientId() const
{
    return m_cwrapper->getClientId();
}

int Service::subscribeToConnectionStatus(OnConnectionStatusChangedCallBackFunction callBack)
{
    return m_cwrapper->subscribeToConnectionStatus(callBack);
}

void Service::unsubscribeToConnectionStatus(int subscriptionID)
{
    return m_cwrapper->unsubscribeToConnectionStatus(subscriptionID);
}

void Service::connectToHost(const std::string& brokerURL)
{
    m_cwrapper->connectToHost(brokerURL);
}

void Service::disconnect() {
    m_cwrapper->disconnect();
}

void Service::notifyPropertyChange(const std::string& topic, const std::string& value)
{
    m_cwrapper->notifyPropertyChange(topic, value);
}

void Service::notifySignal(const std::string& topic, const std::string& args)
{
    m_cwrapper->notifySignal(topic, args);
}

void Service::notifyInvokeResponse(const std::string& responseTopic, const std::string& value, const std::string& correlationData)
{
    m_cwrapper->notifyInvokeResponse(responseTopic, value, correlationData);
}

void Service::subscribeTopic(const std::string& topic, CallbackFunction func)
{
    m_cwrapper->subscribeTopic(topic, func);
}

void Service::unsubscribeTopic(const std::string& topic)
{
    m_cwrapper->unsubscribeTopic(topic);
}
