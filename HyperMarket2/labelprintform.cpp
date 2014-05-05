#include "labelprintform.h"
#include "ui_labelprintform.h"

LabelPrintForm::LabelPrintForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LabelPrintForm)
{
    ui->setupUi(this);
}

LabelPrintForm::~LabelPrintForm()
{
    delete ui;
}
