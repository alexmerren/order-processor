#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <iostream>
#include <string>

#include "Order.hpp"

class Customer
{
    int customerNumber;
    int amountOrdered;
    int date;
    static int invoiceNumber;
    std::string customerName;

public:
    Customer(std::string);

    int getCustomerNumber();
    int getAmountOrdered();

    void setDate(int);

    void shipOrder();
    friend void operator+=(Customer&, Order*);
    void str();
};

#endif