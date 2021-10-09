#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    int a;
    int b;
    while (cin >> a >> b)
    {
        if (a == -1 && b == -1)
        {
            break;
        }

        int mn = min(a, b);
        int mx = max(a, b);

        int d = mx - mn;
        int c = 99 - mx + mn + 1;

        int an = min(c, d);
        cout << an << "\n";
    }
}