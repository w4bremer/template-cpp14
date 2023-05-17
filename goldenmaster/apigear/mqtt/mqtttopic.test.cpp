/**
Tracer Test
Copyright (C) 2022 ApiGear UG
*/
#include "catch2/catch.hpp"
#include "mqtttopic.h"

using namespace ApiGear::MQTT;

TEST_CASE("Testing Topic type conversion", "[TopicType]"){
    std::string topicTypeString { "123" };
    Topic::TopicType topicType { Topic::TopicType::None };

    SECTION("test bad conversion") {
        topicType = Topic::TopicType::None;
        REQUIRE(Topic::convertTopicTypeToString(topicType, topicTypeString) == false);
        REQUIRE(topicTypeString == "");


        topicTypeString = "456";
        REQUIRE(Topic::convertTopicTypeStringToType(topicTypeString, topicType) == false);
        REQUIRE(topicType == Topic::TopicType::None);
    }

    SECTION("test property conversion") {
        topicType = Topic::TopicType::Property;
        REQUIRE(Topic::convertTopicTypeToString(topicType, topicTypeString) == true);
        REQUIRE(topicTypeString == "prop");


        topicTypeString = "prop";
        REQUIRE(Topic::convertTopicTypeStringToType(topicTypeString, topicType) == true);
        REQUIRE(topicType == Topic::TopicType::Property);
    }

    SECTION("test signal conversion") {
        topicType = Topic::TopicType::Signal;
        REQUIRE(Topic::convertTopicTypeToString(topicType, topicTypeString) == true);
        REQUIRE(topicTypeString == "sig");


        topicTypeString = "sig";
        REQUIRE(Topic::convertTopicTypeStringToType(topicTypeString, topicType) == true);
        REQUIRE(topicType == Topic::TopicType::Signal);
    }

    SECTION("test operation conversion") {
        topicType = Topic::TopicType::Operation;
        REQUIRE(Topic::convertTopicTypeToString(topicType, topicTypeString) == true);
        REQUIRE(topicTypeString == "rpc");


        topicTypeString = "rpc";
        REQUIRE(Topic::convertTopicTypeStringToType(topicTypeString, topicType) == true);
        REQUIRE(topicType == Topic::TopicType::Operation);
    }
}

TEST_CASE("Testing Topic comparison operator", "[Topic]"){
    std::string moduleName = "tracer.test.org";
    std::string interfaceName = "tester";
    std::string topicTypeString = "prop";
    std::string propertyName = "testProp";
    const Topic cmpTopic(moduleName, interfaceName, topicTypeString, propertyName);

    SECTION("test bad comparison") {
        Topic testTopic(moduleName, interfaceName, propertyName, topicTypeString);
        REQUIRE(cmpTopic != testTopic);
    }

    SECTION("test good comparison") {
        Topic testTopic(moduleName, interfaceName, topicTypeString, propertyName);
        REQUIRE(cmpTopic == testTopic);
    }
}

TEST_CASE("Testing Topic decoding", "[Topic]"){
    std::string moduleName = "tracer.test.org";
    std::string interfaceName = "tester";
    std::string topicTypeString = "prop";
    std::string propertyName = "testProp";
    const Topic cmpTopic(moduleName, interfaceName, topicTypeString, propertyName);

    SECTION("test bad conversion") {
        Topic testTopic {};
        std::string topicString = moduleName + "/" + interfaceName + "-" + topicTypeString + "/" + propertyName;
        REQUIRE(Topic::decodeTopicString(topicString, testTopic) == false);
        REQUIRE(cmpTopic != testTopic);
    }

    SECTION("test good conversion") {
        Topic testTopic {};
        std::string topicString = moduleName + "/" + interfaceName + "/" + topicTypeString + "/" + propertyName;
        REQUIRE(Topic::decodeTopicString(topicString, testTopic) == true);
        REQUIRE(cmpTopic == testTopic);
    }
}

