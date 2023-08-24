#include "tb_simple/generated/mqtt/simpleinterfaceclient.h"
#include "tb_simple/generated/core/simpleinterface.publisher.h"
#include "tb_simple/generated/core/tb_simple.json.adapter.h"
#include "apigear/mqtt/mqtttopic.h"
#include <random>

using namespace Test::TbSimple;
using namespace Test::TbSimple::MQTT;

namespace {
    std::mt19937 randomNumberGenerator (std::random_device{}());
}

SimpleInterfaceClient::SimpleInterfaceClient(std::shared_ptr<ApiGear::MQTT::Client> client)
    : m_isReady(false)
    , m_client(client)
    , m_publisher(std::make_unique<SimpleInterfacePublisher>())
{
    m_client->subscribeTopic(std::string("tb.simple/SimpleInterface/prop/propBool"), [this](const std::string& topic, const std::string& args, const std::string&, const std::string&){ onPropertyChanged(topic, args, "", ""); });
    m_client->subscribeTopic(std::string("tb.simple/SimpleInterface/prop/propInt"), [this](const std::string& topic, const std::string& args, const std::string&, const std::string&){ onPropertyChanged(topic, args, "", ""); });
    m_client->subscribeTopic(std::string("tb.simple/SimpleInterface/prop/propInt32"), [this](const std::string& topic, const std::string& args, const std::string&, const std::string&){ onPropertyChanged(topic, args, "", ""); });
    m_client->subscribeTopic(std::string("tb.simple/SimpleInterface/prop/propInt64"), [this](const std::string& topic, const std::string& args, const std::string&, const std::string&){ onPropertyChanged(topic, args, "", ""); });
    m_client->subscribeTopic(std::string("tb.simple/SimpleInterface/prop/propFloat"), [this](const std::string& topic, const std::string& args, const std::string&, const std::string&){ onPropertyChanged(topic, args, "", ""); });
    m_client->subscribeTopic(std::string("tb.simple/SimpleInterface/prop/propFloat32"), [this](const std::string& topic, const std::string& args, const std::string&, const std::string&){ onPropertyChanged(topic, args, "", ""); });
    m_client->subscribeTopic(std::string("tb.simple/SimpleInterface/prop/propFloat64"), [this](const std::string& topic, const std::string& args, const std::string&, const std::string&){ onPropertyChanged(topic, args, "", ""); });
    m_client->subscribeTopic(std::string("tb.simple/SimpleInterface/prop/propString"), [this](const std::string& topic, const std::string& args, const std::string&, const std::string&){ onPropertyChanged(topic, args, "", ""); });
    m_client->subscribeTopic(std::string("tb.simple/SimpleInterface/sig/sigBool"), [this](const std::string& topic, const std::string& args, const std::string&, const std::string&){ onSignal(topic, args, "", ""); });
    m_client->subscribeTopic(std::string("tb.simple/SimpleInterface/sig/sigInt"), [this](const std::string& topic, const std::string& args, const std::string&, const std::string&){ onSignal(topic, args, "", ""); });
    m_client->subscribeTopic(std::string("tb.simple/SimpleInterface/sig/sigInt32"), [this](const std::string& topic, const std::string& args, const std::string&, const std::string&){ onSignal(topic, args, "", ""); });
    m_client->subscribeTopic(std::string("tb.simple/SimpleInterface/sig/sigInt64"), [this](const std::string& topic, const std::string& args, const std::string&, const std::string&){ onSignal(topic, args, "", ""); });
    m_client->subscribeTopic(std::string("tb.simple/SimpleInterface/sig/sigFloat"), [this](const std::string& topic, const std::string& args, const std::string&, const std::string&){ onSignal(topic, args, "", ""); });
    m_client->subscribeTopic(std::string("tb.simple/SimpleInterface/sig/sigFloat32"), [this](const std::string& topic, const std::string& args, const std::string&, const std::string&){ onSignal(topic, args, "", ""); });
    m_client->subscribeTopic(std::string("tb.simple/SimpleInterface/sig/sigFloat64"), [this](const std::string& topic, const std::string& args, const std::string&, const std::string&){ onSignal(topic, args, "", ""); });
    m_client->subscribeTopic(std::string("tb.simple/SimpleInterface/sig/sigString"), [this](const std::string& topic, const std::string& args, const std::string&, const std::string&){ onSignal(topic, args, "", ""); });
    m_client->subscribeTopic(std::string("tb.simple/SimpleInterface/rpc/funcBool/"+m_client->getClientId()+"/result"), [this](const std::string&, const std::string& args, const std::string&, const std::string& correlationData){ onInvokeReply("", args, "", correlationData); });
    m_client->subscribeTopic(std::string("tb.simple/SimpleInterface/rpc/funcInt/"+m_client->getClientId()+"/result"), [this](const std::string&, const std::string& args, const std::string&, const std::string& correlationData){ onInvokeReply("", args, "", correlationData); });
    m_client->subscribeTopic(std::string("tb.simple/SimpleInterface/rpc/funcInt32/"+m_client->getClientId()+"/result"), [this](const std::string&, const std::string& args, const std::string&, const std::string& correlationData){ onInvokeReply("", args, "", correlationData); });
    m_client->subscribeTopic(std::string("tb.simple/SimpleInterface/rpc/funcInt64/"+m_client->getClientId()+"/result"), [this](const std::string&, const std::string& args, const std::string&, const std::string& correlationData){ onInvokeReply("", args, "", correlationData); });
    m_client->subscribeTopic(std::string("tb.simple/SimpleInterface/rpc/funcFloat/"+m_client->getClientId()+"/result"), [this](const std::string&, const std::string& args, const std::string&, const std::string& correlationData){ onInvokeReply("", args, "", correlationData); });
    m_client->subscribeTopic(std::string("tb.simple/SimpleInterface/rpc/funcFloat32/"+m_client->getClientId()+"/result"), [this](const std::string&, const std::string& args, const std::string&, const std::string& correlationData){ onInvokeReply("", args, "", correlationData); });
    m_client->subscribeTopic(std::string("tb.simple/SimpleInterface/rpc/funcFloat64/"+m_client->getClientId()+"/result"), [this](const std::string&, const std::string& args, const std::string&, const std::string& correlationData){ onInvokeReply("", args, "", correlationData); });
    m_client->subscribeTopic(std::string("tb.simple/SimpleInterface/rpc/funcString/"+m_client->getClientId()+"/result"), [this](const std::string&, const std::string& args, const std::string&, const std::string& correlationData){ onInvokeReply("", args, "", correlationData); });
}

