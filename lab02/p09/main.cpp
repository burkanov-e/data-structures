#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;

        int max = 99;
        int min = 0;

        for (int j = 0; j < d; j++)
        {
            int inp;
            cin >> inp;

            if (inp < max)
                max = inp;

            if (inp > min)
                min = inp;
        }

        cout << (min - max) * 2 << "\n";
    }
}