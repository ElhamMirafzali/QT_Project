#include "definestuffgroup.h"
#include "ui_definestuffgroup.h"

#include <QMessageBox>

DefineStuffGroup::DefineStuffGroup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DefineStuffGroup)
{
    ui->setupUi(this);
    model = new QSqlQueryModel();
}

DefineStuffGroup::~DefineStuffGroup()
{
    delete ui;
}

void DefineStuffGroup::set_DB(DataBase db)
{
    db.openDataBase();
    DB = db;
    model->setQuery("select * from StuffGroups");
    ui->listView->setModel(model);
}



void DefineStuffGroup::on_Submit_clicked()
{
    if (ui->lineEdit->text().isEmpty())
        QMessageBox::information(this, "خطا", "عبارتی وارد نشده است !");


    else
    {
        QSqlQuery qry;
        qry.prepare("select * from StuffGroups where Name=:n");
        int find = 0;
        qry.bindValue(":n", ui->lineEdit->text());
        if (qry.exec())
        {
            while (qry.next()) find++;
        }
        if (find>0) { QMessageBox::information(this, "خطا", "چنین گروه کالایی وجود دارد");}
        else
        {
            if (DB.insert_StuffGroup(ui->lineEdit->text()))
            {
                QMessageBox::information(this, "اوکی" , "گروه کالا با موفقیت ثبت شد");
                this->accept();
            }
            else
            {
                QMessageBox::information(this, "خطا" , "اطلاعات ثبت نشد!");
                qDebug() << DB.db.lastError().text();
            }
        }
    }
}
