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

void AddDepartment::addItem()
{
    if (ui->eTitle->text() == "")
        return;

    DepartmentModel* model = new DepartmentModel;

    if (Db::ok)
        model->insert(ui->eTitle->text());
    else {
        QMessageBox msgBox;
        // FIXME: doesn't work
        msgBox.setText(Db::setError().text());
        msgBox.exec();
    }
}
