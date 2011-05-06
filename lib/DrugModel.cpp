#include <QtSql>
#include <QDebug>
#include "DrugModel.h"

DrugModel::DrugModel()
{

}

bool DrugModel::insert(item i)
{
    if (!ok) {
        setError(db.lastError().text());
        return false;
    }

    query.prepare("INSERT INTO Drug (id, title) values (:id, :title)");
    query.bindValue(":id", i.id);
    query.bindValue(":title", i.title);

    if (query.exec())
        return true;
    else {
        setError(db.lastError().text());
        return false;
    }
}

bool DrugModel::del(int id)
{
    if (!ok) {
        setError(db.lastError().text());
        return false;
    }

    query.prepare("DELETE FROM Drug WHERE id=:id");
    query.bindValue(":id", id);

    if (query.exec())
        return true;
    else {
        setError(db.lastError().text());
        return false;
    }
}

bool DrugModel::update(item i)
{
    if (!ok) {
        setError(db.lastError().text());
        return false;
    }

    query.prepare("UPDATE Drug SET title=:title WHERE id=:id");
    query.bindValue(":id", i.id);
    query.bindValue(":title", i.title);

    if (query.exec())
        return true;
    else {
        setError(db.lastError().text());
        return false;
    }
}

bool DrugModel::select(int id)
{
    if (!ok) {
        setError(db.lastError());
        return false;
    }

    query.prepare("SELECT id, title FROM Drug WHERE id=:id LIMIT 1");
    query.bindValue(":id", id);
    query.exec();
}

QSqlQueryModel* DrugModel::selectAll()
{
    if (!ok)
        setError(db.lastError());
    else {
//        model.setTable("Drug");
//        model.select();
//        model.setEditStrategy(QSqlTableModel::OnFieldChange);
        model.setQuery("SELECT id, title FROM Drug");

        if (model.lastError().isValid())
            setError(model.lastError());
    }

    return &model;
}

QSqlQueryModel* DrugModel::getModel()
{
    return &model;
}
