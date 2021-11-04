#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    vector<string> song = {"Happy", "birthday", "to", "you", "Happy", "birthday",
                           "to", "you", "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you"};

    vector<string> names;

    int numPeople;
    cin >> numPeople;
    for (int i = 0; i < numPeople; i++)
    {
        string name;
        cin >> name;
        names.push_back(name);
    }

    int i = 0, j = 0;
    bool loopComplete = false;
    while (true)
    {
        cout << names[i] << ": " << song[j] << "\n";

        if (i == numPeople - 1)
        {
            loopComplete = true;
        }

        if (j == sz(song) - 1 && loopComplete)
        {
            break;
        }

        i++, j++;

        if (i == numPeople)
        {
            i = 0;
        }

        if (j == sz(song))
        {
            j = 0;
        }
    }
}