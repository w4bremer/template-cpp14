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
#include "testbed1/implementation/structarrayinterface.h"

using namespace Test::Testbed1;
TEST_CASE("Testing StructArrayInterface", "[StructArrayInterface]"){
    std::unique_ptr<IStructArrayInterface> testStructArrayInterface = std::make_unique<StructArrayInterface>();
    // setup your test
    SECTION("Test operation funcBool") {
        // Do implement test here
        testStructArrayInterface->funcBool(std::list<StructBool>());
    }
    SECTION("Test operation funcInt") {
        // Do implement test here
        testStructArrayInterface->funcInt(std::list<StructInt>());
    }
    SECTION("Test operation funcFloat") {
        // Do implement test here
        testStructArrayInterface->funcFloat(std::list<StructFloat>());
    }
    SECTION("Test operation funcString") {
        // Do implement test here
        testStructArrayInterface->funcString(std::list<StructString>());
    }
    SECTION("Test property propBool") {
        // Do implement test here
        testStructArrayInterface->setPropbool(std::list<StructBool>());
        REQUIRE( testStructArrayInterface->propBool() == std::list<StructBool>() );
    }
    SECTION("Test property propInt") {
        // Do implement test here
        testStructArrayInterface->setPropint(std::list<StructInt>());
        REQUIRE( testStructArrayInterface->propInt() == std::list<StructInt>() );
    }
    SECTION("Test property propFloat") {
        // Do implement test here
        testStructArrayInterface->setPropfloat(std::list<StructFloat>());
        REQUIRE( testStructArrayInterface->propFloat() == std::list<StructFloat>() );
    }
    SECTION("Test property propString") {
        // Do implement test here
        testStructArrayInterface->setPropstring(std::list<StructString>());
        REQUIRE( testStructArrayInterface->propString() == std::list<StructString>() );
    }
}
