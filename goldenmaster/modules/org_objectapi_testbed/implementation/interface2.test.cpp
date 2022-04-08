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
#include "org_objectapi_testbed_interface2.h"

using namespace Test::OrgObjectapiTestbed;
TEST_CASE("Testing Interface2", "[Interface2]"){
    std::unique_ptr<IInterface2> testInterface2 = std::make_unique<Interface2>();
    // setup your test
    SECTION("Test property prop200") {
        // Do implement test here
        testInterface2->setProp200(0);
        REQUIRE( testInterface2->prop200() == 0 );
    }
    SECTION("Test property prop201") {
        // Do implement test here
        testInterface2->setProp201(0);
        REQUIRE( testInterface2->prop201() == 0 );
    }
    SECTION("Test property prop202") {
        // Do implement test here
        testInterface2->setProp202(0);
        REQUIRE( testInterface2->prop202() == 0 );
    }
    SECTION("Test property prop203") {
        // Do implement test here
        testInterface2->setProp203(0.0f);
        REQUIRE( testInterface2->prop203() == Approx( 0.0f ) );
    }
    SECTION("Test property prop204") {
        // Do implement test here
        testInterface2->setProp204(0.0f);
        REQUIRE( testInterface2->prop204() == Approx( 0.0f ) );
    }
    SECTION("Test property prop205") {
        // Do implement test here
        testInterface2->setProp205(std::string());
        REQUIRE( testInterface2->prop205() == std::string() );
    }
}
