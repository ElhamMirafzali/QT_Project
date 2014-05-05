#include "searchfactor.h"
#include "ui_searchfactor.h"

SearchFactor::SearchFactor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchFactor)
{
    this->setFixedSize(400, 300);
    ui->setupUi(this);
}

SearchFactor::~SearchFactor()
{
    delete ui;
}
