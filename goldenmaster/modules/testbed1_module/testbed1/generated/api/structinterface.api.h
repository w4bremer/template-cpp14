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
#include "testbed1/generated/api/common.h"
#include "testbed1/generated/api/datastructs.api.h"

namespace Test {
namespace Testbed1 {
/**
 * Interface IStructInterfaceSubscriber
 *
 * The subscriber is the counter part for the IStructInterfacePublisher.
 */
class TEST_TESTBED1_EXPORT IStructInterfaceSubscriber
{
public:
    /**
    * This function is called when the sigBool signal is triggered.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param paramBool 
    */
    virtual void OnSigBool(const StructBool& paramBool) = 0;
    /**
    * This function is called when the sigInt signal is triggered.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param paramInt 
    */
    virtual void OnSigInt(const StructInt& paramInt) = 0;
    /**
    * This function is called when the sigFloat signal is triggered.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param paramFloat 
    */
    virtual void OnSigFloat(const StructFloat& paramFloat) = 0;
    /**
    * This function is called when the sigString signal is triggered.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param paramString 
    */
    virtual void OnSigString(const StructString& paramString) = 0;
    /**
    * This function is called when the propBool value has changed.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnPropBoolChanged(const StructBool& propBool) = 0;
    /**
    * This function is called when the propInt value has changed.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnPropIntChanged(const StructInt& propInt) = 0;
    /**
    * This function is called when the propFloat value has changed.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnPropFloatChanged(const StructFloat& propFloat) = 0;
    /**
    * This function is called when the propString value has changed.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnPropStringChanged(const StructString& propString) = 0;
};

/** callback for changes of propBool */
typedef std::function<void(const StructBool& propBool)> StructInterfacePropBoolPropertyCb;
/** callback for changes of propInt */
typedef std::function<void(const StructInt& propInt)> StructInterfacePropIntPropertyCb;
/** callback for changes of propFloat */
typedef std::function<void(const StructFloat& propFloat)> StructInterfacePropFloatPropertyCb;
/** callback for changes of propString */
typedef std::function<void(const StructString& propString)> StructInterfacePropStringPropertyCb;
/** callback for sigBool signal triggers */
typedef std::function<void(const StructBool& paramBool)> StructInterfaceSigBoolSignalCb;
/** callback for sigInt signal triggers */
typedef std::function<void(const StructInt& paramInt)> StructInterfaceSigIntSignalCb;
/** callback for sigFloat signal triggers */
typedef std::function<void(const StructFloat& paramFloat)> StructInterfaceSigFloatSignalCb;
/** callback for sigString signal triggers */
typedef std::function<void(const StructString& paramString)> StructInterfaceSigStringSignalCb;
/**
 * Interface IStructInterfacePublisher
 *
 * The publisher contains the signal interface for the IStructInterfaceSubscriber
 * and direct signal function subscribtion.
 */
class TEST_TESTBED1_EXPORT IStructInterfacePublisher
{
public:
    virtual ~IStructInterfacePublisher() = default;

    /**
    * Use this function to subscribe for any changes of the StructInterface changes.
    * This subscription will trigger calls for any property changes or signal events.
    *
    * @param subscriber reference to the IStructInterfaceSubscriber implementation
    */
    virtual void subscribeToStructInterfaceInterface(IStructInterfaceSubscriber& subscriber) = 0;
    /**
    * Use this function to unsubscribe from all changes of the StructInterface changes.
    *
    * @param subscriber reference to the IStructInterfaceSubscriber implementation
    */
    virtual void unsubscribeFromStructInterfaceInterface(IStructInterfaceSubscriber& subscriber) = 0;

