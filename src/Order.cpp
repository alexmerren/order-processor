#include "Order.hpp"

// Constructor
Order::Order(string inputString)
{
    try
    {
        // If the input string is not formatted correctly, reject it.
        if (inputString.length() != 17)
            throw exception();
    }
    catch (exception)
    {
        printf("There was an error with creating an order.\n");
        exit(EXIT_FAILURE);
    }

    this->customerNumber = atoi((inputString.substr(10, 4)).c_str());
    this->shipmentDate = atoi((inputString.substr(1, 8)).c_str());
    this->shipmentQuantity = atoi((inputString.substr(14, 3)).c_str());
    this->type = inputString[9];
}

// Destructor
Order::~Order()
{
}

// Get methods
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

// Auxilliary Methods
void Order::str()
{
    printf("Customer number: %04d, Amount ordered: %d\n",
           this->customerNumber, this->shipmentQuantity);
}
