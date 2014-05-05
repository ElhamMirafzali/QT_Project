#ifndef SENDSTUFFTOSHOP_H
#define SENDSTUFFTOSHOP_H

#include <QDialog>
#include <QMessageBox>

#include "database.h"

namespace Ui {
class SendStuffToShop;
}

class SendStuffToShop : public QDialog
{
    Q_OBJECT
    
public:
    explicit SendStuffToShop(QWidget *parent = 0);
    ~SendStuffToShop();
    void set_DB(DataBase db);
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::SendStuffToShop *ui;
    DataBase DB;
    QSqlQueryModel *model1 ;
    QSqlQueryModel *model2 ;
};

#endif // SENDSTUFFTOSHOP_H
