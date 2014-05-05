#include "staff.h"

Staff::Staff(QString FName, QString LName, int age,QString post_)
{
    fName = FName;
    lName = LName;
    staff_age = age;
    post = post_;
}

void Staff::set_DateOfContract(QDate date)
{
    dateOfContract = date;
}

void Staff::set_DurationOfContract(int y, int m)
{
    durationOfContract_years = y;
    DurationOfContract_month = m;
}

QString Staff::get_fName()
{
    return fName;
}

QString Staff::get_lName()
{
    return lName;
}

int Staff::get_staff_age()
{
    return staff_age;
}

QDate Staff::get_dateOfContract()
{
    return dateOfContract;
}

int Staff::get_durationOfContract_years()
{
    return durationOfContract_years;
}

int Staff::get_durationOfContract_month()
{
    return DurationOfContract_month;
}

QString Staff::get_post()
{
    return post;
}

