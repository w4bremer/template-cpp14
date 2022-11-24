
#pragma once
#include "tb_simple/generated/api/tb_simple.h"
#include "tb_simple/generated/api/common.h"
#include "tb_simple/generated/core/nooperationsinterface.data.h"
#include <memory>

namespace Test {
namespace TbSimple {

/**
* The NoOperationsInterface implementation.
*/
class TEST_TB_SIMPLE_EXPORT NoOperationsInterface : public INoOperationsInterface
{
public:
    explicit NoOperationsInterface();
    ~NoOperationsInterface();
public:
    void setPropBool(bool propBool) override;
    bool getPropBool() const override;
    
    void setPropInt(int propInt) override;
    int getPropInt() const override;
    
    /**
    * Access to a publisher, use it to subscribe for NoOperationsInterface changes and signal emission.
    * @return The publisher for NoOperationsInterface.
    */
    INoOperationsInterfacePublisher& _getPublisher() const override;
private:
    /** The publisher for the NoOperationsInterface. */
    std::unique_ptr<INoOperationsInterfacePublisher> m_publisher;
    /** The helper structure to store all the properties for NoOperationsInterface. */
    NoOperationsInterfaceData m_data;
};
} // namespace TbSimple
} // namespace Test
