#include "databaseconnector.h"
#include <QDebug>
DatabaseConnector::DatabaseConnector()
{
    OpenDatabase("lifenote.db");

}

void DatabaseConnector::OpenDatabase(QString db_path)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(db_path);
    if(!db.open())
    {
        qDebug() << "PROBLEM OF OPENING";
    }


}

void DatabaseConnector::InsertNewUser(QString username, QString password)
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
   if(!query.exec())
       qDebug() << "error of add user";
}

bool DatabaseConnector::TryToLogin(QString username, QString password)
{

}

void DatabaseConnector::LoadUserInfo()
{

}
