#ifndef ADDDRUG_H
#define ADDDRUG_H

#include <QDialog>

namespace Ui {
    class AddDrug;
}

class AddDrug : public QDialog {
    Q_OBJECT
public:
    AddDrug(QWidget *parent = 0);
    ~AddDrug();
    void setEditable(int id);

private slots:
    void addItem();
    void editItem();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::AddDrug *ui;
    int idFromDb;
};

#endif // ADDDRUG_H
