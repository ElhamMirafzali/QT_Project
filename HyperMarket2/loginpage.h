#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QDialog>

namespace Ui {
class logInPage;
}

class logInPage : public QDialog
{
    Q_OBJECT
    
public:
    explicit logInPage(QWidget *parent = 0);
    ~logInPage();
    bool userNamePassword();
    QVector<QString> userPass;
    void set_DB(QVector<QString> db);
    bool validUser;
    
private slots:
    void on_Enter_clicked();

private:
    Ui::logInPage *ui;
    QVector<QString> DataBase;
};

#endif // LOGINPAGE_H
