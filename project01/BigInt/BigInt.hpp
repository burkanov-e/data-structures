#pragma once

#include <cctype>
#include <iosfwd>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

class BigInt {
    friend std::ostream &operator<<(std::ostream &out, const BigInt &x);

    std::vector<int> mDigits;
    bool mIsNegative;

   public:
    BigInt() : mIsNegative(false) { mDigits.push_back(0); }

    BigInt(const std::string &value) : mIsNegative(false) {
        if (value.empty()) {
            throw std::runtime_error("BigInt: empty string");
        }

        size_t i = 0;

        if (value[i] == '-' || value[i] == '+') {
            mIsNegative = value[i] == '-';
            i++;
        }

        while (i < value.size()) {
            if (!isdigit(value[i])) {
                throw std::runtime_error(
                    "BigInt: incorrect string initializer");
            }
            mDigits.push_back(value[i] - '0');
            i++;
        }

        if (mDigits.empty()) {
            throw std::runtime_error("BigInt: incorrect string");
        }
    }

    BigInt(long long x) : BigInt(std::to_string(x)) {}
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

// static BigInt addAbsValues(const BigInt &a, const BigInt &b) { BigInt r; }