SimpleInterfaceClient::~SimpleInterfaceClient()
{
    m_client->unsubscribeTopic(std::string("tb.simple/SimpleInterface/prop/propBool"));
    m_client->unsubscribeTopic(std::string("tb.simple/SimpleInterface/prop/propInt"));
    m_client->unsubscribeTopic(std::string("tb.simple/SimpleInterface/prop/propInt32"));
    m_client->unsubscribeTopic(std::string("tb.simple/SimpleInterface/prop/propInt64"));
    m_client->unsubscribeTopic(std::string("tb.simple/SimpleInterface/prop/propFloat"));
    m_client->unsubscribeTopic(std::string("tb.simple/SimpleInterface/prop/propFloat32"));
    m_client->unsubscribeTopic(std::string("tb.simple/SimpleInterface/prop/propFloat64"));
    m_client->unsubscribeTopic(std::string("tb.simple/SimpleInterface/prop/propString"));
    m_client->unsubscribeTopic(std::string("tb.simple/SimpleInterface/sig/sigBool"));
    m_client->unsubscribeTopic(std::string("tb.simple/SimpleInterface/sig/sigInt"));
    m_client->unsubscribeTopic(std::string("tb.simple/SimpleInterface/sig/sigInt32"));
    m_client->unsubscribeTopic(std::string("tb.simple/SimpleInterface/sig/sigInt64"));
    m_client->unsubscribeTopic(std::string("tb.simple/SimpleInterface/sig/sigFloat"));
    m_client->unsubscribeTopic(std::string("tb.simple/SimpleInterface/sig/sigFloat32"));
    m_client->unsubscribeTopic(std::string("tb.simple/SimpleInterface/sig/sigFloat64"));
    m_client->unsubscribeTopic(std::string("tb.simple/SimpleInterface/sig/sigString"));
    m_client->unsubscribeTopic(std::string("tb.simple/SimpleInterface/rpc/funcBool/"+m_client->getClientId()+"/result"));
    m_client->unsubscribeTopic(std::string("tb.simple/SimpleInterface/rpc/funcInt/"+m_client->getClientId()+"/result"));
    m_client->unsubscribeTopic(std::string("tb.simple/SimpleInterface/rpc/funcInt32/"+m_client->getClientId()+"/result"));
    m_client->unsubscribeTopic(std::string("tb.simple/SimpleInterface/rpc/funcInt64/"+m_client->getClientId()+"/result"));
    m_client->unsubscribeTopic(std::string("tb.simple/SimpleInterface/rpc/funcFloat/"+m_client->getClientId()+"/result"));
    m_client->unsubscribeTopic(std::string("tb.simple/SimpleInterface/rpc/funcFloat32/"+m_client->getClientId()+"/result"));
    m_client->unsubscribeTopic(std::string("tb.simple/SimpleInterface/rpc/funcFloat64/"+m_client->getClientId()+"/result"));
    m_client->unsubscribeTopic(std::string("tb.simple/SimpleInterface/rpc/funcString/"+m_client->getClientId()+"/result"));
}

