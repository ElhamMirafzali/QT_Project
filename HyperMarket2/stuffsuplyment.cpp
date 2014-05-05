#include "stuffsuplyment.h"
#include "ui_stuffsuplyment.h"

StuffSuplyment::StuffSuplyment(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StuffSuplyment)
{
    ui->setupUi(this);
}

StuffSuplyment::~StuffSuplyment()
{
    delete ui;
}
