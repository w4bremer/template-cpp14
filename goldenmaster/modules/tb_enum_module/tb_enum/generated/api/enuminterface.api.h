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
#include "tb_enum/generated/api/common.h"
#include "tb_enum/generated/api/datastructs.api.h"

namespace Test {
namespace TbEnum {
/**
 * Interface IEnumInterfaceSubscriber
 *
 * The subscriber is the counter part for the IEnumInterfacePublisher.
 */
class TEST_TB_ENUM_EXPORT IEnumInterfaceSubscriber
{
public:
    /**
    * This function is called when the sig0 signal is triggered.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param param0 
    */
    virtual void OnSig0(const Enum0Enum& param0) = 0;
    /**
    * This function is called when the sig1 signal is triggered.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param param1 
    */
    virtual void OnSig1(const Enum1Enum& param1) = 0;
    /**
    * This function is called when the sig2 signal is triggered.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param param2 
    */
    virtual void OnSig2(const Enum2Enum& param2) = 0;
    /**
    * This function is called when the sig3 signal is triggered.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param param3 
    */
    virtual void OnSig3(const Enum3Enum& param3) = 0;
    /**
    * This function is called when the prop0 value has changed.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnProp0Changed(const Enum0Enum& prop0) = 0;
    /**
    * This function is called when the prop1 value has changed.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnProp1Changed(const Enum1Enum& prop1) = 0;
    /**
    * This function is called when the prop2 value has changed.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnProp2Changed(const Enum2Enum& prop2) = 0;
    /**
    * This function is called when the prop3 value has changed.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnProp3Changed(const Enum3Enum& prop3) = 0;
};

/** callback for changes of prop0 */
typedef std::function<void(const Enum0Enum& prop0)> EnumInterfaceProp0PropertyCb;
/** callback for changes of prop1 */
typedef std::function<void(const Enum1Enum& prop1)> EnumInterfaceProp1PropertyCb;
/** callback for changes of prop2 */
typedef std::function<void(const Enum2Enum& prop2)> EnumInterfaceProp2PropertyCb;
/** callback for changes of prop3 */
typedef std::function<void(const Enum3Enum& prop3)> EnumInterfaceProp3PropertyCb;
/** callback for sig0 signal triggers */
typedef std::function<void(const Enum0Enum& param0)> EnumInterfaceSig0SignalCb;
/** callback for sig1 signal triggers */
typedef std::function<void(const Enum1Enum& param1)> EnumInterfaceSig1SignalCb;
/** callback for sig2 signal triggers */
typedef std::function<void(const Enum2Enum& param2)> EnumInterfaceSig2SignalCb;
/** callback for sig3 signal triggers */
typedef std::function<void(const Enum3Enum& param3)> EnumInterfaceSig3SignalCb;
/**
 * Interface IEnumInterfacePublisher
 *
 * The publisher contains the signal interface for the IEnumInterfaceSubscriber
 * and direct signal function subscribtion.
 */
class TEST_TB_ENUM_EXPORT IEnumInterfacePublisher
{
public:
    virtual ~IEnumInterfacePublisher() = default;

    /**
    * Use this function to subscribe for any changes of the EnumInterface changes.
    * This subscription will trigger calls for any property changes or signal events.
    *
    * @param subscriber reference to the IEnumInterfaceSubscriber implementation
    */
    virtual void subscribeToEnumInterfaceInterface(IEnumInterfaceSubscriber& subscriber) = 0;
    /**
    * Use this function to unsubscribe from all changes of the EnumInterface changes.
    *
    * @param subscriber reference to the IEnumInterfaceSubscriber implementation
    */
    virtual void unsubscribeFromEnumInterfaceInterface(IEnumInterfaceSubscriber& subscriber) = 0;

