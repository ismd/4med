#include <QMessageBox>
#include "gui/ShowRegistrations.h"
#include "ui_ShowRegistrations.h"
#include "lib/RegistrationModel.h"
#include "lib/DrugModel.h"

ShowRegistrations::ShowRegistrations(QWidget *parent, int idDrug) :
    QWidget(parent),
    ui(new Ui::ShowRegistrations)
{
    ui->setupUi(this);

    DrugModel drugModel;
    ui->lTitle->setText(drugModel.selectById(idDrug));
    ui->lTitle->adjustSize();

    RegistrationModel model;
    QList<RegistrationModel::registration> ls = model.getRegistrations(idDrug);

    ui->tableWidget->setRowCount(ls.count());
    ui->tableWidget->setColumnWidth(0, 70);
    ui->tableWidget->setColumnWidth(1, 120);
    ui->tableWidget->setColumnWidth(2, 90);
    ui->tableWidget->setColumnWidth(3, 200);
    ui->tableWidget->setColumnWidth(4, 70);

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

        QTableWidgetItem *item5 = new QTableWidgetItem(QString::number(reg.id));
        ui->tableWidget->setItem(row, 5, item5);

        row++;
    }

//    connect(ui->bAdd, SIGNAL(clicked()), SLOT(addItem()));
//    connect(ui->bEdit, SIGNAL(clicked()), SLOT(editItem()));
//    connect(ui->bDel, SIGNAL(clicked()), SLOT(delItem()));
}

ShowRegistrations::~ShowRegistrations()
{
    delete ui;
}

void ShowRegistrations::addItem()
{

}

void ShowRegistrations::editItem()
{

}

void ShowRegistrations::delItem()
{
    int ret = QMessageBox::question(this, trUtf8("Удаление"), \
                                    trUtf8("Вы уверены, что хотите удалить запись?\n") +
                                    trUtf8("При выборе отдела также будут удалены все сотрудники отдела"), \
                                    QMessageBox::StandardButtons(QMessageBox::Cancel | QMessageBox::Yes));

    if (ret != QMessageBox::Yes)
        return;

    int curId = ui->tableWidget->item(ui->tableWidget->currentRow(), 5)->text().toInt();

    RegistrationModel model;
    model.del(curId);
}
