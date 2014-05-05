#ifndef SENDSTUFFTOSTORE_H
#define SENDSTUFFTOSTORE_H

#include <QDialog>
#include <QMessageBox>

#include "database.h"

namespace Ui {
class SendStuffToStore;
}

class SendStuffToStore : public QDialog
{
    Q_OBJECT
    
public:
    explicit SendStuffToStore(QWidget *parent = 0);
    ~SendStuffToStore();
    void set_DB(DataBase db);
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::SendStuffToStore *ui;
    DataBase DB;
    QSqlQueryModel *stuff_model;
    QSqlQueryModel *strStore_model;
    QSqlQueryModel *desStore_model;
};

#endif // SENDSTUFFTOSTORE_H
