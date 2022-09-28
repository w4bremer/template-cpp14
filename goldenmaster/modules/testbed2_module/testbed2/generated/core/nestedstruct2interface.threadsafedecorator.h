
#pragma once
#include "testbed2/generated/api/testbed2.h"
#include "testbed2/generated/api/common.h"
#include <memory>
#include <shared_mutex>

namespace Test {
namespace Testbed2 {

/** 
* @brief The NestedStruct2InterfaceThreadSafeDecorator can be used to make property access thread safe.
*
* Each property is guarded with its own mutex.
* Multiple read/get operations can occur at the same time but only one write/set operation at a time.
*
* Operations a are not guarded by default since the function logic can be too complex than to simply lock it.
* However, functions can be locked by just adding the same mechanism in the implementation file of
* the NestedStruct2Interface interface.
* @see NestedStruct2Interface
*
\code{.cpp}
int main(){
    std::unique_ptr<Testbed2::INestedStruct2Interface> testTestbed2NestedStruct2Interface = std::make_unique<Testbed2::NestedStruct2Interface>();
    std::unique_ptr<Testbed2::INestedStruct2Interface> testTestbed2NestedStruct2InterfaceThreadSafeDecorator = std::make_unique<Test::Testbed2::NestedStruct2InterfaceThreadSafeDecorator>(std::move(testTestbed2NestedStruct2Interface));

    // Thread safe access
    testTestbed2NestedStruct2InterfaceThreadSafeDecorator->setProp1(testTestbed2NestedStruct2InterfaceThreadSafeDecorator->getProp1());
    testTestbed2NestedStruct2InterfaceThreadSafeDecorator->setProp2(testTestbed2NestedStruct2InterfaceThreadSafeDecorator->getProp2());
    return 0;
}
\endcode
*/
class TEST_TESTBED2_EXPORT NestedStruct2InterfaceThreadSafeDecorator : public INestedStruct2Interface
{
public:
    /** 
    * ctor
    * @param impl The NestedStruct2Interface object to make thread safe.
    */
    explicit NestedStruct2InterfaceThreadSafeDecorator(std::shared_ptr<INestedStruct2Interface> impl);

    /** Forwards call to NestedStruct2Interface implementation. */
    NestedStruct1 func1(const NestedStruct1& param1) override;
    /** Forwards call to NestedStruct2Interface implementation. */
    std::future<NestedStruct1> func1Async(const NestedStruct1& param1) override;

    /** Forwards call to NestedStruct2Interface implementation. */
    NestedStruct1 func2(const NestedStruct1& param1, const NestedStruct2& param2) override;
    /** Forwards call to NestedStruct2Interface implementation. */
    std::future<NestedStruct1> func2Async(const NestedStruct1& param1, const NestedStruct2& param2) override;

    /** Guards and forwards call to NestedStruct2Interface implementation. */
    void setProp1(const NestedStruct1& prop1) override;
    /** Guards and forwards call to NestedStruct2Interface implementation. */
    const NestedStruct1& getProp1() const override;

    /** Guards and forwards call to NestedStruct2Interface implementation. */
    void setProp2(const NestedStruct2& prop2) override;
    /** Guards and forwards call to NestedStruct2Interface implementation. */
    const NestedStruct2& getProp2() const override;

    /**
    * Access to a publisher, use it to subscribe for NestedStruct2Interface changes and signal emission.
    * @return The publisher for NestedStruct2Interface.
    */
    INestedStruct2InterfacePublisher& _getPublisher() const override;
private:
    /** The NestedStruct2Interface object which is guarded */
    std::shared_ptr<INestedStruct2Interface> m_impl;
    // Mutex for prop1 property
    mutable std::shared_timed_mutex m_prop1Mutex;
    // Mutex for prop2 property
    mutable std::shared_timed_mutex m_prop2Mutex;
};
} // namespace Testbed2
} // namespace Test
