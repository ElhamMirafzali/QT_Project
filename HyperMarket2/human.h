#ifndef HUMAN_H
#define HUMAN_H

#include <QString>

class Human
{
private:
    QString firstName;
    QString lastName;
    int age;
    QString phoneNumber;
    QString address;

public:
    Human();
    Human(QString FName, QString LName, int age);
    void set_phoneNumber(QString number);
    void set_address(QString adrss);
    QString get_firstName();
    QString get_lastName();
    int get_age();
    QString get_phoneNumber();
    QString get_address();
};

#endif // HUMAN_H
