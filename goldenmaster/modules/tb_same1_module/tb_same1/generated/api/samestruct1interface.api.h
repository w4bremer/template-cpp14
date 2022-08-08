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
#include "tb_same1/generated/api/common.h"
#include "tb_same1/generated/api/datastructs.api.h"

namespace Test {
namespace TbSame1 {
/**
 * Interface ISameStruct1InterfaceSubscriber
 *
 * The subscriber is the counter part for the ISameStruct1InterfacePublisher.
 */
class TEST_TB_SAME1_EXPORT ISameStruct1InterfaceSubscriber
{
public:
    /**
    * This function is called when the sig1 signal is triggered.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param param1 
    */
    virtual void OnSig1(const Struct1& param1) = 0;
    /**
    * This function is called when the prop1 value has changed.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnProp1Changed(const Struct1& prop1) = 0;
};

/** callback for changes of prop1 */
typedef std::function<void(const Struct1& prop1)> SameStruct1InterfaceProp1PropertyCb;
/** callback for sig1 signal triggers */
typedef std::function<void(const Struct1& param1)> SameStruct1InterfaceSig1SignalCb;
/**
 * Interface ISameStruct1InterfacePublisher
 *
 * The publisher contains the signal interface for the ISameStruct1InterfaceSubscriber
 * and direct signal function subscribtion.
 */
class TEST_TB_SAME1_EXPORT ISameStruct1InterfacePublisher
{
public:
    virtual ~ISameStruct1InterfacePublisher() = default;

    /**
    * Use this function to subscribe for any changes of the SameStruct1Interface changes.
    * This subscription will trigger calls for any property changes or signal events.
    *
    * @param subscriber reference to the ISameStruct1InterfaceSubscriber implementation
    */
    virtual void subscribeToSameStruct1InterfaceInterface(ISameStruct1InterfaceSubscriber& subscriber) = 0;
    /**
    * Use this function to unsubscribe from all changes of the SameStruct1Interface changes.
    *
    * @param subscriber reference to the ISameStruct1InterfaceSubscriber implementation
    */
    virtual void unsubscribeFromSameStruct1InterfaceInterface(ISameStruct1InterfaceSubscriber& subscriber) = 0;

    /**
    * Use this function to subscribe for prop1 value changes.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param callback any of type SameStruct1InterfaceProp1PropertyCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToProp1Changed(SameStruct1InterfaceProp1PropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from prop1 property changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromProp1Changed(long handleId) = 0;

    /**
    * Use this function to subscribe for sig1 signal changes.
    *
    * @param callback any of type SameStruct1InterfaceSig1SignalCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToSig1(SameStruct1InterfaceSig1SignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sig1 signal changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromSig1(long handleId) = 0;

    /**
    * This function is called by the implementation for prop1 value changes.
    */
    virtual void publishProp1Changed(const Struct1& prop1) const = 0;
    /**
    * This function is called by the implementation when the sig1 signal is triggered.
    *
    * @param param1 
    */
    virtual void publishSig1(const Struct1& param1) const = 0;
};

/**
 * Interface ISameStruct1Interface
 */
class TEST_TB_SAME1_EXPORT ISameStruct1Interface
{
public:
    virtual ~ISameStruct1Interface() = default;

    // methods
    virtual Struct1 func1(const Struct1& param1) = 0;
    /**
    * Asynchronous function call for func1(const Struct1& param1)
    *
    * @return Promise of type Struct1 which is set once the function has completed
    */
    virtual std::future<Struct1> func1Async(const Struct1& param1) = 0;

    // property methods
    /**
    * Sets the value of property prop1
    */
    virtual void setProp1(const Struct1& prop1) = 0;
    /**
    * Gets the value of property prop1
    */
    virtual const Struct1& prop1() const = 0;

    /**
    * @return a pointer to the used ISameStruct1InterfacePublisher for publish/subscribe events
    */
    virtual ISameStruct1InterfacePublisher* _getPublisher() const = 0;
};

/**
 * Interface ISameStruct1InterfaceDecorator
 *
 * Decorator interface helper for inheritance
 */
class TEST_TB_SAME1_EXPORT ISameStruct1InterfaceDecorator: public virtual ISameStruct1Interface, public virtual ISameStruct1InterfaceSubscriber {
public:
    /**
    * Swap the used implementation
    *
    * @param impl pointer to new implementation to be used
    * @return pointer to the original implementation
    */
    virtual ISameStruct1Interface* swapUnderlyingImplementation(ISameStruct1Interface* impl) = 0;
    /**
    * Disconnect the decorator from the originally used implementation
    *
    * @return pointer to the original implementation
    */
    virtual ISameStruct1Interface* disconnectFromUnderlyingImplementation() = 0;
};
} // namespace TbSame1
} // namespace Test
