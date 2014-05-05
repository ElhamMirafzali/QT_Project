#ifndef BUYINGAGENCYDEFINEFORM_H
#define BUYINGAGENCYDEFINEFORM_H

#include <QDialog>
#include <QMessageBox>

#include "database.h"

namespace Ui {
class BuyingAgencyDefineForm;
}

class BuyingAgencyDefineForm : public QDialog
{
    Q_OBJECT
    
public:
    explicit BuyingAgencyDefineForm(QWidget *parent = 0);
    ~BuyingAgencyDefineForm();
    void set_DB(DataBase db);
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::BuyingAgencyDefineForm *ui;
    DataBase DB;
};

#endif // BUYINGAGENCYDEFINEFORM_H
