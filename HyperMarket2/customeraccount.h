#ifndef CUSTOMERACCOUNT_H
#define CUSTOMERACCOUNT_H

#include <QDialog>

namespace Ui {
class CustomerAccount;
}

class CustomerAccount : public QDialog
{
    Q_OBJECT
    
public:
    explicit CustomerAccount(QWidget *parent = 0);
    ~CustomerAccount();
    
private:
    Ui::CustomerAccount *ui;
};

#endif // CUSTOMERACCOUNT_H
