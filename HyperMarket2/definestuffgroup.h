#ifndef DEFINESTUFFGROUP_H
#define DEFINESTUFFGROUP_H

#include "database.h"

#include <QDialog>

namespace Ui {
class DefineStuffGroup;
}

class DefineStuffGroup : public QDialog
{
    Q_OBJECT
    
public:
    explicit DefineStuffGroup(QWidget *parent = 0);
    ~DefineStuffGroup();
    void set_DB(DataBase db);
    
private slots:
    void on_Submit_clicked();

private:
    Ui::DefineStuffGroup *ui;
    DataBase DB;
    QSqlQueryModel * model;
};

#endif // DEFINESTUFFGROUP_H
