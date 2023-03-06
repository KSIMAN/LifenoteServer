#ifndef DATABASECONNECTOR_H
#define DATABASECONNECTOR_H

#include <QObject>
#include <QtSql>
#include <QSqlTableModel>

class DatabaseConnector : public QObject
{
    Q_OBJECT
public:
    DatabaseConnector();
    ~DatabaseConnector();
    void OpenDatabase(QString db_path);
    bool InsertNewUser(QString username, QString password);
    bool TryToLogin(QString username, QString password);
    void LoadUserInfo();
private:
    QString db_path = "lifenote.db";
    QSqlDatabase db;
    QSqlTableModel * users_table;
};

#endif // DATABASECONNECTOR_H
