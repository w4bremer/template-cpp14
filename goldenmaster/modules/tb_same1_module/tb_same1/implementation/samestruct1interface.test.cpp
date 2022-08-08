/**
NO TITLE
Copyright (C) 2020 ApiGear UG

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#include <memory>
#include "catch2/catch.hpp"
#include "tb_same1/implementation/samestruct1interface.h"

using namespace Test::TbSame1;
TEST_CASE("Testing SameStruct1Interface", "[SameStruct1Interface]"){
    std::unique_ptr<ISameStruct1Interface> testSameStruct1Interface = std::make_unique<SameStruct1Interface>();
    // setup your test
    SECTION("Test operation func1") {
        // Do implement test here
        testSameStruct1Interface->func1(Struct1());
    }
    SECTION("Test property prop1") {
        // Do implement test here
        testSameStruct1Interface->setProp1(Struct1());
        REQUIRE( testSameStruct1Interface->prop1() == Struct1() );
    }
}