void SimpleInterfaceClient::applyState(const nlohmann::json& fields) 
{
    if(fields.contains("propBool")) {
        setPropBoolLocal(fields["propBool"].get<bool>());
    }
    if(fields.contains("propInt")) {
        setPropIntLocal(fields["propInt"].get<int>());
    }
    if(fields.contains("propInt32")) {
        setPropInt32Local(fields["propInt32"].get<int32_t>());
    }
    if(fields.contains("propInt64")) {
        setPropInt64Local(fields["propInt64"].get<int64_t>());
    }
    if(fields.contains("propFloat")) {
        setPropFloatLocal(fields["propFloat"].get<float>());
    }
    if(fields.contains("propFloat32")) {
        setPropFloat32Local(fields["propFloat32"].get<float>());
    }
    if(fields.contains("propFloat64")) {
        setPropFloat64Local(fields["propFloat64"].get<double>());
    }
    if(fields.contains("propString")) {
        setPropStringLocal(fields["propString"].get<std::string>());
    }
}

void SimpleInterfaceClient::setPropBool(bool propBool)
{
    if(m_client == nullptr) {
        return;
    }
    static const auto topic = std::string("tb.simple/SimpleInterface/set/propBool");
    m_client->setRemoteProperty(topic, nlohmann::json(propBool).dump());
}

void SimpleInterfaceClient::setPropBoolLocal(bool propBool)
{
    if (m_data.m_propBool != propBool) {
        m_data.m_propBool = propBool;
        m_publisher->publishPropBoolChanged(propBool);
    }
}

bool SimpleInterfaceClient::getPropBool() const
{
    return m_data.m_propBool;
}

void SimpleInterfaceClient::setPropInt(int propInt)
{
    if(m_client == nullptr) {
        return;
    }
    static const auto topic = std::string("tb.simple/SimpleInterface/set/propInt");
    m_client->setRemoteProperty(topic, nlohmann::json(propInt).dump());
}

void SimpleInterfaceClient::setPropIntLocal(int propInt)
{
    if (m_data.m_propInt != propInt) {
        m_data.m_propInt = propInt;
        m_publisher->publishPropIntChanged(propInt);
    }
}

