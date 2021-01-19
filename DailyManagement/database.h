#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QString>
#include <QSqlTableModel>

class dataBase
{
public:
    dataBase();
    ~dataBase();
    QSqlDatabase * db;
    bool connect(QString username, QString password);
    void disconnect();
};

#endif // DATABASE_H
