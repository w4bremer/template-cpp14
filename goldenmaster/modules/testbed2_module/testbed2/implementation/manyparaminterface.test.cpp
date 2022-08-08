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
#include "testbed2/implementation/manyparaminterface.h"

using namespace Test::Testbed2;
TEST_CASE("Testing ManyParamInterface", "[ManyParamInterface]"){
    std::unique_ptr<IManyParamInterface> testManyParamInterface = std::make_unique<ManyParamInterface>();
    // setup your test
    SECTION("Test operation func1") {
        // Do implement test here
        testManyParamInterface->func1(0);
    }
    SECTION("Test operation func2") {
        // Do implement test here
        testManyParamInterface->func2(0,0);
    }
    SECTION("Test operation func3") {
        // Do implement test here
        testManyParamInterface->func3(0,0,0);
    }
    SECTION("Test operation func4") {
        // Do implement test here
        testManyParamInterface->func4(0,0,0,0);
    }
    SECTION("Test property prop1") {
        // Do implement test here
        testManyParamInterface->setProp1(0);
        REQUIRE( testManyParamInterface->prop1() == 0 );
    }
    SECTION("Test property prop2") {
        // Do implement test here
        testManyParamInterface->setProp2(0);
        REQUIRE( testManyParamInterface->prop2() == 0 );
    }
    SECTION("Test property prop3") {
        // Do implement test here
        testManyParamInterface->setProp3(0);
        REQUIRE( testManyParamInterface->prop3() == 0 );
    }
    SECTION("Test property prop4") {
        // Do implement test here
        testManyParamInterface->setProp4(0);
        REQUIRE( testManyParamInterface->prop4() == 0 );
    }
}
