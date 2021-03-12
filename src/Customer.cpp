#include "Customer.hpp"

using namespace std;

// Parameterised Constructor
Customer::Customer(string inputString)
{
    // Get a substring of the input string where the customer number is.
    // Convert that substring into a const char* then get the number
    // from that const char*.
    this->customerNumber = atoi((inputString.substr(1, 4)).c_str());
    this->customerName = inputString.substr(5, string::npos);
    this->amountOrdered = 0;
    this->date = 0;
}

// Set the starting number for invoices, to be shared with all objects.
int Customer::invoiceNumber{1000};

// Get methods
int Customer::getCustomerNumber()
{
    return this->customerNumber;
}

int Customer::getAmountOrdered()
{
    return this->amountOrdered;
}

// Set methods
void Customer::setDate(int date)
{
    this->date = date;
}

// Auxiliary Methods
void Customer::shipOrder()
{
    printf("SC: customer %04d, invoice %d, date %d, quantity %d\n",
           customerNumber, invoiceNumber++, date, amountOrdered);
    this->amountOrdered = 0;
}

void operator+=(Customer &customer, Order *order)
{
    customer.amountOrdered += order->getQuantity();
}

void Customer::str()
{
    printf("Customer number: %04d, Customer name: %s, Current order: %d.\n",
           this->customerNumber, (this->customerName).c_str(), this->amountOrdered);
}
