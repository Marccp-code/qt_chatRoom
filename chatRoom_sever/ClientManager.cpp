#include "ClientManager.h"
#include"qapplication.h"
#include <stdlib.h>
#include <unistd.h>
#include <QThread>
using namespace std;
ClientManager::ClientManager()
{
}

ClientManager* ClientManager::instance = 0;

ClientManager* ClientManager::getInstance(){
    if(0 == instance){
        instance = new ClientManager();
    }

    return instance;
}

void ClientManager::addSocket(User user){
    users.push_back(user);
}

//群发信息
void ClientManager::sendString(pack_t* package){
    sleep(1);
    vector<User>::iterator it;
    for(it = users.begin(); it != users.end(); it++){
        User user = *it;
        user.getSocket()->write((char*)package, sizeof(pack_t));
        user.getSocket()->waitForBytesWritten(sizeof(pack_t));
        QApplication::processEvents();
    }
}

//发送单聊信息
void ClientManager::sendString_single(pack_t* package, QString name){
    vector<User>::iterator it;
    for(it = users.begin(); it != users.end();it++){
        User user = *it;
        if(user.getName() == name){
            user.getSocket()->write((char*)package, sizeof(pack_t));
            user.getSocket()->waitForBytesWritten(sizeof(pack_t));
            break;
        }
    }
}

//判断是否不在线
bool ClientManager::notOnLine(QString name){
    vector<User>::iterator it;
    for(it = users.begin(); it != users.end();it++){
        User user = *it;
        if(user.getName() == name){
           return false;
           break;
        }
    }

    return true;
}

//得到在线列表
QString ClientManager::getOnlineList(){
    QString str;
    qDebug() << "------------------------------------";
    vector<User>::iterator it;
    for(it = users.begin(); it != users.end(); it++){
        User user = *it;
        if(true == user.getState()){
            qDebug() << "getOnline" << user.getState();
            str += user.getName();
              str += ",";
        }

    }
    //str = str.left(str.length() - 1);
    qDebug() << "getOnlineList() manager : " << str;
    qDebug() << "------------------------------------";
    return str;
}

//从容器删除用户
bool ClientManager::toDeleteUser(pack_t* pack){
    QString name = pack->name;
    vector<User>::iterator it;
    for(it = users.begin(); it != users.end();it++){
        User user = *it;
        if(user.getName() == name){
            users.erase(it);
            return true;
        }
    }
    return false;
}

//改登录状态
 void ClientManager::changeState(pack_t* pack){
     QString name = pack->name;
     vector<User>::iterator it;
     for(it = users.begin(); it != users.end();it++){
         User user = *it;
         if(user.getName() == name){
             it->setState(!user.getState());
             qDebug() << "changeState" << user.getState();
         }
     }
 }
