#include "Ordering.hpp"

void checkParams(int amountOfArgs)
{
    if (amountOfArgs != 2)
    {
        printf("%s\n", "There are not enough parameters.");
        printf("%s\n", "./Ordering [inputFile]");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char const *argv[])
{
    // Check that an input file has been specified.
    checkParams(argc);

    bool endOfDay = false;
    vector<Customer *> Customers;

    string filename = argv[1];
    ifstream inputFile(filename);

    // Use a while loop to get the text from the input file line by line,
    // and store that in tempStr.
    char firstChar;
    string line;
    while (getline(inputFile, line))
    {
        firstChar = line[0];
        switch (firstChar)
        {
        // The case where the line represents a new customer.
        case 'C':
        {
            Customer *newCustomer = new Customer(line);
            Customers.push_back(newCustomer);
            printf("OP: customer %04d added\n", newCustomer->getCustomerNumber());
            break;
        }

        // The case where the line represents a sales order.
        case 'S':
        {
            Order *newOrder = new Order(line);
            for (Customer *customer : Customers)
            {
                if (customer->getCustomerNumber() == newOrder->getCustomerNumber())
                {
                    customer->setDate(newOrder->getDate());
                    if (newOrder->getType() == 'X')
                    {
                        printf("OP: customer %04d: EXPRESS order: quantity %d.\n", newOrder->getCustomerNumber(), newOrder->getQuantity());
                        customer->add(newOrder);
                        printf("OP: customer %04d: shipped quantity %d\n",
                               customer->getCustomerNumber(), customer->getAmountOrdered());
                        customer->shipOrder();
                    }
                    else
                    {
                        printf("OP: customer %04d: normal order: quantity %d.\n", newOrder->getCustomerNumber(), newOrder->getQuantity());
                        customer->add(newOrder);
                    }
                }
            }
            delete newOrder;
            break;
        }

        // The case where the line represents the end of day.
        case 'E':
        {
            string date = line.substr(1, string::npos);
            printf("OP: end of day %s\n", date.c_str());
            endOfDay = true;
            break;
        }

        // If the first character is none of the above, it is an invalid choice.
        default:
            printf("%s.\n", "Invalid option");
        }

        if (endOfDay)
        {
            for (Customer *customer : Customers)
            {
                if (customer->getAmountOrdered() > 0)
                {
                    printf("OP: customer %04d: shipped quantity %d\n",
                           customer->getCustomerNumber(), customer->getAmountOrdered());
                    customer->shipOrder();
                }
            }
            endOfDay = false;
        }
    }

    for (Customer *customer : Customers)
    {
        delete customer;
    }

    inputFile.close();
    return 0;
}
