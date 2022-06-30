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
#include "testbed2_common.h"
#include "testbed2_datastructs.api.h"

namespace Test {
namespace Testbed2 {
/**
 * Interface INestedStruct1InterfaceSubscriber
 *
 * The subscriber is the counter part for the INestedStruct1InterfacePublisher.
 */
class TEST_TESTBED2_EXPORT INestedStruct1InterfaceSubscriber
{
public:
    /**
    * This function is called when the sig1 signal is triggered.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param param1 
    */
    virtual void OnSig1(const NestedStruct1& param1) = 0;
    /**
    * This function is called when the prop1 value has changed.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnProp1Changed(const NestedStruct1& prop1) = 0;
};

/** callback for changes of prop1 */
typedef std::function<void(const NestedStruct1& prop1)> NestedStruct1InterfaceProp1PropertyCb;
/** callback for sig1 signal triggers */
typedef std::function<void(const NestedStruct1& param1)> NestedStruct1InterfaceSig1SignalCb;
/**
 * Interface INestedStruct1InterfacePublisher
 *
 * The publisher contains the signal interface for the INestedStruct1InterfaceSubscriber
 * and direct signal function subscribtion.
 */
class TEST_TESTBED2_EXPORT INestedStruct1InterfacePublisher
{
public:
    virtual ~INestedStruct1InterfacePublisher() = default;

    /**
    * Use this function to subscribe for any changes of the NestedStruct1Interface changes.
    * This subscription will trigger calls for any property changes or signal events.
    *
    * @param subscriber reference to the INestedStruct1InterfaceSubscriber implementation
    */
    virtual void subscribeToNestedStruct1InterfaceInterface(INestedStruct1InterfaceSubscriber& subscriber) = 0;
    /**
    * Use this function to unsubscribe from all changes of the NestedStruct1Interface changes.
    *
    * @param subscriber reference to the INestedStruct1InterfaceSubscriber implementation
    */
    virtual void unsubscribeFromNestedStruct1InterfaceInterface(INestedStruct1InterfaceSubscriber& subscriber) = 0;

    /**
    * Use this function to subscribe for prop1 value changes.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param callback any of type NestedStruct1InterfaceProp1PropertyCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToProp1Changed(NestedStruct1InterfaceProp1PropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from prop1 property changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromProp1Changed(long handleId) = 0;

    /**
    * Use this function to subscribe for sig1 signal changes.
    *
    * @param callback any of type NestedStruct1InterfaceSig1SignalCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToSig1(NestedStruct1InterfaceSig1SignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sig1 signal changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromSig1(long handleId) = 0;

    /**
    * This function is called by the implementation for prop1 value changes.
    */
    virtual void publishProp1Changed(const NestedStruct1& prop1) const = 0;
    /**
    * This function is called by the implementation when the sig1 signal is triggered.
    *
    * @param param1 
    */
    virtual void publishSig1(const NestedStruct1& param1) const = 0;
};

/**
 * Interface INestedStruct1Interface
 */
class TEST_TESTBED2_EXPORT INestedStruct1Interface
{
public:
    virtual ~INestedStruct1Interface() = default;

    // methods
    virtual NestedStruct1 func1(const NestedStruct1& param1) = 0;
    /**
    * Asynchronous function call for func1(const NestedStruct1& param1)
    *
    * @return Promise of type NestedStruct1 which is set once the function has completed
    */
    virtual std::future<NestedStruct1> func1Async(const NestedStruct1& param1) = 0;

    // property methods
    /**
    * Sets the value of property prop1
    */
    virtual void setProp1(const NestedStruct1& prop1) = 0;
    /**
    * Gets the value of property prop1
    */
    virtual const NestedStruct1& prop1() const = 0;

    /**
    * @return a pointer to the used INestedStruct1InterfacePublisher for publish/subscribe events
    */
    virtual INestedStruct1InterfacePublisher* _getPublisher() const = 0;
};

/**
 * Interface INestedStruct1InterfaceDecorator
 *
 * Decorator interface helper for inheritance
 */
class TEST_TESTBED2_EXPORT INestedStruct1InterfaceDecorator: public virtual INestedStruct1Interface, public virtual INestedStruct1InterfaceSubscriber {
public:
    /**
    * Swap the used implementation
    *
    * @param impl pointer to new implementation to be used
    * @return pointer to the original implementation
    */
    virtual INestedStruct1Interface* swapUnderlyingImplementation(INestedStruct1Interface* impl) = 0;
    /**
    * Disconnect the decorator from the originally used implementation
    *
    * @return pointer to the original implementation
    */
    virtual INestedStruct1Interface* disconnectFromUnderlyingImplementation() = 0;
};
} // namespace Testbed2
} // namespace Test
