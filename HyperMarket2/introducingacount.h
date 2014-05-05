#ifndef INTRODUCINGACOUNT_H
#define INTRODUCINGACOUNT_H

#include <QDialog>
#include <QMessageBox>

#include "database.h"

namespace Ui {
class IntroducingAcount;
}

class IntroducingAcount : public QDialog
{
    Q_OBJECT
    
public:
    explicit IntroducingAcount(QWidget *parent = 0);
    ~IntroducingAcount();
    void set_DB(DataBase db);
    QSqlQueryModel *model;
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::IntroducingAcount *ui;
    DataBase DB;
};

#endif // INTRODUCINGACOUNT_H
