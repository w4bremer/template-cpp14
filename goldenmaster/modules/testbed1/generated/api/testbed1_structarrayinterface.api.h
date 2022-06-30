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
#include "testbed1_common.h"
#include "testbed1_datastructs.api.h"

namespace Test {
namespace Testbed1 {
/**
 * Interface IStructArrayInterfaceSubscriber
 *
 * The subscriber is the counter part for the IStructArrayInterfacePublisher.
 */
class TEST_TESTBED1_EXPORT IStructArrayInterfaceSubscriber
{
public:
    /**
    * This function is called when the sigBool signal is triggered.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param paramBool 
    */
    virtual void OnSigBool(const std::list<StructBool>& paramBool) = 0;
    /**
    * This function is called when the sigInt signal is triggered.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param paramInt 
    */
    virtual void OnSigInt(const std::list<StructInt>& paramInt) = 0;
    /**
    * This function is called when the sigFloat signal is triggered.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param paramFloat 
    */
    virtual void OnSigFloat(const std::list<StructFloat>& paramFloat) = 0;
    /**
    * This function is called when the sigString signal is triggered.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param paramString 
    */
    virtual void OnSigString(const std::list<StructString>& paramString) = 0;
    /**
    * This function is called when the propBool value has changed.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnPropBoolChanged(const std::list<StructBool>& propBool) = 0;
    /**
    * This function is called when the propInt value has changed.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnPropIntChanged(const std::list<StructInt>& propInt) = 0;
    /**
    * This function is called when the propFloat value has changed.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnPropFloatChanged(const std::list<StructFloat>& propFloat) = 0;
    /**
    * This function is called when the propString value has changed.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnPropStringChanged(const std::list<StructString>& propString) = 0;
};

/** callback for changes of propBool */
typedef std::function<void(const std::list<StructBool>& propBool)> StructArrayInterfacePropBoolPropertyCb;
/** callback for changes of propInt */
typedef std::function<void(const std::list<StructInt>& propInt)> StructArrayInterfacePropIntPropertyCb;
/** callback for changes of propFloat */
typedef std::function<void(const std::list<StructFloat>& propFloat)> StructArrayInterfacePropFloatPropertyCb;
/** callback for changes of propString */
typedef std::function<void(const std::list<StructString>& propString)> StructArrayInterfacePropStringPropertyCb;
/** callback for sigBool signal triggers */
typedef std::function<void(const std::list<StructBool>& paramBool)> StructArrayInterfaceSigBoolSignalCb;
/** callback for sigInt signal triggers */
typedef std::function<void(const std::list<StructInt>& paramInt)> StructArrayInterfaceSigIntSignalCb;
/** callback for sigFloat signal triggers */
typedef std::function<void(const std::list<StructFloat>& paramFloat)> StructArrayInterfaceSigFloatSignalCb;
/** callback for sigString signal triggers */
typedef std::function<void(const std::list<StructString>& paramString)> StructArrayInterfaceSigStringSignalCb;
/**
 * Interface IStructArrayInterfacePublisher
 *
 * The publisher contains the signal interface for the IStructArrayInterfaceSubscriber
 * and direct signal function subscribtion.
 */
class TEST_TESTBED1_EXPORT IStructArrayInterfacePublisher
{
public:
    virtual ~IStructArrayInterfacePublisher() = default;

    /**
    * Use this function to subscribe for any changes of the StructArrayInterface changes.
    * This subscription will trigger calls for any property changes or signal events.
    *
    * @param subscriber reference to the IStructArrayInterfaceSubscriber implementation
    */
    virtual void subscribeToStructArrayInterfaceInterface(IStructArrayInterfaceSubscriber& subscriber) = 0;
    /**
    * Use this function to unsubscribe from all changes of the StructArrayInterface changes.
    *
    * @param subscriber reference to the IStructArrayInterfaceSubscriber implementation
    */
    virtual void unsubscribeFromStructArrayInterfaceInterface(IStructArrayInterfaceSubscriber& subscriber) = 0;

