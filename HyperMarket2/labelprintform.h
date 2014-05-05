#ifndef LABELPRINTFORM_H
#define LABELPRINTFORM_H

#include <QDialog>

namespace Ui {
class LabelPrintForm;
}

class LabelPrintForm : public QDialog
{
    Q_OBJECT
    
public:
    explicit LabelPrintForm(QWidget *parent = 0);
    ~LabelPrintForm();
    
private:
    Ui::LabelPrintForm *ui;
};

#endif // LABELPRINTFORM_H
