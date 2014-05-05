#include "human.h"

Human::Human()
{
}

Human::Human(QString FName, QString LName, int age)
{
    firstName = FName;
    lastName = LName;
    this->age = age;
}

void Human::set_phoneNumber(QString number)
{
    phoneNumber = number;
}

void Human::set_address(QString adrss)
{
    address = adrss;
}

QString Human::get_firstName()
{
    return firstName;
}

QString Human::get_lastName()
{
    return lastName;
}

int Human::get_age()
{
    return age;
}

QString Human::get_phoneNumber()
{
    return phoneNumber;
}

QString Human::get_address()
{
    return address;
}

