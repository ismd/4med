#include <QDateTime>
#include <QMessageBox>
#include "gui/AddRegistration.h"
#include "ui_AddRegistration.h"
#include "lib/DrugModel.h"
#include "lib/DepartmentModel.h"
#include "lib/RecipientModel.h"
#include "lib/RegistrationModel.h"
#include "lib/Db.h"

AddRegistration::AddRegistration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddRegistration)
{
    ui->setupUi(this);

    DrugModel* drm = new DrugModel;
    DepartmentModel* depm = new DepartmentModel;

    drugModel = drm->selectAll();
    departmentModel = depm->selectAll();

    ui->eIdDrug->setModel(drugModel);
    ui->eReceived->setChecked(true);
    setReceived();
    ui->eWhen->setDateTime(QDateTime::currentDateTime());

    ui->eIdDepartment->setModel(departmentModel);

    fillRecipients();

    connect(ui->eReceived, SIGNAL(toggled(bool)), SLOT(setReceived()));
    connect(ui->eIdDepartment, SIGNAL(currentIndexChanged(int)), SLOT(fillRecipients()));
    connect(ui->buttonBox, SIGNAL(accepted()), SLOT(addItem()));
    connect(ui->buttonBox, SIGNAL(rejected()), SLOT(reject()));
}

AddRegistration::~AddRegistration()
{
    delete ui;
}

void AddRegistration::addItem()
{
    if (ui->eIdDrug->currentIndex() == -1) {
        QMessageBox msgBox;
        msgBox.setText(trUtf8("Не выбран медикамент"));
        msgBox.exec();
        return;
    }

    if (ui->eSended->isChecked() && ui->eIdDepartment->currentIndex() == -1) {
        QMessageBox msgBox;
        msgBox.setText(trUtf8("Не выбран отдел"));
        msgBox.exec();
        return;
    }

    if (ui->eSended->isChecked() && ui->eIdRecipient->currentIndex() == -1) {
        QMessageBox msgBox;
        msgBox.setText(trUtf8("Не выбран сотрудник"));
        msgBox.exec();
        return;
    }

    RegistrationModel *model = new RegistrationModel;

    if (Db::connected()) {
        int idDrug = drugModel->record(ui->eIdDrug->currentIndex()).value("id").toInt();
        int idDepartment;
        int idRecipient;

        if (ui->eSended->isChecked())
            idDepartment = recipientModel->record(ui->eIdDepartment->currentIndex()).value("id").toInt();
        else
            idDepartment = -1;

        if (ui->eSended->isChecked())
            idRecipient = recipientModel->record(ui->eIdRecipient->currentIndex()).value("id").toInt();
        else
            idRecipient = -1;

        model->insert(idDrug, ui->eWhen->dateTime(), ui->eAmount->value(), ui->eReceived->isChecked(), idDepartment, idRecipient);
    } else {
        QMessageBox msgBox;
        // FIXME: doesn't work
        msgBox.setText(Db::setError().text());
        msgBox.exec();
    }

    accept();
}

void AddRegistration::setReceived()
{
    bool st = ui->eReceived->isChecked();

    ui->eIdDepartment->setEnabled(!st);
    ui->eIdRecipient->setEnabled(!st);
}

void AddRegistration::fillRecipients()
{
//    int idDepartment = departmentModel->record(ui->eIdDepartment->currentIndex()).value("id").toInt();
//    RecipientModel* rm = new RecipientModel;
//    recipientModel = rm->select(idDepartment);
    RecipientModel* rm = new RecipientModel;
    recipientModel = rm->selectAll();

    ui->eIdRecipient->setModel(recipientModel);
}
