#include "gui/ShowRecipients.h"
#include "ui_ShowRecipients.h"
#include "lib/DepartmentModel.h"
#include "lib/RecipientModel.h"

ShowRecipients::ShowRecipients(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShowRecipients)
{
    ui->setupUi(this);

    fillTree();
}

void ShowRecipients::fillTree()
{
    DepartmentModel *dm = new DepartmentModel;
    QMap<int, QString> departments = dm->select();

    foreach (int key, departments.keys()) {
        QTreeWidgetItem *item = new QTreeWidgetItem(0);
        item->setText(0, departments[key]);

        RecipientModel *rm = new RecipientModel;
        foreach (QString fio, rm->selectList(key)) {
            QTreeWidgetItem *child = new QTreeWidgetItem(0);
            child->setText(0, fio);
            item->addChild(child);
        }

        ui->treeWidget->addTopLevelItem(item);
    }
}

ShowRecipients::~ShowRecipients()
{
    delete ui;
}
