#pragma once

#include <algorithm>
#include <cctype>
#include <iosfwd>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

class BigInt {
    friend std::ostream &operator<<(std::ostream &out, const BigInt &x);
    friend inline BigInt operator+(const BigInt &a, const BigInt &b);
    friend inline BigInt operator-(const BigInt &a, const BigInt &b);
    friend inline BigInt operator-=(const BigInt &a, const BigInt &b);

    std::vector<int> mDigits;
    bool mIsNegative;

    static BigInt addAbsValues(const BigInt &a, const BigInt &b) {
        BigInt result;
        result.mDigits.clear();
        auto i = a.mDigits.rbegin();
        auto j = b.mDigits.rbegin();

        int carry = 0;
        while (i != a.mDigits.rend() || j != b.mDigits.rend()) {
            int sum = carry;
            if (i != a.mDigits.rend()) {
                sum += *i;
                ++i;
            }
            if (j != b.mDigits.rend()) {
                sum += *j;
                ++j;
            }
            result.mDigits.push_back(sum % 10);
            carry = sum / 10;
        }

        if (carry != 0) {
            result.mDigits.push_back(carry);
        }
        std::reverse(result.mDigits.begin(), result.mDigits.end());

        return result;
    }

    static BigInt subAbsValues(const BigInt &a, const BigInt &b) {
        BigInt result;
        result.mDigits.clear();
        auto i = a.mDigits.rbegin();
        auto j = b.mDigits.rbegin();

        int borrow = 0;
        while (i != a.mDigits.rend()) {
            int difference = *i - borrow;
            i++;

            if (j != b.mDigits.rend()) {
                difference -= *j;
                ++j;
            }

            if (difference < 0) {
                difference += 10;
                borrow = 1;
            }

            else {
                borrow = 0;
            }

            result.mDigits.push_back(difference);

            std::reverse(result.mDigits.begin(), result.mDigits.end());

            return result;
        }
    }

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

inline BigInt operator+(const BigInt &a, const BigInt &b) {
    if (a.mIsNegative == b.mIsNegative) {
        BigInt result = BigInt::addAbsValues(a, b);
        result.mIsNegative = a.mIsNegative;
        return result;
    }

    throw std::runtime_error("not implemented yet");
}

// inline BigInt operator-(const BigInt &a, const BigInt &b) {
//     BigInt result;
//     result = a;
//     result -= b;
//     return result;
// }
