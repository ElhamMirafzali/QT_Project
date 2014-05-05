#ifndef PLACE_H
#define PLACE_H

#include <QString>

class Place
{
public:
    QString name;
    QString address;
    QString phoneNumber;
    QString owner;
    QString Curator;

public:
    Place();
    Place(QString name, QString addr ,QString phoneN, QString owner_name, QString curator_name) ;
    void set_phoneNumber(QString number);
    void set_address(QString adrss);
    QString get_name();
    QString get_address();
    QString get_phoneNumber();
    QString get_owner();
    QString get_Curator();
};

#endif // PLACE_H
