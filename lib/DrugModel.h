#ifndef DRUGMODEL_H
#define DRUGMODEL_H

#include <QString>
#include <QtSql>
#include "lib/DefaultModel.h"

class DrugModel : public DefaultModel
{
private:
    QSqlQuery query;

public:
    DrugModel();
    bool insert(QString title);
    bool del(int id);
    bool update(int id, QString title);
    bool select(int id);
    QSqlQueryModel* selectAll();
    QSqlQueryModel* getModel();
};

#endif // DRUGMODEL_H
