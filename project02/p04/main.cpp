#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) {
    return static_cast<int>(c.size());
}

using namespace std;

struct SpecialString {
    string mSequence;
    int mSorting = 0;

    SpecialString(const string sequence) : mSequence(sequence) {}
};

int sorting(string str) {
    int count = 0;
    for (int i = 0; i < sz(str); i++) {
        for (int j = i + 1; j < sz(str); j++) {
            if (str[i] > str[j]) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    iostream::sync_with_stdio(false);

    int test_case;
    cin >> test_case;
    while (test_case--) {
        int n, m;
        cin >> n >> m;

        vector<SpecialString> txt;

        for (int i = 0; i < m; i++) {
            string str;
            cin >> str;
            txt.push_back(str);

            txt[i].mSorting = sorting(txt[i].mSequence);
        }

        stable_sort(begin(txt), end(txt),
                    [](const SpecialString &s1, const SpecialString &s2) {
                        return s1.mSorting < s2.mSorting;
                    });

        for (auto s : txt) {
            cout << s.mSequence << "\n";
        }

        if (test_case) {
            cout << "\n";
        }
    }
}