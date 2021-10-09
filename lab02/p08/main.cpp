#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int letter = 0;

    for (char ch; cin.get(ch);)
    {
        if (ch == '\"')
        {
            letter++;
            if (letter % 2 != 0)
            {
                cout.put('`');
                cout.put('`');
            }

            else
            {
                cout.put('\'');
                cout.put('\'');
            }
        }

        else
        {
            cout.put(ch);
        }
    }