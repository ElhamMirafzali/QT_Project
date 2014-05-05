#include "sendstufftostore.h"
#include "ui_sendstufftostore.h"

#include "stuff.h"

SendStuffToStore::SendStuffToStore(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SendStuffToStore)
{
    ui->setupUi(this);
    stuff_model = new QSqlQueryModel();
    strStore_model = new QSqlQueryModel();
    desStore_model = new QSqlQueryModel();
}

SendStuffToStore::~SendStuffToStore()
{
    delete ui;
}

void SendStuffToStore::set_DB(DataBase db)
{
    db.openDataBase();
    DB = db;
    stuff_model->setQuery("select Name from StuffList");
    ui->comboBox->setModel(stuff_model);
    strStore_model->setQuery("select Name from Store");
    ui->comboBox_2->setModel(strStore_model);
    desStore_model->setQuery("select Name from Store");
    ui->comboBox_3->setModel(desStore_model);
}

void SendStuffToStore::on_pushButton_clicked()
{
    if (ui->lineEdit->text().isEmpty() || ui->lineEdit_2->text().isEmpty())
    {
        QMessageBox::information(this, "خطا", "فیلد تعداد خالیست");
    }
    else if (ui->comboBox_2->currentText() == ui->comboBox_3->currentText())
    {
        QMessageBox::information(this, "خطا", "نمیشه که");
    }
    else
    {
        QSqlQuery qry;
        QVector<QString> loc_num = DB.get_nums_in_locations(ui->comboBox->currentText());
        QString a_loc;
        bool change1 = false, change2 = false;
        for (int i = 0; i < loc_num.size(); i+=2)
        {
            a_loc = loc_num[i];
            qDebug() << loc_num[i] << loc_num[i+1];

            if (a_loc == ui->comboBox_2->currentText())
            {
                qDebug() << "ok";
                if (loc_num[i+1].toInt() < ui->lineEdit->text().toInt()) QMessageBox::information(this, "خطا", "تعداد موجود در انبار مبداء کمتر از تعداد درخواستی است");
                else
                {
                    change1 = true;
                    loc_num[i+1] = QString::number(loc_num[i+1].toInt() - ui->lineEdit->text().toInt());
                }
            }
            else if (a_loc == ui->comboBox_3->currentText())
            {
                qDebug() << "ok2";
                change2 = true;
                loc_num[i+1] = QString::number(loc_num[i+1].toInt() + ui->lineEdit->text().toInt());
            }
            else
            {
                QMessageBox::information(this, "خطا", "در انبار مورد نظر چنین کالایی وجود ندارد");
            }
        }
        if (change1 && !change2)
        {
            loc_num.append(ui->comboBox_3->currentText());
            loc_num.append(ui->lineEdit->text());
        }
        QString location = "";
        for (int i = 0; i < loc_num.size(); i++)
        {
            location += loc_num[i] + ' ';
        }
        qDebug() << location;
        qry.prepare("update StuffList set MinimumNumberInStore=:m where Location=:l");
        qry.bindValue(":m", ui->lineEdit_2->text().toInt());
        qry.bindValue(":l", location);
        if (qry.exec())
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