    /**
    * Use this function to subscribe for prop0 value changes.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param callback any of type EnumInterfaceProp0PropertyCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToProp0Changed(EnumInterfaceProp0PropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from prop0 property changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromProp0Changed(long handleId) = 0;

    /**
    * Use this function to subscribe for prop1 value changes.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param callback any of type EnumInterfaceProp1PropertyCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToProp1Changed(EnumInterfaceProp1PropertyCb callback) = 0;
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
    * @param callback any of type EnumInterfaceProp2PropertyCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToProp2Changed(EnumInterfaceProp2PropertyCb callback) = 0;
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
    * @param callback any of type EnumInterfaceProp3PropertyCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToProp3Changed(EnumInterfaceProp3PropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from prop3 property changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromProp3Changed(long handleId) = 0;

    /**
    * Use this function to subscribe for sig0 signal changes.
    *
    * @param callback any of type EnumInterfaceSig0SignalCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToSig0(EnumInterfaceSig0SignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sig0 signal changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromSig0(long handleId) = 0;

    /**
    * Use this function to subscribe for sig1 signal changes.
    *
    * @param callback any of type EnumInterfaceSig1SignalCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToSig1(EnumInterfaceSig1SignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sig1 signal changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromSig1(long handleId) = 0;

    /**
    * Use this function to subscribe for sig2 signal changes.
    *
    * @param callback any of type EnumInterfaceSig2SignalCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToSig2(EnumInterfaceSig2SignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sig2 signal changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromSig2(long handleId) = 0;

    /**
    * Use this function to subscribe for sig3 signal changes.
    *
    * @param callback any of type EnumInterfaceSig3SignalCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToSig3(EnumInterfaceSig3SignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sig3 signal changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromSig3(long handleId) = 0;

    /**
    * This function is called by the implementation for prop0 value changes.
    */
    virtual void publishProp0Changed(const Enum0Enum& prop0) const = 0;
    /**
    * This function is called by the implementation for prop1 value changes.
    */
    virtual void publishProp1Changed(const Enum1Enum& prop1) const = 0;
    /**
    * This function is called by the implementation for prop2 value changes.
    */
    virtual void publishProp2Changed(const Enum2Enum& prop2) const = 0;
    /**
    * This function is called by the implementation for prop3 value changes.
    */
    virtual void publishProp3Changed(const Enum3Enum& prop3) const = 0;
    /**
    * This function is called by the implementation when the sig0 signal is triggered.
    *
    * @param param0 
    */
    virtual void publishSig0(const Enum0Enum& param0) const = 0;
    /**
    * This function is called by the implementation when the sig1 signal is triggered.
    *
    * @param param1 
    */
    virtual void publishSig1(const Enum1Enum& param1) const = 0;
    /**
    * This function is called by the implementation when the sig2 signal is triggered.
    *
    * @param param2 
    */
    virtual void publishSig2(const Enum2Enum& param2) const = 0;
    /**
    * This function is called by the implementation when the sig3 signal is triggered.
    *
    * @param param3 
    */
    virtual void publishSig3(const Enum3Enum& param3) const = 0;
};

/**
 * Interface IEnumInterface
 */
class TEST_TB_ENUM_EXPORT IEnumInterface
{
public:
    virtual ~IEnumInterface() = default;

    // methods
    virtual Enum0Enum func0(const Enum0Enum& param0) = 0;
    /**
    * Asynchronous function call for func0(const Enum0Enum& param0)
    *
    * @return Promise of type Enum0Enum which is set once the function has completed
    */
    virtual std::future<Enum0Enum> func0Async(const Enum0Enum& param0) = 0;

    virtual Enum1Enum func1(const Enum1Enum& param1) = 0;
    /**
    * Asynchronous function call for func1(const Enum1Enum& param1)
    *
    * @return Promise of type Enum1Enum which is set once the function has completed
    */
    virtual std::future<Enum1Enum> func1Async(const Enum1Enum& param1) = 0;

    virtual Enum2Enum func2(const Enum2Enum& param2) = 0;
    /**
    * Asynchronous function call for func2(const Enum2Enum& param2)
    *
    * @return Promise of type Enum2Enum which is set once the function has completed
    */
    virtual std::future<Enum2Enum> func2Async(const Enum2Enum& param2) = 0;

    virtual Enum3Enum func3(const Enum3Enum& param3) = 0;
    /**
    * Asynchronous function call for func3(const Enum3Enum& param3)
    *
    * @return Promise of type Enum3Enum which is set once the function has completed
    */
    virtual std::future<Enum3Enum> func3Async(const Enum3Enum& param3) = 0;

    // property methods
    /**
    * Sets the value of property prop0
    */
    virtual void setProp0(const Enum0Enum& prop0) = 0;
    /**
    * Gets the value of property prop0
    */
    virtual const Enum0Enum& prop0() const = 0;

    /**
    * Sets the value of property prop1
    */
    virtual void setProp1(const Enum1Enum& prop1) = 0;
    /**
    * Gets the value of property prop1
    */
    virtual const Enum1Enum& prop1() const = 0;

    /**
    * Sets the value of property prop2
    */
    virtual void setProp2(const Enum2Enum& prop2) = 0;
    /**
    * Gets the value of property prop2
    */
    virtual const Enum2Enum& prop2() const = 0;

    /**
    * Sets the value of property prop3
    */
    virtual void setProp3(const Enum3Enum& prop3) = 0;
    /**
    * Gets the value of property prop3
    */
    virtual const Enum3Enum& prop3() const = 0;

    /**
    * @return a pointer to the used IEnumInterfacePublisher for publish/subscribe events
    */
    virtual IEnumInterfacePublisher* _getPublisher() const = 0;
};

/**
 * Interface IEnumInterfaceDecorator
 *
 * Decorator interface helper for inheritance
 */
class TEST_TB_ENUM_EXPORT IEnumInterfaceDecorator: public virtual IEnumInterface, public virtual IEnumInterfaceSubscriber {
public:
    /**
    * Swap the used implementation
    *
    * @param impl pointer to new implementation to be used
    * @return pointer to the original implementation
    */
    virtual IEnumInterface* swapUnderlyingImplementation(IEnumInterface* impl) = 0;
    /**
    * Disconnect the decorator from the originally used implementation
    *
    * @return pointer to the original implementation
    */
    virtual IEnumInterface* disconnectFromUnderlyingImplementation() = 0;
};
} // namespace TbEnum
} // namespace Test
