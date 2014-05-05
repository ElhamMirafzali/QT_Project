#ifndef STAFFINTROFORM_H
#define STAFFINTROFORM_H

#include <QDialog>
#include <QMessageBox>

#include "database.h"
#include "staff.h"

namespace Ui {
class StaffIntroForm;
}

class StaffIntroForm : public QDialog
{
    Q_OBJECT
    
public:
    explicit StaffIntroForm(QWidget *parent = 0);
    ~StaffIntroForm();
    void set_DB(DataBase db);
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::StaffIntroForm *ui;
    DataBase DB;
};

#endif // STAFFINTROFORM_H
