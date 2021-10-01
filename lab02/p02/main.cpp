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
        long long int input;
        cin >> input;

        double j = 1 + 8 * input;
        double div = (-1 + sqrt(j)) / 2;

        cout << (long long int)div << "\n";
    }
}