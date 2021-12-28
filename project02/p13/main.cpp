#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) {
    return static_cast<int>(c.size());
}

using namespace std;

void printAns(vector<string> words, int width) {
    sort(begin(words), end(words), [](const string &w1, const string &w2) {
        string word1 = w1;
        string word2 = w2;

        reverse(begin(word1), end(word1));
        reverse(begin(word2), end(word2));

        return word1 < word2;
    });

    for (auto s : words) {
        cout << setw(width) << s << '\n';
    }
}

int main() {
    iostream::sync_with_stdio(false);

    string w;
    vector<string> words;

    int width = 0;

    while (getline(cin, w)) {
        if (sz(w) > width) {
            width = sz(w);
        }

        if (w == "") {
            printAns(words, width);
            cout << '\n';

            width = 0;
            words.clear();
            continue;
        }
        words.push_back(w);
    }
    printAns(words, width);
}