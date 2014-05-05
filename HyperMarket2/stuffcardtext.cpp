#include "stuffcardtext.h"
#include "ui_stuffcardtext.h"
#include "cardtextpage.h"

StuffCardText::StuffCardText(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StuffCardText)
{
    ui->setupUi(this);
}

StuffCardText::~StuffCardText()
{
    delete ui;
}

void StuffCardText::on_pushButton_2_clicked()
{
    CardTextPage cardText;
    cardText.exec();
}
