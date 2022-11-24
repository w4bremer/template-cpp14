#include <memory>
#include "catch2/catch.hpp"
#include "tb_simple/implementation/nosignalsinterface.h"

using namespace Test::TbSimple;
TEST_CASE("Testing NoSignalsInterface", "[NoSignalsInterface]"){
    std::unique_ptr<INoSignalsInterface> testNoSignalsInterface = std::make_unique<NoSignalsInterface>();
    // setup your test
    SECTION("Test operation funcVoid") {
        // Do implement test here
        testNoSignalsInterface->funcVoid();
    }
    SECTION("Test operation funcBool") {
        // Do implement test here
        testNoSignalsInterface->funcBool(false);
    }
    SECTION("Test property propBool") {
        // Do implement test here
        testNoSignalsInterface->setPropBool(false);
        REQUIRE( testNoSignalsInterface->getPropBool() == false );
    }
    SECTION("Test property propInt") {
        // Do implement test here
        testNoSignalsInterface->setPropInt(0);
        REQUIRE( testNoSignalsInterface->getPropInt() == 0 );
    }
}
