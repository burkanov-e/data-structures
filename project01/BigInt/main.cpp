#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <limits>
#include <sstream>

#include "../../doctest/doctest.h"
#include "BigInt.hpp"

using namespace std;

TEST_CASE("Default constructor") {
    BigInt x;

    ostringstream sout;
    sout << x;

    REQUIRE(sout.str() == "0");
}

TEST_CASE("Constructor with string") {
    ostringstream sout;

    SUBCASE("Case 1: 123") {
        BigInt x("123");

        sout << x;

        REQUIRE(sout.str() == "123");
    }

    SUBCASE("Case 2: -1234567890") {
        BigInt x("-1234567890");

        sout << x;

        REQUIRE(sout.str() == "-1234567890");
    }

    SUBCASE("Case 3: +123") {
        BigInt x("+123");
        sout << x;

        REQUIRE(sout.str() == "123");
    }

    SUBCASE("Case 4: 4824728472048727428978429") {
        BigInt x("4824728472048727428978429");

        sout << x;

        REQUIRE(sout.str() == "4824728472048727428978429");
    }

    SUBCASE("Case 5: empty string") {
        REQUIRE_THROWS_AS(BigInt(""), runtime_error);
    }

    SUBCASE("Case 6: -") { REQUIRE_THROWS_AS(BigInt("-"), runtime_error); }

    SUBCASE("Case 7: +") { REQUIRE_THROWS_AS(BigInt("+"), runtime_error); }
}

TEST_CASE("BigInt with long long") {
    ostringstream sout;
    SUBCASE("-9228372036854775808") {
        BigInt x(numeric_limits<long long>::min());
        sout << x;
        REQUIRE(sout.str() == "-9228372036854775808");
    }
}
