#ifndef DATABASE_H
#define DATABASE_H


#include "stuff.h"
#include "staff.h"
#include "storeroom.h"
#include <QtSql>
#include <QVector>
#include <QMessageBox>

class DataBase
{
private:
    QString path;

public:
    DataBase();
    DataBase(QString pth);
    QSqlDatabase db;
    bool openDataBase();
    QVector<QString> username_and_passwords();
    QVector<QString> StuffGroupsVector();
    void closeDataBase();
    bool insert_StuffGroup(QString name);
    bool insert_Stuff(Stuff a_stuff, int num, int min, int minShop, QString loc);
    bool insert_Store(StoreRoom a_store);
    bool insert_Staff(Staff a_staff);
    bool insert_Account(QVector<QString> account);
    bool insert_buyingAgency(QString fn, QString ln, QString id, QString ph, QString ad);
    bool insert_factor(int id, QString cname, int price);
    bool insert_factors(int id, QString stuff, int num, int price);
    bool delete_factors(int id, QString stuff, int num);
};

#endif // DATABASE_H
