#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int n, m, i = 1;

    while (cin >> n >> m)
    {
        int div = 0;

        if (n == 0 && m == 0)
        {
            break;
        }

        int x = n - m;
        div = x / m;

        if (x > (m * 26))
        {
            cout << "Case " << i++ << ": impossible"
                 << "\n";
            continue;
        }

        if (div * m == x)
        {
            cout << "Case " << i++ << ": " << div << "\n";
        }
        else
        {
            cout << "Case " << i++ << ": " << div + 1 << "\n";
        }
    }
}
