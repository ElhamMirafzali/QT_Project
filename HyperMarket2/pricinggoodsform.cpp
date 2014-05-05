#include "pricinggoodsform.h"
#include "ui_pricinggoodsform.h"

PricingGoodsForm::PricingGoodsForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PricingGoodsForm)
{
    this->setFixedSize(397, 134);
    ui->setupUi(this);
    model = new QSqlQueryModel();
}

PricingGoodsForm::~PricingGoodsForm()
{
    delete ui;
}

void PricingGoodsForm::set_DB(DataBase db)
{
    db.openDataBase();
    DB = db;
    model->setQuery("select Name from StuffList");
    ui->comboBox->setModel(model);
}

void PricingGoodsForm::on_pushButton_clicked()
{
    if (!ui->lineEdit->text().isEmpty() &&
            !ui->lineEdit_2->text().isEmpty())
    {
        QSqlQuery qry;
        qry.prepare("update StuffList set BPrice=:b, SPrice=:s where Name=:n");
        qry.bindValue(":b", ui->lineEdit->text());
        qry.bindValue(":s", ui->lineEdit_2->text());
        qry.bindValue(":n", ui->comboBox->currentText());
        if (qry.exec())
        {
            QMessageBox::information(this, "اوکی" , "تغییر انجام شد");
            this->accept();
        }
        else
        {
            QMessageBox::information(this, "خطا" , "تغییر انجام نشد");
        }
    }
    else
    {
        QMessageBox::information(this, "خطا" , "فیلدی خالیست یا به درستی انتخاب نشده است");
    }
}
