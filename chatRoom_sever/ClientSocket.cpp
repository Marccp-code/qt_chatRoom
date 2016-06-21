#include "ClientSocket.h"
#include <QDebug>
#include "User.h"
#include "UserHandle.h"
#include "ClientManager.h"

ClientSocket::ClientSocket(QTcpSocket* client, QObject *parent) :
    client(client), QObject(parent)
{
    connect(client, SIGNAL(readyRead()), this, SLOT(onReadyRead()));

}

void ClientSocket::onReadyRead(){
    pack_t package;
    memset(&package, 0, sizeof(package));
    client->waitForReadyRead(sizeof(pack_t));
    client->read((char*)&package, sizeof(pack_t));
    qDebug() << package.type << "  " << package.name << "  " << package.pwd << "onReadyRead";
    switch(package.type){
    case APPEAL_REG:
        regist(&package);
        //注册
        break;
     case APPEAL_LOGIN:
        login(&package);
        //登录
        break;
     case APPEAL_CHAT:
        singleChat(&package);
        //单聊
        break;
     case GROUP_CHAT:
        group_chat(&package);
        //群聊
        break;
     case STATE_CHANGE:
       //改变登录状态
        {
        ClientManager* manager = ClientManager::getInstance();
        manager->changeState(&package);
        QString online_str = manager->getOnlineList();
        emit onlineList_emit(online_str);
        break;
        }
    case EXIT:
      //退出
    {
        ClientManager* manager = ClientManager::getInstance();
        bool ret = manager->toDeleteUser(&package);
        QString str = package.name;
        if(true == ret){
          str += " delete success!";
        }else{
          str += " delete false!";
        }
        emit setTextEdit(str);
        break;
    }
     default:
        break;
    }
}

//注册
void ClientSocket::regist(pack_t* pack){
    QString qName = pack->name;
    QString qPwd = pack->pwd;
    User user = User(qName, qPwd, client);
    UserHandle ud;
    QString show_str;
    if(ud.hasUserName(qName)){
        pack->type = REG_FAILED;
        show_str = qName + " " + "regist failed!";
    }else{
        pack->type = REG_SUCCESS;
        ud.insertUser(&user);
        show_str = qName + " " + "regist success!";
    }

    emit sendPackage(pack, client);
    emit showMainWindow_string(show_str);
}

//登录
void ClientSocket::login(pack_t* pack){
    QString qName = pack->name;
    QString qPwd = pack->pwd;
     QString show_str;

    UserHandle ud;
    ClientManager* manager = ClientManager::getInstance();
    bool flag1 = manager->notOnLine(qName);
    bool flag2 = ud.isMatch(qName, qPwd);
    if(flag1 && flag2){
        pack->type = LOG_SUCCESS;
        show_str = qName + " " + "login success!";
        User user = User(qName, qPwd, client);
        manager->addSocket(user);//
    }else{
        pack->type = LOG_FAILED;
        show_str = qName + " " + "regist failed!";
    }
    emit sendPackage(pack, client);
    emit showMainWindow_string(show_str);

    //向mainwindow发送在线列表
    QString online_str = manager->getOnlineList();
    emit onlineList_emit(online_str);
}

//单聊
void ClientSocket::singleChat(pack_t* pack){

    QString qName = pack->des_name;
    ClientManager* manager = ClientManager::getInstance();
    manager->sendString_single(pack, qName);
    emit showMainWindow(pack);
}

//群聊
void ClientSocket::group_chat(pack_t* pa){
    pack_t pack;
    memset(&pack, 0, sizeof(pack));
     pack.type = GROUP_CHAT;
    QString str = pa->chat_info;
    QString name = QString(QLatin1String(pa->name)) ;
    str = "groupChat(from " + name + "): " + str;
    emit showMainWindow_string(str);
    string sStr = str.toStdString();
    strcpy(pack.chat_info, sStr.data());
    ClientManager* manager = ClientManager::getInstance();
    manager->sendString(&pack);
}
