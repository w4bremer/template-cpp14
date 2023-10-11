#include <memory>
#include "catch2/catch.hpp"
#include "tb_names/implementation/names.h"

using namespace Test::TbNames;
TEST_CASE("Testing Names", "[Names]"){
    std::unique_ptr<INames> testNames = std::make_unique<Names>();
    // setup your test
    SECTION("Test property Switch") {
        // Do implement test here
        testNames->setSwitch(false);
        REQUIRE( testNames->getSwitch() == false );
    }
}
