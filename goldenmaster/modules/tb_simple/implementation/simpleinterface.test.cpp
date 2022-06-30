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
#include "tb_simple_simpleinterface.h"

using namespace Test::TbSimple;
TEST_CASE("Testing SimpleInterface", "[SimpleInterface]"){
    std::unique_ptr<ISimpleInterface> testSimpleInterface = std::make_unique<SimpleInterface>();
    // setup your test
    SECTION("Test operation funcBool") {
        // Do implement test here
        testSimpleInterface->funcBool(false);
    }
    SECTION("Test operation funcInt") {
        // Do implement test here
        testSimpleInterface->funcInt(0);
    }
    SECTION("Test operation funcFloat") {
        // Do implement test here
        testSimpleInterface->funcFloat(0.0f);
    }
    SECTION("Test operation funcString") {
        // Do implement test here
        testSimpleInterface->funcString(std::string());
    }
    SECTION("Test property propBool") {
        // Do implement test here
        testSimpleInterface->setPropbool(false);
        REQUIRE( testSimpleInterface->propBool() == false );
    }
    SECTION("Test property propInt") {
        // Do implement test here
        testSimpleInterface->setPropint(0);
        REQUIRE( testSimpleInterface->propInt() == 0 );
    }
    SECTION("Test property propFloat") {
        // Do implement test here
        testSimpleInterface->setPropfloat(0.0f);
        REQUIRE( testSimpleInterface->propFloat() == Approx( 0.0f ) );
    }
    SECTION("Test property propString") {
        // Do implement test here
        testSimpleInterface->setPropstring(std::string());
        REQUIRE( testSimpleInterface->propString() == std::string() );
    }
}
