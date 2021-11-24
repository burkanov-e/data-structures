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

    SUBCASE("First Case: 555") {
        BigInt a("123");

        sout << a;

        REQUIRE(sout.str() == "123");
    }

    SUBCASE("Second Case: -1234567890") {
        BigInt a("-1234567890");

        sout << a;

        REQUIRE(sout.str() == "-1234567890");
    }
}
