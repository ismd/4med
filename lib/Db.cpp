#include <QtSql>
#include "Db.h"

namespace Db
{
    bool connect()
    {
        db = QSqlDatabase::addDatabase("QMYSQL");

        db.setHostName("localhost");
        db.setDatabaseName("4med");
        db.setUserName("root");
        db.setPassword("123");

        ok = db.open();

        if (!ok) {
            setError();
            return false;
        }

        return true;
    }

    QSqlError setError()
    {
        setError(db.lastError());

        return error;
    }

    void setError(QSqlError err)
    {
        error = err;
        qDebug() << error.text();
    }

    QSqlError getError()
    {
        return error;
    }
}
