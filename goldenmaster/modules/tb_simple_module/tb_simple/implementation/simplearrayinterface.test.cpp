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
        testSimpleArrayInterface->setPropBool(std::list<bool>());
        REQUIRE( testSimpleArrayInterface->propBool() == std::list<bool>() );
    }
    SECTION("Test property propInt") {
        // Do implement test here
        testSimpleArrayInterface->setPropInt(std::list<int>());
        REQUIRE( testSimpleArrayInterface->propInt() == std::list<int>() );
    }
    SECTION("Test property propFloat") {
        // Do implement test here
        testSimpleArrayInterface->setPropFloat(std::list<float>());
        REQUIRE( testSimpleArrayInterface->propFloat() == std::list<float>() );
    }
    SECTION("Test property propString") {
        // Do implement test here
        testSimpleArrayInterface->setPropString(std::list<std::string>());
        REQUIRE( testSimpleArrayInterface->propString() == std::list<std::string>() );
    }
}
