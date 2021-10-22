#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int inp;
    cin >> inp;
    for (int j = 0; j < inp; j++)
    {
        vector<string> arrStr;
        vector<int> arrInt;
        int maxmax;

        for (int i = 0; i < 10; i++)
        {
            string url;
            int revealence;

            cin >> url >> revealence;
            maxmax = max(maxmax, revealence);
            arrStr.push_back(url);
            arrInt.push_back(revealence);
        }

        cout << "Case #" << j + 1 << ":\n";
        for (int i = 0; i < 10; i++)
        {
            if (maxmax == arrInt[i])
            {
                cout << arrStr[i] << "\n";
            }
        }
    }
}