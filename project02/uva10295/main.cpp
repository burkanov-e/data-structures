#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) {
    return static_cast<int>(c.size());
}

using namespace std;

struct Skill {
    string mWord;
    int mSalary;
    Skill(const string word, const int salary) : mWord(word), mSalary(salary) {}
};

int main() {
    iostream::sync_with_stdio(false);

    int num1, num2;
    cin >> num1 >> num2;

    vector<Skill> v;

    for (int i = 0; i < num1; i++) {
        string word;
        int salary;
        cin >> word >> salary;

        v.emplace_back(word, salary);
    }

    vector<int> p;

    for (int i = 0; i < num2; i++) {
        int result = 0;

        for (;;) {
            string txt;
            cin >> txt;
            if (txt == ".") {
                break;
            }

            for (auto &s : v) {
                if (s.mWord == txt) {
                    result += s.mSalary;
                    break;
                }
            }
        }
        p.push_back(result);
    }

    for (int i = 0; i < num2; i++) {
        cout << p[i] << "\n";
    }
}