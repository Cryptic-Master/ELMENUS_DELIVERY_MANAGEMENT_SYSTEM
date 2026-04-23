#include "FileOperations.h"
#include <iostream>
#include <string>
#include "Customer.h"
#include "DeliveryDriver.h"
#include "FoodItem.h"
#include "Order.h"
#include "enums.h"
using namespace std;

const int MAX_CUSTOMERS = 100;
const int MAX_DRIVERS = 50;
const int MAX_ORDERS = 200;

void displayMenu() {
    cout << "\n========== ELMENUS DELIVERY MANAGEMENT SYSTEM ==========" << endl;
    cout << "USER MANAGEMENT" << endl;
    cout << "1. Register New Customer" << endl;
    cout << "2. Register New Delivery Driver" << endl;
    cout << "\nORDER MANAGEMENT" << endl;
    cout << "3. Create New Order" << endl;
    cout << "4. Add Items to Order" << endl;
    cout << "5. Assign Driver to Order" << endl;
    cout << "6. Update Order Status" << endl;
    cout << "7. Display Order Details" << endl;
    cout << "\nINFORMATION & REPORTS" << endl;
    cout << "8. Display Customer Information" << endl;
    cout << "9. Display Driver Information" << endl;
    cout << "10. Compare Two Orders by Total" << endl;
    cout << "11. Display System Statistics" << endl;
    cout << "\nFILE OPERATIONS" << endl;
    cout << "12. Save Completed Orders to File" << endl;
    cout << "13. Save Driver Statistics to File" << endl;
    cout << "\n17. Exit System" << endl;
    cout << "=====================================================" << endl;
    cout << "Enter your choice: ";
}

void clearInput() {
    cin.clear();
    cin.ignore(1000, '\n');
}

