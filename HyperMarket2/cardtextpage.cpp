#include "cardtextpage.h"
#include "ui_cardtextpage.h"

CardTextPage::CardTextPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CardTextPage)
{
    ui->setupUi(this);
}

CardTextPage::~CardTextPage()
{
    delete ui;
}
