#include "storeintroform.h"
#include "ui_storeintroform.h"

StoreIntroForm::StoreIntroForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StoreIntroForm)
{
    ui->setupUi(this);
    model = new QSqlQueryModel;
}

StoreIntroForm::~StoreIntroForm()
{
    delete ui;
}

void StoreIntroForm::set_DB(DataBase db)
{
    db.openDataBase();
    DB = db;
    model->setQuery("select * from Store");
    ui->listView->setModel(model);
}

void StoreIntroForm::on_pushButton_clicked()
{
    if (!ui->lineEdit->text().isEmpty() &&
            !ui->lineEdit_2->text().isEmpty() &&
            !ui->lineEdit_3->text().isEmpty() &&
            !ui->lineEdit_4->text().isEmpty() &&
            !ui->lineEdit_5->text().isEmpty())
    {
        QSqlQuery qry;
        qry.prepare("select * from Store where Name=:n");
        int find = 0;
        qry.bindValue(":n", ui->lineEdit->text());
        if (qry.exec())
        {
            while (qry.next()) find++;
        }
        if (find>0) { QMessageBox::information(this, "خطا", "چنین انباری وجود دارد");}
        else
        {
            StoreRoom a_store(ui->lineEdit->text(), ui->lineEdit_2->text(), ui->lineEdit_3->text(), ui->lineEdit_4->text(), ui->lineEdit_5->text());
            if (DB.insert_Store(a_store))
            {
                QMessageBox::information(this, "اوکی" , "انبار جدید ثبت شد");
                this->accept();
            }
            else
            {
                QMessageBox::information(this, "خطا" , "انبار جدید ثبت نشد! ");
            }
        }
    }
    else
    {
        QMessageBox::information(this, "خطا" , "فیلدی خالیست یا به درستی انتخاب نشده است");
    }
}
