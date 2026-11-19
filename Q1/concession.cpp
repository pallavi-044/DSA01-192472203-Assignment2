#include <iostream>
using namespace std;

// 1. Call by Value
void applyByValue(long long fee, int percent)
{
    fee -= fee * percent / 100;
}

// 2. Call by Reference
void applyConcession(long long& fee, int percent)
{
    fee -= fee * percent / 100;
}

// 3. Call by Pointer
void applyByPointer(long long* fee, int percent)
{
    if (fee != nullptr)
    {
        *fee -= (*fee) * percent / 100;
    }
}

// 4. Return by Value
long long applyByReturn(long long fee, int percent)
{
    fee -= fee * percent / 100;
    return fee;
}

int main()
{
    long long fee1 = 45000;
    long long fee2 = 45000;
    long long fee3 = 45000;
    long long fee4 = 45000;

    cout << "HOSTEL FEE CONCESSION SYSTEM\n";
    cout << "Original Fee: Rs. 45000\n\n";

    applyByValue(fee1, 10);
    cout << "After Call by Value     : Rs. " << fee1 << '\n';

    applyConcession(fee2, 10);
    cout << "After Call by Reference : Rs. " << fee2 << '\n';

    applyByPointer(&fee3, 10);
    cout << "After Call by Pointer   : Rs. " << fee3 << '\n';

    fee4 = applyByReturn(fee4, 10);
    cout << "After Return by Value   : Rs. " << fee4 << '\n';

    return 0;
}