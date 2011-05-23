#include <QMessageBox>
#include "gui/AddRecipient.h"
#include "ui_AddRecipient.h"
#include "lib/RecipientModel.h"
#include "lib/Db.h"
#include "lib/DepartmentModel.h"

AddRecipient::AddRecipient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddRecipient)
{
    ui->setupUi(this);

    connect(ui->buttonBox, SIGNAL(accepted()), SLOT(addItem()));
    connect(ui->buttonBox, SIGNAL(rejected()), SLOT(reject()));

    // Fill combobox with departments
    DepartmentModel *depModel = new DepartmentModel;
    depall = depModel->selectAll();
    ui->eIdDepartment->setModel(depall);
}

AddRecipient::~AddRecipient()
{
    delete ui;
}

void AddRecipient::setEditable(int id, int idDepartment)
{
    idFromDb = id;
    RecipientModel *model = new RecipientModel;

    ui->eFIO->setText(model->selectById(id));

    for (int i = 0; i < ui->eIdDepartment->count(); i++)
        if (idDepartment == ui->eIdDepartment->model()->index(i, 1).data())
            ui->eIdDepartment->setCurrentIndex(i);

    disconnect(ui->buttonBox, SIGNAL(accepted()), 0, 0);
    connect(ui->buttonBox, SIGNAL(accepted()), SLOT(editItem()));
}

void AddRecipient::addItem()
{
    if (ui->eFIO->text() == "") {
        QMessageBox msgBox;
        msgBox.setText(trUtf8("Не введено ФИО"));
        msgBox.exec();
        return;
    }

    if (ui->eIdDepartment->currentIndex() == -1) {
        QMessageBox msgBox;
        msgBox.setText(trUtf8("Не выбран отдел"));
        msgBox.exec();
        return;
    }

    RecipientModel* model = new RecipientModel;

    if (Db::connected()) {
        int idDepartment = depall->record(ui->eIdDepartment->currentIndex()).value("id").toInt();
        model->insert(ui->eFIO->text(), idDepartment);
    } else {
        QMessageBox msgBox;
        // FIXME: doesn't work
        msgBox.setText(Db::setError().text());
        msgBox.exec();
    }

    accept();
}

void AddRecipient::editItem()
{
    if (ui->eFIO->text() == "") {
        QMessageBox msgBox;
        msgBox.setText(trUtf8("Не введено ФИО"));
        msgBox.exec();
        return;
    }

    RecipientModel *model = new RecipientModel;
    int idDepartment = depall->record(ui->eIdDepartment->currentIndex()).value("id").toInt();
    model->update(idFromDb, ui->eFIO->text(), idDepartment);

    accept();
}
