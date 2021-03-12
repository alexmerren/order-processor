#ifndef ORDERING_H_
#define ORDERING_H_

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Customer.hpp"

void checkParams(int);
bool processOrder(Order*, std::vector<Customer *> &);
void shipAllOrders(std::vector<Customer *> &);

#endif