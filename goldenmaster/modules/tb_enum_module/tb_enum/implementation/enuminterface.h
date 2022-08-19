
#pragma once
#include "tb_enum/generated/api/tb_enum.h"
#include "tb_enum/generated/api/common.h"
#include "tb_enum/generated/core/enuminterface.data.h"
#include <memory>

namespace Test {
namespace TbEnum {

/**
* The EnumInterface implementation.
*/
class TEST_TB_ENUM_EXPORT EnumInterface : public IEnumInterface
{
public:
    explicit EnumInterface();
    ~EnumInterface();
public:
    void setProp0(const Enum0Enum& prop0) override;
    const Enum0Enum& prop0() const override;
    
    void setProp1(const Enum1Enum& prop1) override;
    const Enum1Enum& prop1() const override;
    
    void setProp2(const Enum2Enum& prop2) override;
    const Enum2Enum& prop2() const override;
    
    void setProp3(const Enum3Enum& prop3) override;
    const Enum3Enum& prop3() const override;
    
    Enum0Enum func0(const Enum0Enum& param0) override;
    std::future<Enum0Enum> func0Async(const Enum0Enum& param0) override;
        
    Enum1Enum func1(const Enum1Enum& param1) override;
    std::future<Enum1Enum> func1Async(const Enum1Enum& param1) override;
        
    Enum2Enum func2(const Enum2Enum& param2) override;
    std::future<Enum2Enum> func2Async(const Enum2Enum& param2) override;
        
    Enum3Enum func3(const Enum3Enum& param3) override;
    std::future<Enum3Enum> func3Async(const Enum3Enum& param3) override;
        
    /**
    * Access to a publisher, use it to subscribe for EnumInterface changes and signal emission.
    * @return The publisher for EnumInterface.
    */
    IEnumInterfacePublisher& _getPublisher() const override;
private:
    /** The publisher for the EnumInterface. */
    std::unique_ptr<IEnumInterfacePublisher> m_publisher;
    /** The helper structure to store all the properties for EnumInterface. */
    EnumInterfaceData m_data;
};
} // namespace TbEnum
} // namespace Test
