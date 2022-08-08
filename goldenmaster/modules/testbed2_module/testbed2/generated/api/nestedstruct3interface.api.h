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
#include "testbed2/generated/api/common.h"
#include "testbed2/generated/api/datastructs.api.h"

namespace Test {
namespace Testbed2 {
/**
 * Interface INestedStruct3InterfaceSubscriber
 *
 * The subscriber is the counter part for the INestedStruct3InterfacePublisher.
 */
class TEST_TESTBED2_EXPORT INestedStruct3InterfaceSubscriber
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
    * This function is called when the sig3 signal is triggered.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param param1 
    * @param param2 
    * @param param3 
    */
    virtual void OnSig3(const NestedStruct1& param1,const NestedStruct2& param2,const NestedStruct3& param3) = 0;
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
    /**
    * This function is called when the prop3 value has changed.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnProp3Changed(const NestedStruct3& prop3) = 0;
};

/** callback for changes of prop1 */
typedef std::function<void(const NestedStruct1& prop1)> NestedStruct3InterfaceProp1PropertyCb;
/** callback for changes of prop2 */
typedef std::function<void(const NestedStruct2& prop2)> NestedStruct3InterfaceProp2PropertyCb;
/** callback for changes of prop3 */
typedef std::function<void(const NestedStruct3& prop3)> NestedStruct3InterfaceProp3PropertyCb;
/** callback for sig1 signal triggers */
typedef std::function<void(const NestedStruct1& param1)> NestedStruct3InterfaceSig1SignalCb;
/** callback for sig2 signal triggers */
typedef std::function<void(const NestedStruct1& param1,const NestedStruct2& param2)> NestedStruct3InterfaceSig2SignalCb;
/** callback for sig3 signal triggers */
typedef std::function<void(const NestedStruct1& param1,const NestedStruct2& param2,const NestedStruct3& param3)> NestedStruct3InterfaceSig3SignalCb;
/**
 * Interface INestedStruct3InterfacePublisher
 *
 * The publisher contains the signal interface for the INestedStruct3InterfaceSubscriber
 * and direct signal function subscribtion.
 */
class TEST_TESTBED2_EXPORT INestedStruct3InterfacePublisher
{
public:
    virtual ~INestedStruct3InterfacePublisher() = default;

    /**
    * Use this function to subscribe for any changes of the NestedStruct3Interface changes.
    * This subscription will trigger calls for any property changes or signal events.
    *
    * @param subscriber reference to the INestedStruct3InterfaceSubscriber implementation
    */
    virtual void subscribeToNestedStruct3InterfaceInterface(INestedStruct3InterfaceSubscriber& subscriber) = 0;
    /**
    * Use this function to unsubscribe from all changes of the NestedStruct3Interface changes.
    *
    * @param subscriber reference to the INestedStruct3InterfaceSubscriber implementation
    */
    virtual void unsubscribeFromNestedStruct3InterfaceInterface(INestedStruct3InterfaceSubscriber& subscriber) = 0;

    /**
    * Use this function to subscribe for prop1 value changes.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param callback any of type NestedStruct3InterfaceProp1PropertyCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToProp1Changed(NestedStruct3InterfaceProp1PropertyCb callback) = 0;
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
    * @param callback any of type NestedStruct3InterfaceProp2PropertyCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToProp2Changed(NestedStruct3InterfaceProp2PropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from prop2 property changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromProp2Changed(long handleId) = 0;

    /**
    * Use this function to subscribe for prop3 value changes.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param callback any of type NestedStruct3InterfaceProp3PropertyCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToProp3Changed(NestedStruct3InterfaceProp3PropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from prop3 property changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromProp3Changed(long handleId) = 0;

    /**
    * Use this function to subscribe for sig1 signal changes.
    *
    * @param callback any of type NestedStruct3InterfaceSig1SignalCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToSig1(NestedStruct3InterfaceSig1SignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sig1 signal changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromSig1(long handleId) = 0;

    /**
    * Use this function to subscribe for sig2 signal changes.
    *
    * @param callback any of type NestedStruct3InterfaceSig2SignalCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToSig2(NestedStruct3InterfaceSig2SignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sig2 signal changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromSig2(long handleId) = 0;

    /**
    * Use this function to subscribe for sig3 signal changes.
    *
    * @param callback any of type NestedStruct3InterfaceSig3SignalCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToSig3(NestedStruct3InterfaceSig3SignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sig3 signal changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromSig3(long handleId) = 0;

    /**
    * This function is called by the implementation for prop1 value changes.
    */
    virtual void publishProp1Changed(const NestedStruct1& prop1) const = 0;
    /**
    * This function is called by the implementation for prop2 value changes.
    */
    virtual void publishProp2Changed(const NestedStruct2& prop2) const = 0;
    /**
    * This function is called by the implementation for prop3 value changes.
    */
    virtual void publishProp3Changed(const NestedStruct3& prop3) const = 0;
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
    /**
    * This function is called by the implementation when the sig3 signal is triggered.
    *
    * @param param1 
    * @param param2 
    * @param param3 
    */
    virtual void publishSig3(const NestedStruct1& param1,const NestedStruct2& param2,const NestedStruct3& param3) const = 0;
};

/**
 * Interface INestedStruct3Interface
 */
class TEST_TESTBED2_EXPORT INestedStruct3Interface
{
public:
    virtual ~INestedStruct3Interface() = default;

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

    virtual NestedStruct1 func3(const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3) = 0;
    /**
    * Asynchronous function call for func3(const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3)
    *
    * @return Promise of type NestedStruct1 which is set once the function has completed
    */
    virtual std::future<NestedStruct1> func3Async(const NestedStruct1& param1, const NestedStruct2& param2, const NestedStruct3& param3) = 0;

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
    * Sets the value of property prop3
    */
    virtual void setProp3(const NestedStruct3& prop3) = 0;
    /**
    * Gets the value of property prop3
    */
    virtual const NestedStruct3& prop3() const = 0;

    /**
    * @return a pointer to the used INestedStruct3InterfacePublisher for publish/subscribe events
    */
    virtual INestedStruct3InterfacePublisher* _getPublisher() const = 0;
};

/**
 * Interface INestedStruct3InterfaceDecorator
 *
 * Decorator interface helper for inheritance
 */
class TEST_TESTBED2_EXPORT INestedStruct3InterfaceDecorator: public virtual INestedStruct3Interface, public virtual INestedStruct3InterfaceSubscriber {
public:
    /**
    * Swap the used implementation
    *
    * @param impl pointer to new implementation to be used
    * @return pointer to the original implementation
    */
    virtual INestedStruct3Interface* swapUnderlyingImplementation(INestedStruct3Interface* impl) = 0;
    /**
    * Disconnect the decorator from the originally used implementation
    *
    * @return pointer to the original implementation
    */
    virtual INestedStruct3Interface* disconnectFromUnderlyingImplementation() = 0;
};
} // namespace Testbed2
} // namespace Test
