#include "FileOperations.h"
#include "Order.h"
#include "DeliveryDriver.h"
#include "enums.h"
#include <iostream>
#include <fstream>
using namespace std;
void saveCompletedOrders(Order* orders[], int totalOrders) {
    cout << endl;
    cout << "Saving completed orders to file..." << endl;

    ofstream file("completed_orders.txt");
    if (!file) {
        cout << "Cannot create file" << endl;
        return;
    }
    int saved = 0;

    for (int i = 0; i < totalOrders; i++) {
        Order* order = orders[i];

        if (order->getStatus() == OrderStatus::DELIVERED) {
            saved++;

            cout << "Order " << order->getOrderId() << endl;
            file << "Order " << order->getOrderId() << endl;

            if (order->getCustomer()) {
                file << "Customer: " << order->getCustomer()->getName() << endl;
            }
            if (order->getDriver()) {
                file << "Driver: " << order->getDriver()->getName() << endl;
            }
            file << "Total: " << order->calculateTotal() << " EGP" << endl;
            file << "Items: " << order->getItemCount() << endl;
            file << endl;
        }
    }
    file.close();

    cout << endl;
    cout << "Saved " << saved << " orders" << endl;
}
void saveDriverStats(DeliveryDriver* drivers[], int totalDrivers) {
    cout << endl;
    cout << "Saving driver statistics..." << endl;

    ofstream file("driver_stats.txt");

    if (!file) {
        cout << "Cannot create file" << endl;
        return;
    }
    cout << "Driver Statistics" << endl;
    file << "Driver Statistics" << endl;

    for (int i = 0; i < totalDrivers; i++) {
        DeliveryDriver* driver = drivers[i];

        cout << endl;
        cout << "Driver: " << driver->getName() << endl;
        cout << "Deliveries: " << driver->getCompletedDeliveries() << endl;
        cout << "Earnings: " << driver->getTotalEarnings() << " EGP" << endl;

        file << endl;
        file << "Driver: " << driver->getName() << endl;
        file << "Deliveries: " << driver->getCompletedDeliveries() << endl;
        file << "Earnings: " << driver->getTotalEarnings() << " EGP" << endl;

        if (driver->getCompletedDeliveries() > 0) {
            double average = driver->getTotalEarnings() / driver->getCompletedDeliveries();
            cout << "Average: " << average << " EGP per delivery" << endl;
            file << "Average: " << average << " EGP per delivery" << endl;
        }
    }
    file.close();

    cout << endl;
    cout << "Saved " << totalDrivers << " drivers" << endl;
}
