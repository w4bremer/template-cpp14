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
#include "tb_simple/generated/api/common.h"
#include "tb_simple/generated/api/datastructs.api.h"

namespace Test {
namespace TbSimple {
/**
 * Interface ISimpleArrayInterfaceSubscriber
 *
 * The subscriber is the counter part for the ISimpleArrayInterfacePublisher.
 */
class TEST_TB_SIMPLE_EXPORT ISimpleArrayInterfaceSubscriber
{
public:
    /**
    * This function is called when the sigBool signal is triggered.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param paramBool 
    */
    virtual void OnSigBool(const std::list<bool>& paramBool) = 0;
    /**
    * This function is called when the sigInt signal is triggered.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param paramInt 
    */
    virtual void OnSigInt(const std::list<int>& paramInt) = 0;
    /**
    * This function is called when the sigFloat signal is triggered.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param paramFloat 
    */
    virtual void OnSigFloat(const std::list<float>& paramFloat) = 0;
    /**
    * This function is called when the sigString signal is triggered.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param paramString 
    */
    virtual void OnSigString(const std::list<std::string>& paramString) = 0;
    /**
    * This function is called when the propBool value has changed.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnPropBoolChanged(const std::list<bool>& propBool) = 0;
    /**
    * This function is called when the propInt value has changed.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnPropIntChanged(const std::list<int>& propInt) = 0;
    /**
    * This function is called when the propFloat value has changed.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnPropFloatChanged(const std::list<float>& propFloat) = 0;
    /**
    * This function is called when the propString value has changed.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnPropStringChanged(const std::list<std::string>& propString) = 0;
};

/** callback for changes of propBool */
typedef std::function<void(const std::list<bool>& propBool)> SimpleArrayInterfacePropBoolPropertyCb;
/** callback for changes of propInt */
typedef std::function<void(const std::list<int>& propInt)> SimpleArrayInterfacePropIntPropertyCb;
/** callback for changes of propFloat */
typedef std::function<void(const std::list<float>& propFloat)> SimpleArrayInterfacePropFloatPropertyCb;
/** callback for changes of propString */
typedef std::function<void(const std::list<std::string>& propString)> SimpleArrayInterfacePropStringPropertyCb;
/** callback for sigBool signal triggers */
typedef std::function<void(const std::list<bool>& paramBool)> SimpleArrayInterfaceSigBoolSignalCb;
/** callback for sigInt signal triggers */
typedef std::function<void(const std::list<int>& paramInt)> SimpleArrayInterfaceSigIntSignalCb;
/** callback for sigFloat signal triggers */
typedef std::function<void(const std::list<float>& paramFloat)> SimpleArrayInterfaceSigFloatSignalCb;
/** callback for sigString signal triggers */
typedef std::function<void(const std::list<std::string>& paramString)> SimpleArrayInterfaceSigStringSignalCb;
/**
 * Interface ISimpleArrayInterfacePublisher
 *
 * The publisher contains the signal interface for the ISimpleArrayInterfaceSubscriber
 * and direct signal function subscribtion.
 */
class TEST_TB_SIMPLE_EXPORT ISimpleArrayInterfacePublisher
{
public:
    virtual ~ISimpleArrayInterfacePublisher() = default;

    /**
    * Use this function to subscribe for any changes of the SimpleArrayInterface changes.
    * This subscription will trigger calls for any property changes or signal events.
    *
    * @param subscriber reference to the ISimpleArrayInterfaceSubscriber implementation
    */
    virtual void subscribeToSimpleArrayInterfaceInterface(ISimpleArrayInterfaceSubscriber& subscriber) = 0;
    /**
    * Use this function to unsubscribe from all changes of the SimpleArrayInterface changes.
    *
    * @param subscriber reference to the ISimpleArrayInterfaceSubscriber implementation
    */
    virtual void unsubscribeFromSimpleArrayInterfaceInterface(ISimpleArrayInterfaceSubscriber& subscriber) = 0;

