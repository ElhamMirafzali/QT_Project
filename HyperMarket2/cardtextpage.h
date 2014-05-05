#ifndef CARDTEXTPAGE_H
#define CARDTEXTPAGE_H

#include <QDialog>

namespace Ui {
class CardTextPage;
}

class CardTextPage : public QDialog
{
    Q_OBJECT
    
public:
    explicit CardTextPage(QWidget *parent = 0);
    ~CardTextPage();
    
private:
    Ui::CardTextPage *ui;
};

#endif // CARDTEXTPAGE_H
