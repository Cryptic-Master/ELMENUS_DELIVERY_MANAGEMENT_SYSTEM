#include "DeliveryDriver.h"
#include <iostream>
#include <string>
using namespace std;

DeliveryDriver::DeliveryDriver() {
    vehicleType = "";
    completedDeliveries = 0;
    totalEarnings = 0;
}
DeliveryDriver::DeliveryDriver(string id, string name, string phone, string vehicle): User(id, name, phone) {
    vehicleType = vehicle;
    completedDeliveries = 0;
    totalEarnings = 0;
}
void DeliveryDriver::displayInfo() const {
    cout << "Driver: " << getName() << endl;
    cout << "ID: " << getUserId() << endl;
    cout << "Phone: " << getPhoneNumber() << endl;
    cout << "Vehicle: " << vehicleType << endl;
    cout << "Deliveries: " << completedDeliveries << endl;
    cout << "Earnings: " << totalEarnings << " EGP" << endl;
    if (completedDeliveries > 0) {
        cout << "Average: " << (totalEarnings / completedDeliveries) << " EGP per delivery" << endl;
    }
    cout << endl;
}
double DeliveryDriver::calculateEarnings() const {return totalEarnings;}

void DeliveryDriver::completeDelivery(double orderValue) {
    double money = orderValue * 0.15;
    totalEarnings = totalEarnings + money;
    completedDeliveries++;
}
DeliveryDriver& DeliveryDriver::operator++() {
    completedDeliveries++;
    return *this;
}
DeliveryDriver DeliveryDriver::operator++(int) {
    DeliveryDriver old = *this;
    completedDeliveries++;
    return old;
}
string DeliveryDriver::getVehicleType() const {return vehicleType;}
int DeliveryDriver::getCompletedDeliveries() const {return completedDeliveries;}
double DeliveryDriver::getTotalEarnings() const {return totalEarnings;}
