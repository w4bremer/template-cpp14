#pragma once

#ifndef JSON_USE_IMPLICIT_CONVERSIONS
#define JSON_USE_IMPLICIT_CONVERSIONS 0
#endif
#include <nlohmann/json.hpp>
#include "testbed2_datastructs.api.h"
#include "generated/api/testbed2_common.h"

namespace Test {
namespace Testbed2 {
void TEST_TESTBED2_EXPORT from_json(const nlohmann::json& j, Struct1& p);
void TEST_TESTBED2_EXPORT to_json(nlohmann::json& j, const Struct1& p);
void TEST_TESTBED2_EXPORT from_json(const nlohmann::json& j, Struct2& p);
void TEST_TESTBED2_EXPORT to_json(nlohmann::json& j, const Struct2& p);
void TEST_TESTBED2_EXPORT from_json(const nlohmann::json& j, Struct3& p);
void TEST_TESTBED2_EXPORT to_json(nlohmann::json& j, const Struct3& p);
void TEST_TESTBED2_EXPORT from_json(const nlohmann::json& j, Struct4& p);
void TEST_TESTBED2_EXPORT to_json(nlohmann::json& j, const Struct4& p);
void TEST_TESTBED2_EXPORT from_json(const nlohmann::json& j, NestedStruct1& p);
void TEST_TESTBED2_EXPORT to_json(nlohmann::json& j, const NestedStruct1& p);
void TEST_TESTBED2_EXPORT from_json(const nlohmann::json& j, NestedStruct2& p);
void TEST_TESTBED2_EXPORT to_json(nlohmann::json& j, const NestedStruct2& p);
void TEST_TESTBED2_EXPORT from_json(const nlohmann::json& j, NestedStruct3& p);
void TEST_TESTBED2_EXPORT to_json(nlohmann::json& j, const NestedStruct3& p);
} // namespace Testbed2
} // namespace Test
