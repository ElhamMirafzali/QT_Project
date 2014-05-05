#include "customerintroform.h"
#include "ui_customerintroform.h"

CustomerIntroForm::CustomerIntroForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomerIntroForm)
{
    ui->setupUi(this);
}

CustomerIntroForm::~CustomerIntroForm()
{
    delete ui;
}
