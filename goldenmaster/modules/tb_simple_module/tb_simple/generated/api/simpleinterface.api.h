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
 * Interface ISimpleInterfaceSubscriber
 *
 * The subscriber is the counter part for the ISimpleInterfacePublisher.
 */
class TEST_TB_SIMPLE_EXPORT ISimpleInterfaceSubscriber
{
public:
    /**
    * This function is called when the sigBool signal is triggered.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param paramBool 
    */
    virtual void OnSigBool(bool paramBool) = 0;
    /**
    * This function is called when the sigInt signal is triggered.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param paramInt 
    */
    virtual void OnSigInt(int paramInt) = 0;
    /**
    * This function is called when the sigFloat signal is triggered.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param paramFloat 
    */
    virtual void OnSigFloat(float paramFloat) = 0;
    /**
    * This function is called when the sigString signal is triggered.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param paramString 
    */
    virtual void OnSigString(const std::string& paramString) = 0;
    /**
    * This function is called when the propBool value has changed.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnPropBoolChanged(bool propBool) = 0;
    /**
    * This function is called when the propInt value has changed.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnPropIntChanged(int propInt) = 0;
    /**
    * This function is called when the propFloat value has changed.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnPropFloatChanged(float propFloat) = 0;
    /**
    * This function is called when the propString value has changed.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnPropStringChanged(std::string propString) = 0;
};

/** callback for changes of propBool */
typedef std::function<void(bool propBool)> SimpleInterfacePropBoolPropertyCb;
/** callback for changes of propInt */
typedef std::function<void(int propInt)> SimpleInterfacePropIntPropertyCb;
/** callback for changes of propFloat */
typedef std::function<void(float propFloat)> SimpleInterfacePropFloatPropertyCb;
/** callback for changes of propString */
typedef std::function<void(const std::string& propString)> SimpleInterfacePropStringPropertyCb;
/** callback for sigBool signal triggers */
typedef std::function<void(bool paramBool)> SimpleInterfaceSigBoolSignalCb;
/** callback for sigInt signal triggers */
typedef std::function<void(int paramInt)> SimpleInterfaceSigIntSignalCb;
/** callback for sigFloat signal triggers */
typedef std::function<void(float paramFloat)> SimpleInterfaceSigFloatSignalCb;
/** callback for sigString signal triggers */
typedef std::function<void(const std::string& paramString)> SimpleInterfaceSigStringSignalCb;
/**
 * Interface ISimpleInterfacePublisher
 *
 * The publisher contains the signal interface for the ISimpleInterfaceSubscriber
 * and direct signal function subscribtion.
 */
class TEST_TB_SIMPLE_EXPORT ISimpleInterfacePublisher
{
public:
    virtual ~ISimpleInterfacePublisher() = default;

    /**
    * Use this function to subscribe for any changes of the SimpleInterface changes.
    * This subscription will trigger calls for any property changes or signal events.
    *
    * @param subscriber reference to the ISimpleInterfaceSubscriber implementation
    */
    virtual void subscribeToSimpleInterfaceInterface(ISimpleInterfaceSubscriber& subscriber) = 0;
    /**
    * Use this function to unsubscribe from all changes of the SimpleInterface changes.
    *
    * @param subscriber reference to the ISimpleInterfaceSubscriber implementation
    */
    virtual void unsubscribeFromSimpleInterfaceInterface(ISimpleInterfaceSubscriber& subscriber) = 0;

