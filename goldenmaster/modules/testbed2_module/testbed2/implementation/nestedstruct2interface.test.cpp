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
#include "testbed2/implementation/nestedstruct2interface.h"

using namespace Test::Testbed2;
TEST_CASE("Testing NestedStruct2Interface", "[NestedStruct2Interface]"){
    std::unique_ptr<INestedStruct2Interface> testNestedStruct2Interface = std::make_unique<NestedStruct2Interface>();
    // setup your test
    SECTION("Test operation func1") {
        // Do implement test here
        testNestedStruct2Interface->func1(NestedStruct1());
    }
    SECTION("Test operation func2") {
        // Do implement test here
        testNestedStruct2Interface->func2(NestedStruct1(),NestedStruct2());
    }
    SECTION("Test property prop1") {
        // Do implement test here
        testNestedStruct2Interface->setProp1(NestedStruct1());
        REQUIRE( testNestedStruct2Interface->prop1() == NestedStruct1() );
    }
    SECTION("Test property prop2") {
        // Do implement test here
        testNestedStruct2Interface->setProp2(NestedStruct2());
        REQUIRE( testNestedStruct2Interface->prop2() == NestedStruct2() );
    }
}
