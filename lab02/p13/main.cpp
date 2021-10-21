#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int B, N;
    while (cin >> B >> N)
    {
        if (B == 0 && N == 0)
        {
            break;
        }

        vector<int> arr;

        for (int i = 0; i < B; i++)
        {
            int inp;
            cin >> inp;
            arr.push_back(inp);
        }

        for (int i = 0; i < N; i++)
        {
            int debtor, creditor, debValue;
            cin >> debtor >> creditor >> debValue;

            for (int k = 0; k < B; k++)
            {
                if ((k + 1) == debtor)
                {
                    arr[k] -= debValue;
                }
                else if ((k + 1) == creditor)
                {
                    arr[k] += debValue;
                }
            }
        }

        bool liqudate = true;

        for (int i = 0; i < sz(arr); i++)
        {
            if (arr[i] < 0)
            {
                liqudate = false;
            }
        }

        if (liqudate)
        {
            cout << "S\n";
        }
        else
        {
            cout << "N\n";
        }
    }
}