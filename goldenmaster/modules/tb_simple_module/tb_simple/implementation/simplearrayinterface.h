
#pragma once
#include "tb_simple/generated/api/tb_simple.h"
#include "tb_simple/generated/api/common.h"
#include "tb_simple/generated/core/simplearrayinterface.data.h"
#include <memory>

namespace Test {
namespace TbSimple {

/**
* The SimpleArrayInterface implementation.
*/
class TEST_TB_SIMPLE_EXPORT SimpleArrayInterface : public ISimpleArrayInterface
{
public:
    explicit SimpleArrayInterface();
    ~SimpleArrayInterface();
public:
    void setPropBool(const std::list<bool>& propBool) override;
    const std::list<bool>& getPropBool() const override;
    
    void setPropInt(const std::list<int>& propInt) override;
    const std::list<int>& getPropInt() const override;
    
    void setPropFloat(const std::list<float>& propFloat) override;
    const std::list<float>& getPropFloat() const override;
    
    void setPropString(const std::list<std::string>& propString) override;
    const std::list<std::string>& getPropString() const override;
    
    std::list<bool> funcBool(const std::list<bool>& paramBool) override;
    std::future<std::list<bool>> funcBoolAsync(const std::list<bool>& paramBool) override;
        
    std::list<int> funcInt(const std::list<int>& paramInt) override;
    std::future<std::list<int>> funcIntAsync(const std::list<int>& paramInt) override;
        
    std::list<float> funcFloat(const std::list<float>& paramFloat) override;
    std::future<std::list<float>> funcFloatAsync(const std::list<float>& paramFloat) override;
        
    std::list<std::string> funcString(const std::list<std::string>& paramString) override;
    std::future<std::list<std::string>> funcStringAsync(const std::list<std::string>& paramString) override;
        
    /**
    * Access to a publisher, use it to subscribe for SimpleArrayInterface changes and signal emission.
    * @return The publisher for SimpleArrayInterface.
    */
    ISimpleArrayInterfacePublisher& _getPublisher() const override;
private:
    /** The publisher for the SimpleArrayInterface. */
    std::unique_ptr<ISimpleArrayInterfacePublisher> m_publisher;
    /** The helper structure to store all the properties for SimpleArrayInterface. */
    SimpleArrayInterfaceData m_data;
};
} // namespace TbSimple
} // namespace Test
