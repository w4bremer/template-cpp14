
#pragma once
#include "testbed1/generated/api/testbed1.h"
#include "testbed1/generated/api/common.h"
#include <memory>
#include <shared_mutex>

namespace Test {
namespace Testbed1 {

/** 
* @brief The StructInterfaceThreadSafeDecorator can be used to make property access thread safe.
*
* Each property is guarded with its own mutex.
* Multiple read/get operations can occur at the same time but only one write/set operation at a time.
*
* Operations a are not guarded by default since the function logic can be too complex than to simply lock it.
* However, functions can be locked by just adding the same mechanism in the implementation file of
* the StructInterface interface.
* @see StructInterface
*
\code{.cpp}
int main(){
    std::unique_ptr<Testbed1::IStructInterface> testTestbed1StructInterface = std::make_unique<Testbed1::StructInterface>();
    std::unique_ptr<Testbed1::IStructInterface> testTestbed1StructInterfaceThreadSafeDecorator = std::make_unique<Test::Testbed1::StructInterfaceThreadSafeDecorator>(std::move(testTestbed1StructInterface));

    // Thread safe access
    testTestbed1StructInterfaceThreadSafeDecorator->setPropBool(testTestbed1StructInterfaceThreadSafeDecorator->getPropBool());
    testTestbed1StructInterfaceThreadSafeDecorator->setPropInt(testTestbed1StructInterfaceThreadSafeDecorator->getPropInt());
    testTestbed1StructInterfaceThreadSafeDecorator->setPropFloat(testTestbed1StructInterfaceThreadSafeDecorator->getPropFloat());
    testTestbed1StructInterfaceThreadSafeDecorator->setPropString(testTestbed1StructInterfaceThreadSafeDecorator->getPropString());
    return 0;
}
\endcode
*/
class TEST_TESTBED1_EXPORT StructInterfaceThreadSafeDecorator : public IStructInterface
{
public:
    /** 
    * ctor
    * @param impl The StructInterface object to make thread safe.
    */
    explicit StructInterfaceThreadSafeDecorator(std::shared_ptr<IStructInterface> impl);

    /** Forwards call to StructInterface implementation. */
    StructBool funcBool(const StructBool& paramBool) override;
    /** Forwards call to StructInterface implementation. */
    std::future<StructBool> funcBoolAsync(const StructBool& paramBool) override;

    /** Forwards call to StructInterface implementation. */
    StructBool funcInt(const StructInt& paramInt) override;
    /** Forwards call to StructInterface implementation. */
    std::future<StructBool> funcIntAsync(const StructInt& paramInt) override;

    /** Forwards call to StructInterface implementation. */
    StructFloat funcFloat(const StructFloat& paramFloat) override;
    /** Forwards call to StructInterface implementation. */
    std::future<StructFloat> funcFloatAsync(const StructFloat& paramFloat) override;

    /** Forwards call to StructInterface implementation. */
    StructString funcString(const StructString& paramString) override;
    /** Forwards call to StructInterface implementation. */
    std::future<StructString> funcStringAsync(const StructString& paramString) override;

    /** Guards and forwards call to StructInterface implementation. */
    void setPropBool(const StructBool& propBool) override;
    /** Guards and forwards call to StructInterface implementation. */
    const StructBool& getPropBool() const override;

    /** Guards and forwards call to StructInterface implementation. */
    void setPropInt(const StructInt& propInt) override;
    /** Guards and forwards call to StructInterface implementation. */
    const StructInt& getPropInt() const override;

    /** Guards and forwards call to StructInterface implementation. */
    void setPropFloat(const StructFloat& propFloat) override;
    /** Guards and forwards call to StructInterface implementation. */
    const StructFloat& getPropFloat() const override;

    /** Guards and forwards call to StructInterface implementation. */
    void setPropString(const StructString& propString) override;
    /** Guards and forwards call to StructInterface implementation. */
    const StructString& getPropString() const override;

    /**
    * Access to a publisher, use it to subscribe for StructInterface changes and signal emission.
    * @return The publisher for StructInterface.
    */
    IStructInterfacePublisher& _getPublisher() const override;
private:
    /** The StructInterface object which is guarded */
    std::shared_ptr<IStructInterface> m_impl;
    // Mutex for propBool property
    mutable std::shared_timed_mutex m_propBoolMutex;
    // Mutex for propInt property
    mutable std::shared_timed_mutex m_propIntMutex;
    // Mutex for propFloat property
    mutable std::shared_timed_mutex m_propFloatMutex;
    // Mutex for propString property
    mutable std::shared_timed_mutex m_propStringMutex;
};
} // namespace Testbed1
} // namespace Test
