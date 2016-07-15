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
void print(Seq &seq) {
#ifdef DEBUG
    for (auto &e : seq) cout << e << ' ';
    cout << endl;
#endif
}

template <typename Seq>
size_t longest_nondecreasing_seq(const Seq &seq) {
    vector<size_t> solution(seq.size());

    for (size_t i = 0; i < seq.size(); ++i) {
        solution[i] = 1;  // initalized the number itself

        // for each smaller state, see if can pass from that state to this state
        for (size_t j = 0; j < i; ++j) {
            if (seq[j] <= seq[i] && solution[j] + 1 > solution[i]) {
                solution[i] = solution[j] + 1;
            }
        }
    }
    print(solution);
    return solution.back();
}

int main() {
    vector<int> v{5, 3, 4, 8, 6, 7};
    cout << longest_nondecreasing_seq(v) << endl;
}