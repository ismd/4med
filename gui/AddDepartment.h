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
    void setEditable(int id);

private slots:
    void addItem();
    void editItem();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::AddDepartment *ui;
    int idFromDb;
};

#endif // ADDDEPARTMENT_H
