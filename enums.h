#ifndef ENUMS_H
#define ENUMS_H
enum OrderStatus {
    PENDING,
    PREPARING,
    OUT_FOR_DELIVERY,
    DELIVERED,
    CANCELLED,
};
enum UserType {
    CUSTOMER,
    DRIVER,
};
#endif //ENUMS_H
