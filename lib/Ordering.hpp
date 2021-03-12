#ifndef ORDERING_H
#define ORDERING_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Customer.hpp"
#include "Order.hpp"

void checkParams(int);
bool processOrder(Order*, std::vector<Customer *> &);
void shipAllOrders(std::vector<Customer *> &);

#endif