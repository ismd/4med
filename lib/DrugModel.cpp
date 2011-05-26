#include <QtSql>
#include <QDebug>
#include "DrugModel.h"
#include "lib/Db.h"

bool DrugModel::insert(QString title)
{
    if (!Db::connected())
        return false;

    if (!query.prepare("INSERT INTO Drug (title) values (:title)"))
        return false;

    query.bindValue(":title", title);

    if (query.exec())
        return true;
    else {
        Db::setError();
        return false;
    }
}

bool DrugModel::del(int id)
{
    if (!Db::connected())
        return false;

    query.prepare("DELETE FROM Drug WHERE id=:id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        Db::setError(query.lastError());
        return false;
    }

    query.clear();
    query.prepare("DELETE FROM Registration WHERE idDrug=:id");
    query.bindValue(":id", id);

    if (query.exec())
        return true;
    else {
        Db::setError(query.lastError());
        return false;
    }
}

bool DrugModel::update(int id, QString title)
{
    if (!Db::connected())
        return false;

    query.prepare("UPDATE Drug SET title=:title WHERE id=:id");
    query.bindValue(":id", id);
    query.bindValue(":title", title);

    if (query.exec())
        return true;
    else {
        Db::setError(query.lastError());
        return false;
    }
}

QString DrugModel::selectById(int id)
{
    if (!Db::connected())
        return "";

    QSqlQuery q("SELECT title FROM Drug WHERE id=" + QString::number(id) + " LIMIT 1");
    q.next();

    return q.value(0).toString();
}

QSqlQueryModel* DrugModel::selectAll()
{
    if (!Db::connected())
        return false;

    model.setQuery("SELECT title, id FROM Drug ORDER BY title");

    if (model.lastError().isValid())
        Db::setError(model.lastError());

    return &model;
}

QSqlQueryModel* DrugModel::getModel()
{
    return &model;
}

/**
 * Returns list
 * 0 - received count
 * 1 - gave count
 * 2 - balance
 */
QList<int> DrugModel::getCounts(int id)
{
    QList<int> ls;

    if (!Db::connected())
        return ls;

    QSqlQuery q("SELECT MAX(id) FROM Registration");
    q.next();
    int maxId = q.value(0).toInt();

    QString queryStr;
    queryStr = "SELECT count(*) FROM Registration WHERE idDrug=";
    queryStr += QString::number(id);
    queryStr += " AND received=1";

    QSqlQuery q1(queryStr);
    q1.next();
    ls.append(q1.value(0).toInt());

    queryStr = "SELECT count(*) FROM Registration WHERE idDrug=";
    queryStr += QString::number(id);
    queryStr += " AND received=0";

    QSqlQuery q2(queryStr);
    q2.next();
    ls.append(q2.value(0).toInt());

    queryStr = "SELECT balance FROM Registration WHERE id=";
    queryStr += QString::number(maxId);

    QSqlQuery q3(queryStr);
    q3.next();
    ls.append(q3.value(0).toInt());

    return ls;
}