    /**
    * Use this function to subscribe for propBool value changes.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param callback any of type StructInterfacePropBoolPropertyCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToPropBoolChanged(StructInterfacePropBoolPropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from propBool property changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromPropBoolChanged(long handleId) = 0;

    /**
    * Use this function to subscribe for propInt value changes.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param callback any of type StructInterfacePropIntPropertyCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToPropIntChanged(StructInterfacePropIntPropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from propInt property changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromPropIntChanged(long handleId) = 0;

    /**
    * Use this function to subscribe for propFloat value changes.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param callback any of type StructInterfacePropFloatPropertyCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToPropFloatChanged(StructInterfacePropFloatPropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from propFloat property changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromPropFloatChanged(long handleId) = 0;

    /**
    * Use this function to subscribe for propString value changes.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param callback any of type StructInterfacePropStringPropertyCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToPropStringChanged(StructInterfacePropStringPropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from propString property changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromPropStringChanged(long handleId) = 0;

    /**
    * Use this function to subscribe for sigBool signal changes.
    *
    * @param callback any of type StructInterfaceSigBoolSignalCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToSigBool(StructInterfaceSigBoolSignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sigBool signal changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromSigBool(long handleId) = 0;

    /**
    * Use this function to subscribe for sigInt signal changes.
    *
    * @param callback any of type StructInterfaceSigIntSignalCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToSigInt(StructInterfaceSigIntSignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sigInt signal changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromSigInt(long handleId) = 0;

    /**
    * Use this function to subscribe for sigFloat signal changes.
    *
    * @param callback any of type StructInterfaceSigFloatSignalCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToSigFloat(StructInterfaceSigFloatSignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sigFloat signal changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromSigFloat(long handleId) = 0;

    /**
    * Use this function to subscribe for sigString signal changes.
    *
    * @param callback any of type StructInterfaceSigStringSignalCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToSigString(StructInterfaceSigStringSignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sigString signal changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromSigString(long handleId) = 0;

    /**
    * This function is called by the implementation for propBool value changes.
    */
    virtual void publishPropBoolChanged(const StructBool& propBool) const = 0;
    /**
    * This function is called by the implementation for propInt value changes.
    */
    virtual void publishPropIntChanged(const StructInt& propInt) const = 0;
    /**
    * This function is called by the implementation for propFloat value changes.
    */
    virtual void publishPropFloatChanged(const StructFloat& propFloat) const = 0;
    /**
    * This function is called by the implementation for propString value changes.
    */
    virtual void publishPropStringChanged(const StructString& propString) const = 0;
    /**
    * This function is called by the implementation when the sigBool signal is triggered.
    *
    * @param paramBool 
    */
    virtual void publishSigBool(const StructBool& paramBool) const = 0;
    /**
    * This function is called by the implementation when the sigInt signal is triggered.
    *
    * @param paramInt 
    */
    virtual void publishSigInt(const StructInt& paramInt) const = 0;
    /**
    * This function is called by the implementation when the sigFloat signal is triggered.
    *
    * @param paramFloat 
    */
    virtual void publishSigFloat(const StructFloat& paramFloat) const = 0;
    /**
    * This function is called by the implementation when the sigString signal is triggered.
    *
    * @param paramString 
    */
    virtual void publishSigString(const StructString& paramString) const = 0;
};

/**
 * Interface IStructInterface
 */
class TEST_TESTBED1_EXPORT IStructInterface
{
public:
    virtual ~IStructInterface() = default;

    // methods
    virtual StructBool funcBool(const StructBool& paramBool) = 0;
    /**
    * Asynchronous function call for funcBool(const StructBool& paramBool)
    *
    * @return Promise of type StructBool which is set once the function has completed
    */
    virtual std::future<StructBool> funcBoolAsync(const StructBool& paramBool) = 0;

    virtual StructBool funcInt(const StructInt& paramInt) = 0;
    /**
    * Asynchronous function call for funcInt(const StructInt& paramInt)
    *
    * @return Promise of type StructBool which is set once the function has completed
    */
    virtual std::future<StructBool> funcIntAsync(const StructInt& paramInt) = 0;

    virtual StructFloat funcFloat(const StructFloat& paramFloat) = 0;
    /**
    * Asynchronous function call for funcFloat(const StructFloat& paramFloat)
    *
    * @return Promise of type StructFloat which is set once the function has completed
    */
    virtual std::future<StructFloat> funcFloatAsync(const StructFloat& paramFloat) = 0;

    virtual StructString funcString(const StructString& paramString) = 0;
    /**
    * Asynchronous function call for funcString(const StructString& paramString)
    *
    * @return Promise of type StructString which is set once the function has completed
    */
    virtual std::future<StructString> funcStringAsync(const StructString& paramString) = 0;

    // property methods
    /**
    * Sets the value of property propBool
    */
    virtual void setPropbool(const StructBool& propBool) = 0;
    /**
    * Gets the value of property propBool
    */
    virtual const StructBool& propBool() const = 0;

    /**
    * Sets the value of property propInt
    */
    virtual void setPropint(const StructInt& propInt) = 0;
    /**
    * Gets the value of property propInt
    */
    virtual const StructInt& propInt() const = 0;

    /**
    * Sets the value of property propFloat
    */
    virtual void setPropfloat(const StructFloat& propFloat) = 0;
    /**
    * Gets the value of property propFloat
    */
    virtual const StructFloat& propFloat() const = 0;

    /**
    * Sets the value of property propString
    */
    virtual void setPropstring(const StructString& propString) = 0;
    /**
    * Gets the value of property propString
    */
    virtual const StructString& propString() const = 0;

    /**
    * @return a pointer to the used IStructInterfacePublisher for publish/subscribe events
    */
    virtual IStructInterfacePublisher* _getPublisher() const = 0;
};

/**
 * Interface IStructInterfaceDecorator
 *
 * Decorator interface helper for inheritance
 */
class TEST_TESTBED1_EXPORT IStructInterfaceDecorator: public virtual IStructInterface, public virtual IStructInterfaceSubscriber {
public:
    /**
    * Swap the used implementation
    *
    * @param impl pointer to new implementation to be used
    * @return pointer to the original implementation
    */
    virtual IStructInterface* swapUnderlyingImplementation(IStructInterface* impl) = 0;
    /**
    * Disconnect the decorator from the originally used implementation
    *
    * @return pointer to the original implementation
    */
    virtual IStructInterface* disconnectFromUnderlyingImplementation() = 0;
};
} // namespace Testbed1
} // namespace Test
