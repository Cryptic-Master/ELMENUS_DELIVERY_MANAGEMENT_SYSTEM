//Habiba Elsayed Hemayed_20255110_Reem Mohamed Behairy_20246053_G3
#ifndef ORDER_H_INCLUDED
#define ORDER_H_INCLUDED
#include "FoodItem.h"
#include "Customer.h"
#include "DeliveryDriver.h"
#include "enums.h"
#include <string>
using namespace std;

class Order {
private:
    string orderId;
    Customer* customer;
    DeliveryDriver* driver;
    FoodItem* items;
    int itemCount;
    int capacity;
    OrderStatus status;
    static int totalOrders;

    void resizeItems();

public:
    Order();
    Order(string id, Customer* cust);
    Order(const Order& other);
    ~Order();

    void addItem(const FoodItem& item);
    void assignDriver(DeliveryDriver* drv);
    void updateStatus(OrderStatus newStatus);
    double calculateTotal() const;
    void displayOrder() const;

    static int getTotalOrders();

    string getOrderId() const;
    Customer* getCustomer() const;
    DeliveryDriver* getDriver() const;
    OrderStatus getStatus() const;
    int getItemCount() const;


    Order& operator+=(const FoodItem& item);
    Order operator+(const Order& other) const;
    FoodItem& operator[](int index);
    const FoodItem& operator[](int index) const;


    friend bool operator>(const Order& lhs, const Order& rhs);
};

#endif
