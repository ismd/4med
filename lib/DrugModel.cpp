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
