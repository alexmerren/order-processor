#ifndef EXPRESS_H
#define EXPRESS_H

#include "Order.hpp"

class Express : public Order
{
public:
    Express(const Order &);
    ~Express();
    string outputMessage();
};

#endif