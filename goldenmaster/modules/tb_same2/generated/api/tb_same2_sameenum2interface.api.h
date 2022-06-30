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
#include "tb_same2_common.h"
#include "tb_same2_datastructs.api.h"

namespace Test {
namespace TbSame2 {
/**
 * Interface ISameEnum2InterfaceSubscriber
 *
 * The subscriber is the counter part for the ISameEnum2InterfacePublisher.
 */
class TEST_TB_SAME2_EXPORT ISameEnum2InterfaceSubscriber
{
public:
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
    * @param param1 
    * @param param2 
    */
    virtual void OnSig2(const Enum1Enum& param1,const Enum2Enum& param2) = 0;
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
};

/** callback for changes of prop1 */
typedef std::function<void(const Enum1Enum& prop1)> SameEnum2InterfaceProp1PropertyCb;
/** callback for changes of prop2 */
typedef std::function<void(const Enum2Enum& prop2)> SameEnum2InterfaceProp2PropertyCb;
/** callback for sig1 signal triggers */
typedef std::function<void(const Enum1Enum& param1)> SameEnum2InterfaceSig1SignalCb;
/** callback for sig2 signal triggers */
typedef std::function<void(const Enum1Enum& param1,const Enum2Enum& param2)> SameEnum2InterfaceSig2SignalCb;
/**
 * Interface ISameEnum2InterfacePublisher
 *
 * The publisher contains the signal interface for the ISameEnum2InterfaceSubscriber
 * and direct signal function subscribtion.
 */
class TEST_TB_SAME2_EXPORT ISameEnum2InterfacePublisher
{
public:
    virtual ~ISameEnum2InterfacePublisher() = default;

    /**
    * Use this function to subscribe for any changes of the SameEnum2Interface changes.
    * This subscription will trigger calls for any property changes or signal events.
    *
    * @param subscriber reference to the ISameEnum2InterfaceSubscriber implementation
    */
    virtual void subscribeToSameEnum2InterfaceInterface(ISameEnum2InterfaceSubscriber& subscriber) = 0;
    /**
    * Use this function to unsubscribe from all changes of the SameEnum2Interface changes.
    *
    * @param subscriber reference to the ISameEnum2InterfaceSubscriber implementation
    */
    virtual void unsubscribeFromSameEnum2InterfaceInterface(ISameEnum2InterfaceSubscriber& subscriber) = 0;

    /**
    * Use this function to subscribe for prop1 value changes.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param callback any of type SameEnum2InterfaceProp1PropertyCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToProp1Changed(SameEnum2InterfaceProp1PropertyCb callback) = 0;
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
    * @param callback any of type SameEnum2InterfaceProp2PropertyCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToProp2Changed(SameEnum2InterfaceProp2PropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from prop2 property changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromProp2Changed(long handleId) = 0;

    /**
    * Use this function to subscribe for sig1 signal changes.
    *
    * @param callback any of type SameEnum2InterfaceSig1SignalCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToSig1(SameEnum2InterfaceSig1SignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sig1 signal changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromSig1(long handleId) = 0;

    /**
    * Use this function to subscribe for sig2 signal changes.
    *
    * @param callback any of type SameEnum2InterfaceSig2SignalCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToSig2(SameEnum2InterfaceSig2SignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sig2 signal changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromSig2(long handleId) = 0;

    /**
    * This function is called by the implementation for prop1 value changes.
    */
    virtual void publishProp1Changed(const Enum1Enum& prop1) const = 0;
    /**
    * This function is called by the implementation for prop2 value changes.
    */
    virtual void publishProp2Changed(const Enum2Enum& prop2) const = 0;
    /**
    * This function is called by the implementation when the sig1 signal is triggered.
    *
    * @param param1 
    */
    virtual void publishSig1(const Enum1Enum& param1) const = 0;
    /**
    * This function is called by the implementation when the sig2 signal is triggered.
    *
    * @param param1 
    * @param param2 
    */
    virtual void publishSig2(const Enum1Enum& param1,const Enum2Enum& param2) const = 0;
};

/**
 * Interface ISameEnum2Interface
 */
class TEST_TB_SAME2_EXPORT ISameEnum2Interface
{
public:
    virtual ~ISameEnum2Interface() = default;

    // methods
    virtual Enum1Enum func1(const Enum1Enum& param1) = 0;
    /**
    * Asynchronous function call for func1(const Enum1Enum& param1)
    *
    * @return Promise of type Enum1Enum which is set once the function has completed
    */
    virtual std::future<Enum1Enum> func1Async(const Enum1Enum& param1) = 0;

    virtual Enum1Enum func2(const Enum1Enum& param1, const Enum2Enum& param2) = 0;
    /**
    * Asynchronous function call for func2(const Enum1Enum& param1, const Enum2Enum& param2)
    *
    * @return Promise of type Enum1Enum which is set once the function has completed
    */
    virtual std::future<Enum1Enum> func2Async(const Enum1Enum& param1, const Enum2Enum& param2) = 0;

    // property methods
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
    * @return a pointer to the used ISameEnum2InterfacePublisher for publish/subscribe events
    */
    virtual ISameEnum2InterfacePublisher* _getPublisher() const = 0;
};

/**
 * Interface ISameEnum2InterfaceDecorator
 *
 * Decorator interface helper for inheritance
 */
class TEST_TB_SAME2_EXPORT ISameEnum2InterfaceDecorator: public virtual ISameEnum2Interface, public virtual ISameEnum2InterfaceSubscriber {
public:
    /**
    * Swap the used implementation
    *
    * @param impl pointer to new implementation to be used
    * @return pointer to the original implementation
    */
    virtual ISameEnum2Interface* swapUnderlyingImplementation(ISameEnum2Interface* impl) = 0;
    /**
    * Disconnect the decorator from the originally used implementation
    *
    * @return pointer to the original implementation
    */
    virtual ISameEnum2Interface* disconnectFromUnderlyingImplementation() = 0;
};
} // namespace TbSame2
} // namespace Test
