#ifndef MINIMUMSTUFFSUPLYMANT_H
#define MINIMUMSTUFFSUPLYMANT_H

#include <QDialog>
#include <QMessageBox>

#include "database.h"

namespace Ui {
class MinimumStuffSuplymant;
}

class MinimumStuffSuplymant : public QDialog
{
    Q_OBJECT
    
public:
    explicit MinimumStuffSuplymant(QWidget *parent = 0);
    ~MinimumStuffSuplymant();
    void set_DB(DataBase db);
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::MinimumStuffSuplymant *ui;
    DataBase DB;
    QSqlQueryModel *stuffModel;
    QSqlQueryModel *model;
};

#endif // MINIMUMSTUFFSUPLYMANT_H
