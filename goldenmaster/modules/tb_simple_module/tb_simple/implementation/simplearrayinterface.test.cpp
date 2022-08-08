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
#include "tb_simple/implementation/simplearrayinterface.h"

using namespace Test::TbSimple;
TEST_CASE("Testing SimpleArrayInterface", "[SimpleArrayInterface]"){
    std::unique_ptr<ISimpleArrayInterface> testSimpleArrayInterface = std::make_unique<SimpleArrayInterface>();
    // setup your test
    SECTION("Test operation funcBool") {
        // Do implement test here
        testSimpleArrayInterface->funcBool(std::list<bool>());
    }
    SECTION("Test operation funcInt") {
        // Do implement test here
        testSimpleArrayInterface->funcInt(std::list<int>());
    }
    SECTION("Test operation funcFloat") {
        // Do implement test here
        testSimpleArrayInterface->funcFloat(std::list<float>());
    }
    SECTION("Test operation funcString") {
        // Do implement test here
        testSimpleArrayInterface->funcString(std::list<std::string>());
    }
    SECTION("Test property propBool") {
        // Do implement test here
        testSimpleArrayInterface->setPropbool(std::list<bool>());
        REQUIRE( testSimpleArrayInterface->propBool() == std::list<bool>() );
    }
    SECTION("Test property propInt") {
        // Do implement test here
        testSimpleArrayInterface->setPropint(std::list<int>());
        REQUIRE( testSimpleArrayInterface->propInt() == std::list<int>() );
    }
    SECTION("Test property propFloat") {
        // Do implement test here
        testSimpleArrayInterface->setPropfloat(std::list<float>());
        REQUIRE( testSimpleArrayInterface->propFloat() == std::list<float>() );
    }
    SECTION("Test property propString") {
        // Do implement test here
        testSimpleArrayInterface->setPropstring(std::list<std::string>());
        REQUIRE( testSimpleArrayInterface->propString() == std::list<std::string>() );
    }
}