int main() {
    Customer* customers[MAX_CUSTOMERS];
    DeliveryDriver* drivers[MAX_DRIVERS];
    Order* orders[MAX_ORDERS];

    int customerCount = 0;
    int driverCount = 0;
    int orderCount = 0;

    int customerIdCounter = 1;
    int driverIdCounter = 1;
    int orderIdCounter = 1;

    // Add some sample data
    customers[customerCount++] = new Customer("CUST100", "Ahmed", "0104757848", "6TH of October, Cairo", 0);
    drivers[driverCount++] = new DeliveryDriver("DRIV100", "Mohamed", "0111251154", "Motorcycle");

    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch(choice) {
            case 1: {
                if (customerCount >= MAX_CUSTOMERS) {
                    cout << "Error: Maximum customers limit reached!" << endl;
                    break;
                }
                string name, phone, address;
                cout << "\n=== Register New Customer ===" << endl;
                cout << "Enter name: ";
                clearInput();
                getline(cin, name);
                cout << "Enter phone: ";
                getline(cin, phone);
                cout << "Enter address: ";
                getline(cin, address);

                string id = "CUST" + to_string(100 + customerIdCounter);
                customers[customerCount] = new Customer(id, name, phone, address, 0);
                customerCount++;
                customerIdCounter++;

                cout << "Customer registered successfully! ID: " << id << endl;
                break;
            }
            case 2: {
                if (driverCount >= MAX_DRIVERS) {
                    cout << "Error: Maximum drivers limit reached!" << endl;
                    break;
                }
                string name, phone, vehicle;
                cout << "\n=== Register New Delivery Driver ===" << endl;
                cout << "Enter name: ";
                clearInput();
                getline(cin, name);
                cout << "Enter phone: ";
                getline(cin, phone);
                cout << "Enter vehicle type: ";
                getline(cin, vehicle);

                string id = "DRIV" + to_string(100 + driverIdCounter);
                drivers[driverCount] = new DeliveryDriver(id, name, phone, vehicle);
                driverCount++;
                driverIdCounter++;

                cout << "Driver registered successfully! ID: " << id << endl;
                break;
            }
            case 3: {
                if (orderCount >= MAX_ORDERS) {
                    cout << "Maximum orders limit reached!" << endl;
                    break;
                }
                if (customerCount == 0) {
                    cout << "No customers available. Register a customer first!" << endl;
                    break;
                }
                cout << "\n=== Available Customers ===" << endl;
                for (int i = 0; i < customerCount; i++) {
                    cout << i + 1 << ". " << customers[i]->getName()
                         << " (" << customers[i]->getUserId() << ")" << endl;
                }
                int customerChoice;
                cout << "Select customer (1-" << customerCount << "): ";
                cin >> customerChoice;

                if (customerChoice < 1 || customerChoice > customerCount) {
                    cout << "Invalid selection!" << endl;
                    break;
                }
                string orderId = "ORD" + to_string(1000 + orderIdCounter);
                orders[orderCount] = new Order(orderId, customers[customerChoice - 1]);
                orderCount++;
                orderIdCounter++;

                cout << "Order created successfully! ID: " << orderId << endl;
                break;
            }
            case 4: {
                if (orderCount == 0) {
                    cout << "No orders available!" << endl;
                    break;
                }
                cout << "\n=== Available Orders ===" << endl;
                for (int i = 0; i < orderCount; i++) {
                    cout << i + 1 << ". " << orders[i]->getOrderId() << endl;
                }
                int orderChoice;
                cout << "Select order (1-" << orderCount << "): ";
                cin >> orderChoice;

                if (orderChoice < 1 || orderChoice > orderCount) {
                    cout << "Invalid selection!" << endl;
                    break;
                }
                string itemName;
                double price;
                int quantity;

                cout << "Enter item name: ";
                clearInput();
                getline(cin, itemName);
                cout << "Enter price: ";
                cin >> price;
                cout << "Enter quantity: ";
                cin >> quantity;

                FoodItem item(itemName, price, quantity);
                *orders[orderChoice - 1] += item;

                cout << "Item added successfully!" << endl;
                break;
            }
            case 5: {
                if (orderCount == 0) {
                    cout << "No orders available!" << endl;
                    break;
                }
                if (driverCount == 0) {
                    cout << "No drivers available!" << endl;
                    break;
                }
                cout << "\n=== Available Orders ===" << endl;
                for (int i = 0; i < orderCount; i++) {
                    cout << i + 1 << ". " << orders[i]->getOrderId() << endl;
                }
                int orderChoice;
                cout << "Select order (1-" << orderCount << "): ";
                cin >> orderChoice;

                if (orderChoice < 1 || orderChoice > orderCount) {
                    cout << "Invalid selection!" << endl;
                    break;
                }
                cout << "\n=== Available Drivers ===" << endl;
                for (int i = 0; i < driverCount; i++) {
                    cout << i + 1 << ". " << drivers[i]->getName()
                         << " (" << drivers[i]->getVehicleType() << ")" << endl;
                }
                int driverChoice;
                cout << "Select driver (1-" << driverCount << "): ";
                cin >> driverChoice;

                if (driverChoice < 1 || driverChoice > driverCount) {
                    cout << "Invalid selection!" << endl;
                    break;
                }
                orders[orderChoice - 1]->assignDriver(drivers[driverChoice - 1]);
                cout << "Driver assigned successfully!" << endl;
                break;
            }
            case 6: {
                if (orderCount == 0) {
                    cout << "No orders available!" << endl;
                    break;
                }
                cout << "\n=== Available Orders ===" << endl;
                for (int i = 0; i < orderCount; i++) {
                    cout << i + 1 << ". " << orders[i]->getOrderId() << endl;
                }
                int orderChoice;
                cout << "Select order (1-" << orderCount << "): ";
                cin >> orderChoice;

                if (orderChoice < 1 || orderChoice > orderCount) {
                    cout << "Invalid selection!" << endl;
                    break;
                }
                cout << "\n=== Update Status ===" << endl;
                cout << "1. PENDING" << endl;
                cout << "2. PREPARING" << endl;
                cout << "3. OUT_FOR_DELIVERY" << endl;
                cout << "4. DELIVERED" << endl;
                cout << "5. CANCELLED" << endl;
                cout << "Select status (1-5): ";

                int statusChoice;
                cin >> statusChoice;

                OrderStatus newStatus;
                switch(statusChoice) {
                    case 1: newStatus = PENDING; break;
                    case 2: newStatus = PREPARING; break;
                    case 3: newStatus = OUT_FOR_DELIVERY; break;
                    case 4: newStatus = DELIVERED; break;
                    case 5: newStatus = CANCELLED; break;
                    default:
                        cout << "Invalid choice!" << endl;
                        break;
                }
                orders[orderChoice - 1]->updateStatus(newStatus);
                cout << "Order status updated successfully!" << endl;
                break;
            }
            case 7: {
                if (orderCount == 0) {
                    cout << "No orders available!" << endl;
                    break;
                }
                cout << "\n=== Available Orders ===" << endl;
                for (int i = 0; i < orderCount; i++) {
                    cout << i + 1 << ". " << orders[i]->getOrderId() << endl;
                }
                int orderChoice;
                cout << "Select order (1-" << orderCount << "): ";
                cin >> orderChoice;

                if (orderChoice < 1 || orderChoice > orderCount) {
                    cout << "Invalid selection!" << endl;
                    break;
                }
                orders[orderChoice - 1]->displayOrder();
                break;
            }
            case 8: {
                if (customerCount == 0) {
                    cout << "No customers available!" << endl;
                    break;
                }
                cout << "\n=== Available Customers ===" << endl;
                for (int i = 0; i < customerCount; i++) {
                    cout << i + 1 << ". " << customers[i]->getName() << endl;
                }
                int customerChoice;
                cout << "Select customer (1-" << customerCount << "): ";
                cin >> customerChoice;

                if (customerChoice < 1 || customerChoice > customerCount) {
                    cout << "Invalid selection!" << endl;
                    break;
                }
                customers[customerChoice - 1]->displayInfo();
                break;
            }
            case 9: {
                if (driverCount == 0) {
                    cout << "No drivers available!" << endl;
                    break;
                }
                cout << "\n=== Available Drivers ===" << endl;
                for (int i = 0; i < driverCount; i++) {
                    cout << i + 1 << ". " << drivers[i]->getName() << endl;
                }
                int driverChoice;
                cout << "Select driver (1-" << driverCount << "): ";
                cin >> driverChoice;

                if (driverChoice < 1 || driverChoice > driverCount) {
                    cout << "Invalid selection!" << endl;
                    break;
                }
                drivers[driverChoice - 1]->displayInfo();
                break;
            }
            case 10: {
                if (orderCount < 2) {
                    cout << "Need at least 2 orders to compare!" << endl;
                    break;
                }
                cout << "\n=== Available Orders ===" << endl;
                for (int i = 0; i < orderCount; i++) {
                    cout << i + 1 << ". " << orders[i]->getOrderId()
                         << " (Total: " << orders[i]->calculateTotal() << " EGP)" << endl;
                }
                int order1, order2;
                cout << "Select first order (1-" << orderCount << "): ";
                cin >> order1;
                cout << "Select second order (1-" << orderCount << "): ";
                cin >> order2;

                if (order1 < 1 || order1 > orderCount || order2 < 1 || order2 > orderCount) {
                    cout << "Invalid selection!" << endl;
                    break;
                }
                cout << "\n=== Comparison Result ===" << endl;
                cout << "Order " << orders[order1 - 1]->getOrderId()
                     << " total: " << orders[order1 - 1]->calculateTotal() << " EGP" << endl;
                cout << "Order " << orders[order2 - 1]->getOrderId()
                     << " total: " << orders[order2 - 1]->calculateTotal() << " EGP" << endl;

                if (*orders[order1 - 1] > *orders[order2 - 1]) {
                    cout << "Order " << orders[order1 - 1]->getOrderId()
                         << " has higher total than Order " << orders[order2 - 1]->getOrderId() << endl;
                } else if (*orders[order2 - 1] > *orders[order1 - 1]) {
                    cout << "Order " << orders[order2 - 1]->getOrderId()
                         << " has higher total than Order " << orders[order1 - 1]->getOrderId() << endl;
                } else {
                    cout << "Both orders have the same total" << endl;
                }
                break;
            }
            case 11: {
                cout << "\n=== System Statistics ===" << endl;
                cout << "Total Users: " << User::getTotalUsers() << endl;
                cout << "Total Customers: " << customerCount << endl;
                cout << "Total Drivers: " << driverCount << endl;
                cout << "Total Orders Created: " << Order::getTotalOrders() << endl;
                cout << "Active Orders: " << orderCount << endl;
                break;
            }
            case 12: {
                if (orderCount == 0) {
                    cout << "No orders to save!" << endl;
                    break;
                }
                saveCompletedOrders(orders, orderCount);
                break;
            }
            case 13: {
                if (driverCount == 0) {
                    cout << "No drivers to save!" << endl;
                    break;
                }
                saveDriverStats(drivers, driverCount);
                break;
            }
            case 17: {
                cout << "\nExiting system..." << endl;

                // Clean up memory
                for (int i = 0; i < customerCount; i++) {
                    delete customers[i];
                }
                for (int i = 0; i < driverCount; i++) {
                    delete drivers[i];
                }
                for (int i = 0; i < orderCount; i++) {
                    delete orders[i];
                }
                cout << "Memory cleaned up. Goodbye!" << endl;
                break;
            }
            default:
                cout << "Error: Invalid choice! Please try again." << endl;
        }
    } while (choice != 17);
    return 0;
}
