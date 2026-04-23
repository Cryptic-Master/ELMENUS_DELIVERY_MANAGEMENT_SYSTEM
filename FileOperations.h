#ifndef FILEOPERATIONS_H
#define FILEOPERATIONS_H
class Order;
class DeliveryDriver;
void saveCompletedOrders(Order* orders[], int orderCount);
void saveDriverStats(DeliveryDriver* drivers[], int driverCount);
#endif
