#include "gui/ShowRegistrations.h"
#include "ui_ShowRegistrations.h"
#include "lib/RegistrationModel.h"

ShowRegistrations::ShowRegistrations(QWidget *parent, int idDrug) :
    QWidget(parent),
    ui(new Ui::ShowRegistrations)
{
    ui->setupUi(this);

    RegistrationModel model;
    QList<RegistrationModel::registration> ls = model.getRegistrations(idDrug);

    ui->tableWidget->setRowCount(ls.count());
    ui->tableWidget->setColumnWidth(0, 60);
    ui->tableWidget->setColumnWidth(1, 110);
    ui->tableWidget->setColumnWidth(2, 80);
    ui->tableWidget->setColumnWidth(3, 110);
    ui->tableWidget->setColumnWidth(4, 60);

    int row = 0;
    foreach (RegistrationModel::registration reg, ls) {
        QString received = (reg.received ? trUtf8("Приход") : trUtf8("Расход"));

        QTableWidgetItem *item = new QTableWidgetItem(received);
        ui->tableWidget->setItem(row, 0, item);

        QTableWidgetItem *item1 = new QTableWidgetItem(reg.happened.toString("dd.MM.yyyy hh:mm"));
        ui->tableWidget->setItem(row, 1, item1);

        QTableWidgetItem *item2 = new QTableWidgetItem(QString::number(reg.amount));
        ui->tableWidget->setItem(row, 2, item2);

        QTableWidgetItem *item3 = new QTableWidgetItem(reg.fioRecipient);
        ui->tableWidget->setItem(row, 3, item3);

        QTableWidgetItem *item4 = new QTableWidgetItem(QString::number(reg.balance));
        ui->tableWidget->setItem(row, 4, item4);

        row++;
    }
}

ShowRegistrations::~ShowRegistrations()
{
    delete ui;
}
