#include "RegistrationModel.h"
#include "lib/Db.h"
#include <QDebug>

bool RegistrationModel::insert(int idDrug, QDateTime happened, int amount, bool received, int idRecipient)
{
    if (!Db::connected())
        return false;

    query.prepare("INSERT INTO Registration (idDrug, happened, amount, received, idRecipient) \
                  VALUES (:idDrug, :happened, :amount, :received, :idRecipient)");

    query.bindValue(":idDrug", idDrug);
    query.bindValue(":happened", happened.toString("yyyy-MM-dd hh:mm:ss"));
    query.bindValue(":amount", amount);
    query.bindValue(":received", received);
    query.bindValue(":idRecipient", (idRecipient == -1 ? "NULL" : QString::number(idRecipient)));

    if (query.exec())
        return true;
    else {
        Db::setError(query.lastError());
        return false;
    }
}
