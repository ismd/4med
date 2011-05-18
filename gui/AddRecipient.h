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

private slots:
    void addItem();

private:
    Ui::AddRecipient *ui;
    QSqlQueryModel *depall;
};

#endif // ADDRECIPIENT_H
