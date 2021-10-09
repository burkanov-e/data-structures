#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int inp;
    cin >> inp;

    for (int i = 0; i < inp; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        int mx = max(a, max(b, c));
        int mn = min(a, min(b, c));
        int mid = (a + b + c) - (mx + mn);

        cout << "Case " << i + 1 << ": " << mid << "\n";
    }
}