int SimpleInterfaceClient::getPropInt() const
{
    return m_data.m_propInt;
}

void SimpleInterfaceClient::setPropInt32(int32_t propInt32)
{
    if(m_client == nullptr) {
        return;
    }
    static const auto topic = std::string("tb.simple/SimpleInterface/set/propInt32");
    m_client->setRemoteProperty(topic, nlohmann::json(propInt32).dump());
}

void SimpleInterfaceClient::setPropInt32Local(int32_t propInt32)
{
    if (m_data.m_propInt32 != propInt32) {
        m_data.m_propInt32 = propInt32;
        m_publisher->publishPropInt32Changed(propInt32);
    }
}

int32_t SimpleInterfaceClient::getPropInt32() const
{
    return m_data.m_propInt32;
}

void SimpleInterfaceClient::setPropInt64(int64_t propInt64)
{
    if(m_client == nullptr) {
        return;
    }
    static const auto topic = std::string("tb.simple/SimpleInterface/set/propInt64");
    m_client->setRemoteProperty(topic, nlohmann::json(propInt64).dump());
}

void SimpleInterfaceClient::setPropInt64Local(int64_t propInt64)
{
    if (m_data.m_propInt64 != propInt64) {
        m_data.m_propInt64 = propInt64;
        m_publisher->publishPropInt64Changed(propInt64);
    }
}

int64_t SimpleInterfaceClient::getPropInt64() const
{
    return m_data.m_propInt64;
}

void SimpleInterfaceClient::setPropFloat(float propFloat)
{
    if(m_client == nullptr) {
        return;
    }
    static const auto topic = std::string("tb.simple/SimpleInterface/set/propFloat");
    m_client->setRemoteProperty(topic, nlohmann::json(propFloat).dump());
}

void SimpleInterfaceClient::setPropFloatLocal(float propFloat)
{
    if (m_data.m_propFloat != propFloat) {
        m_data.m_propFloat = propFloat;
        m_publisher->publishPropFloatChanged(propFloat);
    }
}

float SimpleInterfaceClient::getPropFloat() const
{
    return m_data.m_propFloat;
}

void SimpleInterfaceClient::setPropFloat32(float propFloat32)
{
    if(m_client == nullptr) {
        return;
    }
    static const auto topic = std::string("tb.simple/SimpleInterface/set/propFloat32");
    m_client->setRemoteProperty(topic, nlohmann::json(propFloat32).dump());
}

void SimpleInterfaceClient::setPropFloat32Local(float propFloat32)
{
    if (m_data.m_propFloat32 != propFloat32) {
        m_data.m_propFloat32 = propFloat32;
        m_publisher->publishPropFloat32Changed(propFloat32);
    }
}

float SimpleInterfaceClient::getPropFloat32() const
{
    return m_data.m_propFloat32;
}

void SimpleInterfaceClient::setPropFloat64(double propFloat64)
{
    if(m_client == nullptr) {
        return;
    }
    static const auto topic = std::string("tb.simple/SimpleInterface/set/propFloat64");
    m_client->setRemoteProperty(topic, nlohmann::json(propFloat64).dump());
}

void SimpleInterfaceClient::setPropFloat64Local(double propFloat64)
{
    if (m_data.m_propFloat64 != propFloat64) {
        m_data.m_propFloat64 = propFloat64;
        m_publisher->publishPropFloat64Changed(propFloat64);
    }
}

double SimpleInterfaceClient::getPropFloat64() const
{
    return m_data.m_propFloat64;
}

void SimpleInterfaceClient::setPropString(const std::string& propString)
{
    if(m_client == nullptr) {
        return;
    }
    static const auto topic = std::string("tb.simple/SimpleInterface/set/propString");
    m_client->setRemoteProperty(topic, nlohmann::json(propString).dump());
}

