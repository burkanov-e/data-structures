#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) {
    return static_cast<int>(c.size());
}

bool isEven(int n) { return n % 2 == 0; }

using namespace std;

int main() {
    iostream::sync_with_stdio(false);

    int n;
    int m;

    while (cin >> n >> m) {
        vector<int> v;
        if (n == 0 && m == 0) {
            break;
        }

        for (int i = 0; i < n; i++) {
            int inp;
            cin >> inp;

            v.push_back(inp);
        }

        stable_sort(begin(v), end(v), [m](int n1, int n2) {
            if (n1 % m != n2 % m) {
                return n1 % m < n2 % m;
            }

            if (!isEven(n1)) {
                if (!isEven(n2)) {
                    return n1 > n2;
                }
                return true;
            }

            if (!isEven(n2)) {
                return false;
            }

            return n1 < n2;
        });

        cout << n << " " << m << "\n";
        for (auto &sort : v) {
            cout << sort << "\n";
        }
    }
    cout << 0 << " " << 0 << "\n";
}