#pragma once

#include <future>
#include "tb_names/generated/api/common.h"
#include "tb_names/generated/api/datastructs.api.h"

namespace Test {
namespace TbNames {

class INamesSubscriber;
class INamesPublisher;

/**
*
* INames provides an interface for
 *  - methods defined for your Names 
 *  - property setters and getters for defined properties
 * The INames also provides an interface to access a publisher INamesPublisher, a class used by INamesSubscriber clients.
 * The implementation should notify the publisher INamesPublisher about emitted signals or state changed. 
 * The publisher responsibility is to keep its clients informed about requested changes.
 * See also INamesSubscriber, INamesPublisher
 * and the example implementation Names  or the
 */
class TEST_TB_NAMES_EXPORT INames
{
public:
    virtual ~INames() = default;

    /**
    * Sets the value of the Switch property.
    */
    virtual void setSwitch(bool Switch) = 0;
    /**
    * Gets the value of the Switch property.
    */
    virtual bool getSwitch() const = 0;

    /**
    * Access to a publisher, use it to subscribe for Names changes and signal emission.
    * This function name doesn't follow the convention, because it is added to user defined interface,
    * to avoid potentially name clashes, it has the trailing underscore in the name.
    * @return The publisher for Names.
    */
    virtual INamesPublisher& _getPublisher() const = 0;
};


/**
 * The INamesSubscriber contains functions to allow informing about signals or property changes of the INames implementation.
 * The implementation for INames should provide mechanism for subscription of the INamesSubscriber clients.
 * See INamesPublisher, which provides facilitation for this purpose.
 * The implementation for INames should call the INamesSubscriber interface functions on either signal emit or property change.
 * You can use INamesSubscriber class to implement clients of the INames or the network adapter - see Olink Server and Client example.
 */
class TEST_TB_NAMES_EXPORT INamesSubscriber
{
public:
    virtual ~INamesSubscriber() = default;
    /**
    * Called by the INamesPublisher when Switch value has changed if subscribed for the Switch change.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void onSwitchChanged(bool Switch) = 0;
};

/** Callback for changes of Switch */
using NamesSwitchPropertyCb = std::function<void(bool Switch)>;


/**
 * The INamesPublisher provides an api for clients to subscribe to or unsubscribe from a signal emission 
 * or a property change.
 * Implement this interface to keep track of clients of your INames implementation.
 * The publisher provides two independent methods of subscription
 *  - subscribing with a INamesSubscriber objects - for all of the changes
 *  - subscribing any object for single type of change property or a signal
 * The publish functions needs to be called by implementation of the IINames on each state changed or signal emitted
 * to notify all the subscribers about this change.
 */
class TEST_TB_NAMES_EXPORT INamesPublisher
{
public:
    virtual ~INamesPublisher() = default;

    /**
    * Use this function to subscribe for any change of the Names.
    * Subscriber will be informed of any emitted signal and any property changes.
    * This is parallel notification system to single subscription. If you will subscribe also for a single change
    * your subscriber will be informed twice about that change, one for each subscription mechanism.
    * @param INamesSubscriber which is subscribed in this function to any change of the Names.
    */
    virtual void subscribeToAllChanges(INamesSubscriber& subscriber) = 0;
    /**
    * Use this function to remove subscription to all of the changes of the Names.
    * Not all subscriptions will be removed, the ones made separately for single signal or property change stay intact.
    * Make sure to remove them.
    * @param INamesSubscriber which subscription for any change of the Names is removed.
    */
    virtual void unsubscribeFromAllChanges(INamesSubscriber& subscriber) = 0;

    /**
    * Use this function to subscribe for Switch value changes.
    * If your subscriber uses subscription with INamesSubscriber interface, you will get two notifications, one for each subscription mechanism.
    * @param NamesSwitchPropertyCb callback that will be executed on each change of the property.
    * Make sure to remove subscription before the callback becomes invalid.
    * @return subscription token for the subscription removal.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual long subscribeToSwitchChanged(NamesSwitchPropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from Switch property changes.
    * If your subscriber uses subscription with INamesSubscriber interface, you will be still informed about this change,
    * as those are two independent subscription mechanisms.
    * @param subscription token received on subscription.
    */
    virtual void unsubscribeFromSwitchChanged(long handleId) = 0;

    /**
    * Publishes the property changed to all subscribed clients.
    * Needs to be invoked by the Names implementation when property Switch changes.
    * @param The new value of Switch.
    */
    virtual void publishSwitchChanged(bool Switch) const = 0;
};


} // namespace TbNames
} // namespace Test
