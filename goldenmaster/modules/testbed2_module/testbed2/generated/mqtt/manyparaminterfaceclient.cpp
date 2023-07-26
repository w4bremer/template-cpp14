#include "testbed2/generated/mqtt/manyparaminterfaceclient.h"
#include "testbed2/generated/core/manyparaminterface.publisher.h"
#include "testbed2/generated/core/testbed2.json.adapter.h"
#include <random>

using namespace Test::Testbed2;
using namespace Test::Testbed2::MQTT;

namespace {
    std::mt19937 randomNumberGenerator (std::random_device{}());
}

ManyParamInterfaceClient::ManyParamInterfaceClient(std::shared_ptr<ApiGear::MQTT::Client> client)
    : m_isReady(false)
    , m_client(client)
    , m_publisher(std::make_unique<ManyParamInterfacePublisher>())
{
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed2","ManyParamInterface",ApiGear::MQTT::Topic::TopicType::Property,"prop1"), std::bind(&ManyParamInterfaceClient::onPropertyChanged, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed2","ManyParamInterface",ApiGear::MQTT::Topic::TopicType::Property,"prop2"), std::bind(&ManyParamInterfaceClient::onPropertyChanged, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed2","ManyParamInterface",ApiGear::MQTT::Topic::TopicType::Property,"prop3"), std::bind(&ManyParamInterfaceClient::onPropertyChanged, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed2","ManyParamInterface",ApiGear::MQTT::Topic::TopicType::Property,"prop4"), std::bind(&ManyParamInterfaceClient::onPropertyChanged, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed2","ManyParamInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sig1"), std::bind(&ManyParamInterfaceClient::onSignal, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed2","ManyParamInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sig2"), std::bind(&ManyParamInterfaceClient::onSignal, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed2","ManyParamInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sig3"), std::bind(&ManyParamInterfaceClient::onSignal, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed2","ManyParamInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sig4"), std::bind(&ManyParamInterfaceClient::onSignal, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed2","ManyParamInterface",ApiGear::MQTT::Topic::TopicType::Operation,"func1",m_client->getClientId()+"/result"), std::bind(&ManyParamInterfaceClient::onInvokeReply, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed2","ManyParamInterface",ApiGear::MQTT::Topic::TopicType::Operation,"func2",m_client->getClientId()+"/result"), std::bind(&ManyParamInterfaceClient::onInvokeReply, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed2","ManyParamInterface",ApiGear::MQTT::Topic::TopicType::Operation,"func3",m_client->getClientId()+"/result"), std::bind(&ManyParamInterfaceClient::onInvokeReply, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->subscribeTopic(ApiGear::MQTT::Topic("testbed2","ManyParamInterface",ApiGear::MQTT::Topic::TopicType::Operation,"func4",m_client->getClientId()+"/result"), std::bind(&ManyParamInterfaceClient::onInvokeReply, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
}

ManyParamInterfaceClient::~ManyParamInterfaceClient()
{
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed2","ManyParamInterface",ApiGear::MQTT::Topic::TopicType::Property,"prop1"), std::bind(&ManyParamInterfaceClient::onPropertyChanged, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed2","ManyParamInterface",ApiGear::MQTT::Topic::TopicType::Property,"prop2"), std::bind(&ManyParamInterfaceClient::onPropertyChanged, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed2","ManyParamInterface",ApiGear::MQTT::Topic::TopicType::Property,"prop3"), std::bind(&ManyParamInterfaceClient::onPropertyChanged, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed2","ManyParamInterface",ApiGear::MQTT::Topic::TopicType::Property,"prop4"), std::bind(&ManyParamInterfaceClient::onPropertyChanged, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed2","ManyParamInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sig1"), std::bind(&ManyParamInterfaceClient::onSignal, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed2","ManyParamInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sig2"), std::bind(&ManyParamInterfaceClient::onSignal, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed2","ManyParamInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sig3"), std::bind(&ManyParamInterfaceClient::onSignal, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed2","ManyParamInterface",ApiGear::MQTT::Topic::TopicType::Signal,"sig4"), std::bind(&ManyParamInterfaceClient::onSignal, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed2","ManyParamInterface",ApiGear::MQTT::Topic::TopicType::Operation,"func1",m_client->getClientId()+"/result"), std::bind(&ManyParamInterfaceClient::onInvokeReply, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed2","ManyParamInterface",ApiGear::MQTT::Topic::TopicType::Operation,"func2",m_client->getClientId()+"/result"), std::bind(&ManyParamInterfaceClient::onInvokeReply, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed2","ManyParamInterface",ApiGear::MQTT::Topic::TopicType::Operation,"func3",m_client->getClientId()+"/result"), std::bind(&ManyParamInterfaceClient::onInvokeReply, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    m_client->unsubscribeTopic(ApiGear::MQTT::Topic("testbed2","ManyParamInterface",ApiGear::MQTT::Topic::TopicType::Operation,"func4",m_client->getClientId()+"/result"), std::bind(&ManyParamInterfaceClient::onInvokeReply, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
}

