// https://community.topcoder.com/stat?c=problem_statement&pm=2402&rd=5009
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <vector>
using namespace std;

#define DEBUG
#ifdef DEBUG
#define PRINTLN(x) \
    { cout << x << endl; }
#define RUN(x) \
    { x }
#else
#define PRINTLN(x) \
    {}
#define RUN(X) \
    {}
#endif

template <typename Seq>
void print(Seq& seq) {
#ifdef DEBUG
    for (auto& e : seq) cout << e << ' ';
    cout << endl;
#endif
}

unsigned long long numWays(int size, pair<int, int> start, pair<int, int> finish, int numMoves) {
    vector<vector<vector<unsigned long long>>> grid(numMoves + 1);
    // grid[turn][row][col]

    // turn 0 start at start with 1 way
    for (int t = 0; t <= numMoves; ++t) {
        for (int r = 0; r < size; ++r) {
            grid[t].push_back(vector<unsigned long long>(size, 0));
        }
    }
    grid[0][start.first][start.second] = 1;

    auto getInrangeValue = [&](int t, int r, int c) {
        if (r < 0 || c < 0 || r >= size || c >= size) return (unsigned long long)0;
        return grid[t][r][c];
    };

    for (int t = 1; t <= numMoves; ++t) {
        for (int r = 0; r < size; ++r) {
            for (int c = 0; c < size; ++c) {
                unsigned long long val = 0;
                // 8 king moves
                val += getInrangeValue(t - 1, r - 1, c - 1);
                val += getInrangeValue(t - 1, r - 1, c);
                val += getInrangeValue(t - 1, r - 1, c + 1);
                val += getInrangeValue(t - 1, r, c - 1);
                val += getInrangeValue(t - 1, r, c + 1);
                val += getInrangeValue(t - 1, r + 1, c - 1);
                val += getInrangeValue(t - 1, r + 1, c);
                val += getInrangeValue(t - 1, r + 1, c + 1);
                // 8 knight moves
                val += getInrangeValue(t - 1, r - 2, c - 1);
                val += getInrangeValue(t - 1, r - 1, c - 2);
                val += getInrangeValue(t - 1, r - 1, c + 2);
                val += getInrangeValue(t - 1, r - 2, c + 1);
                val += getInrangeValue(t - 1, r + 2, c - 1);
                val += getInrangeValue(t - 1, r + 1, c - 2);
                val += getInrangeValue(t - 1, r + 1, c + 2);
                val += getInrangeValue(t - 1, r + 2, c + 1);
                grid[t][r][c] = val;
            }
        }
    }

    return grid[numMoves][finish.first][finish.second];
}

int main() {
    cout << numWays(3, {0, 0}, {1, 0}, 1) << endl;
    cout << numWays(3, {0, 0}, {1, 2}, 1) << endl;
    cout << numWays(3, {0, 0}, {2, 2}, 1) << endl;
    cout << numWays(3, {0, 0}, {0, 0}, 2) << endl;
    cout << numWays(100, {0, 0}, {0, 99}, 50) << endl;
}