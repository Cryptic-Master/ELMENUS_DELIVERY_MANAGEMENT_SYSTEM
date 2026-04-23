#include "Order.h"
#include <iostream>
#include <iomanip>
using namespace std;

int Order::totalOrders = 0;

Order::Order() {
    orderId = "";
    customer = nullptr;
    driver = nullptr;
    itemCount = 0;
    capacity = 5;
    status = PENDING;
    items = new FoodItem[capacity];
    totalOrders++;
}

Order::Order(string id, Customer* cust) {
    orderId = id;
    customer = cust;
    driver = nullptr;
    itemCount = 0;
    capacity = 5;
    status = PENDING;
    items = new FoodItem[capacity];
    totalOrders++;
}

Order::Order(const Order& other) {
    orderId = other.orderId;
    customer = other.customer;
    driver = other.driver;
    itemCount = other.itemCount;
    capacity = other.capacity;
    status = other.status;

    items = new FoodItem[capacity];
    for (int i = 0; i < itemCount; i++) {
        items[i] = other.items[i];
    }

    totalOrders++;
}

Order::~Order() {
    delete[] items;
    totalOrders--;
}

void Order::resizeItems() {
    if (itemCount >= capacity) {
        capacity *= 2;
        FoodItem* newItems = new FoodItem[capacity];
        for (int i = 0; i < itemCount; i++) {
            newItems[i] = items[i];
        }
        delete[] items;
        items = newItems;
    }
}

void Order::addItem(const FoodItem& item) {
    resizeItems();
    items[itemCount] = item;
    itemCount++;
}

void Order::assignDriver(DeliveryDriver* drv) {
    driver = drv;
}

void Order::updateStatus(OrderStatus newStatus) {
    status = newStatus;

    if (status == DELIVERED && driver != nullptr && customer != nullptr) {
        driver->completeDelivery(calculateTotal());
        (*driver)++;
        (*customer) += 10;
    }
}

double Order::calculateTotal() const {
    double total = 0.0;
    for (int i = 0; i < itemCount; i++) {
        total += items[i].calculateItemTotal();
    }
    return total;
}

void Order::displayOrder() const {
    cout << "\n=== Order Details ===" << endl;
    cout << "Order ID: " << orderId << endl;

    if (customer != nullptr) {
        cout << "Customer: " << customer->getName() << endl;
    }

    if (driver != nullptr) {
        cout << "Driver: " << driver->getName() << endl;
    }

    cout << "Status: ";
    switch(status) {
        case PENDING: cout << "PENDING"; break;
        case PREPARING: cout << "PREPARING"; break;
        case OUT_FOR_DELIVERY: cout << "OUT_FOR_DELIVERY"; break;
        case DELIVERED: cout << "DELIVERED"; break;
        case CANCELLED: cout << "CANCELLED"; break;
    }
    cout << endl;

    cout << "\nItems:" << endl;
    for (int i = 0; i < itemCount; i++) {
        cout << "  ";
        items[i].displayItem();
    }

    cout << fixed << setprecision(2);
    cout << "Total: " << calculateTotal() << " EGP" << endl;
}

int Order::getTotalOrders() {
    return totalOrders;
}

string Order::getOrderId() const {
    return orderId;
}

Customer* Order::getCustomer() const {
    return customer;
}

DeliveryDriver* Order::getDriver() const {
    return driver;
}

OrderStatus Order::getStatus() const {
    return status;
}

int Order::getItemCount() const {
    return itemCount;
}

Order& Order::operator+=(const FoodItem& item) {
    addItem(item);
    return *this;
}

Order Order::operator+(const Order& other) const {
    Order newOrder(orderId + "_" + other.orderId, customer);

    for (int i = 0; i < itemCount; i++) {
        newOrder.addItem(items[i]);
    }

    for (int i = 0; i < other.itemCount; i++) {
        newOrder.addItem(other.items[i]);
    }

    return newOrder;
}

FoodItem& Order::operator[](int index) {
    return items[index];
}

const FoodItem& Order::operator[](int index) const {
    return items[index];
}

bool operator>(const Order& lhs, const Order& rhs) {
    return lhs.calculateTotal() > rhs.calculateTotal();
}
