/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri May 6 18:54:56 2011
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTableView>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *aShowDrugs;
    QAction *aShowDepartments;
    QAction *aShowRecipients;
    QAction *aAddRegistration;
    QAction *aAddDrug;
    QAction *aAddDepartment;
    QAction *aAddRecipient;
    QWidget *centralWidget;
    QTableView *tableView;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_3;
    QMenu *menu_4;
    QMenu *menu_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 400);
        aShowDrugs = new QAction(MainWindow);
        aShowDrugs->setObjectName(QString::fromUtf8("aShowDrugs"));
        aShowDepartments = new QAction(MainWindow);
        aShowDepartments->setObjectName(QString::fromUtf8("aShowDepartments"));
        aShowRecipients = new QAction(MainWindow);
        aShowRecipients->setObjectName(QString::fromUtf8("aShowRecipients"));
        aAddRegistration = new QAction(MainWindow);
        aAddRegistration->setObjectName(QString::fromUtf8("aAddRegistration"));
        aAddDrug = new QAction(MainWindow);
        aAddDrug->setObjectName(QString::fromUtf8("aAddDrug"));
        aAddDepartment = new QAction(MainWindow);
        aAddDepartment->setObjectName(QString::fromUtf8("aAddDepartment"));
        aAddRecipient = new QAction(MainWindow);
        aAddRecipient->setObjectName(QString::fromUtf8("aAddRecipient"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(20, 20, 471, 301));
        tableView->setSortingEnabled(true);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 20));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_3 = new QMenu(menu);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        menu_4 = new QMenu(menu);
        menu_4->setObjectName(QString::fromUtf8("menu_4"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(menu_3->menuAction());
        menu->addAction(menu_4->menuAction());
        menu_3->addAction(aShowDrugs);
        menu_3->addAction(aShowRecipients);
        menu_3->addAction(aShowDepartments);
        menu_4->addAction(aAddRegistration);
        menu_4->addAction(aAddDrug);
        menu_4->addAction(aAddRecipient);
        menu_4->addAction(aAddDepartment);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        aShowDrugs->setText(QApplication::translate("MainWindow", "\320\233\320\265\320\272\320\260\321\200\321\201\321\202\320\262\320\265\320\275\320\275\321\213\320\265 \321\201\321\200\320\265\320\264\321\201\321\202\320\262\320\260", 0, QApplication::UnicodeUTF8));
        aShowDepartments->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\264\320\265\320\273\321\213", 0, QApplication::UnicodeUTF8));
        aShowRecipients->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\270", 0, QApplication::UnicodeUTF8));
        aAddRegistration->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\270\321\205\320\276\320\264/\321\200\320\260\321\201\321\205\320\276\320\264", 0, QApplication::UnicodeUTF8));
        aAddDrug->setText(QApplication::translate("MainWindow", "\320\233\320\265\320\272\320\260\321\200\321\201\321\202\320\262\320\265\320\275\320\275\320\276\320\265 \321\201\321\200\320\265\320\264\321\201\321\202\320\262\320\276", 0, QApplication::UnicodeUTF8));
        aAddDepartment->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\264\320\265\320\273", 0, QApplication::UnicodeUTF8));
        aAddRecipient->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("MainWindow", "\320\243\321\207\321\221\321\202", 0, QApplication::UnicodeUTF8));
        menu_3->setTitle(QApplication::translate("MainWindow", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200", 0, QApplication::UnicodeUTF8));
        menu_4->setTitle(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        menu_2->setTitle(QApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