void ManyParamInterfaceClient::applyState(const nlohmann::json& fields) 
{
    if(fields.contains("prop1")) {
        setProp1Local(fields["prop1"].get<int>());
    }
    if(fields.contains("prop2")) {
        setProp2Local(fields["prop2"].get<int>());
    }
    if(fields.contains("prop3")) {
        setProp3Local(fields["prop3"].get<int>());
    }
    if(fields.contains("prop4")) {
        setProp4Local(fields["prop4"].get<int>());
    }
}

void ManyParamInterfaceClient::setProp1(int prop1)
{
    if(m_client == nullptr) {
        return;
    }
    static const auto topic = ApiGear::MQTT::Topic("testbed2","ManyParamInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setprop1");
    m_client->setRemoteProperty(topic, nlohmann::json(prop1).dump());
}

void ManyParamInterfaceClient::setProp1Local(int prop1)
{
    if (m_data.m_prop1 != prop1) {
        m_data.m_prop1 = prop1;
        m_publisher->publishProp1Changed(prop1);
    }
}

int ManyParamInterfaceClient::getProp1() const
{
    return m_data.m_prop1;
}

void ManyParamInterfaceClient::setProp2(int prop2)
{
    if(m_client == nullptr) {
        return;
    }
    static const auto topic = ApiGear::MQTT::Topic("testbed2","ManyParamInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setprop2");
    m_client->setRemoteProperty(topic, nlohmann::json(prop2).dump());
}

void ManyParamInterfaceClient::setProp2Local(int prop2)
{
    if (m_data.m_prop2 != prop2) {
        m_data.m_prop2 = prop2;
        m_publisher->publishProp2Changed(prop2);
    }
}

int ManyParamInterfaceClient::getProp2() const
{
    return m_data.m_prop2;
}

void ManyParamInterfaceClient::setProp3(int prop3)
{
    if(m_client == nullptr) {
        return;
    }
    static const auto topic = ApiGear::MQTT::Topic("testbed2","ManyParamInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setprop3");
    m_client->setRemoteProperty(topic, nlohmann::json(prop3).dump());
}

void ManyParamInterfaceClient::setProp3Local(int prop3)
{
    if (m_data.m_prop3 != prop3) {
        m_data.m_prop3 = prop3;
        m_publisher->publishProp3Changed(prop3);
    }
}

int ManyParamInterfaceClient::getProp3() const
{
    return m_data.m_prop3;
}

void ManyParamInterfaceClient::setProp4(int prop4)
{
    if(m_client == nullptr) {
        return;
    }
    static const auto topic = ApiGear::MQTT::Topic("testbed2","ManyParamInterface",ApiGear::MQTT::Topic::TopicType::Operation,"_setprop4");
    m_client->setRemoteProperty(topic, nlohmann::json(prop4).dump());
}

void ManyParamInterfaceClient::setProp4Local(int prop4)
{
    if (m_data.m_prop4 != prop4) {
        m_data.m_prop4 = prop4;
        m_publisher->publishProp4Changed(prop4);
    }
}

