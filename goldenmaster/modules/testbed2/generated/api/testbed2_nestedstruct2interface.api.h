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
 * Interface INestedStruct2InterfaceSubscriber
 *
 * The subscriber is the counter part for the INestedStruct2InterfacePublisher.
 */
class TEST_TESTBED2_EXPORT INestedStruct2InterfaceSubscriber
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
    * This function is called when the sig2 signal is triggered.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param param1 
    * @param param2 
    */
    virtual void OnSig2(const NestedStruct1& param1,const NestedStruct2& param2) = 0;
    /**
    * This function is called when the prop1 value has changed.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnProp1Changed(const NestedStruct1& prop1) = 0;
    /**
    * This function is called when the prop2 value has changed.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnProp2Changed(const NestedStruct2& prop2) = 0;
};

/** callback for changes of prop1 */
typedef std::function<void(const NestedStruct1& prop1)> NestedStruct2InterfaceProp1PropertyCb;
/** callback for changes of prop2 */
typedef std::function<void(const NestedStruct2& prop2)> NestedStruct2InterfaceProp2PropertyCb;
/** callback for sig1 signal triggers */
typedef std::function<void(const NestedStruct1& param1)> NestedStruct2InterfaceSig1SignalCb;
/** callback for sig2 signal triggers */
typedef std::function<void(const NestedStruct1& param1,const NestedStruct2& param2)> NestedStruct2InterfaceSig2SignalCb;
/**
 * Interface INestedStruct2InterfacePublisher
 *
 * The publisher contains the signal interface for the INestedStruct2InterfaceSubscriber
 * and direct signal function subscribtion.
 */
class TEST_TESTBED2_EXPORT INestedStruct2InterfacePublisher
{
public:
    virtual ~INestedStruct2InterfacePublisher() = default;

    /**
    * Use this function to subscribe for any changes of the NestedStruct2Interface changes.
    * This subscription will trigger calls for any property changes or signal events.
    *
    * @param subscriber reference to the INestedStruct2InterfaceSubscriber implementation
    */
    virtual void subscribeToNestedStruct2InterfaceInterface(INestedStruct2InterfaceSubscriber& subscriber) = 0;
    /**
    * Use this function to unsubscribe from all changes of the NestedStruct2Interface changes.
    *
    * @param subscriber reference to the INestedStruct2InterfaceSubscriber implementation
    */
    virtual void unsubscribeFromNestedStruct2InterfaceInterface(INestedStruct2InterfaceSubscriber& subscriber) = 0;

    /**
    * Use this function to subscribe for prop1 value changes.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param callback any of type NestedStruct2InterfaceProp1PropertyCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToProp1Changed(NestedStruct2InterfaceProp1PropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from prop1 property changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromProp1Changed(long handleId) = 0;

    /**
    * Use this function to subscribe for prop2 value changes.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param callback any of type NestedStruct2InterfaceProp2PropertyCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToProp2Changed(NestedStruct2InterfaceProp2PropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from prop2 property changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromProp2Changed(long handleId) = 0;

    /**
    * Use this function to subscribe for sig1 signal changes.
    *
    * @param callback any of type NestedStruct2InterfaceSig1SignalCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToSig1(NestedStruct2InterfaceSig1SignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sig1 signal changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromSig1(long handleId) = 0;

    /**
    * Use this function to subscribe for sig2 signal changes.
    *
    * @param callback any of type NestedStruct2InterfaceSig2SignalCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToSig2(NestedStruct2InterfaceSig2SignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sig2 signal changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromSig2(long handleId) = 0;

    /**
    * This function is called by the implementation for prop1 value changes.
    */
    virtual void publishProp1Changed(const NestedStruct1& prop1) const = 0;
    /**
    * This function is called by the implementation for prop2 value changes.
    */
    virtual void publishProp2Changed(const NestedStruct2& prop2) const = 0;
    /**
    * This function is called by the implementation when the sig1 signal is triggered.
    *
    * @param param1 
    */
    virtual void publishSig1(const NestedStruct1& param1) const = 0;
    /**
    * This function is called by the implementation when the sig2 signal is triggered.
    *
    * @param param1 
    * @param param2 
    */
    virtual void publishSig2(const NestedStruct1& param1,const NestedStruct2& param2) const = 0;
};

/**
 * Interface INestedStruct2Interface
 */
class TEST_TESTBED2_EXPORT INestedStruct2Interface
{
public:
    virtual ~INestedStruct2Interface() = default;

    // methods
    virtual NestedStruct1 func1(const NestedStruct1& param1) = 0;
    /**
    * Asynchronous function call for func1(const NestedStruct1& param1)
    *
    * @return Promise of type NestedStruct1 which is set once the function has completed
    */
    virtual std::future<NestedStruct1> func1Async(const NestedStruct1& param1) = 0;

    virtual NestedStruct1 func2(const NestedStruct1& param1, const NestedStruct2& param2) = 0;
    /**
    * Asynchronous function call for func2(const NestedStruct1& param1, const NestedStruct2& param2)
    *
    * @return Promise of type NestedStruct1 which is set once the function has completed
    */
    virtual std::future<NestedStruct1> func2Async(const NestedStruct1& param1, const NestedStruct2& param2) = 0;

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
    * Sets the value of property prop2
    */
    virtual void setProp2(const NestedStruct2& prop2) = 0;
    /**
    * Gets the value of property prop2
    */
    virtual const NestedStruct2& prop2() const = 0;

    /**
    * @return a pointer to the used INestedStruct2InterfacePublisher for publish/subscribe events
    */
    virtual INestedStruct2InterfacePublisher* _getPublisher() const = 0;
};

/**
 * Interface INestedStruct2InterfaceDecorator
 *
 * Decorator interface helper for inheritance
 */
class TEST_TESTBED2_EXPORT INestedStruct2InterfaceDecorator: public virtual INestedStruct2Interface, public virtual INestedStruct2InterfaceSubscriber {
public:
    /**
    * Swap the used implementation
    *
    * @param impl pointer to new implementation to be used
    * @return pointer to the original implementation
    */
    virtual INestedStruct2Interface* swapUnderlyingImplementation(INestedStruct2Interface* impl) = 0;
    /**
    * Disconnect the decorator from the originally used implementation
    *
    * @return pointer to the original implementation
    */
    virtual INestedStruct2Interface* disconnectFromUnderlyingImplementation() = 0;
};
} // namespace Testbed2
} // namespace Test
