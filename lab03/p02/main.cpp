#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    vector<string> puzzle(5);
    string lineBlank = "";
    int t = 1;
    while (true)
    {

        int spaceX(-1), spaceY(-1);

        for (int y = 0; y < 5; ++y)
        {
            getline(cin, puzzle[y]);

            for (int x = 0; x < 5; ++x)
            {
                if (puzzle[y][x] == 'Z')
                    return 0;

                if (puzzle[y][x] == ' ')
                {
                    spaceX = x;
                    spaceY = y;
                }
            }
        }

        cout << lineBlank;
        lineBlank = '\n';

        bool valid(true);

        char move;
        cin >> move;

        while (move != '0')
        {
            int xChange;
            int yChange;
            switch (move)
            {
            case 'A':
                xChange = 0;
                yChange = -1;
                break;
            case 'B':
                xChange = 0;
                yChange = 1;
                break;
            case 'L':
                xChange = -1;
                yChange = 0;
                break;
            case 'R':
                xChange = 1;
                yChange = 0;
                break;

            default:
                xChange = 0;
                yChange = 0;
                valid = false;
                break;
            }
            int newX(spaceX + xChange), newY(spaceY + yChange);

            if (newX < 0 || newX >= 5 || newY < 0 || newY >= 5)
                valid = false;

            if (valid)
            {
                swap(puzzle[newY][newX], puzzle[spaceY][spaceX]);
                spaceX = newX;
                spaceY = newY;
            }

            cin >> move;
        }

        cout << "Puzzle #" << t << ":\n";

        if (valid)
        {
            for (int y = 0; y < 5; ++y)
            {
                string space = "";
                for (int x = 0; x < 5; ++x)
                {
                    cout << space << puzzle[y][x];
                    space = " ";
                }

                cout << '\n';
            }
        }

        else
            cout << "This puzzle has no final configuration.\n";

        cin.ignore();
        t++;
    }
}
