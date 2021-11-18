#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) {
    return static_cast<int>(c.size());
}

using namespace std;

int main() {
    iostream::sync_with_stdio(false);

    int test_case;
    cin >> test_case;
    while (test_case--) {
        int num_people;
        cin >> num_people;
        int sum = 0;
        int count = 0;

        vector<int> people;
        for (int i = 0; i < num_people; i++) {
            int grades;
            cin >> grades;
            sum += grades;
            people.push_back(grades);
        }

        double avg = sum / num_people;

        for (int i = 0; i < num_people; i++) {
            if (people[i] > avg) {
                count++;
            }
        }

        double abAvg = (count * 100.0 / num_people);

        cout << fixed << setprecision(3) << abAvg << "%"
             << "\n";
    }
}