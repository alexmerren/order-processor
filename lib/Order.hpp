#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <string>
#include <exception>

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
    void str();
};

#endif