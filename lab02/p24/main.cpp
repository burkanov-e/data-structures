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

    for (int t = 0; t < test_case; t++) {
        vector<int> vec;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int inp;
            cin >> inp;
            vec.push_back(inp);
        }

        int sum = 0;
        int min_int = INT_MAX;

        for (int i = 0; i < sz(vec); i++) {
            for (int j = 0; j < sz(vec); j++) {
                sum += abs(vec[j] - vec[i]);
            }

            if (sum < min_int) {
                min_int = sum;
            }

            sum = 0;
        }

        cout << min_int << endl;
    }
}