TEST_CASE("Testing property Topic", "[Topic]"){
    std::string moduleName = "tracer.test.org";
    std::string interfaceName = "tester";
    std::string topicTypeString = "prop";
    Topic::TopicType topicType = Topic::TopicType::Property;

    SECTION("Test default constructor") {
        std::string propertyName = "testProp";
        std::string topic = moduleName + "/" + interfaceName + "/" + topicTypeString + "/" + propertyName;

        Topic testTopic {};

        REQUIRE(testTopic.getEncodedTopic() == "");
        REQUIRE(testTopic.getModuleName() == "");
        REQUIRE(testTopic.getInterfaceName() == "");
        REQUIRE(testTopic.getEntityName() == "");
        REQUIRE(testTopic.getTopicType() == Topic::TopicType::None);
        REQUIRE(testTopic.getTopicTypeString() == "");
    }

    SECTION("Test simple constructor") {
        std::string propertyName = "testProp";
        std::string topic = moduleName + "/" + interfaceName + "/" + topicTypeString + "/" + propertyName;

        Topic testTopic(moduleName, interfaceName, topicTypeString, propertyName);

        REQUIRE(testTopic.getEncodedTopic() == topic);
        REQUIRE(testTopic.getModuleName() == moduleName);
        REQUIRE(testTopic.getInterfaceName() == interfaceName);
        REQUIRE(testTopic.getEntityName() == propertyName);
        REQUIRE(testTopic.getTopicType() == topicType);
        REQUIRE(testTopic.getTopicTypeString() == topicTypeString);
    }

    SECTION("Test simple constructor") {
        std::string propertyName = "testProp";
        std::string topic = moduleName + "/" + interfaceName + "/" + topicTypeString + "/" + propertyName;

        Topic testTopic(moduleName, interfaceName, topicType, propertyName);

        REQUIRE(testTopic.getEncodedTopic() == topic);
        REQUIRE(testTopic.getModuleName() == moduleName);
        REQUIRE(testTopic.getInterfaceName() == interfaceName);
        REQUIRE(testTopic.getEntityName() == propertyName);
        REQUIRE(testTopic.getTopicType() == topicType);
        REQUIRE(testTopic.getTopicTypeString() == topicTypeString);
    }

    SECTION("Test copy constructor") {
        std::string propertyName = "testProp";
        std::string topic = moduleName + "/" + interfaceName + "/" + topicTypeString + "/" + propertyName;

        Topic orgTopic(moduleName, interfaceName, topicType, propertyName);
        Topic testTopic(orgTopic);

        REQUIRE(testTopic.getEncodedTopic() == topic);
        REQUIRE(testTopic.getModuleName() == moduleName);
        REQUIRE(testTopic.getInterfaceName() == interfaceName);
        REQUIRE(testTopic.getEntityName() == propertyName);
        REQUIRE(testTopic.getTopicType() == topicType);
        REQUIRE(testTopic.getTopicTypeString() == topicTypeString);
    }

    SECTION("Test raw constructor") {
        std::string propertyName = "testProp";
        std::string topicTypeString = "prop";
        std::string topic = moduleName + "/" + interfaceName + "/" + topicTypeString + "/" + propertyName;

        Topic testTopic(topic);

        REQUIRE(testTopic.getEncodedTopic() == topic);
        REQUIRE(testTopic.getModuleName() == moduleName);
        REQUIRE(testTopic.getInterfaceName() == interfaceName);
        REQUIRE(testTopic.getEntityName() == propertyName);
        REQUIRE(testTopic.getTopicType() == topicType);
        REQUIRE(testTopic.getTopicTypeString() == topicTypeString);
    }
}

