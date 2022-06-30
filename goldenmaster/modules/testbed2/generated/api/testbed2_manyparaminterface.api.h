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
 * Interface IManyParamInterfaceSubscriber
 *
 * The subscriber is the counter part for the IManyParamInterfacePublisher.
 */
class TEST_TESTBED2_EXPORT IManyParamInterfaceSubscriber
{
public:
    /**
    * This function is called when the sig1 signal is triggered.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param param1 
    */
    virtual void OnSig1(int param1) = 0;
    /**
    * This function is called when the sig2 signal is triggered.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param param1 
    * @param param2 
    */
    virtual void OnSig2(int param1,int param2) = 0;
    /**
    * This function is called when the sig3 signal is triggered.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param param1 
    * @param param2 
    * @param param3 
    */
    virtual void OnSig3(int param1,int param2,int param3) = 0;
    /**
    * This function is called when the sig4 signal is triggered.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param param1 
    * @param param2 
    * @param param3 
    * @param param4 
    */
    virtual void OnSig4(int param1,int param2,int param3,int param4) = 0;
    /**
    * This function is called when the prop1 value has changed.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnProp1Changed(int prop1) = 0;
    /**
    * This function is called when the prop2 value has changed.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnProp2Changed(int prop2) = 0;
    /**
    * This function is called when the prop3 value has changed.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnProp3Changed(int prop3) = 0;
    /**
    * This function is called when the prop4 value has changed.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnProp4Changed(int prop4) = 0;
};

/** callback for changes of prop1 */
typedef std::function<void(int prop1)> ManyParamInterfaceProp1PropertyCb;
/** callback for changes of prop2 */
typedef std::function<void(int prop2)> ManyParamInterfaceProp2PropertyCb;
/** callback for changes of prop3 */
typedef std::function<void(int prop3)> ManyParamInterfaceProp3PropertyCb;
/** callback for changes of prop4 */
typedef std::function<void(int prop4)> ManyParamInterfaceProp4PropertyCb;
/** callback for sig1 signal triggers */
typedef std::function<void(int param1)> ManyParamInterfaceSig1SignalCb;
/** callback for sig2 signal triggers */
typedef std::function<void(int param1,int param2)> ManyParamInterfaceSig2SignalCb;
/** callback for sig3 signal triggers */
typedef std::function<void(int param1,int param2,int param3)> ManyParamInterfaceSig3SignalCb;
/** callback for sig4 signal triggers */
typedef std::function<void(int param1,int param2,int param3,int param4)> ManyParamInterfaceSig4SignalCb;
/**
 * Interface IManyParamInterfacePublisher
 *
 * The publisher contains the signal interface for the IManyParamInterfaceSubscriber
 * and direct signal function subscribtion.
 */
class TEST_TESTBED2_EXPORT IManyParamInterfacePublisher
{
public:
    virtual ~IManyParamInterfacePublisher() = default;

    /**
    * Use this function to subscribe for any changes of the ManyParamInterface changes.
    * This subscription will trigger calls for any property changes or signal events.
    *
    * @param subscriber reference to the IManyParamInterfaceSubscriber implementation
    */
    virtual void subscribeToManyParamInterfaceInterface(IManyParamInterfaceSubscriber& subscriber) = 0;
    /**
    * Use this function to unsubscribe from all changes of the ManyParamInterface changes.
    *
    * @param subscriber reference to the IManyParamInterfaceSubscriber implementation
    */
    virtual void unsubscribeFromManyParamInterfaceInterface(IManyParamInterfaceSubscriber& subscriber) = 0;

