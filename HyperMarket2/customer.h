#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "human.h"

class Customer : public Human
{
private:
    int id;
    int state;

public:
    Customer(int id_);
    void change_state(int amountOfChange);
};

#endif // CUSTOMER_H
