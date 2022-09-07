#pragma once

#include <queue>
#include <set>
#include <map>
#include <memory>
#include <mutex>
#include <string>
#include <atomic>
#include <thread>
#include "nlohmann/json.hpp"
#include "mqttcommon.h"

namespace ApiGear {
namespace MQTTImpl {

class APIGEAR_MQTT_EXPORT Topic {
public:
    enum class TopicType{
        None, //< empty/error
        Property, //< prop
        Signal, //< sig
        Operation //< rpc
    };

    Topic() = default;
    Topic(const std::string& rawTopic);
    Topic(const std::string& moduleName, const std::string& interfaceName, const std::string& topicTypeString, const std::string& entityName);
    Topic(const std::string& moduleName, const std::string& interfaceName, const TopicType& topicType, const std::string& entityName);
    Topic(const std::string& moduleName, const std::string& interfaceName, const std::string& topicTypeString, const std::string& entityName, const std::string& miscInfo);
    Topic(const std::string& moduleName, const std::string& interfaceName, const TopicType& topicType, const std::string& entityName, const std::string& miscInfo);

    bool operator()(const Topic& lhs, const Topic& rhs) const noexcept
    {
        return lhs.getEncodedTopic() < rhs.getEncodedTopic();
    }

    const std::string& getEncodedTopic() const { return m_encodedTopic; }
    const std::string& getModuleName() const { return m_moduleName; }
    const std::string& getInterfaceName() const { return m_interfaceName; }
    const std::string& getEntityName() const { return m_entityName; }
    const TopicType& getTopicType() const { return m_topicType; }
    const std::string& getTopicTypeString() const { return m_topicTypeString; }
    const std::string& getMiscInfo() const { return m_miscInfo; }

    static bool convertTopicTypeToString(const TopicType& topicType, std::string& topicTypeString);
    static bool convertTopicTypeStringToType(const std::string& topicTypeString, TopicType& topicType);
    static bool decodeTopicString(const std::string& topicString, Topic& topic);
private:
    std::string m_encodedTopic {""}; // complete topic encoded

    std::string m_moduleName {""};
    std::string m_interfaceName {""};
    std::string m_entityName {""};
    TopicType m_topicType {TopicType::None};
    std::string m_topicTypeString {""};
    std::string m_miscInfo {""};
};
APIGEAR_MQTT_EXPORT std::ostream& operator<<(std::ostream &, const Topic &);
bool APIGEAR_MQTT_EXPORT operator==(const Topic &, const Topic &) noexcept;
bool APIGEAR_MQTT_EXPORT operator!=(const Topic &, const Topic &) noexcept;

} // namespace MQTTImpl
} // namespace ApiGear
