#include <memory>
#include "catch2/catch.hpp"
#include "testbed1/implementation/structinterface.h"

using namespace Test::Testbed1;
TEST_CASE("Testing StructInterface", "[StructInterface]"){
    std::unique_ptr<IStructInterface> testStructInterface = std::make_unique<StructInterface>();
    // setup your test
    SECTION("Test operation funcBool") {
        // Do implement test here
        testStructInterface->funcBool(StructBool());
    }
    SECTION("Test operation funcInt") {
        // Do implement test here
        testStructInterface->funcInt(StructInt());
    }
    SECTION("Test operation funcFloat") {
        // Do implement test here
        testStructInterface->funcFloat(StructFloat());
    }
    SECTION("Test operation funcString") {
        // Do implement test here
        testStructInterface->funcString(StructString());
    }
    SECTION("Test property propBool") {
        // Do implement test here
        testStructInterface->setPropBool(StructBool());
        REQUIRE( testStructInterface->getPropBool() == StructBool() );
    }
    SECTION("Test property propInt") {
        // Do implement test here
        testStructInterface->setPropInt(StructInt());
        REQUIRE( testStructInterface->getPropInt() == StructInt() );
    }
    SECTION("Test property propFloat") {
        // Do implement test here
        testStructInterface->setPropFloat(StructFloat());
        REQUIRE( testStructInterface->getPropFloat() == StructFloat() );
    }
    SECTION("Test property propString") {
        // Do implement test here
        testStructInterface->setPropString(StructString());
        REQUIRE( testStructInterface->getPropString() == StructString() );
    }
}
