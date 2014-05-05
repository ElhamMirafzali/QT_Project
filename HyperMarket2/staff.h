#ifndef STAFF_H
#define STAFF_H

#include "human.h"

#include <QDate>

class Staff : public Human
{
private:
    QString fName;
    QString lName;
    int staff_age;
    QString post;
    QDate dateOfContract;
    int durationOfContract_years, DurationOfContract_month;

public:
    Staff(QString FName, QString LName, int age,QString post_);
    void set_DateOfContract(QDate date);
    void set_DurationOfContract(int y, int m);
    QString get_fName();
    QString get_lName();
    int get_staff_age();
    QDate get_dateOfContract();
    int get_durationOfContract_years();
    int get_durationOfContract_month();
    QString get_post();
};

#endif // STAFF_H
