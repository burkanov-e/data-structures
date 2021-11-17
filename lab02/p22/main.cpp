#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) {
    return static_cast<int>(c.size());
}

using namespace std;

int main() {
    iostream::sync_with_stdio(false);

    int test_case;
    cin >> test_case;
    while (test_case--) {
        int tcase;
        cin >> tcase;
        vector<int> inp;
        for (int i = 0; i < tcase; i++) {
            int in;
            cin >> in;
            inp.push_back(in);
        }

        int ans = 0;
        for (int i = 0; i < tcase; i++) {
            for (int j = 0; j < i; j++) {
                if (inp[j] <= inp[i]) {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
}