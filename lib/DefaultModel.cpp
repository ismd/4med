#include <QtSql>
#include "DefaultModel.h"

DefaultModel::DefaultModel()
{
    db = QSqlDatabase::addDatabase("QMYSQL");

    db.setHostName("localhost");
    db.setDatabaseName("4med");
    db.setUserName("root");
    db.setPassword("123");

    ok = db.open();

    if (!ok)
        setError(db.lastError().text());
}

bool DefaultModel::connected()
{
    return ok;
}

void DefaultModel::setError(QSqlError err)
{
    error = err;
    qDebug() << err;
}

QSqlError DefaultModel::getError()
{
    return error;
}
