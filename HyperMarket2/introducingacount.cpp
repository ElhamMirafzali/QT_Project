#include "introducingacount.h"
#include "ui_introducingacount.h"

IntroducingAcount::IntroducingAcount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IntroducingAcount)
{
    ui->setupUi(this);
    ui->comboBox->addItem("جاری");
    ui->comboBox->addItem("پس انداز");
    ui->comboBox->addItem("سپرده کوتاه مدت");
    ui->comboBox->addItem("سپرده بلند مدت");
    model = new QSqlQueryModel();
}

IntroducingAcount::~IntroducingAcount()
{
    delete ui;
}

void IntroducingAcount::set_DB(DataBase db)
{
    db.openDataBase();
    DB = db;
    model->setQuery("select * from Account");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("صاحب حساب"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("نام بانک"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("شماره حساب"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("نوع حساب"));
    ui->tableView->setModel(model);
}

void IntroducingAcount::on_pushButton_clicked()
{
    if (!ui->lineEdit->text().isEmpty() &&
            !ui->lineEdit_2->text().isEmpty() &&
            !ui->lineEdit_3->text().isEmpty())
    {
        QSqlQuery qry;
        qry.prepare("select * from Account where AccountNumber=:n");
        int find = 0;
        qry.bindValue(":n", ui->lineEdit_3->text());
        if (qry.exec())
        {
            while (qry.next()) find++;
        }
        if (find>0) { QMessageBox::information(this, "خطا", "چنین حسابی وجود دارد");}
        else
        {
            QVector<QString> acc;
            acc.push_back(ui->lineEdit->text());
            acc.push_back(ui->lineEdit_2->text());
            acc.push_back(ui->lineEdit_3->text());
            acc.push_back(ui->comboBox->currentText());
            if (DB.insert_Account(acc))
            {
                QMessageBox::information(this, "اوکی" , "حساب جدید ثبت شد");
                this->accept();
            }
            else
            {
                QMessageBox::information(this, "خطا" , "حساب جدید ثبت نشد! ");
            }
        }
    }
    else
    {
        QMessageBox::information(this, "خطا" , "فیلدی خالیست یا به درستی انتخاب نشده است");
    }
}
