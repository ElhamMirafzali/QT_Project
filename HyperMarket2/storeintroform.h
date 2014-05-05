#ifndef STOREINTROFORM_H
#define STOREINTROFORM_H

#include <QDialog>
#include <QMessageBox>

#include "database.h"
#include "storeroom.h"

namespace Ui {
class StoreIntroForm;
}

class StoreIntroForm : public QDialog
{
    Q_OBJECT
    
public:
    explicit StoreIntroForm(QWidget *parent = 0);
    ~StoreIntroForm();
    void set_DB(DataBase db);
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::StoreIntroForm *ui;
    DataBase DB;
    QSqlQueryModel *model;
};

#endif // STOREINTROFORM_H
