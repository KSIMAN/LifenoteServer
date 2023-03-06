#include "clientmodel.h"

ClientModel::ClientModel(QObject *parent)
    : QTcpSocket{parent}
{

}

void ClientModel::ChangeUser(QString usrname, QString passwd, QString filespath)
{
    username = usrname;
    password = passwd;
    files_path = filespath;
    authorized = true;
}
