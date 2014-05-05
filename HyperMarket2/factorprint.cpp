#include <QTextEdit>
#include <QPrinter>
#include <QPrintDialog>
#include "factorprint.h"
#include "ui_factorprint.h"

FactorPrint::FactorPrint(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FactorPrint)
{
    ui->setupUi(this);
}

FactorPrint::~FactorPrint()
{
    delete ui;
}

void FactorPrint::set_model(QSqlQueryModel *model, int id, QString customer_name, int total)
{
    this->setFixedSize(333, 546);
    main_model = new QSqlQueryModel();
    main_model = model;
    ui->treeView->setModel(main_model);
    ui->treeView->setColumnWidth(0, 10);
    ui->treeView->setColumnWidth(1, 120);
    ui->treeView->setColumnWidth(2, 30);
    ui->treeView->setColumnWidth(3, 60);
    ui->treeView->setColumnWidth(4, 70);
    ui->id->setText(QString::number(id));
    ui->customer->setText(customer_name);
    ui->total->setText(QString::number(total));
}

void FactorPrint::on_pushButton_clicked()
{
#ifndef QT_NO_PRINTER
    editor = static_cast<QTextEdit*>(ui->tabWidget->currentWidget());
//! [18]
    QPrinter printer;

    QPrintDialog dialog(&printer, this);
    dialog.setWindowTitle(tr("Print Document"));
    if (editor->textCursor().hasSelection())
        dialog.addEnabledOption(QAbstractPrintDialog::PrintSelection);
    if (dialog.exec() != QDialog::Accepted) {
        return;
    }
//! [18]

    editor->print(&printer);

#endif
}
