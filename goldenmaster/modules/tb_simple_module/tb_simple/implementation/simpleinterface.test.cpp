#include <memory>
#include "catch2/catch.hpp"
#include "tb_simple/implementation/simpleinterface.h"

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
        testSimpleInterface->funcFloat(0.0);
    }
    SECTION("Test operation funcString") {
        // Do implement test here
        testSimpleInterface->funcString(std::string());
    }
    SECTION("Test property propBool") {
        // Do implement test here
        testSimpleInterface->setPropBool(false);
        REQUIRE( testSimpleInterface->getPropBool() == false );
    }
    SECTION("Test property propInt") {
        // Do implement test here
        testSimpleInterface->setPropInt(0);
        REQUIRE( testSimpleInterface->getPropInt() == 0 );
    }
    SECTION("Test property propFloat") {
        // Do implement test here
        testSimpleInterface->setPropFloat(0.0);
        REQUIRE( testSimpleInterface->getPropFloat() == Approx( 0.0 ) );
    }
    SECTION("Test property propString") {
        // Do implement test here
        testSimpleInterface->setPropString(std::string());
        REQUIRE( testSimpleInterface->getPropString() == std::string() );
    }
}
