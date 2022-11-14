
#pragma once
#include "tb_simple/generated/api/tb_simple.h"
#include "tb_simple/generated/api/common.h"
#include <memory>
#include <shared_mutex>

namespace Test {
namespace TbSimple {

/** 
* @brief The SimpleArrayInterfaceThreadSafeDecorator can be used to make property access thread safe.
*
* Each property is guarded with its own mutex.
* Multiple read/get operations can occur at the same time but only one write/set operation at a time.
*
* Operations are not guarded by default since the function logic can be too complex than to simply lock it.
* However, functions can be locked by just adding the same mechanism in the implementation file of
* the SimpleArrayInterface interface.
* @see SimpleArrayInterface
*
\code{.cpp}
using namespace Test::TbSimple;

std::unique_ptr<ISimpleArrayInterface> testSimpleArrayInterface = std::make_unique<SimpleArrayInterfaceThreadSafeDecorator>(std::make_shared<SimpleArrayInterface>());

// Thread safe access
auto propBool = testSimpleArrayInterface->getPropBool();
testSimpleArrayInterface->setPropBool(std::list<bool>());
auto propInt = testSimpleArrayInterface->getPropInt();
testSimpleArrayInterface->setPropInt(std::list<int>());
auto propFloat = testSimpleArrayInterface->getPropFloat();
testSimpleArrayInterface->setPropFloat(std::list<float>());
auto propString = testSimpleArrayInterface->getPropString();
testSimpleArrayInterface->setPropString(std::list<std::string>());
\endcode
*/
class TEST_TB_SIMPLE_EXPORT SimpleArrayInterfaceThreadSafeDecorator : public ISimpleArrayInterface
{
public:
    /** 
    * ctor
    * @param impl The SimpleArrayInterface object to make thread safe.
    */
    explicit SimpleArrayInterfaceThreadSafeDecorator(std::shared_ptr<ISimpleArrayInterface> impl);

    /** 
    * Forwards call to SimpleArrayInterface implementation.
    * @warning This forward call is not made thread safe by this class.
    */
    std::list<bool> funcBool(const std::list<bool>& paramBool) override;
    /** 
    * Forwards call to SimpleArrayInterface implementation.
    * @warning This forward call is not made thread safe by this class.
    */
    std::future<std::list<bool>> funcBoolAsync(const std::list<bool>& paramBool) override;

    /** 
    * Forwards call to SimpleArrayInterface implementation.
    * @warning This forward call is not made thread safe by this class.
    */
    std::list<int> funcInt(const std::list<int>& paramInt) override;
    /** 
    * Forwards call to SimpleArrayInterface implementation.
    * @warning This forward call is not made thread safe by this class.
    */
    std::future<std::list<int>> funcIntAsync(const std::list<int>& paramInt) override;

    /** 
    * Forwards call to SimpleArrayInterface implementation.
    * @warning This forward call is not made thread safe by this class.
    */
    std::list<float> funcFloat(const std::list<float>& paramFloat) override;
    /** 
    * Forwards call to SimpleArrayInterface implementation.
    * @warning This forward call is not made thread safe by this class.
    */
    std::future<std::list<float>> funcFloatAsync(const std::list<float>& paramFloat) override;

    /** 
    * Forwards call to SimpleArrayInterface implementation.
    * @warning This forward call is not made thread safe by this class.
    */
    std::list<std::string> funcString(const std::list<std::string>& paramString) override;
    /** 
    * Forwards call to SimpleArrayInterface implementation.
    * @warning This forward call is not made thread safe by this class.
    */
    std::future<std::list<std::string>> funcStringAsync(const std::list<std::string>& paramString) override;

    /** Guards and forwards call to SimpleArrayInterface implementation. */
    void setPropBool(const std::list<bool>& propBool) override;
    /** Guards and forwards call to SimpleArrayInterface implementation. */
    const std::list<bool>& getPropBool() const override;

    /** Guards and forwards call to SimpleArrayInterface implementation. */
    void setPropInt(const std::list<int>& propInt) override;
    /** Guards and forwards call to SimpleArrayInterface implementation. */
    const std::list<int>& getPropInt() const override;

    /** Guards and forwards call to SimpleArrayInterface implementation. */
    void setPropFloat(const std::list<float>& propFloat) override;
    /** Guards and forwards call to SimpleArrayInterface implementation. */
    const std::list<float>& getPropFloat() const override;

    /** Guards and forwards call to SimpleArrayInterface implementation. */
    void setPropString(const std::list<std::string>& propString) override;
    /** Guards and forwards call to SimpleArrayInterface implementation. */
    const std::list<std::string>& getPropString() const override;

    /**
    * Access to a publisher, use it to subscribe for SimpleArrayInterface changes and signal emission.
    * This call is thread safe.
    * @return The publisher for SimpleArrayInterface.
    */
    ISimpleArrayInterfacePublisher& _getPublisher() const override;
private:
    /** The SimpleArrayInterface object which is guarded */
    std::shared_ptr<ISimpleArrayInterface> m_impl;
    // Mutex for propBool property
    mutable std::shared_timed_mutex m_propBoolMutex;
    // Mutex for propInt property
    mutable std::shared_timed_mutex m_propIntMutex;
    // Mutex for propFloat property
    mutable std::shared_timed_mutex m_propFloatMutex;
    // Mutex for propString property
    mutable std::shared_timed_mutex m_propStringMutex;
};
} // namespace TbSimple
} // namespace Test
