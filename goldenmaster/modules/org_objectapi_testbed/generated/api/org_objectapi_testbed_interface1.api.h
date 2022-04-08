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
#include "org_objectapi_testbed_common.h"
#include "org_objectapi_testbed_datastructs.api.h"

namespace Test {
namespace OrgObjectapiTestbed {
/**
 * Interface IInterface1Subscriber
 *
 * The subscriber is the counter part for the IInterface1Publisher.
 */
class TEST_ORG_OBJECTAPI_TESTBED_EXPORT IInterface1Subscriber
{
public:
    /**
    * This function is called when the sig1 signal is triggered.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    */
    virtual void OnSig1() = 0;
    /**
    * This function is called when the sig2 signal is triggered.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param step 
    */
    virtual void OnSig2(int step) = 0;
    /**
    * This function is called when the sig3 signal is triggered.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    */
    virtual void OnSig3() = 0;
    /**
    * This function is called when the prop1 value has changed.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnProp1Changed(bool prop1) = 0;
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
    virtual void OnProp3Changed(float prop3) = 0;
    /**
    * This function is called when the prop4 value has changed.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnProp4Changed(std::string prop4) = 0;
    /**
    * This function is called when the prop5 value has changed.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnProp5Changed(const std::list<int>& prop5) = 0;
    /**
    * This function is called when the prop6 value has changed.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnProp6Changed(const Struct1& prop6) = 0;
    /**
    * This function is called when the prop7 value has changed.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnProp7Changed(int prop7) = 0;
    /**
    * This function is called when the prop10 value has changed.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnProp10Changed(const std::list<int>& prop10) = 0;
    /**
    * This function is called when the prop11 value has changed.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnProp11Changed(const std::list<Struct1>& prop11) = 0;
    /**
    * This function is called when the prop12 value has changed.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnProp12Changed(const std::list<Enum1Enum>& prop12) = 0;
    /**
    * This function is called when the prop14 value has changed.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    */
    virtual void OnProp14Changed(const std::list<Struct1>& prop14) = 0;
};

/** callback for changes of prop1 */
typedef std::function<void(bool prop1)> Interface1Prop1PropertyCb;
/** callback for changes of prop2 */
typedef std::function<void(int prop2)> Interface1Prop2PropertyCb;
/** callback for changes of prop3 */
typedef std::function<void(float prop3)> Interface1Prop3PropertyCb;
/** callback for changes of prop4 */
typedef std::function<void(const std::string& prop4)> Interface1Prop4PropertyCb;
/** callback for changes of prop5 */
typedef std::function<void(const std::list<int>& prop5)> Interface1Prop5PropertyCb;
/** callback for changes of prop6 */
typedef std::function<void(const Struct1& prop6)> Interface1Prop6PropertyCb;
/** callback for changes of prop7 */
typedef std::function<void(int prop7)> Interface1Prop7PropertyCb;
/** callback for changes of prop10 */
typedef std::function<void(const std::list<int>& prop10)> Interface1Prop10PropertyCb;
/** callback for changes of prop11 */
typedef std::function<void(const std::list<Struct1>& prop11)> Interface1Prop11PropertyCb;
/** callback for changes of prop12 */
typedef std::function<void(const std::list<Enum1Enum>& prop12)> Interface1Prop12PropertyCb;
/** callback for changes of prop14 */
typedef std::function<void(const std::list<Struct1>& prop14)> Interface1Prop14PropertyCb;
/** callback for sig1 signal triggers */
typedef std::function<void()> Interface1Sig1SignalCb;
/** callback for sig2 signal triggers */
typedef std::function<void(int step)> Interface1Sig2SignalCb;
/** callback for sig3 signal triggers */
typedef std::function<void()> Interface1Sig3SignalCb;
/**
 * Interface IInterface1Publisher
 *
 * The publisher contains the signal interface for the IInterface1Subscriber
 * and direct signal function subscribtion.
 */
class TEST_ORG_OBJECTAPI_TESTBED_EXPORT IInterface1Publisher
{
public:
    virtual ~IInterface1Publisher() = default;

    /**
    * Use this function to subscribe for any changes of the Interface1 changes.
    * This subscription will trigger calls for any property changes or signal events.
    *
    * @param subscriber reference to the IInterface1Subscriber implementation
    */
    virtual void subscribeToInterface1Interface(IInterface1Subscriber& subscriber) = 0;
    /**
    * Use this function to unsubscribe from all changes of the Interface1 changes.
    *
    * @param subscriber reference to the IInterface1Subscriber implementation
    */
    virtual void unsubscribeFromInterface1Interface(IInterface1Subscriber& subscriber) = 0;

