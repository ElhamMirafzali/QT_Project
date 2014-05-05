#ifndef DEFINESTUFFFORM_H
#define DEFINESTUFFFORM_H

#include <QDialog>

#include "database.h"
#include "stuff.h"

namespace Ui {
class DefineStuffForm;
}

class DefineStuffForm : public QDialog
{
    Q_OBJECT
    
public:
    explicit DefineStuffForm(QWidget *parent = 0);
    ~DefineStuffForm();
    void set_DB(DataBase db);
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::DefineStuffForm *ui;
    QSqlQueryModel *group_model;
    QSqlQueryModel *store_model;
    DataBase DB;
};

#endif // DEFINESTUFFFORM_H
