#pragma once

#ifndef JSON_USE_IMPLICIT_CONVERSIONS
#define JSON_USE_IMPLICIT_CONVERSIONS 0
#endif
#include <nlohmann/json.hpp>
#include "testbed1_datastructs.api.h"
#include "generated/api/testbed1_common.h"

namespace Test {
namespace Testbed1 {
void TEST_TESTBED1_EXPORT from_json(const nlohmann::json& j, StructBool& p);
void TEST_TESTBED1_EXPORT to_json(nlohmann::json& j, const StructBool& p);
void TEST_TESTBED1_EXPORT from_json(const nlohmann::json& j, StructInt& p);
void TEST_TESTBED1_EXPORT to_json(nlohmann::json& j, const StructInt& p);
void TEST_TESTBED1_EXPORT from_json(const nlohmann::json& j, StructFloat& p);
void TEST_TESTBED1_EXPORT to_json(nlohmann::json& j, const StructFloat& p);
void TEST_TESTBED1_EXPORT from_json(const nlohmann::json& j, StructString& p);
void TEST_TESTBED1_EXPORT to_json(nlohmann::json& j, const StructString& p);
} // namespace Testbed1
} // namespace Test
