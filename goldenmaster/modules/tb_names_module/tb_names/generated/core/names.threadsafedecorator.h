
#pragma once
#include "tb_names/generated/api/tb_names.h"
#include "tb_names/generated/api/common.h"
#include <memory>
#include <shared_mutex>

namespace Test {
namespace TbNames {

/** 
* @brief The NamesThreadSafeDecorator can be used to make property access thread safe.
*
* Each property is guarded with its own mutex.
* Multiple read/get operations can occur at the same time but only one write/set operation at a time.
*
* Operations are not guarded by default since the function logic can be too complex than to simply lock it.
* However, functions can be locked by just adding the same mechanism in the implementation file of
* the Names interface.
* @see Names
*
\code{.cpp}
using namespace Test::TbNames;

std::unique_ptr<INames> testNames = std::make_unique<NamesThreadSafeDecorator>(std::make_shared<Names>());

// Thread safe access
auto switch = testNames->getSwitch();
testNames->setSwitch(false);
\endcode
*/
class TEST_TB_NAMES_EXPORT NamesThreadSafeDecorator : public INames
{
public:
    /** 
    * ctor
    * @param impl The Names object to make thread safe.
    */
    explicit NamesThreadSafeDecorator(std::shared_ptr<INames> impl);

    /** Guards and forwards call to Names implementation. */
    void setSwitch(bool Switch) override;
    /** Guards and forwards call to Names implementation. */
    bool getSwitch() const override;

    /**
    * Access to a publisher, use it to subscribe for Names changes and signal emission.
    * This call is thread safe.
    * @return The publisher for Names.
    */
    INamesPublisher& _getPublisher() const override;
private:
    /** The Names object which is guarded */
    std::shared_ptr<INames> m_impl;
    // Mutex for switch property
    mutable std::shared_timed_mutex m_switchMutex;
};
} // namespace TbNames
} // namespace Test
