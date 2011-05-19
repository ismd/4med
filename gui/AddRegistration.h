#ifndef ADDREGISTRATION_H
#define ADDREGISTRATION_H

#include <QDialog>
#include <QSqlQueryModel>

namespace Ui {
    class AddRegistration;
}

class AddRegistration : public QDialog
{
    Q_OBJECT

public:
    explicit AddRegistration(QWidget *parent = 0);
    ~AddRegistration();

private:
    Ui::AddRegistration *ui;
    QSqlQueryModel *drugModel;
    QSqlQueryModel *departmentModel;
    QSqlQueryModel *recipientModel;

private slots:
    void addItem();
    void setReceived();
    void fillRecipients();
};

#endif // ADDREGISTRATION_H
