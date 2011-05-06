#ifndef DEFAULTMODEL_H
#define DEFAULTMODEL_H

#include <QtSql>

class DefaultModel
{
protected:
    QSqlQuery query;
    QSqlDatabase db;
    bool ok;
    QSqlError error;
    QSqlQueryModel model;

public:
    DefaultModel();
    bool connected();
    void setError(QSqlError);
    QSqlError getError();
};

#endif // DEFAULTMODEL_H
