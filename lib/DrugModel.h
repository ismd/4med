#ifndef DRUGMODEL_H
#define DRUGMODEL_H

#include <QString>
#include <QtSql>

class DrugModel
{
private:
    struct item
    {
        int id;
        QString title;
    };

    QSqlQuery query;
    QSqlDatabase db;
    bool ok;
    QSqlError error;
    QSqlQueryModel model;

public:
    DrugModel();

    void setError(QSqlError);
    QSqlError getError();
    bool insert(item);
    bool del(int id);
    bool update(item);
    bool select(int id);
    QSqlQueryModel* selectAll();
    QSqlQueryModel* getModel();
};

#endif // DRUGMODEL_H
