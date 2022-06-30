#pragma once

#ifndef JSON_USE_IMPLICIT_CONVERSIONS
#define JSON_USE_IMPLICIT_CONVERSIONS 0
#endif
#include <nlohmann/json.hpp>
#include "tb_same2_datastructs.api.h"
#include "generated/api/tb_same2_common.h"

namespace Test {
namespace TbSame2 {
void TEST_TB_SAME2_EXPORT from_json(const nlohmann::json& j, Struct1& p);
void TEST_TB_SAME2_EXPORT to_json(nlohmann::json& j, const Struct1& p);
void TEST_TB_SAME2_EXPORT from_json(const nlohmann::json& j, Struct2& p);
void TEST_TB_SAME2_EXPORT to_json(nlohmann::json& j, const Struct2& p);
} // namespace TbSame2
} // namespace Test
