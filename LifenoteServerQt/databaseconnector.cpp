#include "databaseconnector.h"
#include <QDebug>
DatabaseConnector::DatabaseConnector()
{
    OpenDatabase("lifenote.db");
}

DatabaseConnector::~DatabaseConnector()
{
    db.close();
}

void DatabaseConnector::OpenDatabase(QString db_path)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(db_path);
    if(!db.open())
    {
        qDebug() << "PROBLEM OF OPENING";
    }
}

bool DatabaseConnector::InsertNewUser(QString username, QString password)
{
    QString storage_path = "data/" + username;
   QSqlQuery query;
   query.prepare("INSERT INTO users_credentials ("
                     "Username,"
                     "Password,"
                     "StoragePath"
                     ")"
                     "VALUES("
                     "?,?,?);");
   query.addBindValue(username);
   query.addBindValue(password);
   query.addBindValue(storage_path);
   return query.exec();
}

bool DatabaseConnector::TryToLogin(QString username, QString password)
{

}

void DatabaseConnector::LoadUserInfo()
{

}
