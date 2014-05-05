#include "loginpage.h"
#include "mainwindow.h"
#include "database.h"
#include <QVector>
#include <QDebug>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DataBase MainDB("E:\\Univercity\\Advanced Programing\\Project\\QT\\HyperShop\\HyperShopDB");
    if (MainDB.openDataBase())
    {
        QVector<QString> users = MainDB.username_and_passwords();
        logInPage firstPage;
        MainWindow w;
        firstPage.set_DB(users);
        firstPage.exec();
        if (firstPage.validUser)
        {
            w.set_DB(MainDB);
            w.show();
        }
        else return 1;

        MainDB.closeDataBase();
        return a.exec();

    }
    return 0;
}
