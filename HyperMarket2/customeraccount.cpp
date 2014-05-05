#include "customeraccount.h"
#include "ui_customeraccount.h"

CustomerAccount::CustomerAccount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomerAccount)
{
    ui->setupUi(this);
}

CustomerAccount::~CustomerAccount()
{
    delete ui;
}
