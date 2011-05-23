#include <QtSql>
#include <QMessageBox>
#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "lib/Db.h"
#include "gui/AddDrug.h"
#include "gui/AddDepartment.h"
#include "gui/AddRecipient.h"
#include "gui/AddRegistration.h"
#include "gui/ShowRecipients.h"
#include "gui/ShowDrugs.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->aShowDrugs, SIGNAL(activated()), SLOT(showDrugs()));
    connect(ui->aShowRecipients, SIGNAL(activated()), SLOT(showRecipients()));
    connect(ui->aAddDepartment, SIGNAL(activated()), SLOT(addDepartment()));
    connect(ui->aAddDrug, SIGNAL(activated()), SLOT(addDrug()));
    connect(ui->aAddRecipient, SIGNAL(activated()), SLOT(addRecipient()));
    connect(ui->aAddRegistration, SIGNAL(activated()), SLOT(addRegistration()));

    // Connecting to the database
    if (!Db::connect()) {
        QMessageBox msgBox;
        msgBox.setText(Db::getError().text());
        msgBox.exec();

        setStatusMessage(trUtf8("Не могу подключиться к базе"));
    }

    updateCounts();
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

void MainWindow::updateCounts()
{
    ui->lDepartments->setText(QString::number(Db::getCount(QString("Department"))));
    ui->lDrugs->setText(QString::number(Db::getCount(QString("Drug"))));
    ui->lRecipients->setText(QString::number(Db::getCount("Recipient")));
    ui->lRegistrations->setText(QString::number(Db::getCount("Registration")));
}

void MainWindow::setStatusMessage(QString message)
{
    ui->statusBar->showMessage(message);
}

void MainWindow::showDrugs()
{
    ShowDrugs *sd = new ShowDrugs;
    sd->show();

    // FIXME: doesn't work
    connect(sd, SIGNAL(destroyed()), SLOT(updateCounts()));
}

void MainWindow::showRecipients()
{
    ShowRecipients *sr = new ShowRecipients;
    sr->show();

    // FIXME: doesn't work
    connect(sr, SIGNAL(destroyed()), SLOT(updateCounts()));
}

void MainWindow::addDepartment()
{
    AddDepartment *ad = new AddDepartment(this);
    ad->show();

    connect(ad, SIGNAL(accepted()), SLOT(updateCounts()));
}

void MainWindow::addDrug()
{
    AddDrug *ad = new AddDrug(this);
    ad->show();

    connect(ad, SIGNAL(accepted()), SLOT(updateCounts()));
}

void MainWindow::addRecipient()
{
    AddRecipient *ar = new AddRecipient(this);
    ar->show();

    connect(ar, SIGNAL(accepted()), SLOT(updateCounts()));
}

void MainWindow::addRegistration()
{
    AddRegistration *ar = new AddRegistration(this);
    ar->show();

    connect(ar, SIGNAL(accepted()), SLOT(updateCounts()));
}