TEST_CASE("Testing operation Topic", "[Topic]"){
    std::string moduleName = "tracer.test.org";
    std::string interfaceName = "tester";
    std::string topicTypeString = "rpc";
    std::string clientID = "UUID";
    Topic::TopicType topicType = Topic::TopicType::Operation;

    SECTION("Test default constructor") {
        std::string functionName = "funcTest";
        std::string topic = moduleName + "/" + interfaceName + "/" + topicTypeString + "/" + functionName;

        Topic testTopic {};

        REQUIRE(testTopic.getEncodedTopic() == "");
        REQUIRE(testTopic.getModuleName() == "");
        REQUIRE(testTopic.getInterfaceName() == "");
        REQUIRE(testTopic.getEntityName() == "");
        REQUIRE(testTopic.getTopicType() == Topic::TopicType::None);
        REQUIRE(testTopic.getTopicTypeString() == "");
    }

    SECTION("Test simple constructor") {
        std::string functionName = "funcTest";
        std::string topic = moduleName + "/" + interfaceName + "/" + topicTypeString + "/" + functionName;

        Topic testTopic(moduleName, interfaceName, topicTypeString, functionName);

        REQUIRE(testTopic.getEncodedTopic() == topic);
        REQUIRE(testTopic.getModuleName() == moduleName);
        REQUIRE(testTopic.getInterfaceName() == interfaceName);
        REQUIRE(testTopic.getEntityName() == functionName);
        REQUIRE(testTopic.getTopicType() == topicType);
        REQUIRE(testTopic.getTopicTypeString() == topicTypeString);
    }

    SECTION("Test simple constructor") {
        std::string functionName = "funcTest";
        std::string topic = moduleName + "/" + interfaceName + "/" + topicTypeString + "/" + functionName;

        Topic testTopic(moduleName, interfaceName, topicType, functionName);

        REQUIRE(testTopic.getEncodedTopic() == topic);
        REQUIRE(testTopic.getModuleName() == moduleName);
        REQUIRE(testTopic.getInterfaceName() == interfaceName);
        REQUIRE(testTopic.getEntityName() == functionName);
        REQUIRE(testTopic.getTopicType() == topicType);
        REQUIRE(testTopic.getTopicTypeString() == topicTypeString);
    }

    SECTION("Test copy constructor") {
        std::string functionName = "funcTest";
        std::string topic = moduleName + "/" + interfaceName + "/" + topicTypeString + "/" + functionName;

        Topic orgTopic(moduleName, interfaceName, topicType, functionName);
        Topic testTopic(orgTopic);

        REQUIRE(testTopic.getEncodedTopic() == topic);
        REQUIRE(testTopic.getModuleName() == moduleName);
        REQUIRE(testTopic.getInterfaceName() == interfaceName);
        REQUIRE(testTopic.getEntityName() == functionName);
        REQUIRE(testTopic.getTopicType() == topicType);
        REQUIRE(testTopic.getTopicTypeString() == topicTypeString);
    }

    SECTION("Test raw constructor") {
        std::string functionName = "funcTest";
        std::string topicTypeString = "rpc";
        std::string topic = moduleName + "/" + interfaceName + "/" + topicTypeString + "/" + functionName;

        Topic testTopic(topic);

        REQUIRE(testTopic.getEncodedTopic() == topic);
        REQUIRE(testTopic.getModuleName() == moduleName);
        REQUIRE(testTopic.getInterfaceName() == interfaceName);
        REQUIRE(testTopic.getEntityName() == functionName);
        REQUIRE(testTopic.getTopicType() == topicType);
        REQUIRE(testTopic.getTopicTypeString() == topicTypeString);
    }

    SECTION("Test extended raw constructor") {
        std::string functionName = "funcTest";
        std::string topicTypeString = "rpc";
        std::string topic = moduleName + "/" + interfaceName + "/" + topicTypeString + "/" + functionName + "/" + clientID + "/result";

        Topic testTopic(topic);

        REQUIRE(testTopic.getEncodedTopic() == topic);
        REQUIRE(testTopic.getModuleName() == moduleName);
        REQUIRE(testTopic.getInterfaceName() == interfaceName);
        REQUIRE(testTopic.getEntityName() == functionName);
        REQUIRE(testTopic.getTopicType() == topicType);
        REQUIRE(testTopic.getTopicTypeString() == topicTypeString);
    }

    SECTION("Test extended raw constructor 2") {
        std::string functionName = "funcTest";
        std::string topicTypeString = "rpc";
        std::string topic = moduleName + "/" + interfaceName + "/" + topicTypeString + "/" + functionName + "/" + clientID + "/result/we3/es/";

        Topic testTopic(topic);

        REQUIRE(testTopic.getEncodedTopic() == topic);
        REQUIRE(testTopic.getModuleName() == moduleName);
        REQUIRE(testTopic.getInterfaceName() == interfaceName);
        REQUIRE(testTopic.getEntityName() == functionName);
        REQUIRE(testTopic.getTopicType() == topicType);
        REQUIRE(testTopic.getTopicTypeString() == topicTypeString);
    }
}
