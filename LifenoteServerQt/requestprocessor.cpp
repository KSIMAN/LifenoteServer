#include "requestprocessor.h"

RequestProcessor::RequestProcessor(QObject *parent)
    : QObject{parent}
{

}

void RequestProcessor::ProcessClientRequest(ClientModel *client)
{
    QString client_request = client->readAll().toStdString().c_str();
    QString req_type = "";
    int i = 0;
    while(client_request[i].isLetter())
    {
        req_type+=client_request.at(i);
        client_request.remove(client_request.at(i));
    }
    if(req_type == "reg")
        RegisterRequestProcess(client_request, &i);
    else if(req_type == "log")
        LoginRequestProcess(client_request, &i, client);
    else if(req_type == "comp")
    {
        //if(client->authorized)
           // CompareFileDates();
    }else if(req_type == "sendf")
    {


    }


}

void RequestProcessor::RegisterRequestProcess(QString str, int * pos)
{
    QString username = GetParamValue(str, pos);
    QString password = GetParamValue(str, pos);
    bool success = db_connector_ptr->InsertNewUser(username, password);
    if(success)
    {
        //sendAnswer OK
    }else {
        //sendAnswer err
    }
}

QString RequestProcessor::GetParamValue(QString str, int * pos)
{
    QString param = "";
    while((str[*pos] != ' ') && (str[*pos] != '\0'))
    {
        param+=str[*pos];
        *pos+=1;
    }
    return param;
}

void RequestProcessor::LoginRequestProcess(QString str, int * pos, ClientModel * client)
{
    QString username = GetParamValue(str, pos);
    QString password = GetParamValue(str, pos);

}

void RequestProcessor::CompareFileDates(QDate *client_last_date, QDate *server_last_date)
{
    if(client_last_date < server_last_date)
    {
        //sendFiles
    } else
    {
        //getFiles
    }
}
