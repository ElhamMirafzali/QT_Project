#include "manufacturers.h"
#include "ui_manufacturers.h"
#include <QPropertyAnimation>

Manufacturers::Manufacturers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Manufacturers)
{
    ui->setupUi(this);
    this->setFixedSize(400, 300);
    QPropertyAnimation *anim = new QPropertyAnimation(ui->label , "geometry") ;
    anim->setEndValue(QRect(0 , 0 , ui->label->width() , ui->label->height()*2 ));
    anim->setDuration(2000);
    //anim->setEasingCurve();
    anim->start();
}

Manufacturers::~Manufacturers()
{
    delete ui;
}
