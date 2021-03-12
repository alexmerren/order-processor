#include <iostream>
#include <string>
#include <exception>

using namespace std;

class Order
{
    int customerNumber;
    int shipmentDate;
    int shipmentQuantity;
    char type;

public:
    Order(string);
    ~Order();

    int getQuantity();
    int getCustomerNumber();
    char getType();
    int getDate();

    void str();
};