    /**
    * Use this function to subscribe for propBool value changes.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param callback any of type SimpleInterfacePropBoolPropertyCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToPropBoolChanged(SimpleInterfacePropBoolPropertyCb callback) = 0;
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
    * @param callback any of type SimpleInterfacePropIntPropertyCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToPropIntChanged(SimpleInterfacePropIntPropertyCb callback) = 0;
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
    * @param callback any of type SimpleInterfacePropFloatPropertyCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToPropFloatChanged(SimpleInterfacePropFloatPropertyCb callback) = 0;
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
    * @param callback any of type SimpleInterfacePropStringPropertyCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToPropStringChanged(SimpleInterfacePropStringPropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from propString property changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromPropStringChanged(long handleId) = 0;

    /**
    * Use this function to subscribe for sigBool signal changes.
    *
    * @param callback any of type SimpleInterfaceSigBoolSignalCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToSigBool(SimpleInterfaceSigBoolSignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sigBool signal changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromSigBool(long handleId) = 0;

    /**
    * Use this function to subscribe for sigInt signal changes.
    *
    * @param callback any of type SimpleInterfaceSigIntSignalCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToSigInt(SimpleInterfaceSigIntSignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sigInt signal changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromSigInt(long handleId) = 0;

    /**
    * Use this function to subscribe for sigFloat signal changes.
    *
    * @param callback any of type SimpleInterfaceSigFloatSignalCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToSigFloat(SimpleInterfaceSigFloatSignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sigFloat signal changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromSigFloat(long handleId) = 0;

    /**
    * Use this function to subscribe for sigString signal changes.
    *
    * @param callback any of type SimpleInterfaceSigStringSignalCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToSigString(SimpleInterfaceSigStringSignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sigString signal changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromSigString(long handleId) = 0;

    /**
    * This function is called by the implementation for propBool value changes.
    */
    virtual void publishPropBoolChanged(bool propBool) const = 0;
    /**
    * This function is called by the implementation for propInt value changes.
    */
    virtual void publishPropIntChanged(int propInt) const = 0;
    /**
    * This function is called by the implementation for propFloat value changes.
    */
    virtual void publishPropFloatChanged(float propFloat) const = 0;
    /**
    * This function is called by the implementation for propString value changes.
    */
    virtual void publishPropStringChanged(const std::string& propString) const = 0;
    /**
    * This function is called by the implementation when the sigBool signal is triggered.
    *
    * @param paramBool 
    */
    virtual void publishSigBool(bool paramBool) const = 0;
    /**
    * This function is called by the implementation when the sigInt signal is triggered.
    *
    * @param paramInt 
    */
    virtual void publishSigInt(int paramInt) const = 0;
    /**
    * This function is called by the implementation when the sigFloat signal is triggered.
    *
    * @param paramFloat 
    */
    virtual void publishSigFloat(float paramFloat) const = 0;
    /**
    * This function is called by the implementation when the sigString signal is triggered.
    *
    * @param paramString 
    */
    virtual void publishSigString(const std::string& paramString) const = 0;
};

/**
 * Interface ISimpleInterface
 */
class TEST_TB_SIMPLE_EXPORT ISimpleInterface
{
public:
    virtual ~ISimpleInterface() = default;

    // methods
    virtual bool funcBool(bool paramBool) = 0;
    /**
    * Asynchronous function call for funcBool(bool paramBool)
    *
    * @return Promise of type bool which is set once the function has completed
    */
    virtual std::future<bool> funcBoolAsync(bool paramBool) = 0;

    virtual int funcInt(int paramInt) = 0;
    /**
    * Asynchronous function call for funcInt(int paramInt)
    *
    * @return Promise of type int which is set once the function has completed
    */
    virtual std::future<int> funcIntAsync(int paramInt) = 0;

    virtual float funcFloat(float paramFloat) = 0;
    /**
    * Asynchronous function call for funcFloat(float paramFloat)
    *
    * @return Promise of type float which is set once the function has completed
    */
    virtual std::future<float> funcFloatAsync(float paramFloat) = 0;

    virtual std::string funcString(const std::string& paramString) = 0;
    /**
    * Asynchronous function call for funcString(const std::string& paramString)
    *
    * @return Promise of type std::string which is set once the function has completed
    */
    virtual std::future<std::string> funcStringAsync(const std::string& paramString) = 0;

    // property methods
    /**
    * Sets the value of property propBool
    */
    virtual void setPropbool(bool propBool) = 0;
    /**
    * Gets the value of property propBool
    */
    virtual bool propBool() const = 0;

    /**
    * Sets the value of property propInt
    */
    virtual void setPropint(int propInt) = 0;
    /**
    * Gets the value of property propInt
    */
    virtual int propInt() const = 0;

    /**
    * Sets the value of property propFloat
    */
    virtual void setPropfloat(float propFloat) = 0;
    /**
    * Gets the value of property propFloat
    */
    virtual float propFloat() const = 0;

    /**
    * Sets the value of property propString
    */
    virtual void setPropstring(const std::string& propString) = 0;
    /**
    * Gets the value of property propString
    */
    virtual std::string propString() const = 0;

    /**
    * @return a pointer to the used ISimpleInterfacePublisher for publish/subscribe events
    */
    virtual ISimpleInterfacePublisher* _getPublisher() const = 0;
};

/**
 * Interface ISimpleInterfaceDecorator
 *
 * Decorator interface helper for inheritance
 */
class TEST_TB_SIMPLE_EXPORT ISimpleInterfaceDecorator: public virtual ISimpleInterface, public virtual ISimpleInterfaceSubscriber {
public:
    /**
    * Swap the used implementation
    *
    * @param impl pointer to new implementation to be used
    * @return pointer to the original implementation
    */
    virtual ISimpleInterface* swapUnderlyingImplementation(ISimpleInterface* impl) = 0;
    /**
    * Disconnect the decorator from the originally used implementation
    *
    * @return pointer to the original implementation
    */
    virtual ISimpleInterface* disconnectFromUnderlyingImplementation() = 0;
};
} // namespace TbSimple
} // namespace Test
