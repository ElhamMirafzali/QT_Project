#ifndef FACTOR_H
#define FACTOR_H

#include <QDialog>
#include <QMessageBox>

#include "database.h"
#include "factorprint.h"

namespace Ui {
class Factor;
}

class Factor : public QDialog
{
    Q_OBJECT
    
public:
    explicit Factor(QWidget *parent = 0);
    ~Factor();
    void set_DB(DataBase db);
    
private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Factor *ui;
    DataBase DB;
    FactorPrint *factor_print;
    QSqlQueryModel *stuff_model;
    QSqlQueryModel *table_model;
    int total_buy_price, total_sell_price;
};

#endif // FACTOR_H
