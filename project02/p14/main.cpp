#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) {
    return static_cast<int>(c.size());
}

using namespace std;

int main() {
    iostream::sync_with_stdio(false);

    int n;
    while (cin >> n && n != 0) {
        vector<string> v;

        for (int i = 0; i < n; i++) {
            string inp;
            cin >> inp;
            v.push_back(inp);
        }

        stable_sort(begin(v), end(v),
                    [](const string &word1, const string &word2) {
                        string str1 = word1.substr(0, 2);
                        string str2 = word2.substr(0, 2);

                        return str1 < str2;
                    });

        for (int i = 0; i < n; i++) {
            cout << v[i] << endl;
        }

        v.clear();
    }
}