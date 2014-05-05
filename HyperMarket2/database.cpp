#include "database.h"
#include "stuff.h"
#include <QVector>
#include <QtSql>
#include <QDebug>

DataBase::DataBase()
{
}

DataBase::DataBase(QString pth)
{
    path = pth;
}

bool DataBase::openDataBase()
{

    db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName(path);

    if (db.open())
    {
        return true;
    }
    else return false;
}

void DataBase::closeDataBase()
{
    db.close();
}

QVector<QString> DataBase::username_and_passwords()
{
    QVector<QString> Username_and_Password;
    QSqlQuery qry;
    if(qry.exec("select * from Users"))
    {
        while (qry.next())
        {
            Username_and_Password.push_back(qry.value(1).toString());
            Username_and_Password.push_back(qry.value(2).toString());
        }
    }
    return Username_and_Password;
}

QVector<QString> DataBase::StuffGroupsVector()
{
    QVector<QString> stuffGroups;
    QSqlQuery qry;
    if(qry.exec("select * from StuffGroups"))
    {
        while (qry.next())
        {
            stuffGroups.push_back(qry.value(1).toString());
        }
    }
    return stuffGroups;
}

bool DataBase::insert_StuffGroup(QString name)
{
    QString sqry = "insert into StuffGroups values(:n)";
    QSqlQuery qry;
    qry.prepare(sqry);
    qry.bindValue(":n", name);
    return qry.exec();
}

bool DataBase::insert_Stuff(Stuff a_stuff, int num, int minStore, int minShop, QString loc)
{
    QString sqry = "insert into StuffList values(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?);";
    QSqlQuery qry;
    qry.prepare(sqry);
    qry.addBindValue(a_stuff.get_name());
    qry.addBindValue(a_stuff.get_productDate());
    qry.addBindValue(a_stuff.get_expireDate());
    qry.addBindValue(a_stuff.get_buyPrice());
    qry.addBindValue(a_stuff.get_sellPrice());
    qry.addBindValue(a_stuff.get_productor());
    qry.addBindValue(a_stuff.get_stuffGroup());
    qry.addBindValue(num);
    qry.addBindValue(0);
    qry.addBindValue(minStore);
    qry.addBindValue(minShop);
    qry.addBindValue(loc);
    return qry.exec();
}

bool DataBase::insert_Store(StoreRoom a_store)
{
    QString sqry = "insert into Store values(?, ?, ?, ?, ?);";
    QSqlQuery qry;
    qry.prepare(sqry);
    qry.addBindValue(a_store.get_name());
    qry.addBindValue(a_store.get_phoneNumber());
    qry.addBindValue(a_store.get_address());
    qry.addBindValue(a_store.get_Curator());
    qry.addBindValue(a_store.get_owner());
    return qry.exec();
}

bool DataBase::insert_Staff(Staff a_staff)
{
    QString sqry = "insert into People values(?, ?, ?, ?, ?, ?, ?, ?, ?, 0);";
    QSqlQuery qry;
    qry.prepare(sqry);
    qry.addBindValue(a_staff.get_fName());
    qry.addBindValue(a_staff.get_lName());
    qry.addBindValue(a_staff.get_staff_age());
    qry.addBindValue(a_staff.get_phoneNumber());
    qry.addBindValue(a_staff.get_address());
    qry.addBindValue(a_staff.get_dateOfContract());
    qry.addBindValue(a_staff.get_durationOfContract_years());
    qry.addBindValue(a_staff.get_durationOfContract_month());
    qry.addBindValue(a_staff.get_post());
    return qry.exec();
}

bool DataBase::insert_Account(QVector<QString> account)
{
    QString sqry = "insert into Account values(?, ?, ?, ?);";
    QSqlQuery qry;
    qry.prepare(sqry);
    qry.addBindValue(account[0]);
    qry.addBindValue(account[1]);
    qry.addBindValue(account[2]);
    qry.addBindValue(account[3]);
    return qry.exec();
}

bool DataBase::insert_buyingAgency(QString fn, QString ln, QString id, QString ph, QString ad)
{
    QString sqry = "insert into BuyingAgency values(?, ?, ?, ?, ?);";
    QSqlQuery qry;
    qry.prepare(sqry);
    qry.addBindValue(fn);
    qry.addBindValue(ln);
    qry.addBindValue(id);
    qry.addBindValue(ph);
    qry.addBindValue(ad);
    return qry.exec();
}

bool DataBase::insert_factor(int id, QString cname,  int total_price)
{
    QString sqry = "insert into Factor values(?, ?, ?);";
    QSqlQuery qry;
    qry.prepare(sqry);
    qry.addBindValue(id);
    qry.addBindValue(cname);
    qry.addBindValue(total_price);
    return qry.exec();
}

bool DataBase::insert_factors(int id, QString stuff, int num, int price)
{
    QString sqry = "insert into Factors values(?, ?, ?, ?, ?);";
    QSqlQuery qry;
    qry.prepare(sqry);
    qry.addBindValue(id);
    qry.addBindValue(stuff);
    qry.addBindValue(num);
    qry.addBindValue(price);
    qry.addBindValue(num*price);
    return qry.exec();
}

bool DataBase::delete_factors(int id, QString stuff, int num)
{
    QString sqry = "delete from Factors WHERE ID=:i and StuffName=:s and Number=:n";
    QSqlQuery qry;
    qry.prepare(sqry);
    qry.bindValue(":i", id);
    qry.bindValue(":s", stuff);
    qry.bindValue(":n", num);
    return qry.exec();
}
