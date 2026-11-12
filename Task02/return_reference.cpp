
#include <iostream>

// Returns a reference to the highest mark
int& highestMark(int marks[], int size)
{
    int highest = 0;

    for (int i = 1; i < size; i++)
    {
        if (marks[i] > marks[highest])
        {
            highest = i;
        }
    }

    return marks[highest];
}

// Dangerous function: returns reference to a local variable
int& invalidReference()
{
    int value = 50;
    return value;
}

// Returns a copy
int highestMarkCopy(const int marks[], int size)
{
    int highest = 0;

    for (int i = 1; i < size; i++)
    {
        if (marks[i] > marks[highest])
        {
            highest = i;
        }
    }

    return marks[highest];
}

int main()
{
    int marks[] = {75, 88, 92, 81, 67};
    int size = 5;

    std::cout << "Original highest mark: "
              << highestMark(marks, size) << '\n';

    highestMark(marks, size) += 2;

    std::cout << "After moderation: "
              << highestMark(marks, size) << '\n';

    std::cout << "Returned copy: "
              << highestMarkCopy(marks, size) << '\n';

    return 0;
}
