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
#include "tb_enum_enuminterface.h"

using namespace Test::TbEnum;
TEST_CASE("Testing EnumInterface", "[EnumInterface]"){
    std::unique_ptr<IEnumInterface> testEnumInterface = std::make_unique<EnumInterface>();
    // setup your test
    SECTION("Test operation func0") {
        // Do implement test here
        testEnumInterface->func0(Enum0Enum::value0);
    }
    SECTION("Test operation func1") {
        // Do implement test here
        testEnumInterface->func1(Enum1Enum::value1);
    }
    SECTION("Test operation func2") {
        // Do implement test here
        testEnumInterface->func2(Enum2Enum::value2);
    }
    SECTION("Test operation func3") {
        // Do implement test here
        testEnumInterface->func3(Enum3Enum::value3);
    }
    SECTION("Test property prop0") {
        // Do implement test here
        testEnumInterface->setProp0(Enum0Enum::value0);
        REQUIRE( testEnumInterface->prop0() == Enum0Enum::value0 );
    }
    SECTION("Test property prop1") {
        // Do implement test here
        testEnumInterface->setProp1(Enum1Enum::value1);
        REQUIRE( testEnumInterface->prop1() == Enum1Enum::value1 );
    }
    SECTION("Test property prop2") {
        // Do implement test here
        testEnumInterface->setProp2(Enum2Enum::value2);
        REQUIRE( testEnumInterface->prop2() == Enum2Enum::value2 );
    }
    SECTION("Test property prop3") {
        // Do implement test here
        testEnumInterface->setProp3(Enum3Enum::value3);
        REQUIRE( testEnumInterface->prop3() == Enum3Enum::value3 );
    }
}
