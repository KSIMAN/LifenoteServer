#include <QCoreApplication>
#include "baseserver.h"
#include <databaseconnector.h>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    BaseServer server;
    DatabaseConnector connector;
    return a.exec();
}
