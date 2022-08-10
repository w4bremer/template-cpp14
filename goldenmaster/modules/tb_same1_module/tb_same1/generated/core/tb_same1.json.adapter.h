#pragma once

#ifndef JSON_USE_IMPLICIT_CONVERSIONS
#define JSON_USE_IMPLICIT_CONVERSIONS 0
#endif
#include <nlohmann/json.hpp>
#include "tb_same1/generated/api/datastructs.api.h"
#include "tb_same1/generated/api/common.h"

namespace Test {
namespace TbSame1 {
/** Function that converts json formated data into Struct1.
* The functions signature must follow the nlohmann from_jason function rules.
* It is automatically called in usage j.get<class>();
* @param j an input json formated data
* @param p Struct1 that will be filled with data from j.
*  In case data is malformed or not convertable to Struct1 the function will throw.
*/
void TEST_TB_SAME1_EXPORT from_json(const nlohmann::json& j, Struct1& p);
/** Function that converts json formated data into Struct1
* The functions signature must follow the nlohmann to_jason function rules.
* It is automatically called in usage j = p;
* @param j a json formated data that will be filled with data from p
* @param p an input Struct1/'}
' from which json data will be filled
*/
void TEST_TB_SAME1_EXPORT to_json(nlohmann::json& j, const Struct1& p);
/** Function that converts json formated data into Struct2.
* The functions signature must follow the nlohmann from_jason function rules.
* It is automatically called in usage j.get<class>();
* @param j an input json formated data
* @param p Struct2 that will be filled with data from j.
*  In case data is malformed or not convertable to Struct2 the function will throw.
*/
void TEST_TB_SAME1_EXPORT from_json(const nlohmann::json& j, Struct2& p);
/** Function that converts json formated data into Struct2
* The functions signature must follow the nlohmann to_jason function rules.
* It is automatically called in usage j = p;
* @param j a json formated data that will be filled with data from p
* @param p an input Struct2/'}
' from which json data will be filled
*/
void TEST_TB_SAME1_EXPORT to_json(nlohmann::json& j, const Struct2& p);
} // namespace TbSame1
} // namespace Test
