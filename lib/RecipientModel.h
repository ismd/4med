#ifndef RECIPIENTMODEL_H
#define RECIPIENTMODEL_H

#include <QString>
#include <QtSql>
#include "lib/DefaultModel.h"

class RecipientModel : virtual public DefaultModel
{
private:
    QSqlQuery query;

public:
    bool insert(QString fio, int idDepartment);
    bool del(int id);
    bool update(int id, QString fio, int idDepartment);
    QSqlQueryModel* select(int idDepartment);
    QString selectById(int);
    QMap<int, QString> selectMap(int idDepartment);
    QList<QString> selectList(int idDepartment);
    QSqlQueryModel* selectAll();
};

#endif // RECIPIENTMODEL_H
