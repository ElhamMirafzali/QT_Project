#include "staffintroform.h"
#include "ui_staffintroform.h"

StaffIntroForm::StaffIntroForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StaffIntroForm)
{
    ui->setupUi(this);
    this->setFixedSize(392, 352);
    ui->dateEdit->setDate(QDate::currentDate());
}

StaffIntroForm::~StaffIntroForm()
{
    delete ui;
}

void StaffIntroForm::set_DB(DataBase db)
{
    db.openDataBase();
    DB = db;
}

void StaffIntroForm::on_pushButton_clicked()
{
    if (!ui->lineEdit->text().isEmpty() &&
            !ui->lineEdit_2->text().isEmpty() &&
            !ui->lineEdit_3->text().isEmpty() &&
            !ui->lineEdit_4->text().isEmpty() &&
            !ui->lineEdit_5->text().isEmpty() &&
            !ui->lineEdit_6->text().isEmpty() &&
            !ui->lineEdit_7->text().isEmpty() &&
            !ui->plainTextEdit->toPlainText().isEmpty())
    {
        QSqlQuery qry;
        qry.prepare("select * from People where FirstName=:n and LastName=:l");
        int find = 0;
        qry.bindValue(":n", ui->lineEdit->text());
        qry.bindValue(":l", ui->lineEdit_2->text());
        if (qry.exec())
        {
            while (qry.next()) find++;
        }
        if (find>0) { QMessageBox::information(this, "خطا", "چنین شخصی قبلا استخدام شده است");}
        else
        {
            Staff a_staff(ui->lineEdit->text(), ui->lineEdit_2->text(), ui->lineEdit_3->text().toInt(), ui->lineEdit_5->text());
            a_staff.set_address(ui->plainTextEdit->toPlainText());
            a_staff.set_phoneNumber(ui->lineEdit_4->text());
            a_staff.set_DateOfContract(ui->dateEdit->date());
            a_staff.set_DurationOfContract(ui->lineEdit_6->text().toInt(), ui->lineEdit_7->text().toInt());
            if (DB.insert_Staff(a_staff))
            {
                QMessageBox::information(this, "اوکی" , "استخدام انجام شد");
                this->accept();
            }
            else
            {
                QMessageBox::information(this, "خطا" , "قرارداد ثبت نشد! ");
            }
        }
    }
    else
    {
        QMessageBox::information(this, "خطا" , "فیلدی خالیست یا به درستی انتخاب نشده است");
    }
}
