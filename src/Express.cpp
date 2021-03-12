#include "Express.hpp"

Express::Express(const Order &)
{
}

Express::~Express()
{}

string Express::outputMessage()
{
    char* str;
    sprintf(str, "%s\n", "Heck"); 
    return str;
}
