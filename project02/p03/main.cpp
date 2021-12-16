#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) {
    return static_cast<int>(c.size());
}

using namespace std;

struct Freq {
    char mLetter;
    int mCount = 1;
    Freq(const char letter) : mLetter(letter) {}
};

int main() {
    iostream::sync_with_stdio(false);

    int tcase;
    cin >> tcase;
    while (tcase--) {
        int r, c, m, n;
        cin >> r >> c >> m >> n;
        vector<Freq> txt;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                bool hasChar = false;
                char ch;
                cin >> ch;

                for (int l = 0; l < sz(txt); l++) {
                    if (txt[l].mLetter == ch) {
                        txt[l].mCount++;
                        hasChar = true;
                    }
                }
                if (!hasChar) {
                    txt.push_back(ch);
                }
            }
        }

        sort(begin(txt), end(txt), [](const Freq &n1, const Freq &n2) {
            return n1.mCount > n2.mCount;
        });

        int ans = 0;

        for (int i = 0; i < sz(txt); i++) {
            if (txt[i].mCount == txt[0].mCount) {
                ans += txt[i].mCount * m;
            }

            else {
                ans += txt[i].mCount * n;
            }
        }

        int CASE = 1;
        cout << "Case " << CASE++ << ": " << ans << "\n";
    }
}