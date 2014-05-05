#include "stuff.h"

Stuff::Stuff(QString stuffname, int buyP, int sellP, QDate pDate, QDate eDate, QString productor, QString group)
{
    name = stuffname;
    buyPrice = buyP;
    sellPrice = sellP;
    productDate = pDate;
    expireDate = eDate;
    this->productor = productor;
    stuffGroup = group;
}

QString Stuff::get_name() { return name; }

int Stuff::get_buyPrice() { return buyPrice; }

int Stuff::get_sellPrice() { return sellPrice; }

QDate Stuff::get_productDate() { return productDate; }

QDate Stuff::get_expireDate() { return expireDate; }

QString Stuff::get_productor() { return productor; }

QString Stuff::get_stuffGroup() { return stuffGroup; }
