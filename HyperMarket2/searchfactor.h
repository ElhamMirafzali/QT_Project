#ifndef SEARCHFACTOR_H
#define SEARCHFACTOR_H

#include <QDialog>

namespace Ui {
class SearchFactor;
}

class SearchFactor : public QDialog
{
    Q_OBJECT
    
public:
    explicit SearchFactor(QWidget *parent = 0);
    ~SearchFactor();
    
private:
    Ui::SearchFactor *ui;
};

#endif // SEARCHFACTOR_H
