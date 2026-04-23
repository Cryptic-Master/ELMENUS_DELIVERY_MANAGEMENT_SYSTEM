#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "User.h"
#include <string>
using namespace std;
class Customer : public User {
private:
    string deliveryAddress;
    int loyaltyPoints;
public:
    Customer();
    Customer(string id, string name, string phone, string address, int points);

    void displayInfo() const override;
    double calculateEarnings() const override;

    string getDeliveryAddress() const;
    int getLoyaltyPoints() const;

    void setDeliveryAddress(const string& address);
    void setLoyaltyPoints(int points);

    Customer& operator+=(int points);
};
#endif