    /**
    * Use this function to subscribe for prop1 value changes.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param callback any of type Interface1Prop1PropertyCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToProp1Changed(Interface1Prop1PropertyCb callback) = 0;
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
    * @param callback any of type Interface1Prop2PropertyCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToProp2Changed(Interface1Prop2PropertyCb callback) = 0;
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
    * @param callback any of type Interface1Prop3PropertyCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToProp3Changed(Interface1Prop3PropertyCb callback) = 0;
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
    * @param callback any of type Interface1Prop4PropertyCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToProp4Changed(Interface1Prop4PropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from prop4 property changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromProp4Changed(long handleId) = 0;

    /**
    * Use this function to subscribe for prop5 value changes.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param callback any of type Interface1Prop5PropertyCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToProp5Changed(Interface1Prop5PropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from prop5 property changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromProp5Changed(long handleId) = 0;

    /**
    * Use this function to subscribe for prop6 value changes.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param callback any of type Interface1Prop6PropertyCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToProp6Changed(Interface1Prop6PropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from prop6 property changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromProp6Changed(long handleId) = 0;

    /**
    * Use this function to subscribe for prop7 value changes.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param callback any of type Interface1Prop7PropertyCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToProp7Changed(Interface1Prop7PropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from prop7 property changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromProp7Changed(long handleId) = 0;

    /**
    * Use this function to subscribe for prop10 value changes.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param callback any of type Interface1Prop10PropertyCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToProp10Changed(Interface1Prop10PropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from prop10 property changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromProp10Changed(long handleId) = 0;

    /**
    * Use this function to subscribe for prop11 value changes.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param callback any of type Interface1Prop11PropertyCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToProp11Changed(Interface1Prop11PropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from prop11 property changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromProp11Changed(long handleId) = 0;

    /**
    * Use this function to subscribe for prop12 value changes.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param callback any of type Interface1Prop12PropertyCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToProp12Changed(Interface1Prop12PropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from prop12 property changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromProp12Changed(long handleId) = 0;

    /**
    * Use this function to subscribe for prop14 value changes.
    *
    * @warning the subscribed function shall not be blocking and must return immediately!
    *
    * @param callback any of type Interface1Prop14PropertyCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToProp14Changed(Interface1Prop14PropertyCb callback) = 0;
    /**
    * Use this function to unsubscribe from prop14 property changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromProp14Changed(long handleId) = 0;

    /**
    * Use this function to subscribe for sig1 signal changes.
    *
    * @param callback any of type Interface1Sig1SignalCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToSig1(Interface1Sig1SignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sig1 signal changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromSig1(long handleId) = 0;

    /**
    * Use this function to subscribe for sig2 signal changes.
    *
    * @param callback any of type Interface1Sig2SignalCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToSig2(Interface1Sig2SignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sig2 signal changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromSig2(long handleId) = 0;

    /**
    * Use this function to subscribe for sig3 signal changes.
    *
    * @param callback any of type Interface1Sig3SignalCb
    * @return unique identifier for this subscription, needed for removal
    */
    virtual long subscribeToSig3(Interface1Sig3SignalCb callback) = 0;
    /**
    * Use this function to unsubscribe from sig3 signal changes.
    *
    * @param handleId identifier returned by the original subscription call
    */
    virtual void unsubscribeFromSig3(long handleId) = 0;

    /**
    * This function is called by the implementation for prop1 value changes.
    */
    virtual void publishProp1Changed(bool prop1) const = 0;
    /**
    * This function is called by the implementation for prop2 value changes.
    */
    virtual void publishProp2Changed(int prop2) const = 0;
    /**
    * This function is called by the implementation for prop3 value changes.
    */
    virtual void publishProp3Changed(float prop3) const = 0;
    /**
    * This function is called by the implementation for prop4 value changes.
    */
    virtual void publishProp4Changed(const std::string& prop4) const = 0;
    /**
    * This function is called by the implementation for prop5 value changes.
    */
    virtual void publishProp5Changed(const std::list<int>& prop5) const = 0;
    /**
    * This function is called by the implementation for prop6 value changes.
    */
    virtual void publishProp6Changed(const Struct1& prop6) const = 0;
    /**
    * This function is called by the implementation for prop7 value changes.
    */
    virtual void publishProp7Changed(int prop7) const = 0;
    /**
    * This function is called by the implementation for prop10 value changes.
    */
    virtual void publishProp10Changed(const std::list<int>& prop10) const = 0;
    /**
    * This function is called by the implementation for prop11 value changes.
    */
    virtual void publishProp11Changed(const std::list<Struct1>& prop11) const = 0;
    /**
    * This function is called by the implementation for prop12 value changes.
    */
    virtual void publishProp12Changed(const std::list<Enum1Enum>& prop12) const = 0;
    /**
    * This function is called by the implementation for prop14 value changes.
    */
    virtual void publishProp14Changed(const std::list<Struct1>& prop14) const = 0;
    /**
    * This function is called by the implementation when the sig1 signal is triggered.
    *
    */
    virtual void publishSig1() const = 0;
    /**
    * This function is called by the implementation when the sig2 signal is triggered.
    *
    * @param step 
    */
    virtual void publishSig2(int step) const = 0;
    /**
    * This function is called by the implementation when the sig3 signal is triggered.
    *
    */
    virtual void publishSig3() const = 0;
};

/**
 * Interface IInterface1
 */
class TEST_ORG_OBJECTAPI_TESTBED_EXPORT IInterface1
{
public:
    virtual ~IInterface1() = default;

