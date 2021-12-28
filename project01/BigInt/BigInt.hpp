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
    friend inline BigInt operator+=(const BigInt &a, const BigInt &b);
    friend inline BigInt operator-(const BigInt &a, const BigInt &b);
    friend inline BigInt operator-=(const BigInt &a, const BigInt &b);
    friend bool operator==(const BigInt &a, const BigInt &b);
    friend bool operator!=(const BigInt &a, const BigInt &b);
    friend bool operator<(const BigInt &a, const BigInt &b);
    friend bool operator>(const BigInt &a, const BigInt &b);
    friend bool operator<=(const BigInt &a, const BigInt &b);
    friend bool operator>=(const BigInt &a, const BigInt &b);

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

    static BigInt subValues(const BigInt &a, const BigInt &b) {
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

            while (result.mDigits.size() > 1 && result.mDigits.back() == 0) {
                result.mDigits.pop_back();
            }

            std::reverse(result.mDigits.begin(), result.mDigits.end());

            return result;
        }
    }

    static bool cmpValues(const BigInt &a, const BigInt &b) {
        if (!a.mIsNegative == b.mIsNegative) {
            return true;
        } else if (a.mIsNegative == !b.mIsNegative) {
            return false;
        }

        if (a.mDigits.size() < b.mDigits.size()) {
            return false;
        }

        if (a.mDigits.size() > b.mDigits.size()) {
            return true;
        }

        for (size_t i = 0; i < a.mDigits.size(); i++) {
            if (a.mDigits[i] != b.mDigits[i]) {
                if (a.mDigits[i] - b.mDigits[i] < 0) {
                    return false;
                } else {
                    return true;
                }
            }
        }

        return 0;
    }

   public:
    BigInt() : mIsNegative(false) { mDigits.push_back(0); }

    explicit BigInt(const std::string &value) : mIsNegative(false) {
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

inline bool operator==(const BigInt &a, const BigInt &b) {
    if (a.mIsNegative == b.mIsNegative) {
        if (a.mDigits.size() == b.mDigits.size()) {
            auto it1 = a.mDigits.begin();
            auto it2 = b.mDigits.begin();
            while (it1 != a.mDigits.end() && it2 != b.mDigits.end()) {
                if (*it1 - *it2 != 0) {
                    return false;
                }
                it1++;
                it2++;
            }
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }

    return BigInt::cmpValues(a, b);
}

inline bool operator!=(const BigInt &a, const BigInt &b) {
    if (a.mDigits == b.mDigits) {
        return false;
    }

    return true;
}

inline bool operator<(const BigInt &a, const BigInt &b) {
    if (a == b) {
        return false;
    } else if (BigInt::cmpValues(a, b) > 0) {
        return false;
    } else {
        return true;
    }
}

inline bool operator>(const BigInt &a, const BigInt &b) {
    return BigInt::cmpValues(a, b);
}

// inline bool operator>(const BigInt &a, const BigInt &b) { return b > a; }

inline bool operator<=(const BigInt &a, const BigInt &b) { return !(a > b); }

inline bool operator>=(const BigInt &a, const BigInt &b) { return !(a < b); }

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

    int compare = BigInt::cmpValues(a, b);
    if (compare == 0) {
        return BigInt();
    }

    throw std::runtime_error("not implemented yet");
}

// inline BigInt operator-(const BigInt &a, const BigInt &b) {
//     if (a.mIsNegative == b.mIsNegative) {
//         BigInt result = BigInt::subAbsValues(a, b);
//         result.mIsNegative = a.mIsNegative;
//         return result;
//     }

//     throw std::runtime_error("not implemented yet");
// }
