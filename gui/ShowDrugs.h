#ifndef SHOWDRUGS_H
#define SHOWDRUGS_H

#include <QWidget>

namespace Ui {
    class ShowDrugs;
}

class ShowDrugs : public QWidget
{
    Q_OBJECT

public:
    explicit ShowDrugs(QWidget *parent = 0);
    ~ShowDrugs();

private slots:
    void showRegistrations();
    void fillList();
    void fillCounts();
    void editDrug();
    void delDrug();

private:
    Ui::ShowDrugs *ui;
};

#endif // SHOWDRUGS_H
