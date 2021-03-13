#ifndef ORDERING_H_
#define ORDERING_H_

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Customer.hpp"
#include "Order.hpp"

void checkParams(int);
bool processLine(std::string, std::vector<Customer *> &);
bool processOrder(Order*, std::vector<Customer *> &);
void shipAllOrders(std::vector<Customer *> &);

#endif // ORDERING_H_