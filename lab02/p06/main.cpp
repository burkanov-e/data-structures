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

        int ans = max(a, min(b, c));

        cout << "Case " << i + 1 << ": " << ans << "\n";
    }
}