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

    string inp;
    istringstream str(inp);

    getline(cin, inp);

    while (test_case--) {
        getline(cin, inp);
        str.clear();
        str.str(inp);

        map<char, int> MF;
        while (str >> inp) {
            for (int i = 0; i <= 1; i++) {
                ++MF[inp[i]];
            }
        }

        if (MF['M'] > 1 && MF['M'] == MF['F']) {
            cout << "LOOP" << endl;
        } else {
            cout << "NO LOOP" << endl;
        }
    }
}