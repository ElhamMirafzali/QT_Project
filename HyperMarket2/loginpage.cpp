#include "loginpage.h"
#include "ui_loginpage.h"
#include <QVector>
#include <QDebug>
#include <QMessageBox>

logInPage::logInPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::logInPage)
{
    ui->setupUi(this);
    validUser = false;
    this->setFixedSize(400, 300);
}

logInPage::~logInPage()
{
    delete ui;
}

void logInPage::set_DB(QVector<QString> db)
{
    DataBase = db;
}

bool logInPage::userNamePassword()
{
    userPass.push_back(ui->UserNameLineEdit->text());
    userPass.push_back(ui->PasswordLineEdit->text());
    for (int i = 0; i < DataBase.size(); i+=2)
    {
        if (userPass[0] == DataBase[i] && userPass[1] == DataBase[i+1]) return true;
    }
    return false;
}

void logInPage::on_Enter_clicked()
{
    validUser = this->userNamePassword();
    if (validUser)
    {
        this->accept();
    }
    else
    {
        QMessageBox::information(this, "خطا", "نام کاربری یا رمز وارد شده اشتباه است");
        ui->UserNameLineEdit->clear();
        ui->PasswordLineEdit->clear();
        userPass.clear();
    }
}
