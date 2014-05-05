#ifndef CUSTOMERINTROFORM_H
#define CUSTOMERINTROFORM_H

#include <QDialog>

namespace Ui {
class CustomerIntroForm;
}

class CustomerIntroForm : public QDialog
{
    Q_OBJECT
    
public:
    explicit CustomerIntroForm(QWidget *parent = 0);
    ~CustomerIntroForm();
    
private:
    Ui::CustomerIntroForm *ui;
};

#endif // CUSTOMERINTROFORM_H
