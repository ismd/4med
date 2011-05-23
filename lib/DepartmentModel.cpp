#include <QtSql>
#include <QDebug>
#include "DepartmentModel.h"
#include "lib/Db.h"

bool DepartmentModel::insert(QString title)
{
    if (!Db::connected())
        return false;

    if (!query.prepare("INSERT INTO Department (title) values (:title)"))
        return false;

    query.bindValue(":title", title);

    if (query.exec())
        return true;
    else {
        Db::setError();
        return false;
    }
}

bool DepartmentModel::del(int id)
{
    if (!Db::connected())
        return false;

    query.prepare("DELETE FROM Department WHERE id=:id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        Db::setError(query.lastError());
        return false;
    }

    query.clear();
    query.prepare("DELETE FROM Recipient WHERE idDepartment=:id");
    query.bindValue(":id", id);

    if (query.exec())
        return true;
    else {
        Db::setError(query.lastError());
        return false;
    }
}

bool DepartmentModel::update(int id, QString title)
{
    if (!Db::connected())
        return false;

    query.prepare("UPDATE Department SET title=:title WHERE id=:id");
    query.bindValue(":id", id);
    query.bindValue(":title", title);

    if (query.exec())
        return true;
    else {
        Db::setError();
        return false;
    }
}

QString DepartmentModel::selectById(int id)
{
    if (!Db::connected())
        return "";

    QSqlQuery q("SELECT title FROM Department WHERE id=" + QString::number(id) + " LIMIT 1");
    q.next();

    return q.value(0).toString();
}

QMap<int, QString> DepartmentModel::select()
{
    QMap<int, QString> map;

    if (!Db::connected())
        return map;

    QSqlQuery q("SELECT id, title FROM Department ORDER BY id");

    while (q.next())
        map[q.value(0).toInt()] = q.value(1).toString();

    return map;
}

QSqlQueryModel* DepartmentModel::selectAll()
{
    if (!Db::connected())
        return false;
    else {
        model.setQuery("SELECT title, id FROM Department ORDER BY title");

        if (model.lastError().isValid())
            Db::setError(model.lastError());
    }

    return &model;
}

QSqlQueryModel* DepartmentModel::getModel()
{
    return &model;
}
