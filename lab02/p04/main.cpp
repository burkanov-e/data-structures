#include <bits/stdc++.h>
#include <cmath>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;

        long long ans = ((((((n * 567) / 9) + 7492) * 235) / 47) - 498);

        cout << std::abs(ans / 10) % 10 << "\n";
    }
}