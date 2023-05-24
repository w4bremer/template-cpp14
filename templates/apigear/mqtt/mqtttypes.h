#pragma once

#include "nlohmann/json.hpp"
#include "mqttcommon.h"

namespace ApiGear {
namespace MQTT {

typedef std::function<void(bool connectionStatus)> OnConnectionStatusChangedCallBackFunction;

class APIGEAR_MQTT_EXPORT InvokeReplyArg {
public:
    nlohmann::json value;
};

typedef std::function<void(InvokeReplyArg)> InvokeReplyFunc;

class APIGEAR_MQTT_EXPORT Message {
public:
    Topic topic {""};
    std::string content {""}; //optional
    Topic responseTopic {""}; //optional
    std::string correlationData {""}; //optional
};

} // namespace MQTT
} // namespace ApiGear
