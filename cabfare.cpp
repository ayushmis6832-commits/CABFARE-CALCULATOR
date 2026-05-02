#include <iostream>
using namespace std;

class Cab {
protected:
    float baseFare;
    float perKmRate;

public:
    Cab(float base, float rate) {
        baseFare = base;
        perKmRate = rate;
    }

    float calculateFare(float distance, int waitingTime, bool surge) {
        float fare = baseFare + (distance * perKmRate);
        fare += waitingTime * 2; // waiting charge

        if (surge) {
            fare *= 1.5; // surge pricing
        }

        return fare;
    }
};

int main() {
    int choice;
    float distance;
    int waitingTime;
    bool surge;

    cout << "---- Cab Fare Calculator ----\n";
    cout << "1. Mini\n2. Sedan\n3. SUV\n";
    cout << "Select Cab Type: ";
    cin >> choice;

    cout << "Enter distance (km): ";
    cin >> distance;

    cout << "Enter waiting time (minutes): ";
    cin >> waitingTime;

    cout << "Is it peak time? (1 = Yes, 0 = No): ";
    cin >> surge;

    Cab *cab;

    switch(choice) {
        case 1:
            cab = new Cab(50, 10);
            break;
        case 2:
            cab = new Cab(80, 15);
            break;
        case 3:
            cab = new Cab(100, 20);
            break;
        default:
            cout << "Invalid choice!";
            return 0;
    }

    float totalFare = cab->calculateFare(distance, waitingTime, surge);

    cout << "\nTotal Fare: ₹" << totalFare << endl;

    delete cab;
    return 0;
}