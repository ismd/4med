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
        Db::setError();
        return false;
    }
}

bool RecipientModel::update(int id, QString fio, int idDepartment)
{
    if (!Db::connected())
        return false;

    query.prepare("UPDATE Department SET fio=:fio, idDepartment=:idDepartment WHERE id=:id");
    query.bindValue(":id", id);
    query.bindValue(":fio", fio);
    query.bindValue(":idDepartment", idDepartment);

    if (query.exec())
        return true;
    else {
        Db::setError();
        return false;
    }
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
