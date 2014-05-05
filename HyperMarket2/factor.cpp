#include "factor.h"
#include "ui_factor.h"

Factor::Factor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Factor)
{
    ui->setupUi(this);
    this->setFixedSize(505, 343);
    factor_print = new FactorPrint();
    stuff_model = new QSqlQueryModel();
    table_model = new QSqlQueryModel();
}

Factor::~Factor()
{
    delete ui;
}

void Factor::set_DB(DataBase db)
{
    db.openDataBase();
    DB = db;
    stuff_model->setQuery("select Name from StuffList");
    ui->comboBox->setModel(stuff_model);
    total_buy_price = total_sell_price = 0;
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
}

void Factor::on_pushButton_3_clicked()
{
    ui->lineEdit->setEnabled(false);
    ui->lineEdit_2->setEnabled(false);
    if (ui->lineEdit->text().isEmpty() || ui->lineEdit_2->text().isEmpty())
    {
        QMessageBox::information(this, "خطا", "ابتدا شماره فاکتور و نام خریدار را وارد کنید");
    }
    else if (ui->lineEdit_3->text().isEmpty())
    {
        QMessageBox::information(this, "خطا", "تعداد را وارد کنید");
    }
    else
    {
        int buy_price, sell_price, n, suplymentInShop;
        n = ui->lineEdit_3->text().toInt();
        QSqlQuery qry;
        qry.prepare("select * from StuffList where Name=:n");
        qry.bindValue(":n", ui->comboBox->currentText());
        qry.exec();
        while (qry.next())
        {
            buy_price = qry.value(3).toInt();
            sell_price = qry.value(4).toInt();
            suplymentInShop = qry.value(8).toInt();
        }
        if (suplymentInShop >= n)
        {
            if(DB.insert_factors(ui->lineEdit->text().toInt(), ui->comboBox->currentText(), ui->lineEdit_3->text().toInt(), sell_price))
            {
                total_buy_price += (ui->lineEdit_3->text().toInt())*buy_price;
                total_sell_price += (ui->lineEdit_3->text().toInt())*sell_price;
                table_model->setQuery("select * from Factors WHERE ID="+ui->lineEdit->text());
                table_model->setHeaderData(0, Qt::Horizontal, QObject::tr("شماره فاکتور"));
                table_model->setHeaderData(1, Qt::Horizontal, QObject::tr("نام کالا"));
                table_model->setHeaderData(2, Qt::Horizontal, QObject::tr("تعداد"));
                table_model->setHeaderData(3, Qt::Horizontal, QObject::tr("قیمت واحد"));
                table_model->setHeaderData(4, Qt::Horizontal, QObject::tr("قیمت کل"));
                ui->tableView->setModel(table_model);
                ui->tableView->setColumnWidth(0, 60);
                ui->tableView->setColumnWidth(2, 50);
                QSqlQuery new_qry;
                new_qry.prepare("update StuffList set NumberInShop=:n where Name=:m");
                new_qry.bindValue(":n", suplymentInShop-ui->lineEdit_3->text().toInt());
                new_qry.bindValue(":m", ui->comboBox->currentText());
                new_qry.exec();
            }
            ui->total_label->setText(QString::number(total_sell_price));
        }
        else { QMessageBox::information(this, "خطا", "موجودی موجود در فروشگاه کمتر است"); }
    }
}

void Factor::on_pushButton_4_clicked()
{
    if (DB.delete_factors(ui->lineEdit->text().toInt(), ui->comboBox->currentText(), ui->lineEdit_3->text().toInt()))
    {
        int buy_price, sell_price, n, suplymentInShop;
        n = ui->lineEdit_3->text().toInt();
        QSqlQuery qry;
        qry.prepare("select * from StuffList where Name=:n");
        qry.bindValue(":n", ui->comboBox->currentText());
        qry.exec();
        while (qry.next())
        {
            buy_price = qry.value(3).toInt();
            sell_price = qry.value(4).toInt();
            suplymentInShop = qry.value(8).toInt();
        }
        total_buy_price -= (ui->lineEdit_3->text().toInt())*buy_price;
        total_sell_price -= (ui->lineEdit_3->text().toInt())*sell_price;
        table_model->setQuery("select * from Factors WHERE ID="+ui->lineEdit->text());
        table_model->setHeaderData(0, Qt::Horizontal, QObject::tr("شماره فاکتور"));
        table_model->setHeaderData(1, Qt::Horizontal, QObject::tr("نام کالا"));
        table_model->setHeaderData(2, Qt::Horizontal, QObject::tr("تعداد"));
        table_model->setHeaderData(3, Qt::Horizontal, QObject::tr("قیمت واحد"));
        table_model->setHeaderData(4, Qt::Horizontal, QObject::tr("قیمت کل"));
        ui->tableView->setModel(table_model);
        ui->tableView->setColumnWidth(0, 60);
        ui->tableView->setColumnWidth(2, 50);
        QSqlQuery new_qry;
        new_qry.prepare("update StuffList set NumberInShop=:n where Name=:m");
        new_qry.bindValue(":n", suplymentInShop+ui->lineEdit_3->text().toInt());
        new_qry.bindValue(":m", ui->comboBox->currentText());
        new_qry.exec();
        ui->total_label->setText(QString::number(total_sell_price));
    }
    else
    {
        QMessageBox::information(this, "err", "nemishe");
    }
}

void Factor::on_pushButton_2_clicked()
{
    QSqlQuery qry, sub_qry, new_qry;
    qry.prepare("select * from Factors WHERE ID="+ui->lineEdit->text());
    qry.exec();
    while(qry.next())
    {
        int buy_price, sell_price, suplymentInShop;
        sub_qry.prepare("select * from StuffList where Name=:n");
        sub_qry.bindValue(":n", qry.value(1).toString());
        sub_qry.exec();
        while (sub_qry.next())
        {
            buy_price = sub_qry.value(3).toInt();
            sell_price = sub_qry.value(4).toInt();
            suplymentInShop = sub_qry.value(8).toInt();
        }
        total_buy_price -= (qry.value(2).toInt()) * buy_price;
        total_sell_price -= (qry.value(2).toInt())*sell_price;
        new_qry.prepare("update StuffList set NumberInShop=:n where Name=:m");
        new_qry.bindValue(":n", suplymentInShop+ui->lineEdit_3->text().toInt());
        new_qry.bindValue(":m", ui->comboBox->currentText());
        new_qry.exec();
        ui->total_label->setText(QString::number(total_sell_price));
    }
    ui->lineEdit->setEnabled(true);
    ui->lineEdit_2->setEnabled(true);
    this->close();
}

void Factor::on_pushButton_clicked()
{
    factor_print = new FactorPrint(this);
    factor_print->set_model(table_model, ui->lineEdit->text().toInt(), ui->lineEdit_2->text(), total_sell_price);
    factor_print->show();
}
