#include <QMessageBox>
#include "gui/AddDepartment.h"
#include "ui_AddDepartment.h"
#include "lib/DepartmentModel.h"
#include "lib/Db.h"

AddDepartment::AddDepartment(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDepartment)
{
    ui->setupUi(this);

    connect(ui->buttonBox, SIGNAL(accepted()), SLOT(addItem()));
    connect(ui->buttonBox, SIGNAL(rejected()), SLOT(reject()));
}

AddDepartment::~AddDepartment()
{
    delete ui;
}

void AddDepartment::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void AddDepartment::setEditable(int id)
{
    idFromDb = id;
    DepartmentModel *model = new DepartmentModel;

    ui->eTitle->setText(model->selectById(id));

    disconnect(ui->buttonBox, SIGNAL(accepted()), 0, 0);
    connect(ui->buttonBox, SIGNAL(accepted()), SLOT(editItem()));
}

void AddDepartment::addItem()
{
    if (ui->eTitle->text() == "") {
        QMessageBox msgBox;
        msgBox.setText(trUtf8("Не введено наименование"));
        msgBox.exec();
        return;
    }

    DepartmentModel *model = new DepartmentModel;

    if (Db::connected())
        model->insert(ui->eTitle->text());
    else {
        QMessageBox msgBox;
        // FIXME: doesn't work
        msgBox.setText(Db::setError().text());
        msgBox.exec();
    }

    accept();
}

void AddDepartment::editItem()
{
    if (ui->eTitle->text() == "") {
        QMessageBox msgBox;
        msgBox.setText(trUtf8("Не введено наименование"));
        msgBox.exec();
        return;
    }

    DepartmentModel *model = new DepartmentModel;
    model->update(idFromDb, ui->eTitle->text());

    accept();
}
