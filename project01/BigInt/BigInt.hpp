#pragma once

#include <iosfwd>
#include <iostream>
#include <vector>

class BigInt {
    friend std::ostream &operator<<(std::ostream &out, const BigInt &x);

    std::vector<int> mDigits;
    bool mIsNegative;

   public:
    BigInt() : mIsNegative(false) { mDigits.push_back(0); }
};

inline std::ostream &operator<<(std::ostream &out, const BigInt &x) {
    if (x.mIsNegative) {
        out << '-';
    }

    for (auto digit : x.mDigits) {
        out << digit;
    }

    return out;
}