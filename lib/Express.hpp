#include "Order.hpp"

class Express : public Order
{
public:
    Express(const Order &);
    ~Express();
    string outputMessage();
};
