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

    connect(ui->bEdit, SIGNAL(clicked()), SLOT(editDrug()));
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

void ShowDrugs::editDrug()
{
    int idDrug = ui->drugsList->model()->index(ui->drugsList->currentIndex().row(), 1).data().toInt();

    AddDrug *editWindow = new AddDrug(this);
    editWindow->setEditable(idDrug);
    editWindow->show();

    connect(editWindow, SIGNAL(accepted()), SLOT(fillList()));
}
