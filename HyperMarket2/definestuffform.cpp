#include "definestuffform.h"
#include "ui_definestuffform.h"

#include <QMessageBox>

DefineStuffForm::DefineStuffForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DefineStuffForm)
{
    ui->setupUi(this);
    this->setFixedSize(400, 300);
    group_model = new QSqlQueryModel() ;
    store_model = new QSqlQueryModel() ;
}

DefineStuffForm::~DefineStuffForm()
{
    delete ui;
}

void DefineStuffForm::set_DB(DataBase db)
{
    db.openDataBase();
    DB = db;
    group_model->setQuery("select * from StuffGroups");
    ui->comboBox->setModel(group_model);
    store_model->setQuery("select Name from Store");
    ui->comboBox_2->setModel(store_model);
    ui->dateEdit->setDate(QDate::currentDate());
    ui->dateEdit_2->setDate(QDate::currentDate());
}

void DefineStuffForm::on_pushButton_clicked()
{
    if (!ui->lineEdit->text().isEmpty() &&
            !ui->lineEdit_2->text().isEmpty() &&
            !ui->lineEdit_3->text().isEmpty() &&
            !ui->lineEdit_4->text().isEmpty() &&
            !ui->lineEdit_5->text().isEmpty() &&
            !ui->lineEdit_6->text().isEmpty() &&
            !ui->lineEdit_7->text().isEmpty() &&
            ui->dateEdit->date() <= ui->dateEdit_2->date())
    {
        QSqlQuery qry;
        qry.prepare("select * from StuffList where Name=:n");
        int find = 0;
        qry.bindValue(":n", ui->lineEdit->text());
        if (qry.exec())
        {
            while (qry.next()) find++;
        }
        if (find>0) { QMessageBox::information(this, "خطا", "چنین کالایی وجود دارد");}
        else
        {
            Stuff a_stuff(ui->lineEdit->text(), ui->lineEdit_3->text().toInt(), ui->lineEdit_4->text().toInt(), ui->dateEdit->date(), ui->dateEdit_2->date(), ui->lineEdit_5->text(), ui->comboBox->currentText());
            if (DB.insert_Stuff(a_stuff, ui->lineEdit_2->text().toInt(), ui->lineEdit_6->text().toInt(), ui->lineEdit_7->text().toInt(), ui->comboBox_2->currentText()))
            {
                QMessageBox::information(this, "اوکی" , "کالای جدید ثبت شد");
                this->accept();
            }
            else
            {
                QMessageBox::information(this, "خطا" , "کالای جدید ثبت نشد! ");
            }
        }
    }
    else
    {
        QMessageBox::information(this, "خطا" , "فیلدی خالیست یا به درستی انتخاب نشده است");
    }
}