void SimpleInterfaceClient::setPropStringLocal(const std::string& propString)
{
    if (m_data.m_propString != propString) {
        m_data.m_propString = propString;
        m_publisher->publishPropStringChanged(propString);
    }
}

const std::string& SimpleInterfaceClient::getPropString() const
{
    return m_data.m_propString;
}

bool SimpleInterfaceClient::funcBool(bool paramBool)
{
    if(m_client == nullptr) {
        return false;
    }
    bool value(funcBoolAsync(paramBool).get());
    return value;
}

std::future<bool> SimpleInterfaceClient::funcBoolAsync(bool paramBool)
{
    if(m_client == nullptr) {
        throw std::runtime_error("Client is not initialized");
    }
    return std::async(std::launch::async, [this,
                    paramBool]()
        {
            std::promise<bool> resultPromise;
            static const auto topic = std::string("tb.simple/SimpleInterface/rpc/funcBool");
            static const auto responseTopic = std::string(topic + "/" + m_client->getClientId() + "/result");
            ApiGear::MQTT::InvokeReplyFunc responseHandler = [&resultPromise](ApiGear::MQTT::InvokeReplyArg arg) {
                const bool& value = arg.value.get<bool>();
                resultPromise.set_value(value);
            };
            auto responseId = registerResponseHandler(responseHandler);
            m_client->invokeRemote(topic, responseTopic,
                nlohmann::json::array({paramBool}).dump(), responseId);
            return resultPromise.get_future().get();
        }
    );
}

int SimpleInterfaceClient::funcInt(int paramInt)
{
    if(m_client == nullptr) {
        return 0;
    }
    int value(funcIntAsync(paramInt).get());
    return value;
}

std::future<int> SimpleInterfaceClient::funcIntAsync(int paramInt)
{
    if(m_client == nullptr) {
        throw std::runtime_error("Client is not initialized");
    }
    return std::async(std::launch::async, [this,
                    paramInt]()
        {
            std::promise<int> resultPromise;
            static const auto topic = std::string("tb.simple/SimpleInterface/rpc/funcInt");
            static const auto responseTopic = std::string(topic + "/" + m_client->getClientId() + "/result");
            ApiGear::MQTT::InvokeReplyFunc responseHandler = [&resultPromise](ApiGear::MQTT::InvokeReplyArg arg) {
                const int& value = arg.value.get<int>();
                resultPromise.set_value(value);
            };
            auto responseId = registerResponseHandler(responseHandler);
            m_client->invokeRemote(topic, responseTopic,
                nlohmann::json::array({paramInt}).dump(), responseId);
            return resultPromise.get_future().get();
        }
    );
}

int32_t SimpleInterfaceClient::funcInt32(int32_t paramInt32)
{
    if(m_client == nullptr) {
        return 0;
    }
    int32_t value(funcInt32Async(paramInt32).get());
    return value;
}

std::future<int32_t> SimpleInterfaceClient::funcInt32Async(int32_t paramInt32)
{
    if(m_client == nullptr) {
        throw std::runtime_error("Client is not initialized");
    }
    return std::async(std::launch::async, [this,
                    paramInt32]()
        {
            std::promise<int32_t> resultPromise;
            static const auto topic = std::string("tb.simple/SimpleInterface/rpc/funcInt32");
            static const auto responseTopic = std::string(topic + "/" + m_client->getClientId() + "/result");
            ApiGear::MQTT::InvokeReplyFunc responseHandler = [&resultPromise](ApiGear::MQTT::InvokeReplyArg arg) {
                const int32_t& value = arg.value.get<int32_t>();
                resultPromise.set_value(value);
            };
            auto responseId = registerResponseHandler(responseHandler);
            m_client->invokeRemote(topic, responseTopic,
                nlohmann::json::array({paramInt32}).dump(), responseId);
            return resultPromise.get_future().get();
        }
    );
}

int64_t SimpleInterfaceClient::funcInt64(int64_t paramInt64)
{
    if(m_client == nullptr) {
        return 0LL;
    }
    int64_t value(funcInt64Async(paramInt64).get());
    return value;
}

