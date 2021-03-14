#include "Customer.hpp"

using namespace std;

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

// Number for the next invoice.
int Customer::invoiceNumber{1000};

int Customer::getCustomerNumber()
{
    return this->customerNumber;
}

int Customer::getAmountOrdered()
{
    return this->amountOrdered;
}

void Customer::setDate(int date)
{
    this->date = date;
}

void Customer::shipOrder()
{
    cout << "SC: customer " << setw(4) << setfill('0') << customerNumber
         << ", invoice " << invoiceNumber++
         << ", date " << date
         << ", quantity " << amountOrdered << endl;
    cout << "OP: customer " << setw(4) << setfill('0') << customerNumber
         << ": shipped quantity " << amountOrdered << endl;
    this->amountOrdered = 0;
}

void operator+=(Customer &customer, Order *order)
{
    customer.amountOrdered += order->getQuantity();
}
