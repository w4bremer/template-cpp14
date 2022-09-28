
#pragma once
#include "tb_same2/generated/api/tb_same2.h"
#include "tb_same2/generated/api/common.h"
#include <memory>
#include <shared_mutex>

namespace Test {
namespace TbSame2 {

/** 
* @brief The SameEnum2InterfaceThreadSafeDecorator can be used to make property access thread safe.
*
* Each property is guarded with its own mutex.
* Multiple read/get operations can occur at the same time but only one write/set operation at a time.
*
* Operations a are not guarded by default since the function logic can be too complex than to simply lock it.
* However, functions can be locked by just adding the same mechanism in the implementation file of
* the SameEnum2Interface interface.
* @see SameEnum2Interface
*
\code{.cpp}
int main(){
    std::unique_ptr<TbSame2::ISameEnum2Interface> testTbSame2SameEnum2Interface = std::make_unique<TbSame2::SameEnum2Interface>();
    std::unique_ptr<TbSame2::ISameEnum2Interface> testTbSame2SameEnum2InterfaceThreadSafeDecorator = std::make_unique<Test::TbSame2::SameEnum2InterfaceThreadSafeDecorator>(std::move(testTbSame2SameEnum2Interface));

    // Thread safe access
    testTbSame2SameEnum2InterfaceThreadSafeDecorator->setProp1(testTbSame2SameEnum2InterfaceThreadSafeDecorator->getProp1());
    testTbSame2SameEnum2InterfaceThreadSafeDecorator->setProp2(testTbSame2SameEnum2InterfaceThreadSafeDecorator->getProp2());
    return 0;
}
\endcode
*/
class TEST_TB_SAME2_EXPORT SameEnum2InterfaceThreadSafeDecorator : public ISameEnum2Interface
{
public:
    /** 
    * ctor
    * @param impl The SameEnum2Interface object to make thread safe.
    */
    explicit SameEnum2InterfaceThreadSafeDecorator(std::shared_ptr<ISameEnum2Interface> impl);

    /** Forwards call to SameEnum2Interface implementation. */
    Enum1Enum func1(Enum1Enum param1) override;
    /** Forwards call to SameEnum2Interface implementation. */
    std::future<Enum1Enum> func1Async(Enum1Enum param1) override;

    /** Forwards call to SameEnum2Interface implementation. */
    Enum1Enum func2(Enum1Enum param1, Enum2Enum param2) override;
    /** Forwards call to SameEnum2Interface implementation. */
    std::future<Enum1Enum> func2Async(Enum1Enum param1, Enum2Enum param2) override;

    /** Guards and forwards call to SameEnum2Interface implementation. */
    void setProp1(Enum1Enum prop1) override;
    /** Guards and forwards call to SameEnum2Interface implementation. */
    Enum1Enum getProp1() const override;

    /** Guards and forwards call to SameEnum2Interface implementation. */
    void setProp2(Enum2Enum prop2) override;
    /** Guards and forwards call to SameEnum2Interface implementation. */
    Enum2Enum getProp2() const override;

    /**
    * Access to a publisher, use it to subscribe for SameEnum2Interface changes and signal emission.
    * @return The publisher for SameEnum2Interface.
    */
    ISameEnum2InterfacePublisher& _getPublisher() const override;
private:
    /** The SameEnum2Interface object which is guarded */
    std::shared_ptr<ISameEnum2Interface> m_impl;
    // Mutex for prop1 property
    mutable std::shared_timed_mutex m_prop1Mutex;
    // Mutex for prop2 property
    mutable std::shared_timed_mutex m_prop2Mutex;
};
} // namespace TbSame2
} // namespace Test
