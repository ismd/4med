#include <QMessageBox>
#include "gui/ShowRecipients.h"
#include "ui_ShowRecipients.h"
#include "lib/DepartmentModel.h"
#include "lib/RecipientModel.h"
#include "gui/AddDepartment.h"
#include "gui/AddRecipient.h"

ShowRecipients::ShowRecipients(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShowRecipients)
{
    ui->setupUi(this);

    fillTree();

    connect(ui->bEdit, SIGNAL(clicked()), SLOT(editItem()));
    connect(ui->bDel, SIGNAL(clicked()), SLOT(delItem()));
}

ShowRecipients::~ShowRecipients()
{
    delete ui;
}

void ShowRecipients::fillTree()
{
    ui->treeWidget->clear();

    DepartmentModel *dm = new DepartmentModel;
    QMap<int, QString> departmentsMap = dm->select();

    foreach (int key, departmentsMap.keys()) {
        QTreeWidgetItem *item = new QTreeWidgetItem(0);
        item->setText(0, departmentsMap[key]);
        item->setText(1, QString::number(key));

        RecipientModel *rm = new RecipientModel;
        QMap<int, QString> recipientsMap = rm->selectMap(key);

        foreach (int rKey, recipientsMap.keys()) {
            QTreeWidgetItem *child = new QTreeWidgetItem(0);

            child->setText(0, recipientsMap[rKey]);
            child->setText(1, QString::number(rKey));
            item->addChild(child);
        }

        ui->treeWidget->addTopLevelItem(item);
    }
}

void ShowRecipients::editItem()
{
    int curInd = ui->treeWidget->currentIndex().row();

    if (curInd == -1) {
        QMessageBox msgBox;
        msgBox.setText(trUtf8("Не выбран отдел либо сотрудник"));
        msgBox.exec();
        return;
    }

    // Check if current item is department or recipient
    bool departmentChecked = ui->treeWidget->currentIndex().parent() == ui->treeWidget->model()->index(-1, 0);

    if (departmentChecked) {
        AddDepartment *editWindow = new AddDepartment;
        int idDepartment = ui->treeWidget->currentItem()->data(1, 0).toInt();
        editWindow->setEditable(idDepartment);

        editWindow->show();
        connect(editWindow, SIGNAL(accepted()), SLOT(fillTree()));
    } else {
        AddRecipient *editWindow = new AddRecipient;
        int idRecipient = ui->treeWidget->currentItem()->data(1, 0).toInt();
        int idDepartment = ui->treeWidget->currentItem()->parent()->data(1, 0).toInt();

        editWindow->setEditable(idRecipient, idDepartment);

        editWindow->show();
        connect(editWindow, SIGNAL(accepted()), SLOT(fillTree()));
    }
}

void ShowRecipients::delItem()
{
    int curInd = ui->treeWidget->currentIndex().row();

    if (curInd == -1) {
        QMessageBox msgBox;
        msgBox.setText(trUtf8("Не выбран отдел либо сотрудник"));
        msgBox.exec();
        return;
    }

    int ret = QMessageBox::question(this, trUtf8("Удаление"), \
                                    trUtf8("Вы уверены, что хотите удалить запись?"), \
                                    QMessageBox::StandardButtons(QMessageBox::Cancel | QMessageBox::Yes));

    if (ret != QMessageBox::Yes)
        return;

    // Check if current item is department or recipient
    bool departmentChecked = ui->treeWidget->currentIndex().parent() == ui->treeWidget->model()->index(-1, 0);

    if (departmentChecked) {
        DepartmentModel *model = new DepartmentModel;
        int idDepartment = ui->treeWidget->currentItem()->data(1, 0).toInt();
        model->del(idDepartment);

        fillTree();
    } else {
        RecipientModel *model = new RecipientModel;
        int idRecipient = ui->treeWidget->currentItem()->data(1, 0).toInt();
        model->del(idRecipient);

        fillTree();
    }
}
