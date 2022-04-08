#pragma once

#ifndef JSON_USE_IMPLICIT_CONVERSIONS
#define JSON_USE_IMPLICIT_CONVERSIONS 0
#endif
#include <nlohmann/json.hpp>
#include "org_objectapi_testbed_datastructs.api.h"
#include "generated/api/org_objectapi_testbed_common.h"

namespace Test {
namespace OrgObjectapiTestbed {
void TEST_ORG_OBJECTAPI_TESTBED_EXPORT from_json(const nlohmann::json& j, Struct1& p);
void TEST_ORG_OBJECTAPI_TESTBED_EXPORT to_json(nlohmann::json& j, const Struct1& p);
} // namespace OrgObjectapiTestbed
} // namespace Test