    // methods
    virtual void op1() = 0;
    /**
    * Asynchronous function call for op1()
    *
    * @return Promise of type void which is set once the function has completed
    */
    virtual std::future<void> op1Async() = 0;

    virtual void op2(int step) = 0;
    /**
    * Asynchronous function call for op2(int step)
    *
    * @return Promise of type void which is set once the function has completed
    */
    virtual std::future<void> op2Async(int step) = 0;

    virtual int op3() = 0;
    /**
    * Asynchronous function call for op3()
    *
    * @return Promise of type int which is set once the function has completed
    */
    virtual std::future<int> op3Async() = 0;

    // property methods
    /**
    * Sets the value of property prop1
    */
    virtual void setProp1(bool prop1) = 0;
    /**
    * Gets the value of property prop1
    */
    virtual bool prop1() const = 0;

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
    virtual void setProp3(float prop3) = 0;
    /**
    * Gets the value of property prop3
    */
    virtual float prop3() const = 0;

    /**
    * Sets the value of property prop4
    */
    virtual void setProp4(const std::string& prop4) = 0;
    /**
    * Gets the value of property prop4
    */
    virtual std::string prop4() const = 0;

    /**
    * Sets the value of property prop5
    */
    virtual void setProp5(const std::list<int>& prop5) = 0;
    /**
    * Gets the value of property prop5
    */
    virtual const std::list<int>& prop5() const = 0;

    /**
    * Sets the value of property prop6
    */
    virtual void setProp6(const Struct1& prop6) = 0;
    /**
    * Gets the value of property prop6
    */
    virtual const Struct1& prop6() const = 0;

    /**
    * Sets the value of property prop7
    */
    virtual void setProp7(int prop7) = 0;
    /**
    * Gets the value of property prop7
    */
    virtual int prop7() const = 0;

    /**
    * Sets the value of property prop10
    */
    virtual void setProp10(const std::list<int>& prop10) = 0;
    /**
    * Gets the value of property prop10
    */
    virtual const std::list<int>& prop10() const = 0;

    /**
    * Sets the value of property prop11
    */
    virtual void setProp11(const std::list<Struct1>& prop11) = 0;
    /**
    * Gets the value of property prop11
    */
    virtual const std::list<Struct1>& prop11() const = 0;

    /**
    * Sets the value of property prop12
    */
    virtual void setProp12(const std::list<Enum1Enum>& prop12) = 0;
    /**
    * Gets the value of property prop12
    */
    virtual const std::list<Enum1Enum>& prop12() const = 0;

    /**
    * Sets the value of property prop14
    */
    virtual void setProp14(const std::list<Struct1>& prop14) = 0;
    /**
    * Gets the value of property prop14
    */
    virtual const std::list<Struct1>& prop14() const = 0;

    /**
    * @return a pointer to the used IInterface1Publisher for publish/subscribe events
    */
    virtual IInterface1Publisher* _getPublisher() const = 0;
};

/**
 * Interface IInterface1Decorator
 *
 * Decorator interface helper for inheritance
 */
class TEST_ORG_OBJECTAPI_TESTBED_EXPORT IInterface1Decorator: public virtual IInterface1, public virtual IInterface1Subscriber {
public:
    /**
    * Swap the used implementation
    *
    * @param impl pointer to new implementation to be used
    * @return pointer to the original implementation
    */
    virtual IInterface1* swapUnderlyingImplementation(IInterface1* impl) = 0;
    /**
    * Disconnect the decorator from the originally used implementation
    *
    * @return pointer to the original implementation
    */
    virtual IInterface1* disconnectFromUnderlyingImplementation() = 0;
};
} // namespace OrgObjectapiTestbed
} // namespace Test
