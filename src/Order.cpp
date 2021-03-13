#include "Order.hpp"

using namespace std;

Order::Order(string inputString)
{
    // If the input string is not formatted correctly, reject it.
    if (inputString.length() != 17)
    {
        cerr << "There was an error when creating an order." << endl;
        exit(EXIT_FAILURE);
    }
    this->customerNumber = atoi((inputString.substr(10, 4)).c_str());
    this->shipmentDate = atoi((inputString.substr(1, 8)).c_str());
    this->shipmentQuantity = atoi((inputString.substr(14, 3)).c_str());
    this->type = inputString[9];
}

int Order::getQuantity()
{
    return this->shipmentQuantity;
}

int Order::getCustomerNumber()
{
    return this->customerNumber;
}

char Order::getType()
{
    return this->type;
}

int Order::getDate()
{
    return this->shipmentDate;
}
