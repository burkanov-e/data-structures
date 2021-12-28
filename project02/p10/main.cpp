#include <bits/stdc++.h>

#include <string>

template <typename C>
int sz(const C &c) {
    return static_cast<int>(c.size());
}

using namespace std;

int main() {
    iostream::sync_with_stdio(false);

    int numOfCups;
    cin >> numOfCups;

    vector<pair<int, string>> cups;

    while (numOfCups--) {
        string color;
        string radInp;
        int rad;

        cin >> color >> radInp;

        if (isdigit(color[0])) {
            rad = stoi(color) / 2;
            color = radInp;
        } else {
            rad = stoi(radInp);
        }

        cups.emplace_back(rad, color);
    }

    sort(begin(cups), end(cups));

    for (auto s : cups) {
        cout << s.second << endl;
    }
}