    /**
    * Use this function to subscribe for propBool value changes.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param callback any of type SimpleArrayInterfacePropBoolPropertyCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToPropBoolChanged(SimpleArrayInterfacePropBoolPropertyCb callback) = 0;
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
    * @param callback any of type SimpleArrayInterfacePropIntPropertyCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToPropIntChanged(SimpleArrayInterfacePropIntPropertyCb callback) = 0;
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
    * @param callback any of type SimpleArrayInterfacePropFloatPropertyCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToPropFloatChanged(SimpleArrayInterfacePropFloatPropertyCb callback) = 0;
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
    * @param callback any of type SimpleArrayInterfacePropStringPropertyCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToPropStringChanged(SimpleArrayInterfacePropStringPropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from propString property changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromPropStringChanged(long handleId) = 0;

    /**
    * Use this function to subscribe for sigBool signal changes.
    *
    * @param callback any of type SimpleArrayInterfaceSigBoolSignalCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToSigBool(SimpleArrayInterfaceSigBoolSignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sigBool signal changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromSigBool(long handleId) = 0;

    /**
    * Use this function to subscribe for sigInt signal changes.
    *
    * @param callback any of type SimpleArrayInterfaceSigIntSignalCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToSigInt(SimpleArrayInterfaceSigIntSignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sigInt signal changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromSigInt(long handleId) = 0;

    /**
    * Use this function to subscribe for sigFloat signal changes.
    *
    * @param callback any of type SimpleArrayInterfaceSigFloatSignalCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToSigFloat(SimpleArrayInterfaceSigFloatSignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sigFloat signal changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromSigFloat(long handleId) = 0;

    /**
    * Use this function to subscribe for sigString signal changes.
    *
    * @param callback any of type SimpleArrayInterfaceSigStringSignalCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToSigString(SimpleArrayInterfaceSigStringSignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sigString signal changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromSigString(long handleId) = 0;

    /**
    * This function is called by the implementation for propBool value changes.
    */
    virtual void publishPropBoolChanged(const std::list<bool>& propBool) const = 0;
    /**
    * This function is called by the implementation for propInt value changes.
    */
    virtual void publishPropIntChanged(const std::list<int>& propInt) const = 0;
    /**
    * This function is called by the implementation for propFloat value changes.
    */
    virtual void publishPropFloatChanged(const std::list<float>& propFloat) const = 0;
    /**
    * This function is called by the implementation for propString value changes.
    */
    virtual void publishPropStringChanged(const std::list<std::string>& propString) const = 0;
    /**
    * This function is called by the implementation when the sigBool signal is triggered.
    *
    * @param paramBool 
    */
    virtual void publishSigBool(const std::list<bool>& paramBool) const = 0;
    /**
    * This function is called by the implementation when the sigInt signal is triggered.
    *
    * @param paramInt 
    */
    virtual void publishSigInt(const std::list<int>& paramInt) const = 0;
    /**
    * This function is called by the implementation when the sigFloat signal is triggered.
    *
    * @param paramFloat 
    */
    virtual void publishSigFloat(const std::list<float>& paramFloat) const = 0;
    /**
    * This function is called by the implementation when the sigString signal is triggered.
    *
    * @param paramString 
    */
    virtual void publishSigString(const std::list<std::string>& paramString) const = 0;
};

/**
 * Interface ISimpleArrayInterface
 */
class TEST_TB_SIMPLE_EXPORT ISimpleArrayInterface
{
public:
    virtual ~ISimpleArrayInterface() = default;

    // methods
    virtual std::list<bool> funcBool(const std::list<bool>& paramBool) = 0;
    /**
    * Asynchronous function call for funcBool(const std::list<bool>& paramBool)
    *
    * @return Promise of type std::list<bool> which is set once the function has completed
    */
    virtual std::future<std::list<bool>> funcBoolAsync(const std::list<bool>& paramBool) = 0;

    virtual std::list<int> funcInt(const std::list<int>& paramInt) = 0;
    /**
    * Asynchronous function call for funcInt(const std::list<int>& paramInt)
    *
    * @return Promise of type std::list<int> which is set once the function has completed
    */
    virtual std::future<std::list<int>> funcIntAsync(const std::list<int>& paramInt) = 0;

    virtual std::list<float> funcFloat(const std::list<float>& paramFloat) = 0;
    /**
    * Asynchronous function call for funcFloat(const std::list<float>& paramFloat)
    *
    * @return Promise of type std::list<float> which is set once the function has completed
    */
    virtual std::future<std::list<float>> funcFloatAsync(const std::list<float>& paramFloat) = 0;

    virtual std::list<std::string> funcString(const std::list<std::string>& paramString) = 0;
    /**
    * Asynchronous function call for funcString(const std::list<std::string>& paramString)
    *
    * @return Promise of type std::list<std::string> which is set once the function has completed
    */
    virtual std::future<std::list<std::string>> funcStringAsync(const std::list<std::string>& paramString) = 0;

    // property methods
    /**
    * Sets the value of property propBool
    */
    virtual void setPropbool(const std::list<bool>& propBool) = 0;
    /**
    * Gets the value of property propBool
    */
    virtual const std::list<bool>& propBool() const = 0;

    /**
    * Sets the value of property propInt
    */
    virtual void setPropint(const std::list<int>& propInt) = 0;
    /**
    * Gets the value of property propInt
    */
    virtual const std::list<int>& propInt() const = 0;

    /**
    * Sets the value of property propFloat
    */
    virtual void setPropfloat(const std::list<float>& propFloat) = 0;
    /**
    * Gets the value of property propFloat
    */
    virtual const std::list<float>& propFloat() const = 0;

    /**
    * Sets the value of property propString
    */
    virtual void setPropstring(const std::list<std::string>& propString) = 0;
    /**
    * Gets the value of property propString
    */
    virtual const std::list<std::string>& propString() const = 0;

    /**
    * @return a pointer to the used ISimpleArrayInterfacePublisher for publish/subscribe events
    */
    virtual ISimpleArrayInterfacePublisher* _getPublisher() const = 0;
};

/**
 * Interface ISimpleArrayInterfaceDecorator
 *
 * Decorator interface helper for inheritance
 */
class TEST_TB_SIMPLE_EXPORT ISimpleArrayInterfaceDecorator: public virtual ISimpleArrayInterface, public virtual ISimpleArrayInterfaceSubscriber {
public:
    /**
    * Swap the used implementation
    *
    * @param impl pointer to new implementation to be used
    * @return pointer to the original implementation
    */
    virtual ISimpleArrayInterface* swapUnderlyingImplementation(ISimpleArrayInterface* impl) = 0;
    /**
    * Disconnect the decorator from the originally used implementation
    *
    * @return pointer to the original implementation
    */
    virtual ISimpleArrayInterface* disconnectFromUnderlyingImplementation() = 0;
};
} // namespace TbSimple
} // namespace Test
