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

    if (query.exec())
        return true;
    else {
        Db::setError();
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

//bool DrugModel::select(int id)
//{
//    // TODO: доделать
//    if (!ok) {
//        setError(db.lastError());
//        return false;
//    }
//
//    query.prepare("SELECT id, title FROM Drug WHERE id=:id LIMIT 1");
//    query.bindValue(":id", id);
//    query.exec();
//}

QSqlQueryModel* DepartmentModel::selectAll()
{
    if (!Db::connected())
        return false;
    else {
        model.setQuery("SELECT id, title FROM Department");

        if (model.lastError().isValid())
            Db::setError(model.lastError());
    }

    return &model;
}

QSqlQueryModel* DepartmentModel::getModel()
{
    return &model;
}
