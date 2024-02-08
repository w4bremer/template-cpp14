#include <memory>
#include "catch2/catch.hpp"
#include "tb_simple/implementation/nooperationsinterface.h"

using namespace Test::TbSimple;
TEST_CASE("Testing NoOperationsInterface", "[NoOperationsInterface]"){
    std::unique_ptr<INoOperationsInterface> testNoOperationsInterface = std::make_unique<NoOperationsInterface>();
    // setup your test
    SECTION("Test property propBool") {
        // Do implement test here
        testNoOperationsInterface->setPropBool(false);
        REQUIRE( testNoOperationsInterface->getPropBool() == false );
    }
    SECTION("Test property propInt") {
        // Do implement test here
        testNoOperationsInterface->setPropInt(0);
        REQUIRE( testNoOperationsInterface->getPropInt() == 0 );
    }
}
