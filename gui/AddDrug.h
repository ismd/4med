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

private slots:
    void addItem();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::AddDrug *ui;
};

#endif // ADDDRUG_H
