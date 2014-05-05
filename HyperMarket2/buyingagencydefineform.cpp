#include "buyingagencydefineform.h"
#include "ui_buyingagencydefineform.h"

BuyingAgencyDefineForm::BuyingAgencyDefineForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BuyingAgencyDefineForm)
{
    ui->setupUi(this);
}

BuyingAgencyDefineForm::~BuyingAgencyDefineForm()
{
    delete ui;
}

void BuyingAgencyDefineForm::set_DB(DataBase db)
{
    db.openDataBase();
    DB = db;
}

void BuyingAgencyDefineForm::on_pushButton_clicked()
{
    if (DB.insert_buyingAgency(ui->lineEdit->text(), ui->lineEdit_2->text(), ui->lineEdit_3->text(), ui->lineEdit_4->text(), ui->plainTextEdit->toPlainText()))
    {
        QMessageBox::information(this, "اوکی", "نمایندگی خرید ثبت شد");
        this->accept();
    }
    else
    {
        QMessageBox::information(this, "خطا", "نمایندگی خرید ثبت نشد");
    }
}
