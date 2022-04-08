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
#include "org_objectapi_testbed_interface1.h"

using namespace Test::OrgObjectapiTestbed;
TEST_CASE("Testing Interface1", "[Interface1]"){
    std::unique_ptr<IInterface1> testInterface1 = std::make_unique<Interface1>();
    // setup your test
    SECTION("Test operation op1") {
        // Do implement test here
        testInterface1->op1();
    }
    SECTION("Test operation op2") {
        // Do implement test here
        testInterface1->op2(0);
    }
    SECTION("Test operation op3") {
        // Do implement test here
        testInterface1->op3();
    }
    SECTION("Test property prop1") {
        // Do implement test here
        testInterface1->setProp1(false);
        REQUIRE( testInterface1->prop1() == false );
    }
    SECTION("Test property prop2") {
        // Do implement test here
        testInterface1->setProp2(0);
        REQUIRE( testInterface1->prop2() == 0 );
    }
    SECTION("Test property prop3") {
        // Do implement test here
        testInterface1->setProp3(0.0f);
        REQUIRE( testInterface1->prop3() == Approx( 0.0f ) );
    }
    SECTION("Test property prop4") {
        // Do implement test here
        testInterface1->setProp4(std::string());
        REQUIRE( testInterface1->prop4() == std::string() );
    }
    SECTION("Test property prop5") {
        // Do implement test here
        testInterface1->setProp5(std::list<int>());
        REQUIRE( testInterface1->prop5() == std::list<int>() );
    }
    SECTION("Test property prop6") {
        // Do implement test here
        testInterface1->setProp6(Struct1());
        REQUIRE( testInterface1->prop6() == Struct1() );
    }
    SECTION("Test property prop7") {
        // Do implement test here
        testInterface1->setProp7(0);
        REQUIRE( testInterface1->prop7() == 0 );
    }
    SECTION("Test property prop10") {
        // Do implement test here
        testInterface1->setProp10(std::list<int>());
        REQUIRE( testInterface1->prop10() == std::list<int>() );
    }
    SECTION("Test property prop11") {
        // Do implement test here
        testInterface1->setProp11(std::list<Struct1>());
        REQUIRE( testInterface1->prop11() == std::list<Struct1>() );
    }
    SECTION("Test property prop12") {
        // Do implement test here
        testInterface1->setProp12(std::list<Enum1Enum>());
        REQUIRE( testInterface1->prop12() == std::list<Enum1Enum>() );
    }
    SECTION("Test property prop14") {
        // Do implement test here
        testInterface1->setProp14(std::list<Struct1>());
        REQUIRE( testInterface1->prop14() == std::list<Struct1>() );
    }
}
