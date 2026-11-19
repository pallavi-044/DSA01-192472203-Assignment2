#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

class Time {
public:
    int h, m;

    Time(int hh, int mm) : h(hh), m(mm) {}
};

inline int inlineDifference(const Time& a, const Time& b) {
    int x = a.h * 60 + a.m;
    int y = b.h * 60 + b.m;
    return x > y ? x - y : y - x;
}

__attribute__((noinline))
int normalDifference(const Time& a, const Time& b) {
    int x = a.h * 60 + a.m;
    int y = b.h * 60 + b.m;
    return x > y ? x - y : y - x;
}

int main() {
    Time a(9, 45), b(13, 10);
    const int iterations = 10000000;

    volatile long long result = 0;

    auto start1 = high_resolution_clock::now();

    for (int i = 0; i < iterations; i++)
        result += inlineDifference(a, b);

    auto end1 = high_resolution_clock::now();

    auto start2 = high_resolution_clock::now();

    for (int i = 0; i < iterations; i++)
        result += normalDifference(a, b);

    auto end2 = high_resolution_clock::now();

    cout << "Inline time: "
         << duration_cast<milliseconds>(end1 - start1).count()
         << " ms\n";

    cout << "Non-inline time: "
         << duration_cast<milliseconds>(end2 - start2).count()
         << " ms\n";

    cout << "Result: " << result << '\n';

    return 0;
}