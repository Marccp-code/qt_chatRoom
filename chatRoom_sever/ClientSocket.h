#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include "Package.h"

class ClientSocket : public QObject
{
    Q_OBJECT
private:
    QTcpSocket* client;
     void regist(pack_t* pack);
     void login(pack_t* pack);
     void singleChat(pack_t* pack);
     void group_chat(pack_t* pack);
public:
    explicit ClientSocket(QTcpSocket* client, QObject *parent = 0);
signals:
    void showMainWindow(pack_t*);
    void showMainWindow_string(QString);
    void onlineList_emit(QString);
    void setTextEdit(QString);
    void sendPackage(pack_t* package, QTcpSocket* socket);
public slots:
    void onReadyRead();
};

#endif // CLIENTSOCKET_H
