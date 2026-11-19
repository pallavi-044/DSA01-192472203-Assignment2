#include <iostream>
#include <vector>
using namespace std;

// Return reference to highest mark
int& highestMark(int marks[], int size)
{
    int maxIndex = 0;

    for (int i = 1; i < size; i++)
    {
        if (marks[i] > marks[maxIndex])
            maxIndex = i;
    }

    return marks[maxIndex];
}

// Return const reference
const int& highestMarkConst(int marks[], int size)
{
    int maxIndex = 0;

    for (int i = 1; i < size; i++)
    {
        if (marks[i] > marks[maxIndex])
            maxIndex = i;
    }

    return marks[maxIndex];
}

// Return by value
int highestMarkCopy(int marks[], int size)
{
    int maxIndex = 0;

    for (int i = 1; i < size; i++)
    {
        if (marks[i] > marks[maxIndex])
            maxIndex = i;
    }

    return marks[maxIndex];
}

// Dangerous: returning reference to local variable
int& dangerousFunction()
{
    int local = 50;
    return local;
}

int main()
{
    int marks[] = {78, 92, 85, 88};
    int size = 4;

    cout << "EXAMINATION MARKS REGISTER\n";

    cout << "Original highest mark: "
         << highestMarkCopy(marks, size) << '\n';

    // Modify highest mark directly
    highestMark(marks, size) += 2;

    cout << "After moderation: "
         << marks[1] << '\n';

    cout << "Using const reference: "
         << highestMarkConst(marks, size) << '\n';

    cout << "Using value copy: "
         << highestMarkCopy(marks, size) << '\n';

    // Vector reallocation demonstration
    vector<int> values = {10, 20};

    size_t oldCapacity = values.capacity();

    values.push_back(30);

    while (values.capacity() == oldCapacity)
        values.push_back(40);

    cout << "Vector capacity changed: YES\n";

    cout << "Old capacity: " << oldCapacity << '\n';
    cout << "New capacity: " << values.capacity() << '\n';

    return 0;
}