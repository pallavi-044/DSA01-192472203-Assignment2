#include <iostream>
#include <iomanip>
using namespace std;

struct Parcel
{
    double weightKg;
    bool express;
    bool insured;
};

// Overload 1: Weight in grams
double charge(int grams, bool express = false, bool insured = false)
{
    double total = 50 + (grams / 1000.0) * 20;

    if (express) total += 30;
    if (insured) total += 20;

    return total;
}

// Overload 2: Weight in kilograms
double charge(double kg, bool express = false, bool insured = false)
{
    double total = 50 + kg * 20;

    if (express) total += 30;
    if (insured) total += 20;

    return total;
}

// Overload 3: Parcel object
double charge(const Parcel& p)
{
    return charge(p.weightKg, p.express, p.insured);
}

int main()
{
    cout << fixed << setprecision(2);

    cout << "COURIER CHARGE CALCULATOR\n\n";

    cout << "charge(500): Rs. " << charge(500) << '\n';

    cout << "charge(2): Rs. " << charge(2) << '\n';

    cout << "charge(2.0f): Rs. " << charge(2.0f) << '\n';

    cout << "charge(1.5): Rs. " << charge(1.5) << '\n';

    cout << "charge(2.0, true): Rs. "
         << charge(2.0, true) << '\n';

    Parcel p = {1.5, true, true};

    cout << "charge(Parcel): Rs. " << charge(p) << '\n';

    return 0;
}