#ifndef FACTORPRINT_H
#define FACTORPRINT_H

#include <QDialog>
#include <QSqlQueryModel>
#include <QTextEdit>

namespace Ui {
class FactorPrint;
}

class FactorPrint : public QDialog
{
    Q_OBJECT
    
public:
    explicit FactorPrint(QWidget *parent = 0);
    ~FactorPrint();
    void set_model(QSqlQueryModel* model, int id, QString customer_name, int total);
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::FactorPrint *ui;
    QSqlQueryModel *main_model;
    QTextEdit *editor;
};

#endif // FACTORPRINT_H
