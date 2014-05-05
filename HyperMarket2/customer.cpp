#include "customer.h"

Customer::Customer(int id_)
{
    id = id_;
    state = 0;
}

void Customer::change_state(int amountOfChange)
{
    state += amountOfChange;
}
