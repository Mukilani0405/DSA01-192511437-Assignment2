
#include <iostream>
#include <string>
using namespace std;

class BusTicket
{
private:
    static int issued;
    static const int CAPACITY = 3;

    int seatNumber;
    string passengerName;

public:
    BusTicket(string name)
    {
        passengerName = name;

        if (issued < CAPACITY)
        {
            ++issued;
            seatNumber = issued;
        }
        else
        {
            seatNumber = -1;
        }
    }

    void display()
    {
        cout << "Passenger: " << passengerName << " | ";

        if (seatNumber != -1)
            cout << "Seat: " << seatNumber << '\n';
        else
            cout << "Waiting List\n";
    }

    static int count()
    {
        return issued;
    }
};

// Definition of static data member
int BusTicket::issued = 0;

class Token
{
private:
    static int nextId;

public:
    int id;

    Token()
    {
        id = nextId++;
    }

    static int issued()
    {
        return nextId - 100;
    }
};

// Definition of Token static data member
int Token::nextId = 100;

int main()
{
    cout << "BUS TICKET BOOKING\n";

    BusTicket passengers[] = {
        BusTicket("Asha"),
        BusTicket("Bala"),
        BusTicket("Chitra"),
        BusTicket("Dev")
    };

    for (int i = 0; i < 4; i++)
        passengers[i].display();

    cout << "Total Tickets Issued: "
         << BusTicket::count() << '\n';

    cout << "\nSTATIC TOKEN COUNTER\n";

    Token counter[3];
    Token extra;

    cout << counter[0].id << " "
         << counter[2].id << " "
         << extra.id << " "
         << Token::issued() << '\n';

    return 0;
}
