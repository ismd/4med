#ifndef SHOWRECIPIENTS_H
#define SHOWRECIPIENTS_H

#include <QWidget>
#include <QString>
#include <QMap>

namespace Ui {
    class ShowRecipients;
}

class ShowRecipients : public QWidget
{
    Q_OBJECT

public:
    explicit ShowRecipients(QWidget *parent = 0);
    ~ShowRecipients();

private slots:
    void editItem();
    void delItem();
    void fillTree();

private:
    Ui::ShowRecipients *ui;
};

#endif // SHOWRECIPIENTS_H
