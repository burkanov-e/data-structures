#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <sstream>

#include "../../doctest/doctest.h"
#include "BigInt.hpp"

using namespace std;

TEST_CASE("Default constructor") {
    BigInt a;

    ostringstream sout;
    sout << a;

    REQUIRE(sout.str() == "0");
}

TEST_CASE("Default constructor") {
    ostringstream sout;

    SUBCASE("Case 1: 555") {
        BigInt a("123");

        sout << a;

        REQUIRE(sout.str() == "123");
    }

    SUBCASE("Case 2: -1234567890") {
        BigInt a("-1234567890");

        sout << a;

        REQUIRE(sout.str() == "-1234567890");
    }

    SUBCASE("Case 3: 4824728472048727428978429") {
        BigInt a("4824728472048727428978429");

        sout << a;

        REQUIRE(sout.str() == "4824728472048727428978429");
    }
}
