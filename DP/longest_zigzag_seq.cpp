// https://community.topcoder.com/tc?module=ProblemDetail&rd=4493&pm=1259
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

struct zigzag {
    constexpr static int INIT_VAL = numeric_limits<int>::lowest();
    bool isZigZag(int curVal, int nextVal) {
        if (lastVal == INIT_VAL) return true;
        int prevDiff = curVal - lastVal;
        int curDiff = nextVal - curVal;
        // if negative then must be different sign i.e. zigzagging
        return (prevDiff * curDiff) < 0;
    }

    zigzag() : lastVal(INIT_VAL), length(1) {}

    int lastVal;
    size_t length;
};

ostream& operator<<(ostream& out, const zigzag& z) { return out << z.length; }

template <typename Seq>
size_t longest_zigzag_seq(const Seq& seq) {
    vector<zigzag> solution(seq.size());

    for (size_t i = 0; i < seq.size(); ++i) {
        solution[i] = zigzag();

        // for each smaller state, see if can pass from that state to this state
        for (size_t j = 0; j < i; ++j) {
            if (solution[j].isZigZag(seq[j], seq[i]) &&
                solution[j].length + 1 > solution[i].length) {
                solution[i].length = solution[j].length + 1;
                solution[i].lastVal = seq[j];
            }
        }
    }

    print(solution);
    return solution.back().length;
}

int main() {
    vector<int> v{1, 7, 4, 9, 2, 5};
    vector<int> v1{1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
    vector<int> v2{44};
    vector<int> v3{1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> v4{70,  55, 13, 2, 99, 2, 80,   80, 80, 80,
                   100, 19, 7,  5, 5,  5, 1000, 32, 32};
    vector<int> v5{374, 40,  854, 203, 203, 156, 362, 279, 812, 955,
                   600, 947, 978, 46,  100, 953, 670, 862, 568, 188,
                   67,  669, 810, 704, 52,  861, 49,  640, 370, 908,
                   477, 245, 413, 109, 659, 401, 483, 308, 609, 120,
                   249, 22,  176, 279, 23,  22,  617, 462, 459, 244};

    cout << longest_zigzag_seq(v) << endl;
    cout << longest_zigzag_seq(v1) << endl;
    cout << longest_zigzag_seq(v2) << endl;
    cout << longest_zigzag_seq(v3) << endl;
    cout << longest_zigzag_seq(v4) << endl;
    cout << longest_zigzag_seq(v5) << endl;
    cout << longest_zigzag_seq(v5) << endl;
}