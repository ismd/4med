#include "gui/AddDrug.h"
#include "ui_AddDrug.h"
#include "lib/DrugModel.h"

AddDrug::AddDrug(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDrug)
{
    ui->setupUi(this);

    connect(ui->buttonBox, SIGNAL(accepted()), SLOT(addDrug()));
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

void AddDrug::addDrug()
{
    if (ui->eTitle->text() == "")
        return;

    DrugModel* dm = new DrugModel;

    if (dm->connected())
        dm->insert(ui->eTitle->text());

    // TODO: don't know how to set status bar message of parent
//    else
//        parent()->setStatusMessage(tr("!!!"));
}
