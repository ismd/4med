#include <QMessageBox>
#include "gui/AddDrug.h"
#include "ui_AddDrug.h"
#include "lib/DrugModel.h"
#include "lib/Db.h"

AddDrug::AddDrug(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDrug)
{
    ui->setupUi(this);

    connect(ui->buttonBox, SIGNAL(accepted()), SLOT(addItem()));
    connect(ui->buttonBox, SIGNAL(rejected()), SLOT(reject()));
}

AddDrug::~AddDrug()
{
    delete ui;
}

void AddDrug::changeEvent(QEvent *e)
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

void AddDrug::setEditable(int id)
{
    idFromDb = id;
    DrugModel *model = new DrugModel;

    ui->eTitle->setText(model->selectById(id));

    disconnect(ui->buttonBox, SIGNAL(accepted()), 0, 0);
    connect(ui->buttonBox, SIGNAL(accepted()), SLOT(editItem()));
}

void AddDrug::addItem()
{
    if (ui->eTitle->text() == "") {
        QMessageBox msgBox;
        msgBox.setText(trUtf8("Не введено наименование"));
        msgBox.exec();
        return;
    }

    DrugModel* model = new DrugModel;

    if (Db::connected())
        model->insert(ui->eTitle->text());
    else {
        QMessageBox msgBox;
        // FIXME: doesn't work
        msgBox.setText(Db::setError().text());
        msgBox.exec();
    }

    // TODO: don't know how to set status bar message of parent
//    else
//        parent()->setStatusMessage(tr("!!!"));

    accept();
}

void AddDrug::editItem()
{
    if (ui->eTitle->text() == "") {
        QMessageBox msgBox;
        msgBox.setText(trUtf8("Не введено наименование"));
        msgBox.exec();
        return;
    }

    DrugModel *model = new DrugModel;
    model->update(idFromDb, ui->eTitle->text());

    accept();
}
