
#pragma once
#include "tb_simple/generated/api/tb_simple.h"
#include "tb_simple/generated/api/common.h"
#include "tb_simple/generated/core/simpleinterface.data.h"
#include <memory>

namespace Test {
namespace TbSimple {

/**
* The SimpleInterface implementation.
*/
class TEST_TB_SIMPLE_EXPORT SimpleInterface : public ISimpleInterface
{
public:
    explicit SimpleInterface();
    ~SimpleInterface();
public:
    void setPropBool(bool propBool) override;
    bool getPropBool() const override;
    
    void setPropInt(int propInt) override;
    int getPropInt() const override;
    
    void setPropFloat(float propFloat) override;
    float getPropFloat() const override;
    
    void setPropString(const std::string& propString) override;
    const std::string& getPropString() const override;
    
    bool funcBool(bool paramBool) override;
    std::future<bool> funcBoolAsync(bool paramBool) override;
        
    int funcInt(int paramInt) override;
    std::future<int> funcIntAsync(int paramInt) override;
        
    float funcFloat(float paramFloat) override;
    std::future<float> funcFloatAsync(float paramFloat) override;
        
    std::string funcString(const std::string& paramString) override;
    std::future<std::string> funcStringAsync(const std::string& paramString) override;
        
    /**
    * Access to a publisher, use it to subscribe for SimpleInterface changes and signal emission.
    * @return The publisher for SimpleInterface.
    */
    ISimpleInterfacePublisher& _getPublisher() const override;
private:
    /** The publisher for the SimpleInterface. */
    std::unique_ptr<ISimpleInterfacePublisher> m_publisher;
    /** The helper structure to store all the properties for SimpleInterface. */
    SimpleInterfaceData m_data;
};
} // namespace TbSimple
} // namespace Test
