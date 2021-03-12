#include "Ordering.hpp"

using namespace std;

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
    vector<Customer *> allCustomers;

    string const FILENAME= argv[1];
    ifstream inputFile(FILENAME);
    if (!inputFile)
    {
        printf("%s\n", "Failed to open the input file, exiting...");
        return EXIT_FAILURE;
    }

    // Use a while loop to get the text from the input file line by line,
    // and store the line in the 'line' variable.
    char firstChar;
    string line;
    while (getline(inputFile, line))
    {
        firstChar = line[0];
        switch (firstChar)
        {
            case 'C':
            {
                // The case for a new customer record.
                Customer *newCustomer = new Customer(line);
                allCustomers.push_back(newCustomer);
                printf("OP: customer %04d added\n", newCustomer->getCustomerNumber());
                break;
            }
            case 'S':
            {
                // The case for a new order record.
                Order *newOrder = new Order(line);
                if (!processOrder(newOrder, allCustomers))
                {
                    // If the order cannot be processed, for any reason, 
                    // then exit the program.
                    printf("%s\n", "There was an invalid order., exiting...");
                    return EXIT_FAILURE;
                }
                delete newOrder;
                break;
            }
            case 'E':
            {
                // The case for an end-of-day record.
                string date = line.substr(1);
                printf("OP: end of day %s\n", date.c_str());
                endOfDay = true;
                break;
            }
            default:
            {
                // The case where it's none of the options.
                printf("%s.\n", "Invalid option, exiting...");
                return EXIT_FAILURE;
            }
        }

        if (endOfDay)
        {
            shipAllOrders(allCustomers);
            endOfDay = false;
        }
    }

    for (Customer *customer : allCustomers)
        delete customer;

    inputFile.close();
    return EXIT_SUCCESS;
}

bool processOrder(Order *newOrder, vector<Customer *> &allCustomers)
{
    for (Customer *customer : allCustomers)
    {
        if (customer->getCustomerNumber() == newOrder->getCustomerNumber())
        {
            customer->setDate(newOrder->getDate());
            if (newOrder->getType() == 'X')
            {
                // Condition for an express order.
                printf("OP: customer %04d: EXPRESS order: quantity %d.\n",
                        newOrder->getCustomerNumber(), newOrder->getQuantity());
                printf("OP: customer %04d: shipped quantity %d\n",
                        customer->getCustomerNumber(), customer->getAmountOrdered());
                *customer += newOrder;
                customer->shipOrder();
            }
            else 
            {
                // Condition for a normal order.
                printf("OP: customer %04d: normal order: quantity %d.\n",
                        newOrder->getCustomerNumber(), newOrder->getQuantity());
                *customer += newOrder;
            }
            return true;
        }
    }
    return false;
}

void shipAllOrders(vector<Customer *> &allCustomers)
{
    for (Customer *customer : allCustomers)
    {
        if (customer->getAmountOrdered() > 0)
        {
            printf("OP: customer %04d: shipped quantity %d\n",
                   customer->getCustomerNumber(), customer->getAmountOrdered());
            customer->shipOrder();
        }
    }
}
