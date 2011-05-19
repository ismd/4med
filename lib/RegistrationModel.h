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
    bool insert(int idDrug, QDateTime happened, int amount, bool received, int idRecipient);
};

#endif // REGISTRATIONMODEL_H
