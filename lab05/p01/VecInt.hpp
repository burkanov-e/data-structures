#ifndef VECINT_HPP
#define VECINT_HPP

#include <cstddef>
#include <iostream>

#ifdef AUCA_DEBUG
#include <string>
#endif

class VecInt {
    int *data;
    size_t sz;
    size_t cp;

   public:
    using Iter = int *;
    using CIter = const int *;

    VecInt() : data(nullptr), sz(0), cp(0) {}

    explicit VecInt(size_t aSz, int initValue = 0)
        : data(new int[aSz]), sz(aSz), cp(aSz) {
        for (size_t i = 0; i < sz; i++) {
            data[i] = initValue;
        }
    }

    ~VecInt() {
        std::cout << "~VecInt: " << sz << " integers released" << std::endl;
        delete[] data;
    }

    std::size_t size() const { return sz; }
    Iter begin() { return data; }

    CIter begint() const { return data; }

    Iter end() { return data + sz; }

    CIter end() const { return data + sz; }

    const int &operator[](std::size_t index) const {
#ifndef AUCA_DEBUG
        if (sz <= index) {
            throw std::runtime_error("VecInt: incorrect index: " +
                                     std::to_string(index));
        }
#endif
        return data[index];
    }

    int &operator[](std::size_t index) {
#ifndef AUCA_DEBUG
        if (sz <= index) {
            throw std::runtime_error("VecInt: incorrect index: " +
                                     std::to_string(index));
        }
#endif
        return data[index];
    }

    void pushBack(int x);
};

#endif