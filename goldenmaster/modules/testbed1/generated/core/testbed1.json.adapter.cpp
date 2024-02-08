#include "testbed1/generated/core/testbed1.json.adapter.h"

namespace Test {
namespace Testbed1 {
void from_json(const nlohmann::json& j, StructBool& p) {
    p = StructBool(
        j.at("fieldBool").get<bool>()
    );
}
void to_json(nlohmann::json& j, const StructBool& p) {
    j = nlohmann::json{
        {"fieldBool", p.fieldBool}
        };
}
void from_json(const nlohmann::json& j, StructInt& p) {
    p = StructInt(
        j.at("fieldInt").get<int>()
    );
}
void to_json(nlohmann::json& j, const StructInt& p) {
    j = nlohmann::json{
        {"fieldInt", p.fieldInt}
        };
}
void from_json(const nlohmann::json& j, StructFloat& p) {
    p = StructFloat(
        j.at("fieldFloat").get<float>()
    );
}
void to_json(nlohmann::json& j, const StructFloat& p) {
    j = nlohmann::json{
        {"fieldFloat", p.fieldFloat}
        };
}
void from_json(const nlohmann::json& j, StructString& p) {
    p = StructString(
        j.at("fieldString").get<std::string>()
    );
}
void to_json(nlohmann::json& j, const StructString& p) {
    j = nlohmann::json{
        {"fieldString", p.fieldString}
        };
}
} // namespace Testbed1
} // namespace Test
