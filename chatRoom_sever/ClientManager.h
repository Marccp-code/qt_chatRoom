#ifndef CLIENTMANAGER_H
#define CLIENTMANAGER_H

#include <QTcpSocket>
#include <vector>
#include "User.h"
#include "Package.h"

using namespace std;
class ClientManager
{
public:
    static ClientManager* getInstance();
    void addSocket(User user);
    void sendString(pack_t* package);
    void sendString_single(pack_t* package, QString name);
    bool notOnLine(QString name);
    QString getOnlineList();
    bool toDeleteUser(pack_t*);
    void changeState(pack_t*);
private:
    vector<User> users;
    static ClientManager* instance;
    ClientManager();
};

#endif // CLIENTMANAGER_H
