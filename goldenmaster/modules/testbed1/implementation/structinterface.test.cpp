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
#include "testbed1_structinterface.h"

using namespace Test::Testbed1;
TEST_CASE("Testing StructInterface", "[StructInterface]"){
    std::unique_ptr<IStructInterface> testStructInterface = std::make_unique<StructInterface>();
    // setup your test
    SECTION("Test operation funcBool") {
        // Do implement test here
        testStructInterface->funcBool(StructBool());
    }
    SECTION("Test operation funcInt") {
        // Do implement test here
        testStructInterface->funcInt(StructInt());
    }
    SECTION("Test operation funcFloat") {
        // Do implement test here
        testStructInterface->funcFloat(StructFloat());
    }
    SECTION("Test operation funcString") {
        // Do implement test here
        testStructInterface->funcString(StructString());
    }
    SECTION("Test property propBool") {
        // Do implement test here
        testStructInterface->setPropbool(StructBool());
        REQUIRE( testStructInterface->propBool() == StructBool() );
    }
    SECTION("Test property propInt") {
        // Do implement test here
        testStructInterface->setPropint(StructInt());
        REQUIRE( testStructInterface->propInt() == StructInt() );
    }
    SECTION("Test property propFloat") {
        // Do implement test here
        testStructInterface->setPropfloat(StructFloat());
        REQUIRE( testStructInterface->propFloat() == StructFloat() );
    }
    SECTION("Test property propString") {
        // Do implement test here
        testStructInterface->setPropstring(StructString());
        REQUIRE( testStructInterface->propString() == StructString() );
    }
}
