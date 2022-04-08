#include "org_objectapi_testbed.json.adapter.h"

namespace Test {
namespace OrgObjectapiTestbed {
void from_json(const nlohmann::json& j, Struct1& p) {
    p = Struct1(
        j.at("field1").get<bool>(),
        j.at("field2").get<int>(),
        j.at("field3").get<float>(),
        j.at("field4").get<std::string>()
    );
}
void to_json(nlohmann::json& j, const Struct1& p) {
    j = nlohmann::json{
        {"field1", p.field1},
        {"field2", p.field2},
        {"field3", p.field3},
        {"field4", p.field4}
        };
}
} // namespace OrgObjectapiTestbed
} // namespace Test