std::future<int64_t> SimpleInterfaceClient::funcInt64Async(int64_t paramInt64)
{
    if(m_client == nullptr) {
        throw std::runtime_error("Client is not initialized");
    }
    return std::async(std::launch::async, [this,
                    paramInt64]()
        {
            std::promise<int64_t> resultPromise;
            static const auto topic = std::string("tb.simple/SimpleInterface/rpc/funcInt64");
            static const auto responseTopic = std::string(topic + "/" + m_client->getClientId() + "/result");
            ApiGear::MQTT::InvokeReplyFunc responseHandler = [&resultPromise](ApiGear::MQTT::InvokeReplyArg arg) {
                const int64_t& value = arg.value.get<int64_t>();
                resultPromise.set_value(value);
            };
            auto responseId = registerResponseHandler(responseHandler);
            m_client->invokeRemote(topic, responseTopic,
                nlohmann::json::array({paramInt64}).dump(), responseId);
            return resultPromise.get_future().get();
        }
    );
}

float SimpleInterfaceClient::funcFloat(float paramFloat)
{
    if(m_client == nullptr) {
        return 0.0f;
    }
    float value(funcFloatAsync(paramFloat).get());
    return value;
}

std::future<float> SimpleInterfaceClient::funcFloatAsync(float paramFloat)
{
    if(m_client == nullptr) {
        throw std::runtime_error("Client is not initialized");
    }
    return std::async(std::launch::async, [this,
                    paramFloat]()
        {
            std::promise<float> resultPromise;
            static const auto topic = std::string("tb.simple/SimpleInterface/rpc/funcFloat");
            static const auto responseTopic = std::string(topic + "/" + m_client->getClientId() + "/result");
            ApiGear::MQTT::InvokeReplyFunc responseHandler = [&resultPromise](ApiGear::MQTT::InvokeReplyArg arg) {
                const float& value = arg.value.get<float>();
                resultPromise.set_value(value);
            };
            auto responseId = registerResponseHandler(responseHandler);
            m_client->invokeRemote(topic, responseTopic,
                nlohmann::json::array({paramFloat}).dump(), responseId);
            return resultPromise.get_future().get();
        }
    );
}

float SimpleInterfaceClient::funcFloat32(float paramFloat32)
{
    if(m_client == nullptr) {
        return 0.0f;
    }
    float value(funcFloat32Async(paramFloat32).get());
    return value;
}

std::future<float> SimpleInterfaceClient::funcFloat32Async(float paramFloat32)
{
    if(m_client == nullptr) {
        throw std::runtime_error("Client is not initialized");
    }
    return std::async(std::launch::async, [this,
                    paramFloat32]()
        {
            std::promise<float> resultPromise;
            static const auto topic = std::string("tb.simple/SimpleInterface/rpc/funcFloat32");
            static const auto responseTopic = std::string(topic + "/" + m_client->getClientId() + "/result");
            ApiGear::MQTT::InvokeReplyFunc responseHandler = [&resultPromise](ApiGear::MQTT::InvokeReplyArg arg) {
                const float& value = arg.value.get<float>();
                resultPromise.set_value(value);
            };
            auto responseId = registerResponseHandler(responseHandler);
            m_client->invokeRemote(topic, responseTopic,
                nlohmann::json::array({paramFloat32}).dump(), responseId);
            return resultPromise.get_future().get();
        }
    );
}

double SimpleInterfaceClient::funcFloat64(double paramFloat)
{
    if(m_client == nullptr) {
        return 0.0;
    }
    double value(funcFloat64Async(paramFloat).get());
    return value;
}

