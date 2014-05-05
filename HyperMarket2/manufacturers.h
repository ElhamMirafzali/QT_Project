#ifndef MANUFACTURERS_H
#define MANUFACTURERS_H

#include <QDialog>

namespace Ui {
class Manufacturers;
}

class Manufacturers : public QDialog
{
    Q_OBJECT
    
public:
    explicit Manufacturers(QWidget *parent = 0);
    ~Manufacturers();
    
private:
    Ui::Manufacturers *ui;
};

#endif // MANUFACTURERS_H
