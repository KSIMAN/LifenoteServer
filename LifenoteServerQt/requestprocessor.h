#ifndef REQUESTPROCESSOR_H
#define REQUESTPROCESSOR_H
#include <functional>
#include <QObject>
#include <QTcpSocket>
#include <QString>
#include <QDate>
#include "clientmodel.h"
#include "databaseconnector.h"

class RequestProcessor : public QObject
{
    Q_OBJECT
public:
    explicit RequestProcessor(QObject *parent = nullptr);
    void ProcessClientRequest(ClientModel * sender);
    void RegisterRequestProcess(QString str, int * pos);
    QString GetParamValue(QString str, int * pos);
    void LoginRequestProcess(QString str, int * pos, ClientModel * client);
    void CompareFileDates(QDate * client_last_date, QDate * server_last_date);
private:
    DatabaseConnector * db_connector_ptr;

signals:

};

#endif // REQUESTPROCESSOR_H
