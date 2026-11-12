
#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

const int CAPACITY = 1000;
const int TOTAL = 20000;

// Original approach: shift elements when full
class ShiftingBuffer
{
private:
    int data[CAPACITY];
    int count;

public:
    ShiftingBuffer()
    {
        count = 0;
    }

    void insert(int value)
    {
        if (count < CAPACITY)
        {
            data[count++] = value;
        }
        else
        {
            for (int i = 1; i < CAPACITY; i++)
                data[i - 1] = data[i];

            data[CAPACITY - 1] = value;
        }
    }

    int get(int index)
    {
        return data[index];
    }
};

// Improved approach: circular buffer
class CircularBuffer
{
private:
    int data[CAPACITY];
    int count;
    int nextIndex;

public:
    CircularBuffer()
    {
        count = 0;
        nextIndex = 0;
    }

    void insert(int value)
    {
        data[nextIndex] = value;

        nextIndex = (nextIndex + 1) % CAPACITY;

        if (count < CAPACITY)
            count++;
    }

    int get(int index)
    {
        int start = (nextIndex - count + CAPACITY) % CAPACITY;
        return data[(start + index) % CAPACITY];
    }
};

int main()
{
    ShiftingBuffer original;
    CircularBuffer improved;

    // Measure original approach
    auto start1 = high_resolution_clock::now();

    for (int i = 1; i <= TOTAL; i++)
        original.insert(i);

    auto end1 = high_resolution_clock::now();

    // Measure improved approach
    auto start2 = high_resolution_clock::now();

    for (int i = 1; i <= TOTAL; i++)
        improved.insert(i);

    auto end2 = high_resolution_clock::now();

    double originalTime =
        duration<double, milli>(end1 - start1).count();

    double improvedTime =
        duration<double, milli>(end2 - start2).count();

    // Verify that both buffers contain identical data
    bool correct = true;

    for (int i = 0; i < CAPACITY; i++)
    {
        if (original.get(i) != improved.get(i))
        {
            correct = false;
            break;
        }
    }

    cout << "TRANSACTION BUFFER PERFORMANCE\n";
    cout << "Capacity: " << CAPACITY << '\n';
    cout << "Total insertions: " << TOTAL << '\n';

    cout << "\nOriginal shifting approach: "
         << originalTime << " ms\n";

    cout << "Improved circular approach: "
         << improvedTime << " ms\n";

    cout << "\nData verification: "
         << (correct ? "PASSED" : "FAILED") << '\n';

    cout << "Oldest stored transaction: "
         << improved.get(0) << '\n';

    cout << "Newest stored transaction: "
         << improved.get(CAPACITY - 1) << '\n';

    return 0;
}
