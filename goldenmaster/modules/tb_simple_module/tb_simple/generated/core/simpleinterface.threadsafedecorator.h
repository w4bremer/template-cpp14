
#pragma once
#include "tb_simple/generated/api/tb_simple.h"
#include "tb_simple/generated/api/common.h"
#include <memory>
#include <shared_mutex>

namespace Test {
namespace TbSimple {

/** 
* @brief The SimpleInterfaceThreadSafeDecorator can be used to make property access thread safe.
*
* Each property is guarded with its own mutex.
* Multiple read/get operations can occur at the same time but only one write/set operation at a time.
*
* Operations a are not guarded by default since the function logic can be too complex than to simply lock it.
* However, functions can be locked by just adding the same mechanism in the implementation file of
* the SimpleInterface interface.
* @see SimpleInterface
*
\code{.cpp}
int main(){
    std::unique_ptr<TbSimple::ISimpleInterface> testTbSimpleSimpleInterface = std::make_unique<TbSimple::SimpleInterface>();
    std::unique_ptr<TbSimple::ISimpleInterface> testTbSimpleSimpleInterfaceThreadSafeDecorator = std::make_unique<Test::TbSimple::SimpleInterfaceThreadSafeDecorator>(std::move(testTbSimpleSimpleInterface));

    // Thread safe access
    testTbSimpleSimpleInterfaceThreadSafeDecorator->setPropBool(testTbSimpleSimpleInterfaceThreadSafeDecorator->getPropBool());
    testTbSimpleSimpleInterfaceThreadSafeDecorator->setPropInt(testTbSimpleSimpleInterfaceThreadSafeDecorator->getPropInt());
    testTbSimpleSimpleInterfaceThreadSafeDecorator->setPropFloat(testTbSimpleSimpleInterfaceThreadSafeDecorator->getPropFloat());
    testTbSimpleSimpleInterfaceThreadSafeDecorator->setPropString(testTbSimpleSimpleInterfaceThreadSafeDecorator->getPropString());
    return 0;
}
\endcode
*/
class TEST_TB_SIMPLE_EXPORT SimpleInterfaceThreadSafeDecorator : public ISimpleInterface
{
public:
    /** 
    * ctor
    * @param impl The SimpleInterface object to make thread safe.
    */
    explicit SimpleInterfaceThreadSafeDecorator(std::shared_ptr<ISimpleInterface> impl);

    /** Forwards call to SimpleInterface implementation. */
    bool funcBool(bool paramBool) override;
    /** Forwards call to SimpleInterface implementation. */
    std::future<bool> funcBoolAsync(bool paramBool) override;

    /** Forwards call to SimpleInterface implementation. */
    int funcInt(int paramInt) override;
    /** Forwards call to SimpleInterface implementation. */
    std::future<int> funcIntAsync(int paramInt) override;

    /** Forwards call to SimpleInterface implementation. */
    float funcFloat(float paramFloat) override;
    /** Forwards call to SimpleInterface implementation. */
    std::future<float> funcFloatAsync(float paramFloat) override;

    /** Forwards call to SimpleInterface implementation. */
    std::string funcString(const std::string& paramString) override;
    /** Forwards call to SimpleInterface implementation. */
    std::future<std::string> funcStringAsync(const std::string& paramString) override;

    /** Guards and forwards call to SimpleInterface implementation. */
    void setPropBool(bool propBool) override;
    /** Guards and forwards call to SimpleInterface implementation. */
    bool getPropBool() const override;

    /** Guards and forwards call to SimpleInterface implementation. */
    void setPropInt(int propInt) override;
    /** Guards and forwards call to SimpleInterface implementation. */
    int getPropInt() const override;

    /** Guards and forwards call to SimpleInterface implementation. */
    void setPropFloat(float propFloat) override;
    /** Guards and forwards call to SimpleInterface implementation. */
    float getPropFloat() const override;

    /** Guards and forwards call to SimpleInterface implementation. */
    void setPropString(const std::string& propString) override;
    /** Guards and forwards call to SimpleInterface implementation. */
    const std::string& getPropString() const override;

    /**
    * Access to a publisher, use it to subscribe for SimpleInterface changes and signal emission.
    * @return The publisher for SimpleInterface.
    */
    ISimpleInterfacePublisher& _getPublisher() const override;
private:
    /** The SimpleInterface object which is guarded */
    std::shared_ptr<ISimpleInterface> m_impl;
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
