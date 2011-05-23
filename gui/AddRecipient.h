#ifndef ADDRECIPIENT_H
#define ADDRECIPIENT_H

#include <QDialog>
#include <QSqlQueryModel>

namespace Ui {
    class AddRecipient;
}

class AddRecipient : public QDialog
{
    Q_OBJECT

public:
    explicit AddRecipient(QWidget *parent = 0);
    ~AddRecipient();
    void setEditable(int id, int idDepartment);

private slots:
    void addItem();
    void editItem();

private:
    Ui::AddRecipient *ui;
    QSqlQueryModel *depall;
    int idFromDb;
};

#endif // ADDRECIPIENT_H
