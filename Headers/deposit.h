#ifndef DEPOSIT_H
#define DEPOSIT_H

#include "mainwindow.h"
#include "secondwindow1.h"
#include <QDialog>

namespace Ui {
class Deposit;
}

class Deposit : public QDialog
{
    Q_OBJECT

public:
    explicit Deposit(QWidget *parent = nullptr);
    ~Deposit();

private slots:
    void on_exit_clicked();

    void on_back_clicked();

    void on_submit_clicked();

private:
    Ui::Deposit *ui;
    secondwindow1* sw;
    MainWindow* mw;
};

#endif // DEPOSIT_H
