#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) {
    return static_cast<int>(c.size());
}

using namespace std;

int main() {
    iostream::sync_with_stdio(false);

    int r, c;

    while (cin >> r && cin >> c && r != 0 && c != 0) {
        vector<string> v(c, "");

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                char ch;
                cin >> ch;

                v[j].push_back(ch);
            }
        }

        stable_sort(begin(v), end(v), [](string a, string b) {
            for (auto &s : a) {
                s = tolower(s);
            }
            for (auto &s : b) {
                s = tolower(s);
            }

            return a < b;
        });

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << v[j][i];
            }

            cout << '\n';
        }

        cout << '\n';
    }
}