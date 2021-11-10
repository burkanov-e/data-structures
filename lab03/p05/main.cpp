#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) {
    return static_cast<int>(c.size());
}

using namespace std;

class Computer {
    vector<int> registers;
    vector<int> memory;
    int instructionPointer;

    void runCommand2(int d1, int d2) {
        registers[d1] = d2;
        ++instructionPointer;
    }

    void runCommand3(int d1, int d2) {
        registers[d1] += d2;
        registers[d1] %= 1000;
        ++instructionPointer;
    }

    void runCommand4(int d1, int d2) {
        registers[d1] *= d2;
        registers[d1] %= 1000;
        ++instructionPointer;
    }

    void runCommand5(int d1, int d2) {
        registers[d1] = registers[d2];
        ++instructionPointer;
    }

    void runCommand6(int d1, int d2) {
        registers[d1] += registers[d2];
        registers[d1] %= 1000;
        ++instructionPointer;
    }

    void runCommand7(int d1, int d2) {
        registers[d1] *= registers[d2];
        registers[d1] %= 1000;
        ++instructionPointer;
    }

    void runCommand8(int d1, int d2) {
        registers[d1] = memory[registers[d2]];
        ++instructionPointer;
    }

    void runCommand9(int d1, int d2) {
        memory[registers[d2]] = registers[d1];
        ++instructionPointer;
    }

    void runCommand0(int d1, int d2) {
        if (registers[d2] != 0)
            instructionPointer = registers[d1];

        else
            ++instructionPointer;
    }

   public:
    Computer() : registers(10, 0), memory(1000, 0), instructionPointer(0) {}

    void readCommands(istream &input) {
        int curPos = 0;
        for (string line; getline(input, line) && !line.empty();) {
            memory[curPos] = stoi(line);
            ++curPos;
        }
    }

    int run() {
        int res = 1;

        while (memory[instructionPointer] != 100) {
            int t = memory[instructionPointer];

            int d2 = t % 10;
            t /= 10;
            int d1 = t % 10;
            t /= 10;
            int d0 = t % 10;

            switch (d0) {
                case 2:
                    runCommand2(d1, d2);
                    break;
                case 3:
                    runCommand3(d1, d2);
                    break;
                case 4:
                    runCommand4(d1, d2);
                    break;
                case 5:
                    runCommand5(d1, d2);
                    break;
                case 6:
                    runCommand6(d1, d2);
                    break;
                case 7:
                    runCommand7(d1, d2);
                    break;
                case 8:
                    runCommand8(d1, d2);
                    break;
                case 9:
                    runCommand9(d1, d2);
                    break;
                case 0:
                    runCommand0(d1, d2);
                    break;
                default:
                    break;
            }
            res++;
        }

        return res;
    }
};

int main() {
    iostream::sync_with_stdio(false);

    int tests;
    cin >> tests >> ws;

    for (int test = 0; test < tests; ++test) {
        Computer comp;

        comp.readCommands(cin);

        cout << comp.run() << "\n";

        if (test != tests - 1) {
            cout << "\n";
        }
    }
}