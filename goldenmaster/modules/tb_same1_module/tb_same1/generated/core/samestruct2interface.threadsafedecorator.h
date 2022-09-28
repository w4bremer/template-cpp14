
#pragma once
#include "tb_same1/generated/api/tb_same1.h"
#include "tb_same1/generated/api/common.h"
#include <memory>
#include <shared_mutex>

namespace Test {
namespace TbSame1 {

/** 
* @brief The SameStruct2InterfaceThreadSafeDecorator can be used to make property access thread safe.
*
* Each property is guarded with its own mutex.
* Multiple read/get operations can occur at the same time but only one write/set operation at a time.
*
* Operations a are not guarded by default since the function logic can be too complex than to simply lock it.
* However, functions can be locked by just adding the same mechanism in the implementation file of
* the SameStruct2Interface interface.
* @see SameStruct2Interface
*
\code{.cpp}
int main(){
    std::unique_ptr<TbSame1::ISameStruct2Interface> testTbSame1SameStruct2Interface = std::make_unique<TbSame1::SameStruct2Interface>();
    std::unique_ptr<TbSame1::ISameStruct2Interface> testTbSame1SameStruct2InterfaceThreadSafeDecorator = std::make_unique<Test::TbSame1::SameStruct2InterfaceThreadSafeDecorator>(std::move(testTbSame1SameStruct2Interface));

    // Thread safe access
    testTbSame1SameStruct2InterfaceThreadSafeDecorator->setProp1(testTbSame1SameStruct2InterfaceThreadSafeDecorator->getProp1());
    testTbSame1SameStruct2InterfaceThreadSafeDecorator->setProp2(testTbSame1SameStruct2InterfaceThreadSafeDecorator->getProp2());
    return 0;
}
\endcode
*/
class TEST_TB_SAME1_EXPORT SameStruct2InterfaceThreadSafeDecorator : public ISameStruct2Interface
{
public:
    /** 
    * ctor
    * @param impl The SameStruct2Interface object to make thread safe.
    */
    explicit SameStruct2InterfaceThreadSafeDecorator(std::shared_ptr<ISameStruct2Interface> impl);

    /** Forwards call to SameStruct2Interface implementation. */
    Struct1 func1(const Struct1& param1) override;
    /** Forwards call to SameStruct2Interface implementation. */
    std::future<Struct1> func1Async(const Struct1& param1) override;

    /** Forwards call to SameStruct2Interface implementation. */
    Struct1 func2(const Struct1& param1, const Struct2& param2) override;
    /** Forwards call to SameStruct2Interface implementation. */
    std::future<Struct1> func2Async(const Struct1& param1, const Struct2& param2) override;

    /** Guards and forwards call to SameStruct2Interface implementation. */
    void setProp1(const Struct2& prop1) override;
    /** Guards and forwards call to SameStruct2Interface implementation. */
    const Struct2& getProp1() const override;

    /** Guards and forwards call to SameStruct2Interface implementation. */
    void setProp2(const Struct2& prop2) override;
    /** Guards and forwards call to SameStruct2Interface implementation. */
    const Struct2& getProp2() const override;

    /**
    * Access to a publisher, use it to subscribe for SameStruct2Interface changes and signal emission.
    * @return The publisher for SameStruct2Interface.
    */
    ISameStruct2InterfacePublisher& _getPublisher() const override;
private:
    /** The SameStruct2Interface object which is guarded */
    std::shared_ptr<ISameStruct2Interface> m_impl;
    // Mutex for prop1 property
    mutable std::shared_timed_mutex m_prop1Mutex;
    // Mutex for prop2 property
    mutable std::shared_timed_mutex m_prop2Mutex;
};
} // namespace TbSame1
} // namespace Test
