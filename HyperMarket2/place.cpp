#include "place.h"

Place::Place()
{
}

Place::Place(QString name, QString addr, QString phoneN, QString owner_name, QString curator_name)
{
    name = name;
    address = addr;
    phoneNumber = phoneN;
    owner = owner_name;
    Curator = curator_name;
}

void Place::set_phoneNumber(QString number)
{
    phoneNumber = number;
}

void Place::set_address(QString adrss)
{
    address = adrss;
}

QString Place::get_name()
{
    return name;
}

QString Place::get_address()
{
    return address;
}

QString Place::get_phoneNumber()
{
    return phoneNumber;
}

QString Place::get_owner()
{
    return owner;
}

QString Place::get_Curator()
{
    return Curator;
}
