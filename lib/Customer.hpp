#include <iostream>
#include <string>

#include "Order.hpp"

using namespace std;

class Customer
{
    int customerNumber;
    int amountOrdered;
    int date;
    static int invoiceNumber;
    string customerName;

public:
    Customer(string);
    ~Customer();

    int getCustomerNumber();
    int getAmountOrdered();

    void setDate(int);

    void shipOrder();
    void add(Order *);
    void str();
};