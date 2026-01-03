include "loans.h"
#include "ui_loans.h"

loans::loans(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::loans)
{
    ui->setupUi(this);
}

loans::~loans()
{
    delete ui;
}

