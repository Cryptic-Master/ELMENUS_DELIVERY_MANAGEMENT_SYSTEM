#include "Customer.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

Customer::Customer() {
    deliveryAddress = "";
    loyaltyPoints = 0;
}
Customer::Customer(string id, string userName, string phone, string address, int points) : User(id, userName, phone) {
    deliveryAddress = address;
    loyaltyPoints = points;
}
void Customer::displayInfo() const {
    cout << "\nCustomer: " << getName() << " (ID: " << getUserId() << ")" << endl;
    cout << "Phone: " << getPhoneNumber() << endl;
    cout << "Address: " << deliveryAddress << endl;
    cout << loyaltyPoints << " points = " << (loyaltyPoints * 0.5) << " EGP" << endl;
}
double Customer::calculateEarnings() const {return loyaltyPoints * 0.5;}
string Customer::getDeliveryAddress() const {return deliveryAddress;}
int Customer::getLoyaltyPoints() const {return loyaltyPoints;}
void Customer::setDeliveryAddress(const string& address) {deliveryAddress = address;}
void Customer::setLoyaltyPoints(int points) {loyaltyPoints = points;}
Customer& Customer::operator+=(int points) {
    loyaltyPoints = loyaltyPoints + points;
    return *this;
}
