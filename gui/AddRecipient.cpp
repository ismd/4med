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
    DepartmentModel* depmodel = new DepartmentModel;
    depall = depmodel->selectAll();
    ui->eIdDepartment->setModel(depall);
}

AddRecipient::~AddRecipient()
{
    delete ui;
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
