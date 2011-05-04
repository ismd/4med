#include "MainWindow.h"
#include "ui_mainwindow.h"
#include "lib/DrugModel.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->aAddDepartment, SIGNAL(activated()), SLOT(addDepartment()));
    connect(ui->aAddDrug, SIGNAL(activated()), SLOT(addDrug));
    connect(ui->aAddRecipient, SIGNAL(activated()), SLOT(addRecipient));
    connect(ui->aAddRegistration, SIGNAL(activated()), SLOT(addRegistration));
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

void MainWindow::addDepartment()
{

}

void MainWindow::addDrug()
{
    DrugModel* dm = new DrugModel;
    dm->addItem();
}

void MainWindow::addRecipient()
{

}

void MainWindow::addRegistration()
{

}
