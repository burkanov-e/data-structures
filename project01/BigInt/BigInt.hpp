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

    BigInt(const std::string value) : mIsNegative(false) {
        size_t i = 0;

        if (value[i] == '-' || value[i] == '+') {
            mIsNegative = value[i] == '-';
            i++;
        }

        for (; i != value.size(); i++) {
            if (!isdigit(value[i])) {
                throw std::runtime_error(
                    "BigInt: incorrect string initializer");
            }
            mDigits.push_back(value[i]);
        }
    }
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