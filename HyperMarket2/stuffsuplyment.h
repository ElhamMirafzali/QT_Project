#ifndef STUFFSUPLYMENT_H
#define STUFFSUPLYMENT_H

#include <QDialog>

namespace Ui {
class StuffSuplyment;
}

class StuffSuplyment : public QDialog
{
    Q_OBJECT
    
public:
    explicit StuffSuplyment(QWidget *parent = 0);
    ~StuffSuplyment();
    
private:
    Ui::StuffSuplyment *ui;
};

#endif // STUFFSUPLYMENT_H
