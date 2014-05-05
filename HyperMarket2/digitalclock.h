#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H

#include <QLCDNumber>

//! [0]
class DigitalClock : private QLCDNumber
{
    Q_OBJECT

public:
    DigitalClock(QWidget *parent = 0);

private slots:
    void showTime();
};
//! [0]

#endif
