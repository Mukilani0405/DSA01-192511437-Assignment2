
#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

// Normal function: compiler is instructed not to inline it
__attribute__((noinline))
int normalFunction(int x)
{
    return (x * 3 + 7) % 1009;
}

// Inline function
inline int inlineFunction(int x)
{
    return (x * 3 + 7) % 1009;
}

int main()
{
    const int N = 10000000;

    volatile int data[1000];

    for (int i = 0; i < 1000; i++)
        data[i] = i;

    volatile long long resultSink = 0;

    // Benchmark normal function
    long long sum1 = 0;

    auto start1 = high_resolution_clock::now();

    for (int i = 0; i < N; i++)
        sum1 += normalFunction(data[i % 1000]);

    auto end1 = high_resolution_clock::now();

    resultSink = sum1;

    // Benchmark inline function
    long long sum2 = 0;

    auto start2 = high_resolution_clock::now();

    for (int i = 0; i < N; i++)
        sum2 += inlineFunction(data[i % 1000]);

    auto end2 = high_resolution_clock::now();

    resultSink = sum2;

    double normalTime =
        duration<double, milli>(end1 - start1).count();

    double inlineTime =
        duration<double, milli>(end2 - start2).count();

    cout << "Number of calls: " << N << '\n';

    cout << "Normal function time: "
         << normalTime << " ms\n";

    cout << "Inline function time: "
         << inlineTime << " ms\n";

    cout << "Result check: "
         << (sum1 == sum2 ? "Passed" : "Failed") << '\n';

    return 0;
}
