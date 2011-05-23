#include "gui/ShowDrugs.h"
#include "ui_ShowDrugs.h"

ShowDrugs::ShowDrugs(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShowDrugs)
{
    ui->setupUi(this);
}

ShowDrugs::~ShowDrugs()
{
    delete ui;
}
