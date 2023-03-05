#ifndef BASESERVER_H
#define BASESERVER_H

#include <QTcpSocket>
#include <QDebug>
#include <QTcpServer>
#include <QObject>

class BaseServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit BaseServer(QObject *parent = nullptr);
    void incomingConnection(int handle);
    QList<QTcpSocket*> connections;
public slots:
    void onReadyRead();
    void onDisconnected();
};

#endif // BASESERVER_H
