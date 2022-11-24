
#pragma once
#include "tb_simple/generated/api/tb_simple.h"
#include "tb_simple/generated/api/common.h"
#include "tb_simple/generated/core/nopropertiesinterface.data.h"
#include <memory>

namespace Test {
namespace TbSimple {

/**
* The NoPropertiesInterface implementation.
*/
class TEST_TB_SIMPLE_EXPORT NoPropertiesInterface : public INoPropertiesInterface
{
public:
    explicit NoPropertiesInterface();
    ~NoPropertiesInterface();
public:
    void funcVoid() override;
    std::future<void> funcVoidAsync() override;
        
    bool funcBool(bool paramBool) override;
    std::future<bool> funcBoolAsync(bool paramBool) override;
        
    /**
    * Access to a publisher, use it to subscribe for NoPropertiesInterface changes and signal emission.
    * @return The publisher for NoPropertiesInterface.
    */
    INoPropertiesInterfacePublisher& _getPublisher() const override;
private:
    /** The publisher for the NoPropertiesInterface. */
    std::unique_ptr<INoPropertiesInterfacePublisher> m_publisher;
    /** The helper structure to store all the properties for NoPropertiesInterface. */
    NoPropertiesInterfaceData m_data;
};
} // namespace TbSimple
} // namespace Test
