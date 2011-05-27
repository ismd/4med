#include <QtSql>
#include "RecipientModel.h"
#include "lib/Db.h"

bool RecipientModel::insert(QString fio, int idDepartment)
{
    if (!Db::connected())
        return false;

    if (!query.prepare("INSERT INTO Recipient (fio, idDepartment) values (:fio, :idDepartment)"))
        return false;

    query.bindValue(":fio", fio);
    query.bindValue(":idDepartment", idDepartment);

    if (query.exec())
        return true;
    else {
        Db::setError();
        return false;
    }
}

bool RecipientModel::del(int id)
{
    if (!Db::connected())
        return false;

    query.prepare("DELETE FROM Recipient WHERE id=:id");
    query.bindValue(":id", id);

    if (query.exec())
        return true;
    else {
        Db::setError(query.lastError());
        return false;
    }
}

bool RecipientModel::update(int id, QString fio, int idDepartment)
{
    if (!Db::connected())
        return false;

    query.prepare("UPDATE Recipient SET fio=:fio, idDepartment=:idDepartment WHERE id=:id");
    query.bindValue(":id", id);
    query.bindValue(":idDepartment", idDepartment);
    query.bindValue(":fio", fio);

    if (query.exec())
        return true;
    else {
        Db::setError();
        return false;
    }
}

QString RecipientModel::selectById(int id)
{
    if (!Db::connected())
        return "";

    QSqlQuery q("SELECT fio FROM Recipient WHERE id=" + QString::number(id) + " LIMIT 1");
    q.next();

    return q.value(0).toString();
}

QSqlQueryModel* RecipientModel::select(int idDepartment)
{
    if (!Db::connected())
        return false;
    else {
        QString queryStr = "SELECT fio, id FROM Recipient WHERE idDepartment=" + \
                QString::number(idDepartment) + " ORDER BY fio";

        QSqlQuery query(queryStr);

        model.setQuery(query);

        if (model.lastError().isValid())
            Db::setError(model.lastError());
    }

    return &model;
}

QMap<int, QString> RecipientModel::selectMap(int idDepartment)
{
    QMap<int, QString> map;

    if (!Db::connected())
        return map;

    QSqlQuery q("SELECT id, fio FROM Recipient WHERE idDepartment=" + QString::number(idDepartment));

    while (q.next())
        map[q.value(0).toInt()] = q.value(1).toString();

    return map;
}

QList<QString> RecipientModel::selectList(int idDepartment)
{
    QList<QString> ls;

    if (!Db::connected())
        return ls;

    QSqlQuery q("SELECT fio FROM Recipient WHERE idDepartment=" + QString::number(idDepartment));

    while (q.next())
        ls.append(q.value(0).toString());

    return ls;
}
