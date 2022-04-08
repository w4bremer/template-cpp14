/**
NO TITLE
Copyright (C) 2020 ApiGear UG

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#pragma once

#include <future>
#include "org_objectapi_testbed_common.h"
#include "org_objectapi_testbed_datastructs.api.h"

namespace Test {
namespace OrgObjectapiTestbed {
/**
 * Interface IInterface2Subscriber
 *
 * The subscriber is the counter part for the IInterface2Publisher.
 */
class TEST_ORG_OBJECTAPI_TESTBED_EXPORT IInterface2Subscriber
{
public:
    /**
    * This function is called when the prop200 value has changed.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnProp200Changed(int prop200) = 0;
    /**
    * This function is called when the prop201 value has changed.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnProp201Changed(int prop201) = 0;
    /**
    * This function is called when the prop202 value has changed.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnProp202Changed(int prop202) = 0;
    /**
    * This function is called when the prop203 value has changed.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnProp203Changed(float prop203) = 0;
    /**
    * This function is called when the prop204 value has changed.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnProp204Changed(float prop204) = 0;
    /**
    * This function is called when the prop205 value has changed.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnProp205Changed(std::string prop205) = 0;
};

/** callback for changes of prop200 */
typedef std::function<void(int prop200)> Interface2Prop200PropertyCb;
/** callback for changes of prop201 */
typedef std::function<void(int prop201)> Interface2Prop201PropertyCb;
/** callback for changes of prop202 */
typedef std::function<void(int prop202)> Interface2Prop202PropertyCb;
/** callback for changes of prop203 */
typedef std::function<void(float prop203)> Interface2Prop203PropertyCb;
/** callback for changes of prop204 */
typedef std::function<void(float prop204)> Interface2Prop204PropertyCb;
/** callback for changes of prop205 */
typedef std::function<void(const std::string& prop205)> Interface2Prop205PropertyCb;
/**
 * Interface IInterface2Publisher
 *
 * The publisher contains the signal interface for the IInterface2Subscriber
 * and direct signal function subscribtion.
 */
class TEST_ORG_OBJECTAPI_TESTBED_EXPORT IInterface2Publisher
{
public:
    virtual ~IInterface2Publisher() = default;

    /**
    * Use this function to subscribe for any changes of the Interface2 changes.
    * This subscription will trigger calls for any property changes or signal events.
    *
    * @param subscriber reference to the IInterface2Subscriber implementation
    */
    virtual void subscribeToInterface2Interface(IInterface2Subscriber& subscriber) = 0;
    /**
    * Use this function to unsubscribe from all changes of the Interface2 changes.
    *
    * @param subscriber reference to the IInterface2Subscriber implementation
    */
    virtual void unsubscribeFromInterface2Interface(IInterface2Subscriber& subscriber) = 0;

    /**
    * Use this function to subscribe for prop200 value changes.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param callback any of type Interface2Prop200PropertyCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToProp200Changed(Interface2Prop200PropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from prop200 property changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromProp200Changed(long handleId) = 0;

    /**
    * Use this function to subscribe for prop201 value changes.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param callback any of type Interface2Prop201PropertyCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToProp201Changed(Interface2Prop201PropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from prop201 property changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromProp201Changed(long handleId) = 0;

    /**
    * Use this function to subscribe for prop202 value changes.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param callback any of type Interface2Prop202PropertyCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToProp202Changed(Interface2Prop202PropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from prop202 property changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromProp202Changed(long handleId) = 0;

    /**
    * Use this function to subscribe for prop203 value changes.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param callback any of type Interface2Prop203PropertyCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToProp203Changed(Interface2Prop203PropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from prop203 property changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromProp203Changed(long handleId) = 0;

    /**
    * Use this function to subscribe for prop204 value changes.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param callback any of type Interface2Prop204PropertyCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToProp204Changed(Interface2Prop204PropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from prop204 property changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromProp204Changed(long handleId) = 0;

    /**
    * Use this function to subscribe for prop205 value changes.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param callback any of type Interface2Prop205PropertyCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToProp205Changed(Interface2Prop205PropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from prop205 property changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromProp205Changed(long handleId) = 0;

    /**
    * This function is called by the implementation for prop200 value changes.
    */
    virtual void publishProp200Changed(int prop200) const = 0;
    /**
    * This function is called by the implementation for prop201 value changes.
    */
    virtual void publishProp201Changed(int prop201) const = 0;
    /**
    * This function is called by the implementation for prop202 value changes.
    */
    virtual void publishProp202Changed(int prop202) const = 0;
    /**
    * This function is called by the implementation for prop203 value changes.
    */
    virtual void publishProp203Changed(float prop203) const = 0;
    /**
    * This function is called by the implementation for prop204 value changes.
    */
    virtual void publishProp204Changed(float prop204) const = 0;
    /**
    * This function is called by the implementation for prop205 value changes.
    */
    virtual void publishProp205Changed(const std::string& prop205) const = 0;
};

/**
 * Interface IInterface2
 */
class TEST_ORG_OBJECTAPI_TESTBED_EXPORT IInterface2
{
public:
    virtual ~IInterface2() = default;

    // property methods
    /**
    * Sets the value of property prop200
    */
    virtual void setProp200(int prop200) = 0;
    /**
    * Gets the value of property prop200
    */
    virtual int prop200() const = 0;

    /**
    * Sets the value of property prop201
    */
    virtual void setProp201(int prop201) = 0;
    /**
    * Gets the value of property prop201
    */
    virtual int prop201() const = 0;

    /**
    * Sets the value of property prop202
    */
    virtual void setProp202(int prop202) = 0;
    /**
    * Gets the value of property prop202
    */
    virtual int prop202() const = 0;

    /**
    * Sets the value of property prop203
    */
    virtual void setProp203(float prop203) = 0;
    /**
    * Gets the value of property prop203
    */
    virtual float prop203() const = 0;

    /**
    * Sets the value of property prop204
    */
    virtual void setProp204(float prop204) = 0;
    /**
    * Gets the value of property prop204
    */
    virtual float prop204() const = 0;

    /**
    * Sets the value of property prop205
    */
    virtual void setProp205(const std::string& prop205) = 0;
    /**
    * Gets the value of property prop205
    */
    virtual std::string prop205() const = 0;

    /**
    * @return a pointer to the used IInterface2Publisher for publish/subscribe events
    */
    virtual IInterface2Publisher* _getPublisher() const = 0;
};

/**
 * Interface IInterface2Decorator
 *
 * Decorator interface helper for inheritance
 */
class TEST_ORG_OBJECTAPI_TESTBED_EXPORT IInterface2Decorator: public virtual IInterface2, public virtual IInterface2Subscriber {
public:
    /**
    * Swap the used implementation
    *
    * @param impl pointer to new implementation to be used
    * @return pointer to the original implementation
    */
    virtual IInterface2* swapUnderlyingImplementation(IInterface2* impl) = 0;
    /**
    * Disconnect the decorator from the originally used implementation
    *
    * @return pointer to the original implementation
    */
    virtual IInterface2* disconnectFromUnderlyingImplementation() = 0;
};
} // namespace OrgObjectapiTestbed
} // namespace Test