int ManyParamInterfaceClient::getProp4() const
{
    return m_data.m_prop4;
}

int ManyParamInterfaceClient::func1(int param1)
{
    if(m_client == nullptr) {
        return 0;
    }
    int value(func1Async(param1).get());
    return value;
}

std::future<int> ManyParamInterfaceClient::func1Async(int param1)
{
    if(m_client == nullptr) {
        throw std::runtime_error("Client is not initialized");
    }
    return std::async(std::launch::async, [this,
                    param1]()
        {
            std::promise<int> resultPromise;
            static const auto topic = ApiGear::MQTT::Topic("testbed2","ManyParamInterface",ApiGear::MQTT::Topic::TopicType::Operation,"func1");
            static const auto responseTopic = ApiGear::MQTT::Topic(topic.getEncodedTopic() + "/" + m_client->getClientId() + "/result");
            ApiGear::MQTT::InvokeReplyFunc responseHandler = [&resultPromise](ApiGear::MQTT::InvokeReplyArg arg) {
                const int& value = arg.value.get<int>();
                resultPromise.set_value(value);
            };
            auto responseId = registerResponseHandler(responseHandler);
            m_client->invokeRemote(topic, responseTopic,
                nlohmann::json::array({param1}).dump(), responseId);
            return resultPromise.get_future().get();
        }
    );
}

int ManyParamInterfaceClient::func2(int param1, int param2)
{
    if(m_client == nullptr) {
        return 0;
    }
    int value(func2Async(param1, param2).get());
    return value;
}

std::future<int> ManyParamInterfaceClient::func2Async(int param1, int param2)
{
    if(m_client == nullptr) {
        throw std::runtime_error("Client is not initialized");
    }
    return std::async(std::launch::async, [this,
                    param1,
                    param2]()
        {
            std::promise<int> resultPromise;
            static const auto topic = ApiGear::MQTT::Topic("testbed2","ManyParamInterface",ApiGear::MQTT::Topic::TopicType::Operation,"func2");
            static const auto responseTopic = ApiGear::MQTT::Topic(topic.getEncodedTopic() + "/" + m_client->getClientId() + "/result");
            ApiGear::MQTT::InvokeReplyFunc responseHandler = [&resultPromise](ApiGear::MQTT::InvokeReplyArg arg) {
                const int& value = arg.value.get<int>();
                resultPromise.set_value(value);
            };
            auto responseId = registerResponseHandler(responseHandler);
            m_client->invokeRemote(topic, responseTopic,
                nlohmann::json::array({param1, param2}).dump(), responseId);
            return resultPromise.get_future().get();
        }
    );
}

int ManyParamInterfaceClient::func3(int param1, int param2, int param3)
{
    if(m_client == nullptr) {
        return 0;
    }
    int value(func3Async(param1, param2, param3).get());
    return value;
}

std::future<int> ManyParamInterfaceClient::func3Async(int param1, int param2, int param3)
{
    if(m_client == nullptr) {
        throw std::runtime_error("Client is not initialized");
    }
    return std::async(std::launch::async, [this,
                    param1,
                    param2,
                    param3]()
        {
            std::promise<int> resultPromise;
            static const auto topic = ApiGear::MQTT::Topic("testbed2","ManyParamInterface",ApiGear::MQTT::Topic::TopicType::Operation,"func3");
            static const auto responseTopic = ApiGear::MQTT::Topic(topic.getEncodedTopic() + "/" + m_client->getClientId() + "/result");
            ApiGear::MQTT::InvokeReplyFunc responseHandler = [&resultPromise](ApiGear::MQTT::InvokeReplyArg arg) {
                const int& value = arg.value.get<int>();
                resultPromise.set_value(value);
            };
            auto responseId = registerResponseHandler(responseHandler);
            m_client->invokeRemote(topic, responseTopic,
                nlohmann::json::array({param1, param2, param3}).dump(), responseId);
            return resultPromise.get_future().get();
        }
    );
}