    /**
    * Use this function to subscribe for prop1 value changes.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param callback any of type ManyParamInterfaceProp1PropertyCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToProp1Changed(ManyParamInterfaceProp1PropertyCb callback) = 0;
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
    * @param callback any of type ManyParamInterfaceProp2PropertyCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToProp2Changed(ManyParamInterfaceProp2PropertyCb callback) = 0;
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
    * @param callback any of type ManyParamInterfaceProp3PropertyCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToProp3Changed(ManyParamInterfaceProp3PropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from prop3 property changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromProp3Changed(long handleId) = 0;

    /**
    * Use this function to subscribe for prop4 value changes.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param callback any of type ManyParamInterfaceProp4PropertyCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToProp4Changed(ManyParamInterfaceProp4PropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from prop4 property changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromProp4Changed(long handleId) = 0;

    /**
    * Use this function to subscribe for sig1 signal changes.
    *
    * @param callback any of type ManyParamInterfaceSig1SignalCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToSig1(ManyParamInterfaceSig1SignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sig1 signal changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromSig1(long handleId) = 0;

    /**
    * Use this function to subscribe for sig2 signal changes.
    *
    * @param callback any of type ManyParamInterfaceSig2SignalCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToSig2(ManyParamInterfaceSig2SignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sig2 signal changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromSig2(long handleId) = 0;

    /**
    * Use this function to subscribe for sig3 signal changes.
    *
    * @param callback any of type ManyParamInterfaceSig3SignalCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToSig3(ManyParamInterfaceSig3SignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sig3 signal changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromSig3(long handleId) = 0;

    /**
    * Use this function to subscribe for sig4 signal changes.
    *
    * @param callback any of type ManyParamInterfaceSig4SignalCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToSig4(ManyParamInterfaceSig4SignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sig4 signal changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromSig4(long handleId) = 0;

    /**
    * This function is called by the implementation for prop1 value changes.
    */
    virtual void publishProp1Changed(int prop1) const = 0;
    /**
    * This function is called by the implementation for prop2 value changes.
    */
    virtual void publishProp2Changed(int prop2) const = 0;
    /**
    * This function is called by the implementation for prop3 value changes.
    */
    virtual void publishProp3Changed(int prop3) const = 0;
    /**
    * This function is called by the implementation for prop4 value changes.
    */
    virtual void publishProp4Changed(int prop4) const = 0;
    /**
    * This function is called by the implementation when the sig1 signal is triggered.
    *
    * @param param1 
    */
    virtual void publishSig1(int param1) const = 0;
    /**
    * This function is called by the implementation when the sig2 signal is triggered.
    *
    * @param param1 
    * @param param2 
    */
    virtual void publishSig2(int param1,int param2) const = 0;
    /**
    * This function is called by the implementation when the sig3 signal is triggered.
    *
    * @param param1 
    * @param param2 
    * @param param3 
    */
    virtual void publishSig3(int param1,int param2,int param3) const = 0;
    /**
    * This function is called by the implementation when the sig4 signal is triggered.
    *
    * @param param1 
    * @param param2 
    * @param param3 
    * @param param4 
    */
    virtual void publishSig4(int param1,int param2,int param3,int param4) const = 0;
};

/**
 * Interface IManyParamInterface
 */
class TEST_TESTBED2_EXPORT IManyParamInterface
{
public:
    virtual ~IManyParamInterface() = default;

    // methods
    virtual int func1(int param1) = 0;
    /**
    * Asynchronous function call for func1(int param1)
    *
    * @return Promise of type int which is set once the function has completed
    */
    virtual std::future<int> func1Async(int param1) = 0;

    virtual int func2(int param1, int param2) = 0;
    /**
    * Asynchronous function call for func2(int param1, int param2)
    *
    * @return Promise of type int which is set once the function has completed
    */
    virtual std::future<int> func2Async(int param1, int param2) = 0;

    virtual int func3(int param1, int param2, int param3) = 0;
    /**
    * Asynchronous function call for func3(int param1, int param2, int param3)
    *
    * @return Promise of type int which is set once the function has completed
    */
    virtual std::future<int> func3Async(int param1, int param2, int param3) = 0;

    virtual int func4(int param1, int param2, int param3, int param4) = 0;
    /**
    * Asynchronous function call for func4(int param1, int param2, int param3, int param4)
    *
    * @return Promise of type int which is set once the function has completed
    */
    virtual std::future<int> func4Async(int param1, int param2, int param3, int param4) = 0;

    // property methods
    /**
    * Sets the value of property prop1
    */
    virtual void setProp1(int prop1) = 0;
    /**
    * Gets the value of property prop1
    */
    virtual int prop1() const = 0;

    /**
    * Sets the value of property prop2
    */
    virtual void setProp2(int prop2) = 0;
    /**
    * Gets the value of property prop2
    */
    virtual int prop2() const = 0;

    /**
    * Sets the value of property prop3
    */
    virtual void setProp3(int prop3) = 0;
    /**
    * Gets the value of property prop3
    */
    virtual int prop3() const = 0;

    /**
    * Sets the value of property prop4
    */
    virtual void setProp4(int prop4) = 0;
    /**
    * Gets the value of property prop4
    */
    virtual int prop4() const = 0;

    /**
    * @return a pointer to the used IManyParamInterfacePublisher for publish/subscribe events
    */
    virtual IManyParamInterfacePublisher* _getPublisher() const = 0;
};

/**
 * Interface IManyParamInterfaceDecorator
 *
 * Decorator interface helper for inheritance
 */
class TEST_TESTBED2_EXPORT IManyParamInterfaceDecorator: public virtual IManyParamInterface, public virtual IManyParamInterfaceSubscriber {
public:
    /**
    * Swap the used implementation
    *
    * @param impl pointer to new implementation to be used
    * @return pointer to the original implementation
    */
    virtual IManyParamInterface* swapUnderlyingImplementation(IManyParamInterface* impl) = 0;
    /**
    * Disconnect the decorator from the originally used implementation
    *
    * @return pointer to the original implementation
    */
    virtual IManyParamInterface* disconnectFromUnderlyingImplementation() = 0;
};
} // namespace Testbed2
} // namespace Test
