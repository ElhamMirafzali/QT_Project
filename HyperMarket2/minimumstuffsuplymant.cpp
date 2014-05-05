#include "minimumstuffsuplymant.h"
#include "ui_minimumstuffsuplymant.h"

MinimumStuffSuplymant::MinimumStuffSuplymant(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MinimumStuffSuplymant)
{
    ui->setupUi(this);
    this->setFixedSize(390, 120);
    stuffModel = new QSqlQueryModel();
    model = new QSqlQueryModel();
}

MinimumStuffSuplymant::~MinimumStuffSuplymant()
{
    delete ui;
}

void MinimumStuffSuplymant::set_DB(DataBase db)
{
    db.openDataBase();
    DB = db;
    stuffModel->setQuery("select Name from StuffList");
    ui->comboBox->setModel(stuffModel);
    ui->comboBox_2->addItem("انبار");
    ui->comboBox_2->addItem("فروشگاه");
}

void MinimumStuffSuplymant::on_pushButton_clicked()
{
    if (!ui->lineEdit->text().isEmpty())
    {
        QSqlQuery qry;
        if (ui->comboBox_2->currentText() == "انبار")
        {
            qry.prepare("update StuffList set MinimumNumberInStore=:m where Name=:n");
        }
        else
        {
            qry.prepare("update StuffList set MinimumNumberInShop=:m where Name=:n");
        }
        qry.bindValue(":m", ui->lineEdit->text().toInt());
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