std::future<double> SimpleInterfaceClient::funcFloat64Async(double paramFloat)
{
    if(m_client == nullptr) {
        throw std::runtime_error("Client is not initialized");
    }
    return std::async(std::launch::async, [this,
                    paramFloat]()
        {
            std::promise<double> resultPromise;
            static const auto topic = std::string("tb.simple/SimpleInterface/rpc/funcFloat64");
            static const auto responseTopic = std::string(topic + "/" + m_client->getClientId() + "/result");
            ApiGear::MQTT::InvokeReplyFunc responseHandler = [&resultPromise](ApiGear::MQTT::InvokeReplyArg arg) {
                const double& value = arg.value.get<double>();
                resultPromise.set_value(value);
            };
            auto responseId = registerResponseHandler(responseHandler);
            m_client->invokeRemote(topic, responseTopic,
                nlohmann::json::array({paramFloat}).dump(), responseId);
            return resultPromise.get_future().get();
        }
    );
}

std::string SimpleInterfaceClient::funcString(const std::string& paramString)
{
    if(m_client == nullptr) {
        return std::string();
    }
    std::string value(funcStringAsync(paramString).get());
    return value;
}

std::future<std::string> SimpleInterfaceClient::funcStringAsync(const std::string& paramString)
{
    if(m_client == nullptr) {
        throw std::runtime_error("Client is not initialized");
    }
    return std::async(std::launch::async, [this,
                    paramString]()
        {
            std::promise<std::string> resultPromise;
            static const auto topic = std::string("tb.simple/SimpleInterface/rpc/funcString");
            static const auto responseTopic = std::string(topic + "/" + m_client->getClientId() + "/result");
            ApiGear::MQTT::InvokeReplyFunc responseHandler = [&resultPromise](ApiGear::MQTT::InvokeReplyArg arg) {
                const std::string& value = arg.value.get<std::string>();
                resultPromise.set_value(value);
            };
            auto responseId = registerResponseHandler(responseHandler);
            m_client->invokeRemote(topic, responseTopic,
                nlohmann::json::array({paramString}).dump(), responseId);
            return resultPromise.get_future().get();
        }
    );
}

void SimpleInterfaceClient::onSignal(const std::string& topic, const std::string& args, const std::string&, const std::string&)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string entityName = ApiGear::MQTT::Topic(topic).getEntityName();
    if(entityName == "sigBool") {
        m_publisher->publishSigBool(json_args[0].get<bool>());
        return;
    }
    if(entityName == "sigInt") {
        m_publisher->publishSigInt(json_args[0].get<int>());
        return;
    }
    if(entityName == "sigInt32") {
        m_publisher->publishSigInt32(json_args[0].get<int32_t>());
        return;
    }
    if(entityName == "sigInt64") {
        m_publisher->publishSigInt64(json_args[0].get<int64_t>());
        return;
    }
    if(entityName == "sigFloat") {
        m_publisher->publishSigFloat(json_args[0].get<float>());
        return;
    }
    if(entityName == "sigFloat32") {
        m_publisher->publishSigFloat32(json_args[0].get<float>());
        return;
    }
    if(entityName == "sigFloat64") {
        m_publisher->publishSigFloat64(json_args[0].get<double>());
        return;
    }
    if(entityName == "sigString") {
        m_publisher->publishSigString(json_args[0].get<std::string>());
        return;
    }
}

void SimpleInterfaceClient::onPropertyChanged(const std::string& topic, const std::string& args, const std::string&, const std::string&)
{
    nlohmann::json json_args = nlohmann::json::parse(args);
    const std::string& name = ApiGear::MQTT::Topic(topic).getEntityName();
    applyState({ {name, json_args} });
    return;
}

int SimpleInterfaceClient::registerResponseHandler(ApiGear::MQTT::InvokeReplyFunc handler)
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

void SimpleInterfaceClient::onInvokeReply(const std::string& /*topic*/, const std::string& args, const std::string& /*responseTopic*/, const std::string& correlationData)
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

bool SimpleInterfaceClient::isReady() const
{
    return m_isReady;
}

ISimpleInterfacePublisher& SimpleInterfaceClient::_getPublisher() const
{
    return *m_publisher;
}
