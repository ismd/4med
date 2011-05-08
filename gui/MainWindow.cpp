#include <QtSql>
#include <QMessageBox>
#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "lib/DrugModel.h"
#include "lib/DefaultModel.h"
#include "gui/AddDrug.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->aShowDepartments, SIGNAL(activated()), SLOT(showDepartments()));
    connect(ui->aShowDrugs, SIGNAL(activated()), SLOT(showDrugs()));
    connect(ui->aShowRecipients, SIGNAL(activated()), SLOT(showRecipients()));
    connect(ui->aAddDepartment, SIGNAL(activated()), SLOT(addDepartment()));
    connect(ui->aAddDrug, SIGNAL(activated()), SLOT(addDrug()));
    connect(ui->aAddRecipient, SIGNAL(activated()), SLOT(addRecipient()));
    connect(ui->aAddRegistration, SIGNAL(activated()), SLOT(addRegistration()));

    // Check if we can connect to the database
    DefaultModel* dm = new DefaultModel;

    if (!dm->connected()) {
        QMessageBox msgBox;
        msgBox.setText(dm->getError().text());
        msgBox.exec();

        setStatusMessage(tr("Can't connect to MySQL"));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::setStatusMessage(QString message)
{
    ui->statusBar->showMessage(message);
}

void MainWindow::showDepartments()
{

}

void MainWindow::showDrugs()
{
    DrugModel *dm = new DrugModel();
    dm->selectAll();

    //ui->tableView->setModel(dm->getModel());
}

void MainWindow::showRecipients()
{

}

void MainWindow::addDepartment()
{

}

void MainWindow::addDrug()
{
    AddDrug* ad = new AddDrug(this);
    ad->show();
}

void MainWindow::addRecipient()
{

}

void MainWindow::addRegistration()
{

}
