
#include <iostream>
using namespace std;

class Time
{
private:
    int h, m;

public:
    Time(int hours, int minutes)
    {
        h = hours;
        m = minutes;
    }

    friend int minutesBetween(const Time& a, const Time& b);
    friend bool earlier(const Time& a, const Time& b);
};

// Friend function to calculate absolute time difference
int minutesBetween(const Time& a, const Time& b)
{
    int first = a.h * 60 + a.m;
    int second = b.h * 60 + b.m;

    return (first > second) ? first - second : second - first;
}

// Friend function to compare two Time objects
bool earlier(const Time& a, const Time& b)
{
    return (a.h < b.h) ||
           (a.h == b.h && a.m < b.m);
}

int main()
{
    Time t1(10, 30);
    Time t2(13, 55);

    cout << "Time Difference: "
         << minutesBetween(t1, t2)
         << " minutes\n";

    cout << "Is first time earlier? "
         << boolalpha << earlier(t1, t2) << '\n';

    // Additional test cases
    Time t3(12, 0);
    Time t4(12, 0);

    cout << "Same time difference: "
         << minutesBetween(t3, t4) << " minutes\n";

    cout << "Is first time earlier? "
         << earlier(t3, t4) << '\n';

    Time t5(11, 45);
    Time t6(12, 15);

    cout << "Before and after noon difference: "
         << minutesBetween(t5, t6) << " minutes\n";

    cout << "Is first time earlier? "
         << earlier(t5, t6) << '\n';

    return 0;
}
