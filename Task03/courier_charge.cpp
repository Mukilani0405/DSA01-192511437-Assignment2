
#include <iostream>
#include <iomanip>
using namespace std;

// Structure for Parcel details
struct Parcel
{
    double weightKg;
    bool express;
    bool insured;
};

// Overload 1: Weight in grams
double charge(int weightGrams,
              bool express = false,
              bool insured = false)
{
    double amount = (weightGrams / 1000.0) * 50;

    if (express)
        amount += 30;

    if (insured)
        amount += 20;

    return amount;
}

// Overload 2: Weight in kilograms
double charge(double weightKg,
              bool express = false,
              bool insured = false)
{
    double amount = weightKg * 50;

    if (express)
        amount += 30;

    if (insured)
        amount += 20;

    return amount;
}

// Overload 3: Parcel object
double charge(const Parcel& p)
{
    return charge(p.weightKg, p.express, p.insured);
}

int main()
{
    Parcel p = {1.5, true, true};

    cout << fixed << setprecision(2);

    cout << "1. charge(2): "
         << charge(2) << '\n';

    cout << "2. charge(2.0f): "
         << charge(2.0f) << '\n';

    cout << "3. charge(2.0): "
         << charge(2.0) << '\n';

    cout << "4. charge(500, true): "
         << charge(500, true) << '\n';

    cout << "5. charge(p): "
         << charge(p) << '\n';

    cout << "6. charge(2.0, true, true): "
         << charge(2.0, true, true) << '\n';

    return 0;
}