    /**
    * Use this function to subscribe for propBool value changes.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param callback any of type StructArrayInterfacePropBoolPropertyCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToPropBoolChanged(StructArrayInterfacePropBoolPropertyCb callback) = 0;
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
    * @param callback any of type StructArrayInterfacePropIntPropertyCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToPropIntChanged(StructArrayInterfacePropIntPropertyCb callback) = 0;
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
    * @param callback any of type StructArrayInterfacePropFloatPropertyCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToPropFloatChanged(StructArrayInterfacePropFloatPropertyCb callback) = 0;
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
    * @param callback any of type StructArrayInterfacePropStringPropertyCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToPropStringChanged(StructArrayInterfacePropStringPropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from propString property changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromPropStringChanged(long handleId) = 0;

    /**
    * Use this function to subscribe for sigBool signal changes.
    *
    * @param callback any of type StructArrayInterfaceSigBoolSignalCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToSigBool(StructArrayInterfaceSigBoolSignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sigBool signal changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromSigBool(long handleId) = 0;

    /**
    * Use this function to subscribe for sigInt signal changes.
    *
    * @param callback any of type StructArrayInterfaceSigIntSignalCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToSigInt(StructArrayInterfaceSigIntSignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sigInt signal changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromSigInt(long handleId) = 0;

    /**
    * Use this function to subscribe for sigFloat signal changes.
    *
    * @param callback any of type StructArrayInterfaceSigFloatSignalCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToSigFloat(StructArrayInterfaceSigFloatSignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sigFloat signal changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromSigFloat(long handleId) = 0;

    /**
    * Use this function to subscribe for sigString signal changes.
    *
    * @param callback any of type StructArrayInterfaceSigStringSignalCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToSigString(StructArrayInterfaceSigStringSignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sigString signal changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromSigString(long handleId) = 0;

    /**
    * This function is called by the implementation for propBool value changes.
    */
    virtual void publishPropBoolChanged(const std::list<StructBool>& propBool) const = 0;
    /**
    * This function is called by the implementation for propInt value changes.
    */
    virtual void publishPropIntChanged(const std::list<StructInt>& propInt) const = 0;
    /**
    * This function is called by the implementation for propFloat value changes.
    */
    virtual void publishPropFloatChanged(const std::list<StructFloat>& propFloat) const = 0;
    /**
    * This function is called by the implementation for propString value changes.
    */
    virtual void publishPropStringChanged(const std::list<StructString>& propString) const = 0;
    /**
    * This function is called by the implementation when the sigBool signal is triggered.
    *
    * @param paramBool 
    */
    virtual void publishSigBool(const std::list<StructBool>& paramBool) const = 0;
    /**
    * This function is called by the implementation when the sigInt signal is triggered.
    *
    * @param paramInt 
    */
    virtual void publishSigInt(const std::list<StructInt>& paramInt) const = 0;
    /**
    * This function is called by the implementation when the sigFloat signal is triggered.
    *
    * @param paramFloat 
    */
    virtual void publishSigFloat(const std::list<StructFloat>& paramFloat) const = 0;
    /**
    * This function is called by the implementation when the sigString signal is triggered.
    *
    * @param paramString 
    */
    virtual void publishSigString(const std::list<StructString>& paramString) const = 0;
};

/**
 * Interface IStructArrayInterface
 */
class TEST_TESTBED1_EXPORT IStructArrayInterface
{
public:
    virtual ~IStructArrayInterface() = default;

    // methods
    virtual StructBool funcBool(const std::list<StructBool>& paramBool) = 0;
    /**
    * Asynchronous function call for funcBool(const std::list<StructBool>& paramBool)
    *
    * @return Promise of type StructBool which is set once the function has completed
    */
    virtual std::future<StructBool> funcBoolAsync(const std::list<StructBool>& paramBool) = 0;

    virtual StructBool funcInt(const std::list<StructInt>& paramInt) = 0;
    /**
    * Asynchronous function call for funcInt(const std::list<StructInt>& paramInt)
    *
    * @return Promise of type StructBool which is set once the function has completed
    */
    virtual std::future<StructBool> funcIntAsync(const std::list<StructInt>& paramInt) = 0;

    virtual StructBool funcFloat(const std::list<StructFloat>& paramFloat) = 0;
    /**
    * Asynchronous function call for funcFloat(const std::list<StructFloat>& paramFloat)
    *
    * @return Promise of type StructBool which is set once the function has completed
    */
    virtual std::future<StructBool> funcFloatAsync(const std::list<StructFloat>& paramFloat) = 0;

    virtual StructBool funcString(const std::list<StructString>& paramString) = 0;
    /**
    * Asynchronous function call for funcString(const std::list<StructString>& paramString)
    *
    * @return Promise of type StructBool which is set once the function has completed
    */
    virtual std::future<StructBool> funcStringAsync(const std::list<StructString>& paramString) = 0;

    // property methods
    /**
    * Sets the value of property propBool
    */
    virtual void setPropbool(const std::list<StructBool>& propBool) = 0;
    /**
    * Gets the value of property propBool
    */
    virtual const std::list<StructBool>& propBool() const = 0;

    /**
    * Sets the value of property propInt
    */
    virtual void setPropint(const std::list<StructInt>& propInt) = 0;
    /**
    * Gets the value of property propInt
    */
    virtual const std::list<StructInt>& propInt() const = 0;

    /**
    * Sets the value of property propFloat
    */
    virtual void setPropfloat(const std::list<StructFloat>& propFloat) = 0;
    /**
    * Gets the value of property propFloat
    */
    virtual const std::list<StructFloat>& propFloat() const = 0;

    /**
    * Sets the value of property propString
    */
    virtual void setPropstring(const std::list<StructString>& propString) = 0;
    /**
    * Gets the value of property propString
    */
    virtual const std::list<StructString>& propString() const = 0;

    /**
    * @return a pointer to the used IStructArrayInterfacePublisher for publish/subscribe events
    */
    virtual IStructArrayInterfacePublisher* _getPublisher() const = 0;
};

/**
 * Interface IStructArrayInterfaceDecorator
 *
 * Decorator interface helper for inheritance
 */
class TEST_TESTBED1_EXPORT IStructArrayInterfaceDecorator: public virtual IStructArrayInterface, public virtual IStructArrayInterfaceSubscriber {
public:
    /**
    * Swap the used implementation
    *
    * @param impl pointer to new implementation to be used
    * @return pointer to the original implementation
    */
    virtual IStructArrayInterface* swapUnderlyingImplementation(IStructArrayInterface* impl) = 0;
    /**
    * Disconnect the decorator from the originally used implementation
    *
    * @return pointer to the original implementation
    */
    virtual IStructArrayInterface* disconnectFromUnderlyingImplementation() = 0;
};
} // namespace Testbed1
} // namespace Test
