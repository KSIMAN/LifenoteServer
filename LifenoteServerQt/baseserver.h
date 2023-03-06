#ifndef BASESERVER_H
#define BASESERVER_H

#include <QTcpSocket>
#include <QDebug>
#include <QTcpServer>
#include <QObject>
#include "databaseconnector.h"
#include "clientmodel.h"
#include "requestprocessor.h"

class BaseServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit BaseServer(QObject *parent = nullptr);
    void incomingConnection(int handle);

protected:
    QList<ClientModel*> connections;
    RequestProcessor request_handler;
    DatabaseConnector db_connector;
public slots:
    void onReadyRead();
    void onDisconnected();
};

#endif // BASESERVER_H
