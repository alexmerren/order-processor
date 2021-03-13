#ifndef ORDER_H_
#define ORDER_H_

#include <iostream>
#include <string>

class Order
{
    int customerNumber;
    int shipmentDate;
    int shipmentQuantity;
    char type;
public:
    Order(std::string);
    int getQuantity();
    int getCustomerNumber();
    char getType();
    int getDate();
};

#endif // ORDER_H_