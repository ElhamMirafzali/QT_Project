#include "sendstufftoshop.h"
#include "ui_sendstufftoshop.h"

SendStuffToShop::SendStuffToShop(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SendStuffToShop)
{
    ui->setupUi(this);
    this->setFixedSize(390, 190);
    model1 = new QSqlQueryModel();
    model2 = new QSqlQueryModel();
}

SendStuffToShop::~SendStuffToShop()
{
    delete ui;
}

void SendStuffToShop::set_DB(DataBase db)
{
    db.openDataBase();
    DB = db;
    model1->setQuery("select Name from StuffList");
    ui->comboBox->setModel(model1);
    model2->setQuery("select Name from Store");
    ui->comboBox_2->setModel(model2);
}

void SendStuffToShop::on_pushButton_clicked()
{
    if (ui->lineEdit->text().isEmpty() || ui->lineEdit_2->text().isEmpty())
    {
        QMessageBox::information(this, "خطا", "فیلدی خالیست");
    }
    else
    {
        QSqlQuery qry;
        qry.prepare("select * from StuffList where Name=:n and Location=:l");
        int suplyCount = 0, shopCount = 0;
        int find = 0;
        qry.bindValue(":n", ui->comboBox->currentText());
        qry.bindValue(":l", ui->comboBox_2->currentText());
        if (qry.exec())
        {
            while (qry.next())
            {
                suplyCount = qry.value(7).toInt();
                shopCount = qry.value(8).toInt();
                find++;
            }
        }
        if (find == 0) { QMessageBox::information(this, "خطا", "این کالا در این انبار موجود نیست");}
        else
        {
            if (suplyCount == 0) { QMessageBox::information(this, "خطا", "موجودی کالا در این انبار صفر است");}
            else
            {
                qDebug() << suplyCount << shopCount;
                if (suplyCount < ui->lineEdit->text().toInt()) {QMessageBox::information(this, "خطا", "تعداد موجود در انبار مبداء کمتر از تعداد درخواستی است");}
                else
                {
                    QSqlQuery new_qry;
                    new_qry.prepare("update StuffList set NumberInStore=:s, NumberInShop=:p where Name=:n");
                    new_qry.bindValue(":s", (suplyCount - ui->lineEdit->text().toInt()));
                    new_qry.bindValue(":p", (shopCount + ui->lineEdit->text().toInt()));
                    new_qry.bindValue(":n", ui->comboBox->currentText());
                    if (new_qry.exec())
                    {
                        QMessageBox::information(this, "اوکی", "حله ");
                        this->accept();
                    }
                    else
                    {
                        QMessageBox::information(this, "خطا", "نمیدونم چرا نمیشه! ");
                    }
                }
            }
        }
    }
}
