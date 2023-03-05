#include "baseserver.h"
#include <QDateTime>
BaseServer::BaseServer(QObject *parent)
    : QTcpServer{parent}
{
    if(listen(QHostAddress::AnyIPv4, 80))
    {
        qDebug() << "Listen!!\n" ;
    } else {
        qDebug() << "Error: " << errorString();
    }
}

void BaseServer::incomingConnection(int handle)
{
    QTcpSocket * socket = new QTcpSocket();
    socket->setSocketDescriptor(handle);
    connections.push_back(socket);
    connect(socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(onDisconnected()));

}

void BaseServer::onReadyRead()
{
    QTcpSocket * socket = qobject_cast<QTcpSocket*>(sender());
    qDebug() << socket->readAll();

    QString responce = "HTTP/1.1 200 OK\r\n\r\n%1";
    socket->write(responce.arg(QDateTime::currentDateTime().toString()).toStdString().c_str());
    socket->disconnectFromHost();
}

void BaseServer::onDisconnected()
{
    QTcpSocket * socket = qobject_cast<QTcpSocket*>(sender());
    socket->close();
    socket->deleteLater();
}
