#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    while (true)
    {

        int n;
        int m;
        cin >> n >> m;

        if (n == 0 && m == 0)
        {
            break;
        }
        int x = n - m;
        int div = x / m;
        int count = 1;

        if (x <= 26)
        {
            cout << "Case " << count << ": " << div;
            count++;
        }
        else
        {
            cout << "Case " << count << ": impossible";
            count++;
        }
    }
}
