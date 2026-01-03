#include "archieve.h"
#include "ui_archieve.h"
#include "mainwindow.h"

archieve::archieve(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::archieve)
{
    ui->setupUi(this);
    ui->tabs->tabBar()->setEnabled(true);
    managermenu *mg = qobject_cast<managermenu*>(this->parentWidget());
    secondwindow3 *sw3 = qobject_cast<secondwindow3*>(mg->parentWidget());
    MainWindow *mw = qobject_cast<MainWindow*>(sw3->parentWidget());
    Arch=mw->arch;
    loadAccounts();
    loadLoans();
    loadTransactions();
    ui->accounts_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->transactions_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->loans_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

archieve::~archieve()
{
    delete ui;
}

void archieve::on_accounts_2_cellActivated(int row, int column)
{

}
void archieve::on_loans_2_cellActivated(int row, int column)
{

}


void archieve::on_transactions_2_cellActivated(int row, int column)
{

}
void archieve::loadAccounts()
{
    int count = Arch.nacc;
    if (count <= 0)
    {
        ui->accounts_2->setRowCount(0);
        ui->l1->setFont(QFont("Segoe UI", 14, QFont::Bold));
        ui->l1->setStyleSheet("color: rgb(170,0,0);");
        ui->l1->setText("There are no archived accounts to display");
        return;
    }

    ui->accounts_2->setRowCount(count);

    for (int i = 0; i < count; i++)
    {
        account a = Arch.archivedacc[i];

        ui->accounts_2->setItem(i, 0, new QTableWidgetItem(a.AccountNumber));
        ui->accounts_2->setItem(i, 1, new QTableWidgetItem(a.AccountType));
        ui->accounts_2->setItem(i, 2, new QTableWidgetItem(a.IBAN));
        ui->accounts_2->setItem(i, 3, new QTableWidgetItem(a.BranchCode));
        ui->accounts_2->setItem(i, 4, new QTableWidgetItem(a.AccountHolderName));
        ui->accounts_2->setItem(i, 5, new QTableWidgetItem(a.OpeningDate));
        ui->accounts_2->setItem(i, 6, new QTableWidgetItem(QString::number(a.Balance)));
        ui->accounts_2->setItem(i, 7, new QTableWidgetItem(a.Status));
    }

    ui->l1->clear();
}


void archieve::loadLoans()
{
    node *curr = Arch.completed_loans.head;

    if (curr == nullptr)
    {
        ui->loans_2->setRowCount(0);
        ui->l2->setFont(QFont("Segoe UI", 14, QFont::Bold));
        ui->l2->setFont(QFont("Segoe UI", 14, QFont::Bold));
        ui->l2->setStyleSheet("color: rgb(170,0,0);");
        ui->l2->setText("There are no archived loans to display");
        return;
    }
    ui->loans_2->setRowCount(Arch.completed_loans.size);

    int row = 0;
    while (curr != nullptr)
    {
        loan ln = curr->data;

        ui->loans_2->setItem(row, 0, new QTableWidgetItem(ln.LoanID));
        ui->loans_2->setItem(row, 1, new QTableWidgetItem(ln.LoanType));
        ui->loans_2->setItem(row, 2, new QTableWidgetItem(ln.StartDate));
        ui->loans_2->setItem(row, 3, new QTableWidgetItem(ln.EndDate));
        ui->loans_2->setItem(row, 4, new QTableWidgetItem(QString::number(ln.PrincipalAmount)));
        ui->loans_2->setItem(row, 5, new QTableWidgetItem(QString::number(ln.InterestRate)));
        ui->loans_2->setItem(row, 6, new QTableWidgetItem(QString::number(ln.MonthlyPayment)));
        ui->loans_2->setItem(row, 7, new QTableWidgetItem(ln.LoanStatus));

        curr = curr->next;
        row++;
    }

    ui->l2->clear();
}
void archieve::loadTransactions()
{
    NODE *curr = Arch.transactions.head;

    if (curr == nullptr)
    {
        ui->transactions_2->setRowCount(0);
        ui->l3->setFont(QFont("Segoe UI", 14, QFont::Bold));
        ui->l3->setStyleSheet("color: rgb(170,0,0);");
        ui->l3->setText("There are no archived transactions to display");
        return;
    }
    ui->transactions_2->setRowCount(Arch.transactions.size);

    int row = 0;
    while (curr != nullptr)
    {
        tran t = curr->data;

        ui->transactions_2->setItem(row, 0, new QTableWidgetItem(t.username));
        ui->transactions_2->setItem(row, 1, new QTableWidgetItem(QString::number(t.t.TID)));
        ui->transactions_2->setItem(row, 2, new QTableWidgetItem(t.t.number));
        ui->transactions_2->setItem(row, 3, new QTableWidgetItem(t.t.Type));
        ui->transactions_2->setItem(row, 4, new QTableWidgetItem(t.t.Date));
        ui->transactions_2->setItem(row, 5, new QTableWidgetItem(QString::number(t.t.Amount)));

        curr = curr->next;
        row++;
    }

    ui->l3->clear();
}




void archieve::on_back_clicked()
{
    this->parentWidget()->show();
    this->hide();
}


void archieve::on_exit_clicked()
{
    exit(1);
}


