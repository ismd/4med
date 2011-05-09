#ifndef DB_H
#define DB_H

#include <QtSql>

namespace Db
{
    static QSqlDatabase db;
    static QSqlError error;
    static bool ok;

    bool connect();
    bool connected();
    QSqlError setError();
    void setError(QSqlError);
    QSqlError getError();
    int getCount(QString tableName);
}

#endif // DB_H
