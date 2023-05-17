#pragma once

#include "mqttcommon.h"

namespace ApiGear {
namespace MQTT {

class Topic;

/**
 * @brief Describes the interface to be implemented by each endpoint
 */
class APIGEAR_MQTT_EXPORT ISink
{
public:
    virtual ~ISink() = default;

    virtual void onSignal(const Topic& name, const std::string& args) = 0;
    virtual void onPropertyChanged(const Topic& name, const std::string& args) = 0;
    virtual void onInvoke(const Topic& name, const std::string& args, const Topic& responceTopic, const std::string& correlationData) = 0;
    virtual void onConnected() = 0;
};

} // namespace MQTT
} // namespace ApiGear
