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

// donations aranged in circles where neighbours will not donate
int max_donations(const vector<int>& donations) {
    int N = donations.size();
    if (N < 3) {
        return max(donations[0], donations[1]);
    }
    vector<int> solution(N + 1, 0);
    solution[0] = donations[0];
    solution[1] = donations[1];

    bool firstChosen = false;
    for (int i = 2; i < N + 1; ++i) {
        // either self or not choose self
        int solutionChooseSelf = solution[i - 2] + donations[i % N];
        if (solutionChooseSelf > solution[i - 1]) {
            solution[i] = solutionChooseSelf;
            if (i == 2) {
                firstChosen = true;
            }
        } else {
            solution[i] = solution[i - 1];
        }
    }

    if (firstChosen) {
        solution[N] -= donations[0];
    }

    print(solution);
    return solution.back();
}

int main() {
    vector<int> v1{10, 3, 2, 5, 7, 8};
    vector<int> v2{11, 15};
    vector<int> v3{7, 7, 7, 7, 7, 7, 7};
    vector<int> v4{1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
    vector<int> v5{94,  40, 49, 65, 21, 21,  106, 80, 92, 81, 679, 4,   61, 6,
                   237, 12, 72, 74, 29, 95,  265, 35, 47, 1,  61,  397, 52, 72,
                   37,  51, 1,  81, 45, 435, 7,   36, 57, 86, 81,  72};
    cout << max_donations(v1) << endl;
    cout << max_donations(v2) << endl;
    cout << max_donations(v3) << endl;
    cout << max_donations(v4) << endl;
    cout << max_donations(v5) << endl;
}