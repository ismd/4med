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

        Db::ok = db.open();

        if (!ok) {
            setError();
            return false;
        }

        return true;
    }

    bool connected()
    {
        return ok;
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

    int getCount(QString tableName)
    {
        if (!connected())
            return -1;

        QSqlQuery query;

        // Don't know why query.bindValue don't work here
        query.prepare("SELECT * FROM " + tableName);

        query.exec();

        return query.size();
    }
}
