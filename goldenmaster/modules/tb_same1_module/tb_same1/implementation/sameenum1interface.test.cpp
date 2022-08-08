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
#include "tb_same1/implementation/sameenum1interface.h"

using namespace Test::TbSame1;
TEST_CASE("Testing SameEnum1Interface", "[SameEnum1Interface]"){
    std::unique_ptr<ISameEnum1Interface> testSameEnum1Interface = std::make_unique<SameEnum1Interface>();
    // setup your test
    SECTION("Test operation func1") {
        // Do implement test here
        testSameEnum1Interface->func1(Enum1Enum::value1);
    }
    SECTION("Test property prop1") {
        // Do implement test here
        testSameEnum1Interface->setProp1(Enum1Enum::value1);
        REQUIRE( testSameEnum1Interface->prop1() == Enum1Enum::value1 );
    }
}
