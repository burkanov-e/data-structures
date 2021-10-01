#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int a, b, temp;
    while (cin >> a >> b)
    {
        int numA = a, numB = b, maxInt = 0;

        if (a > b)
        {
            temp = a;
            a = b;
            b = temp;
        }

        for (int i = a; i <= b; i++)
        {
            int count = 1;
            int N = i;

            while (N != 1)
            {
                if (N % 2 == 1)
                {
                    N = (3 * N) + 1;
                    count++;
                }
                else
                {
                    N /= 2;
                    count++;
                }
            }

            if (maxInt <= count)
            {
                maxInt = count;
            }
        }
        cout << numA << " " << numB << " " << maxInt << "\n";
    }
}