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
#define PRINTLN(x)                                                             \
    { cout << x << endl; }
#define RUN(x)                                                                 \
    { x }
#else
#define PRINTLN(x)                                                             \
    {}
#define RUN(X)                                                                 \
    {}
#endif

template <typename Seq> void print(Seq &seq) {
#ifdef DEBUG
    for (auto &e : seq)
        cout << e << ' ';
    cout << endl;
#endif
}

int main() {}