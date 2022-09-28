
#pragma once
#include "testbed2/generated/api/testbed2.h"
#include "testbed2/generated/api/common.h"
#include <memory>
#include <shared_mutex>

namespace Test {
namespace Testbed2 {

/** 
* @brief The ManyParamInterfaceThreadSafeDecorator can be used to make property access thread safe.
*
* Each property is guarded with its own mutex.
* Multiple read/get operations can occur at the same time but only one write/set operation at a time.
*
* Operations a are not guarded by default since the function logic can be too complex than to simply lock it.
* However, functions can be locked by just adding the same mechanism in the implementation file of
* the ManyParamInterface interface.
* @see ManyParamInterface
*
\code{.cpp}
int main(){
    std::unique_ptr<Testbed2::IManyParamInterface> testTestbed2ManyParamInterface = std::make_unique<Testbed2::ManyParamInterface>();
    std::unique_ptr<Testbed2::IManyParamInterface> testTestbed2ManyParamInterfaceThreadSafeDecorator = std::make_unique<Test::Testbed2::ManyParamInterfaceThreadSafeDecorator>(std::move(testTestbed2ManyParamInterface));

    // Thread safe access
    testTestbed2ManyParamInterfaceThreadSafeDecorator->setProp1(testTestbed2ManyParamInterfaceThreadSafeDecorator->getProp1());
    testTestbed2ManyParamInterfaceThreadSafeDecorator->setProp2(testTestbed2ManyParamInterfaceThreadSafeDecorator->getProp2());
    testTestbed2ManyParamInterfaceThreadSafeDecorator->setProp3(testTestbed2ManyParamInterfaceThreadSafeDecorator->getProp3());
    testTestbed2ManyParamInterfaceThreadSafeDecorator->setProp4(testTestbed2ManyParamInterfaceThreadSafeDecorator->getProp4());
    return 0;
}
\endcode
*/
class TEST_TESTBED2_EXPORT ManyParamInterfaceThreadSafeDecorator : public IManyParamInterface
{
public:
    /** 
    * ctor
    * @param impl The ManyParamInterface object to make thread safe.
    */
    explicit ManyParamInterfaceThreadSafeDecorator(std::shared_ptr<IManyParamInterface> impl);

    /** Forwards call to ManyParamInterface implementation. */
    int func1(int param1) override;
    /** Forwards call to ManyParamInterface implementation. */
    std::future<int> func1Async(int param1) override;

    /** Forwards call to ManyParamInterface implementation. */
    int func2(int param1, int param2) override;
    /** Forwards call to ManyParamInterface implementation. */
    std::future<int> func2Async(int param1, int param2) override;

    /** Forwards call to ManyParamInterface implementation. */
    int func3(int param1, int param2, int param3) override;
    /** Forwards call to ManyParamInterface implementation. */
    std::future<int> func3Async(int param1, int param2, int param3) override;

    /** Forwards call to ManyParamInterface implementation. */
    int func4(int param1, int param2, int param3, int param4) override;
    /** Forwards call to ManyParamInterface implementation. */
    std::future<int> func4Async(int param1, int param2, int param3, int param4) override;

    /** Guards and forwards call to ManyParamInterface implementation. */
    void setProp1(int prop1) override;
    /** Guards and forwards call to ManyParamInterface implementation. */
    int getProp1() const override;

    /** Guards and forwards call to ManyParamInterface implementation. */
    void setProp2(int prop2) override;
    /** Guards and forwards call to ManyParamInterface implementation. */
    int getProp2() const override;

    /** Guards and forwards call to ManyParamInterface implementation. */
    void setProp3(int prop3) override;
    /** Guards and forwards call to ManyParamInterface implementation. */
    int getProp3() const override;

    /** Guards and forwards call to ManyParamInterface implementation. */
    void setProp4(int prop4) override;
    /** Guards and forwards call to ManyParamInterface implementation. */
    int getProp4() const override;

    /**
    * Access to a publisher, use it to subscribe for ManyParamInterface changes and signal emission.
    * @return The publisher for ManyParamInterface.
    */
    IManyParamInterfacePublisher& _getPublisher() const override;
private:
    /** The ManyParamInterface object which is guarded */
    std::shared_ptr<IManyParamInterface> m_impl;
    // Mutex for prop1 property
    mutable std::shared_timed_mutex m_prop1Mutex;
    // Mutex for prop2 property
    mutable std::shared_timed_mutex m_prop2Mutex;
    // Mutex for prop3 property
    mutable std::shared_timed_mutex m_prop3Mutex;
    // Mutex for prop4 property
    mutable std::shared_timed_mutex m_prop4Mutex;
};
} // namespace Testbed2
} // namespace Test
