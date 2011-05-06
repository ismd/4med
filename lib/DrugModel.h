#ifndef DRUGMODEL_H
#define DRUGMODEL_H

#include <QString>
#include <QtSql>
#include "lib/DefaultModel.h"

class DrugModel : public DefaultModel
{
private:
    struct item
    {
        int id;
        QString title;
    };

public:
    DrugModel();
    bool insert(item);
    bool del(int id);
    bool update(item);
    bool select(int id);
    QSqlQueryModel* selectAll();
    QSqlQueryModel* getModel();
};

#endif // DRUGMODEL_H
