#include "RegistrationModel.h"
#include "lib/Db.h"
#include <QDebug>

bool RegistrationModel::insert(int idDrug, QDateTime happened, int amount, bool received, int idDepartment, int idRecipient)
{
    if (!Db::connected())
        return false;

    QString queryStr = "SELECT MAX(id) FROM Registration WHERE idDrug=";
    queryStr += QString::number(idDrug);
    queryStr += " LIMIT 1";

    QSqlQuery q(queryStr);
    q.next();
    int maxId = q.value(0).toInt();

    queryStr = "SELECT balance FROM Registration WHERE id=";
    queryStr += QString::number(maxId);
    queryStr += " LIMIT 1";

    QSqlQuery q1(queryStr);
    q1.next();
    int curBalance = q1.value(0).toInt();

    if (received)
        curBalance += amount;
    else
        curBalance -= amount;

    query.prepare("INSERT INTO Registration (idDrug, happened, amount, received, idDepartment, idRecipient, balance) \
                  VALUES (:idDrug, :happened, :amount, :received, :idDepartment, :idRecipient, :balance)");

    query.bindValue(":idDrug", idDrug);
    query.bindValue(":happened", happened.toString("yyyy-MM-dd hh:mm:ss"));
    query.bindValue(":amount", amount);
    query.bindValue(":received", received);
    query.bindValue(":idDepartment", (idDepartment == -1 ? "-1" : QString::number(idDepartment)));
    query.bindValue(":idRecipient", (idRecipient == -1 ? "-1" : QString::number(idRecipient)));
    query.bindValue(":balance", QString::number(curBalance));

    if (query.exec())
        return true;
    else {
        Db::setError(query.lastError());
        return false;
    }
}

QList<RegistrationModel::registration> RegistrationModel::getRegistrations(int id)
{
    QList<RegistrationModel::registration> ls;

    if (!Db::connected()) {
        return ls;
    }

    QString queryStr = "SELECT a.idRecipient, a.happened, a.amount, a.received, a.balance, b.fio, c.title ";
    queryStr += "FROM Registration a LEFT OUTER JOIN Recipient b ON a.idRecipient=b.id ";
    queryStr += "LEFT OUTER JOIN Department c ON a.idDepartment=c.id WHERE a.idDrug=";
    queryStr += QString::number(id);
    queryStr += " ORDER BY a.id DESC";

    QSqlQuery q(queryStr);

    while (q.next()) {
        RegistrationModel::registration reg;
        reg.idRecipient = q.value(0).toInt();
        reg.happened = q.value(1).toDateTime();
        reg.amount = q.value(2).toInt();
        reg.received = q.value(3).toBool();
        reg.balance = q.value(4).toInt();
        reg.fioRecipient = q.value(5).toString();
        reg.titleDepartment = q.value(6).toString();

        ls.append(reg);
    }

    return ls;
}

bool RegistrationModel::del(int id)
{
    // Don't use this method. I don't like to realise it
    return false;
//    if (!Db::connected())
//        return false;

//    query.prepare("DELETE FROM Registration WHERE id=:id");
//    query.bindValue(":id", id);

//    if (query.exec())
//        return true;
//    else {
//        Db::setError(query.lastError());
//        return false;
//    }
}
