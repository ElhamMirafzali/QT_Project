#ifndef STOREROOM_H
#define STOREROOM_H

#include "place.h"

class StoreRoom : public Place
{
public:
    StoreRoom();
    StoreRoom(QString nm, QString phoneN, QString add, QString cur, QString own);
};

#endif // STOREROOM_H
