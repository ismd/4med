#ifndef SHOWRECIPIENTS_H
#define SHOWRECIPIENTS_H

#include <QWidget>

namespace Ui {
    class ShowRecipients;
}

class ShowRecipients : public QWidget
{
    Q_OBJECT

public:
    explicit ShowRecipients(QWidget *parent = 0);
    ~ShowRecipients();

private:
    Ui::ShowRecipients *ui;
    void fillTree();
};

#endif // SHOWRECIPIENTS_H
