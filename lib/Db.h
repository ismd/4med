#ifndef DB_H
#define DB_H

#include <QtSql>

namespace Db
{
    static QSqlDatabase db;
    static QSqlError error;
    static bool ok;

    bool connect();
    QSqlError setError();
    void setError(QSqlError);
    QSqlError getError();
}

#endif // DB_H
