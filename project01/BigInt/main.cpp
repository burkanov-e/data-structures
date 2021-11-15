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