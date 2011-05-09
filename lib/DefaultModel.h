#ifndef DEFAULTMODEL_H
#define DEFAULTMODEL_H

#include <QtSql>

// FIXME: need to make this class abstract
class DefaultModel
{
protected:
    QSqlQueryModel model;

//public:
//    virtual bool insert();
//    virtual bool del();
//    virtual bool update();
//    virtual QSqlQueryModel* selectAll();
};

#endif // DEFAULTMODEL_H
