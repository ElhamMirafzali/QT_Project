#ifndef PRICINGGOODSFORM_H
#define PRICINGGOODSFORM_H

#include <QDialog>
#include <QMessageBox>

#include "database.h"

namespace Ui {
class PricingGoodsForm;
}

class PricingGoodsForm : public QDialog
{
    Q_OBJECT
    
public:
    explicit PricingGoodsForm(QWidget *parent = 0);
    ~PricingGoodsForm();
    void set_DB(DataBase db);
    QSqlQueryModel *model;
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::PricingGoodsForm *ui;
    DataBase DB;
};

#endif // PRICINGGOODSFORM_H
