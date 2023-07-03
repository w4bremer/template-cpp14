#include <iostream>
#include <string>
#include "mqtttopic.h"

namespace ApiGear {
namespace MQTT {

Topic::Topic(const std::string& rawTopic)
    : m_moduleName("")
    , m_interfaceName("")
    , m_topicType(Topic::TopicType::None)
    , m_entityName("")
    , m_encodedTopic("")
{
    decodeTopicString(rawTopic, *this);
}

Topic::Topic(const std::string& moduleName, const std::string& interfaceName, const std::string& topicTypeString, const std::string& entityName)
    : m_moduleName(moduleName)
    , m_interfaceName(interfaceName)
    , m_entityName(entityName)
    , m_topicTypeString(topicTypeString)
{
    convertTopicTypeStringToType(m_topicTypeString, m_topicType);
    m_encodedTopic = moduleName + "/" + interfaceName + "/" + m_topicTypeString + "/" + m_entityName;
}

Topic::Topic(const std::string& moduleName, const std::string& interfaceName, const TopicType& topicType, const std::string& entityName)
    : m_moduleName(moduleName)
    , m_interfaceName(interfaceName)
    , m_entityName(entityName)
    , m_topicType(topicType)
{
    convertTopicTypeToString(topicType, m_topicTypeString);
    m_encodedTopic = moduleName + "/" + interfaceName + "/" + m_topicTypeString + "/" + m_entityName;
}

Topic::Topic(const std::string& moduleName, const std::string& interfaceName, const std::string& topicTypeString, const std::string& entityName, const std::string& miscInfo)
    : m_moduleName(moduleName)
    , m_interfaceName(interfaceName)
    , m_entityName(entityName)
    , m_topicTypeString(topicTypeString)
    , m_miscInfo(miscInfo)
{
    convertTopicTypeStringToType(m_topicTypeString, m_topicType);
    m_encodedTopic = moduleName + "/" + interfaceName + "/" + m_topicTypeString + "/" + m_entityName + "/" + m_miscInfo;
}

Topic::Topic(const std::string& moduleName, const std::string& interfaceName, const TopicType& topicType, const std::string& entityName, const std::string& miscInfo)
    : m_moduleName(moduleName)
    , m_interfaceName(interfaceName)
    , m_entityName(entityName)
    , m_topicType(topicType)
    , m_miscInfo(miscInfo)
{
    convertTopicTypeToString(topicType, m_topicTypeString);
    m_encodedTopic = moduleName + "/" + interfaceName + "/" + m_topicTypeString + "/" + m_entityName + "/" + m_miscInfo;
}

bool operator==(const Topic& lhs, const Topic& rhs) noexcept
{
    return (
        lhs.getEncodedTopic() == rhs.getEncodedTopic() &&
        lhs.getModuleName() == rhs.getModuleName() &&
        lhs.getInterfaceName() == rhs.getInterfaceName() &&
        lhs.getTopicType() == rhs.getTopicType() &&
        lhs.getTopicTypeString() == rhs.getTopicTypeString() &&
        lhs.getEntityName() == rhs.getEntityName() &&
        lhs.getMiscInfo() == rhs.getMiscInfo()
    );
}

bool operator!=(const Topic& lhs, const Topic& rhs) noexcept
{
    return !(lhs == rhs);
}

std::ostream& operator<<(std::ostream& os, const Topic& topic)
{
    os << topic.getEncodedTopic();
    return os;
}

bool Topic::convertTopicTypeToString(const TopicType& topicType, std::string& topicTypeString)
{
    if(topicType == TopicType::Property)
    {
        topicTypeString = "prop";
        return true;
    }
    else if(topicType == TopicType::Signal)
    {
        topicTypeString = "sig";
        return true;
    }
    else if(topicType == TopicType::Operation)
    {
        topicTypeString = "rpc";
        return true;
    }

    topicTypeString = "";
    return false;
}

bool Topic::convertTopicTypeStringToType(const std::string& topicTypeString, TopicType& topicType)
{
    if(topicTypeString == "prop")
    {
        topicType = TopicType::Property;
        return true;
    }
    else if(topicTypeString == "sig")
    {
        topicType = TopicType::Signal;
        return true;
    }
    else if(topicTypeString == "rpc")
    {
        topicType = TopicType::Operation;
        return true;
    }
    else
    {
        topicType = TopicType::None;
        return false;
    }
}

bool Topic::decodeTopicString(const std::string& topicString, Topic& topic)
{
    bool success {false};
    size_t pos = 0;
    static const std::string delimiter { "/" };
    std::vector<std::string> splitTopic;
    std::string token { "" };
    std::string tmp { topicString };
    while ((pos = tmp.find(delimiter)) != std::string::npos) {
        token = tmp.substr(0, pos);
        splitTopic.push_back(token);
        tmp.erase(0, pos + delimiter.length());
    }
    splitTopic.push_back(tmp);

    Topic::TopicType type { Topic::TopicType::None };
    using namespace std::literals;
    auto moduleName = ""s;
    auto interfaceName = ""s;
    auto typeString = ""s;
    auto entityName = ""s;
    // check whether we can decode the module, interface and type
    if(splitTopic.size() <= 2)
    {
        success = false;
        return success;
    }
    moduleName = splitTopic.at(0);
    interfaceName = splitTopic.at(1);
    typeString = splitTopic.at(2);
    success = convertTopicTypeStringToType(typeString, type);

    // check whether we can decode the entity
    if(splitTopic.size() <= 3)
    {
        success = false;
        return success;
    }
    entityName = splitTopic.at(3);
    topic = Topic(moduleName, interfaceName, typeString, entityName);

    // optional
    if(splitTopic.size() > 4)
    {
        auto miscInfo = ""s;
        for(auto cnt = 4; cnt < splitTopic.size(); cnt++)
        {
            miscInfo.append(splitTopic.at(cnt));
            if(cnt < splitTopic.size()-1)
            {
                miscInfo.append(delimiter);
            }
        }
        topic = Topic(moduleName, interfaceName, typeString, entityName, miscInfo);
    }

    return success;
}
} // namespace MQTT
} // namespace ApiGear
