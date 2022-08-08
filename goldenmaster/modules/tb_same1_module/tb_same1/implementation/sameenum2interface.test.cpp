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
#include "tb_same1/implementation/sameenum2interface.h"

using namespace Test::TbSame1;
TEST_CASE("Testing SameEnum2Interface", "[SameEnum2Interface]"){
    std::unique_ptr<ISameEnum2Interface> testSameEnum2Interface = std::make_unique<SameEnum2Interface>();
    // setup your test
    SECTION("Test operation func1") {
        // Do implement test here
        testSameEnum2Interface->func1(Enum1Enum::value1);
    }
    SECTION("Test operation func2") {
        // Do implement test here
        testSameEnum2Interface->func2(Enum1Enum::value1,Enum2Enum::value1);
    }
    SECTION("Test property prop1") {
        // Do implement test here
        testSameEnum2Interface->setProp1(Enum1Enum::value1);
        REQUIRE( testSameEnum2Interface->prop1() == Enum1Enum::value1 );
    }
    SECTION("Test property prop2") {
        // Do implement test here
        testSameEnum2Interface->setProp2(Enum2Enum::value1);
        REQUIRE( testSameEnum2Interface->prop2() == Enum2Enum::value1 );
    }
}
