#ifndef REGISTRATIONMODEL_H
#define REGISTRATIONMODEL_H

#include <QtSql>
#include <QDateTime>
#include "lib/DefaultModel.h"

class RegistrationModel : virtual public DefaultModel
{
private:
    QSqlQuery query;

public:
    struct registration {
        int id;
        int idRecipient;
        QString fioRecipient;
        QDateTime happened;
        int amount;
        bool received;
        int balance;
    };

    bool insert(int idDrug, QDateTime happened, int amount, bool received, int idRecipient);
    bool del(int id);
    QList<registration> getRegistrations(int id);
};

#endif // REGISTRATIONMODEL_H
