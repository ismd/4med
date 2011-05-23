#ifndef DEPARTMENTMODEL_H
#define DEPARTMENTMODEL_H

#include <QString>
#include <QtSql>
#include "lib/DefaultModel.h"

class DepartmentModel : virtual public DefaultModel
{
private:
    QSqlQuery query;

public:
    bool insert(QString title);
    bool del(int id);
    bool update(int id, QString title);
    QString selectById(int);
    QMap<int, QString> select();
    QSqlQueryModel* selectAll();
    QSqlQueryModel* getModel();
};

#endif // DEPARTMENTMODEL_H
