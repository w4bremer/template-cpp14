
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
    
    void setPropInt32(int32_t propInt32) override;
    int32_t getPropInt32() const override;
    
    void setPropInt64(int64_t propInt64) override;
    int64_t getPropInt64() const override;
    
    void setPropFloat(float propFloat) override;
    float getPropFloat() const override;
    
    void setPropFloat32(float propFloat32) override;
    float getPropFloat32() const override;
    
    void setPropFloat64(double propFloat64) override;
    double getPropFloat64() const override;
    
    void setPropString(const std::string& propString) override;
    const std::string& getPropString() const override;
    
    bool funcBool(bool paramBool) override;
    std::future<bool> funcBoolAsync(bool paramBool) override;
        
    int funcInt(int paramInt) override;
    std::future<int> funcIntAsync(int paramInt) override;
        
    int32_t funcInt32(int32_t paramInt32) override;
    std::future<int32_t> funcInt32Async(int32_t paramInt32) override;
        
    int64_t funcInt64(int64_t paramInt64) override;
    std::future<int64_t> funcInt64Async(int64_t paramInt64) override;
        
    float funcFloat(float paramFloat) override;
    std::future<float> funcFloatAsync(float paramFloat) override;
        
    float funcFloat32(float paramFloat32) override;
    std::future<float> funcFloat32Async(float paramFloat32) override;
        
    double funcFloat64(double paramFloat) override;
    std::future<double> funcFloat64Async(double paramFloat) override;
        
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
