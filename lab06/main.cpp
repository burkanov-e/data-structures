#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

#include "../au/algol.hpp"

using namespace std;
//  support call operator: TR t; t()

struct Student {
    string mName;
    double mGpa;
    Student(const string &name, double gpa)
        : mName(name),
          mGpa(gpa)

    {}
};

struct IsEven {
    bool operator()(int value) const { return value % 2 == 0; }
};

void p0101() {
    int a[] = {3, 1, 20, 4, 7, 0, 5};
    vector<int> b = {3, 1, 20, 4, 7, 0, 5};

    auto itA = find(begin(a), end(a), 20);

    if (itA != end(a)) {
        cout << "position of 20 is " << itA - begin(a) << endl;
    } else {
        cout << "20 not found" << endl;
    }

    auto itB = find(begin(b), end(b), -1);

    if (itB != end(b)) {
        cout << "position of -1 is " << itB - begin(b) << endl;
    } else {
        cout << "-1 not found" << endl;
    }
}

void p0102() {
    int a[] = {3, 1, 20, 4, 7, 0, 5};
    vector<int> b = {3, 1, 20, 4, 7, 0, 5};

    auto itA = auFind(begin(a), end(a), 20);

    if (itA != end(a)) {
        cout << "position of 20 is " << itA - begin(a) << endl;
    } else {
        cout << "20 not found" << endl;
    }

    auto itB = auFind(begin(b), end(b), -1);

    if (itB != end(b)) {
        cout << "position of -1 is " << itB - begin(b) << endl;
    } else {
        cout << "-1 not found" << endl;
    }
}

void p0201() {
    vector<int> b = {3, 1, 20, 4, 7, 0, 5};

    auto it = find_if(begin(b), end(b), IsEven());

    if (it != end(b)) {
        cout << "position of first even number is " << it - begin(b) << endl;
        cout << "the number is " << *it << endl;
    } else {
        cout << "even number is not found" << endl;
    }

    // lambda expression
    auto it2 =
        find_if(begin(b), end(b), [](int value) { return value % 2 == 0; });

    if (it2 != end(b)) {
        cout << "position of first even number is " << it2 - begin(b) << endl;
        cout << "the number is " << *it2 << endl;
    } else {
        cout << "even number is not found" << endl;
    }
}

void p0202() {
    vector<int> b = {3, 1, 20, 4, 7, 0, 5};

    IsEven functor;

    auto it = auFindIf(begin(b), end(b), functor);

    if (it != end(b)) {
        cout << "position of first even number is " << it - begin(b) << endl;
        cout << "the number is " << *it << endl;
    } else {
        cout << "even number is not found" << endl;
    }

    // lambda expression
    auto it2 =
        auFindIf(begin(b), end(b), [](int value) { return value % 2 == 0; });

    if (it != end(b)) {
        cout << "position of first even number is " << it2 - begin(b) << endl;
        cout << "the number is " << *it2 << endl;
    } else {
        cout << "even number is not found" << endl;
    }
}

struct CmpByGpa {
    bool operator()(const Student &s1, const Student &s2) const {
        return s1.mGpa < s2.mGpa;
    }
};
void p06() {
    vector<Student> stud;

    string name;
    double gpa;

    while (cin >> name >> gpa) {
        // stud.push_back(Student(name, gpa))
        stud.emplace_back(name, gpa);
    }

    sort(begin(stud), end(stud), [](const Student &s1, const Student &s2) {
        return s1.mName < s2.mName;
    });

    for (const auto &s : stud) {
        cout << "{" << s.mName << ", " << s.mGpa << "}" << endl;
    }

    cout << "-----" << endl;

    sort(begin(stud), end(stud), CmpByGpa());

    for (const auto &s : stud) {
        cout << "{" << s.mName << ", " << s.mGpa << "}" << endl;
    }
}

int main() {
    // p0101();
    // p0102();

    // p0201();
    // p0202();

    p06();
}