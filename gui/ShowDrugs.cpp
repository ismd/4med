#include <QMessageBox>
#include "gui/ShowDrugs.h"
#include "ui_ShowDrugs.h"
#include "lib/DrugModel.h"
#include "gui/AddDrug.h"

ShowDrugs::ShowDrugs(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShowDrugs)
{
    ui->setupUi(this);

    fillList();

    connect(ui->bRegistration, SIGNAL(clicked()), SLOT(showRegistrations()));
    connect(ui->bEdit, SIGNAL(clicked()), SLOT(editDrug()));
    connect(ui->bDel, SIGNAL(clicked()), SLOT(delDrug()));
}

ShowDrugs::~ShowDrugs()
{
    delete ui;
}

void ShowDrugs::fillList()
{
    DrugModel *model = new DrugModel;
    QSqlQueryModel *queryModel = model->selectAll();

    ui->drugsList->setModel(queryModel);
}

void ShowDrugs::showRegistrations()
{
    if (ui->drugsList->currentIndex().row() == -1) {
        QMessageBox msgBox;
        msgBox.setText(trUtf8("Не выбрано лекарственное средство"));
        msgBox.exec();
        return;
    }

    int idDrug = ui->drugsList->model()->index(ui->drugsList->currentIndex().row(), 1).data().toInt();

    // TODO: show form
}

void ShowDrugs::editDrug()
{
    if (ui->drugsList->currentIndex().row() == -1) {
        QMessageBox msgBox;
        msgBox.setText(trUtf8("Не выбрано лекарственное средство"));
        msgBox.exec();
        return;
    }

    int idDrug = ui->drugsList->model()->index(ui->drugsList->currentIndex().row(), 1).data().toInt();

    AddDrug *editWindow = new AddDrug(this);
    editWindow->setEditable(idDrug);
    editWindow->show();

    connect(editWindow, SIGNAL(accepted()), SLOT(fillList()));
}

void ShowDrugs::delDrug()
{
    if (ui->drugsList->currentIndex().row() == -1) {
        QMessageBox msgBox;
        msgBox.setText(trUtf8("Не выбрано лекарственное средство"));
        msgBox.exec();
        return;
    }

    int ret = QMessageBox::question(this, trUtf8("Удаление"), \
                                    trUtf8("Вы уверены, что хотите удалить запись?\n") +
                                    trUtf8("Это также удалит все приходы/расходы данного ") +
                                    trUtf8("лекарственного средства"), \
                                    QMessageBox::StandardButtons(QMessageBox::Cancel | QMessageBox::Yes));

    if (ret != QMessageBox::Yes)
        return;

    int idDrug = ui->drugsList->model()->index(ui->drugsList->currentIndex().row(), 1).data().toInt();

    DrugModel model;
    model.del(idDrug);

    fillList();
}
