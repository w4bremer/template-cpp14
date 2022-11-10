
#pragma once
#include "tb_same1/generated/api/tb_same1.h"
#include "tb_same1/generated/api/common.h"
#include <memory>
#include <shared_mutex>

namespace Test {
namespace TbSame1 {

/** 
* @brief The SameEnum1InterfaceThreadSafeDecorator can be used to make property access thread safe.
*
* Each property is guarded with its own mutex.
* Multiple read/get operations can occur at the same time but only one write/set operation at a time.
*
* Operations a are not guarded by default since the function logic can be too complex than to simply lock it.
* However, functions can be locked by just adding the same mechanism in the implementation file of
* the SameEnum1Interface interface.
* @see SameEnum1Interface
*
\code{.cpp}
using namespace Test::TbSame1;

std::unique_ptr<ISameEnum1Interface> testSameEnum1Interface = std::make_unique<SameEnum1InterfaceThreadSafeDecorator>(std::make_shared<SameEnum1Interface>());

// Thread safe access
auto prop1 = testSameEnum1Interface->getProp1();
testSameEnum1Interface->setProp1(Enum1Enum::value1);
\endcode
*/
class TEST_TB_SAME1_EXPORT SameEnum1InterfaceThreadSafeDecorator : public ISameEnum1Interface
{
public:
    /** 
    * ctor
    * @param impl The SameEnum1Interface object to make thread safe.
    */
    explicit SameEnum1InterfaceThreadSafeDecorator(std::shared_ptr<ISameEnum1Interface> impl);

    /** Forwards call to SameEnum1Interface implementation. */
    Enum1Enum func1(Enum1Enum param1) override;
    /** Forwards call to SameEnum1Interface implementation. */
    std::future<Enum1Enum> func1Async(Enum1Enum param1) override;

    /** Guards and forwards call to SameEnum1Interface implementation. */
    void setProp1(Enum1Enum prop1) override;
    /** Guards and forwards call to SameEnum1Interface implementation. */
    Enum1Enum getProp1() const override;

    /**
    * Access to a publisher, use it to subscribe for SameEnum1Interface changes and signal emission.
    * @return The publisher for SameEnum1Interface.
    */
    ISameEnum1InterfacePublisher& _getPublisher() const override;
private:
    /** The SameEnum1Interface object which is guarded */
    std::shared_ptr<ISameEnum1Interface> m_impl;
    // Mutex for prop1 property
    mutable std::shared_timed_mutex m_prop1Mutex;
};
} // namespace TbSame1
} // namespace Test
