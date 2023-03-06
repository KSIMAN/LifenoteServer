#ifndef CLIENTMODEL_H
#define CLIENTMODEL_H

#include <QTcpSocket>
#include <QObject>

class ClientModel : public QTcpSocket
{
    Q_OBJECT
public:
    explicit ClientModel(QObject *parent = nullptr);
    bool authorized {false};
    QString username, password, files_path;

    void ChangeUser(QString usrname, QString passwd, QString filespath);
};

#endif // CLIENTMODEL_H
