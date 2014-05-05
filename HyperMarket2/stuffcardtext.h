#ifndef STUFFCARDTEXT_H
#define STUFFCARDTEXT_H

#include <QDialog>

namespace Ui {
class StuffCardText;
}

class StuffCardText : public QDialog
{
    Q_OBJECT
    
public:
    explicit StuffCardText(QWidget *parent = 0);
    ~StuffCardText();
    
private slots:
    void on_pushButton_2_clicked();

private:
    Ui::StuffCardText *ui;
};

#endif // STUFFCARDTEXT_H
