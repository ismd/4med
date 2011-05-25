#ifndef DRUGMODEL_H
#define DRUGMODEL_H

#include <QString>
#include <QtSql>
#include "lib/DefaultModel.h"

class DrugModel : virtual public DefaultModel
{
private:
    QSqlQuery query;

public:
    bool insert(QString title);
    bool del(int id);
    bool update(int id, QString title);
    QString selectById(int id);
    QSqlQueryModel* selectAll();
    QSqlQueryModel* getModel();
};

#endif // DRUGMODEL_H
