#include "storeroom.h"

StoreRoom::StoreRoom()
{
}

StoreRoom::StoreRoom(QString nm, QString phoneN, QString add, QString cur, QString own)
{
    name = nm;
    phoneNumber = phoneN;
    address = add;
    Curator = cur;
    owner = own;
}
