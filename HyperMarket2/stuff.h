#ifndef STUFF_H
#define STUFF_H

#include <QString>
#include <QDate>
#include <QLabel>

class Stuff
{

private:
    QString name;
    int buyPrice;
    int sellPrice;
    QDate productDate;
    QDate expireDate;
    QString productor;
    QString stuffGroup;

public:
    Stuff(QString stuffname);
    Stuff(QString, int, int, QDate, QDate, QString, QString);
    int set_sellPrice();
    QString get_name();
    int get_buyPrice();
    int get_sellPrice();
    QDate get_productDate();
    QDate get_expireDate();
    QString get_productor();
    QString get_stuffGroup();
};

#endif // STUFF_H
