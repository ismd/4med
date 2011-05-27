#ifndef SHOWREGISTRATIONS_H
#define SHOWREGISTRATIONS_H

#include <QWidget>

namespace Ui {
    class ShowRegistrations;
}

class ShowRegistrations : public QWidget
{
    Q_OBJECT

public:
    explicit ShowRegistrations(QWidget *parent = 0, int idDrug = -1);
    ~ShowRegistrations();

private slots:
    void addItem();
    void editItem();
    void delItem();

private:
    Ui::ShowRegistrations *ui;
};

#endif // SHOWREGISTRATIONS_H
