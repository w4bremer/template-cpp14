#pragma once

#ifndef JSON_USE_IMPLICIT_CONVERSIONS
#define JSON_USE_IMPLICIT_CONVERSIONS 0
#endif
#include <nlohmann/json.hpp>
#include "tb_same1/generated/api/datastructs.api.h"
#include "tb_same1/generated/api/common.h"

namespace Test {
namespace TbSame1 {
void TEST_TB_SAME1_EXPORT from_json(const nlohmann::json& j, Struct1& p);
void TEST_TB_SAME1_EXPORT to_json(nlohmann::json& j, const Struct1& p);
void TEST_TB_SAME1_EXPORT from_json(const nlohmann::json& j, Struct2& p);
void TEST_TB_SAME1_EXPORT to_json(nlohmann::json& j, const Struct2& p);
} // namespace TbSame1
} // namespace Test
