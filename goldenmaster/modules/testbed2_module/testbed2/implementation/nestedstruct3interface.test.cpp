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
#include "testbed2/implementation/nestedstruct3interface.h"

using namespace Test::Testbed2;
TEST_CASE("Testing NestedStruct3Interface", "[NestedStruct3Interface]"){
    std::unique_ptr<INestedStruct3Interface> testNestedStruct3Interface = std::make_unique<NestedStruct3Interface>();
    // setup your test
    SECTION("Test operation func1") {
        // Do implement test here
        testNestedStruct3Interface->func1(NestedStruct1());
    }
    SECTION("Test operation func2") {
        // Do implement test here
        testNestedStruct3Interface->func2(NestedStruct1(),NestedStruct2());
    }
    SECTION("Test operation func3") {
        // Do implement test here
        testNestedStruct3Interface->func3(NestedStruct1(),NestedStruct2(),NestedStruct3());
    }
    SECTION("Test property prop1") {
        // Do implement test here
        testNestedStruct3Interface->setProp1(NestedStruct1());
        REQUIRE( testNestedStruct3Interface->prop1() == NestedStruct1() );
    }
    SECTION("Test property prop2") {
        // Do implement test here
        testNestedStruct3Interface->setProp2(NestedStruct2());
        REQUIRE( testNestedStruct3Interface->prop2() == NestedStruct2() );
    }
    SECTION("Test property prop3") {
        // Do implement test here
        testNestedStruct3Interface->setProp3(NestedStruct3());
        REQUIRE( testNestedStruct3Interface->prop3() == NestedStruct3() );
    }
}
