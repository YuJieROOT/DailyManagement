#include "database.h"
#include <QMessageBox>


dataBase::dataBase()
{

}
dataBase::~dataBase()
{

}

bool dataBase::connect(QString username, QString password)
{
    db = new QSqlDatabase;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
    {
        *db = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
    *db =QSqlDatabase::addDatabase("QMYSQL");
    }
    //连接数据库
    db->setHostName("rm-bp190fc4v6g0mfmmmno.mysql.rds.aliyuncs.com");
    db->setUserName(username);
    db->setPassword(password);
    db->setDatabaseName("daily_management");//使用的数据库
    if(!db->open())
    {
        return false;
    }
    else
    {
        return true;
    }
}

void dataBase::disconnect()
{
    QString connection;
    connection = db->connectionName();
    db->close();
    delete db;
    db = nullptr;
    QSqlDatabase::removeDatabase(connection);
}
