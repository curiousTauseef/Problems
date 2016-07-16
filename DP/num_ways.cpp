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

unsigned long long numWays(int width, int length, const vector<string>& bad) {
    map<pair<int, int>, vector<pair<int, int>>> restricted;
    for (const auto& restriction : bad) {
        int a, b, c, d;
        stringstream ss;
        ss << restriction;
        ss >> a >> b >> c >> d;
        restricted[{a, b}].emplace_back(c, d);
        restricted[{c, d}].emplace_back(a, b);
    }
    auto isRestricted = [&](int a, int b, int c, int d) {
        if (restricted.find({a, b}) == restricted.end()) return false;
        const auto& rlist = restricted.at({a, b});
        return find(rlist.begin(), rlist.end(), pair<int, int>(c, d)) != rlist.end();
    };

    vector<vector<unsigned long long>> grid;
    for (int w = 0; w <= width; ++w) {
        grid.push_back(vector<unsigned long long>(length + 1, 0));
    }

    grid[0][0] = 1;
    for (int w = 0; w <= width; ++w) {
        for (int l = 0; l <= length; ++l) {
            if (w == 0 && l == 0) continue;
            if (w == 0) {
                if (isRestricted(w, l, w, l - 1) == false) {
                    grid[w][l] = grid[w][l - 1];
                }
                // else 0
            } else if (l == 0) {
                if (w > 0 && isRestricted(w, l, w - 1, l) == false) {
                    grid[w][l] = grid[w - 1][l];
                }
                // else 0
            } else {
                unsigned long long bot = 0;
                unsigned long long left = 0;

                if (isRestricted(w, l, w - 1, l) == false) {
                    bot = grid[w - 1][l];
                }
                if (isRestricted(w, l, w, l - 1) == false) {
                    left = grid[w][l - 1];
                }
                grid[w][l] = bot + left;
            }
        }
    }
    // for (const auto& line : grid) print(line);
    return grid[width][length];
}

int main() {
    cout << numWays(6, 6, {"0 0 0 1", "6 6 5 6"}) << endl;
    cout << numWays(35, 31, {}) << endl;
    cout << numWays(2, 2, {"0 0 1 0", "1 2 2 2", "1 1 2 1"}) << endl;
}