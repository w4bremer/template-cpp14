
#pragma once
#include "tb_names/generated/api/tb_names.h"
#include "tb_names/generated/api/common.h"
#include "tb_names/generated/core/names.data.h"
#include <memory>

namespace Test {
namespace TbNames {

/**
* The Names implementation.
*/
class TEST_TB_NAMES_EXPORT Names : public INames
{
public:
    explicit Names();
    ~Names();
public:
    void setSwitch(bool Switch) override;
    bool getSwitch() const override;
    
    /**
    * Access to a publisher, use it to subscribe for Names changes and signal emission.
    * @return The publisher for Names.
    */
    INamesPublisher& _getPublisher() const override;
private:
    /** The publisher for the Names. */
    std::unique_ptr<INamesPublisher> m_publisher;
    /** The helper structure to store all the properties for Names. */
    NamesData m_data;
};
} // namespace TbNames
} // namespace Test
