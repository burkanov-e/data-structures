#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

void computeDigits(int n)
{
    int sum = 0;

    while (n > 0 || sum > 9)
    {
        if (n == 0)
        {
            n = sum;
            sum = 0;
        }
        sum += n % 10;
        n /= 10;
    }

    cout << sum << "\n";
}

int main()
{
    iostream::sync_with_stdio(false);
    int n;
    while (cin >> n)
    {
        if (n == 0)
        {
            break;
        }
        computeDigits(n);
    }
}
