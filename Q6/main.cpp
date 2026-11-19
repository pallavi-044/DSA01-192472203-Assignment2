#include <iostream>
#include <cstdlib>
using namespace std;

class Time {
    int h, m;

public:
    Time(int hh, int mm) : h(hh), m(mm) {}

    friend int minutesBetween(const Time& a, const Time& b);
    friend bool earlier(const Time& a, const Time& b);
};

int minutesBetween(const Time& a, const Time& b) {
    int t1 = a.h * 60 + a.m;
    int t2 = b.h * 60 + b.m;
    return abs(t1 - t2);
}

bool earlier(const Time& a, const Time& b) {
    return (a.h * 60 + a.m) < (b.h * 60 + b.m);
}

int main() {
    Time departure(9, 45);
    Time arrival(13, 10);

    cout << minutesBetween(departure, arrival) << " "
         << boolalpha << earlier(arrival, departure) << '\n';

    Time morning(11, 30);
    Time afternoon(12, 30);
    cout << "Before noon test: "
         << earlier(morning, afternoon) << '\n';

    Time same1(10, 15);
    Time same2(10, 15);
    cout << "Same time difference: "
         << minutesBetween(same1, same2) << '\n';

    return 0;
}