#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int N, prev_jump, low_jump = 0, high_jump = 0;
        cin >> N;
        cin >> prev_jump;

        for (int j = 1; j < N; j++)
        {
            int inp;
            cin >> inp;

            if (inp > prev_jump)
            {
                high_jump++;
            }
            else if (inp < prev_jump)
            {
                low_jump++;
            }
            prev_jump = inp;
        }

        cout << "Case " << i + 1 << ": " << high_jump << " " << low_jump << "\n";
    }
}