int ManyParamInterfaceClient::func4(int param1, int param2, int param3, int param4)
{
    if(m_client == nullptr) {
        return 0;
    }
    int value(func4Async(param1, param2, param3, param4).get());
    return value;
}

std::future<int> ManyParamInterfaceClient::func4Async(int param1, int param2, int param3, int param4)
{
    if(m_client == nullptr) {
        throw std::runtime_error("Client is not initialized");
    }
    return std::async(std::launch::async, [this,
                    param1,
                    param2,
                    param3,
                    param4]()
        {
            std::promise<int> resultPromise;
            static const auto topic = ApiGear::MQTT::Topic("testbed2","ManyParamInterface",ApiGear::MQTT::Topic::TopicType::Operation,"func4");
            static const auto responseTopic = ApiGear::MQTT::Topic(topic.getEncodedTopic() + "/" + m_client->getClientId() + "/result");
            ApiGear::MQTT::InvokeReplyFunc responseHandler = [&resultPromise](ApiGear::MQTT::InvokeReplyArg arg) {
                const int& value = arg.value.get<int>();
                resultPromise.set_value(value);
            };
            auto responseId = registerResponseHandler(responseHandler);
            m_client->invokeRemote(topic, responseTopic,
                nlohmann::json::array({param1, param2, param3, param4}).dump(), responseId);
            return resultPromise.get_future().get();
        }
    );
}

void ManyParamInterfaceClient::onSignal(const ApiGear::MQTT::Topic& topic, const std::string& args, const ApiGear::MQTT::Topic&, const std::string&)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    if(topic.getEntityName() == "sig1") {
        m_publisher->publishSig1(json_args[0].get<int>());
        return;
    }
    if(topic.getEntityName() == "sig2") {
        m_publisher->publishSig2(json_args[0].get<int>(),json_args[1].get<int>());
        return;
    }
    if(topic.getEntityName() == "sig3") {
        m_publisher->publishSig3(json_args[0].get<int>(),json_args[1].get<int>(),json_args[2].get<int>());
        return;
    }
    if(topic.getEntityName() == "sig4") {
        m_publisher->publishSig4(json_args[0].get<int>(),json_args[1].get<int>(),json_args[2].get<int>(),json_args[3].get<int>());
        return;
    }
}

void ManyParamInterfaceClient::onPropertyChanged(const ApiGear::MQTT::Topic& topic, const std::string& args, const ApiGear::MQTT::Topic&, const std::string&)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string& name = topic.getEntityName();
    applyState({ {name, json_args} });
    return;
}

int ManyParamInterfaceClient::registerResponseHandler(ApiGear::MQTT::InvokeReplyFunc handler)
{
    auto responseId = 0;
    std::uniform_int_distribution<> distribution (0, 100000);
    m_responseHandlerMutex.lock();
    do {
        responseId = distribution(randomNumberGenerator);
    } while (m_responseHandlerMap.find(responseId) != m_responseHandlerMap.end());
    m_responseHandlerMap.insert(std::pair<int, ApiGear::MQTT::InvokeReplyFunc>(responseId, handler));
    m_responseHandlerMutex.unlock();

    return responseId;
}

void ManyParamInterfaceClient::onInvokeReply(const ApiGear::MQTT::Topic& /*topic*/, const std::string& args, const ApiGear::MQTT::Topic& /*responseTopic*/, const std::string& correlationData)
{
    const int randomId = std::stoi(correlationData);
    ApiGear::MQTT::InvokeReplyFunc responseHandler {};
    m_responseHandlerMutex.lock();
    if((m_responseHandlerMap.find(randomId) != m_responseHandlerMap.end()))
    {
        responseHandler = m_responseHandlerMap[randomId];
        m_responseHandlerMap.erase(randomId);
    }
    m_responseHandlerMutex.unlock();
    if(responseHandler) {
        const ApiGear::MQTT::InvokeReplyArg response{nlohmann::json::parse(args)};
        responseHandler(response);
    }
}

bool ManyParamInterfaceClient::isReady() const
{
    return m_isReady;
}

IManyParamInterfacePublisher& ManyParamInterfaceClient::_getPublisher() const
{
    return *m_publisher;
}
