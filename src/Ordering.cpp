#include "Ordering.hpp"

using namespace std;

/**
 * Usage: ./orderings [inputFile]
 * */
int main(int argc, char const *argv[])
{
    checkParams(argc);

    bool endOfDay = false;
    vector<Customer *> allCustomers;

    string filename = argv[1];
    ifstream inputFile(filename);
    // If there is an error creating the input file stream, exit the program.
    if (!inputFile)
    {
        cerr << "Failed to open the input file." << endl;
        return EXIT_FAILURE;
    }

    // Get each line from the input file and store the contents in the line variable.
    string line;
    while (getline(inputFile, line))
    {
        // Process each line
        endOfDay = processLine(line, allCustomers);
        if (endOfDay)
            shipAllOrders(allCustomers);
        endOfDay = false;
    }

    // Free up the memory for exiting the program.
    for (Customer *customer : allCustomers)
        delete customer;

    inputFile.close();
    return EXIT_SUCCESS;
}

/**
 * Check the amount of parameters is right for the functionality of the program.
 * */
void checkParams(const int amountOfArgs)
{
    if (amountOfArgs != 2)
    {
        cerr << "Not enough parameters to run program." << endl;
        cout << "Please use the following structure: ./ordering [inputFile]" << endl;
        exit(EXIT_FAILURE);
    }
}

/**
 * Process a line with the different types of records in the input file.
 * */
bool processLine(string line, vector<Customer *> &allCustomers)
{
    char firstChar = line[0];
    if (firstChar == 'E')
    {
        string date = line.substr(1);
        cout << "OP: End of day " << date << endl;
        return true;
    }
    else if (firstChar == 'C')
    {
        Customer *newCustomer = new Customer(line);
        allCustomers.push_back(newCustomer);
        cout << "OP: customer " << setw(4) << setfill('0') << newCustomer->getCustomerNumber() << " added" << endl;
    } 
    else if (firstChar == 'S')
    {
        Order *newOrder = new Order(line);
        // If the order cannot be processed, for any reason, then exit the program.
        if (!processOrder(newOrder, allCustomers))
        {
            cerr << "There was an invalid order." << endl;
            exit(EXIT_FAILURE);
        }
        // Free up  memory as the order no longer needs to be accessed.
        delete newOrder;
    }
    else
    {
        cerr << "Invalid formatting of line." << endl;
        exit(EXIT_FAILURE);
    }
    return false;
}

/**
 * Process an order and check whether it is an express or normal order.
 * */
bool processOrder(Order *newOrder, const vector<Customer *> &allCustomers)
{
    for (Customer *customer : allCustomers)
    {
        if (customer->getCustomerNumber() == newOrder->getCustomerNumber())
        {
            customer->setDate(newOrder->getDate());
            // Add the quantity ordered in the order to the relevant customer.
            *customer += newOrder;
            string type;
            if (newOrder->getType() == 'X')
            {
                // Condition for an express order.
                type = "EXPRESS";
                customer->shipOrder();
            }
            else 
            {
                // Condition for a normal order.
                type = "normal";
            }
            cout << "OP: customer " << setw(4) << setfill('0') << newOrder->getCustomerNumber()
                 << " " << type << " order: " 
                 << "quantity " << newOrder->getQuantity() << endl;
            return true;
        }
    }
    return false;
}

/**
 * Ship all the orders that meet a criteria at the end of a given day.
 * */
void shipAllOrders(const vector<Customer *> &allCustomers)
{
    // Process all customers who have an amount ordered above 0.
    for (Customer *customer : allCustomers)
    {
        if (customer->getAmountOrdered() > 0)
            customer->shipOrder();
    }
}
