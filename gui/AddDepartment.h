#ifndef ADDDEPARTMENT_H
#define ADDDEPARTMENT_H

#include <QDialog>

namespace Ui {
    class AddDepartment;
}

class AddDepartment : public QDialog {
    Q_OBJECT
public:
    AddDepartment(QWidget *parent = 0);
    ~AddDepartment();

private slots:
    void addItem();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::AddDepartment *ui;
};

#endif // ADDDEPARTMENT_H
