#ifndef ORDER_H_
#define ORDER_H_

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