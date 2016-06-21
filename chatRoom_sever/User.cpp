#include "User.h"

User::User()
{
}

User::User(QString name, QString pwd,  QTcpSocket* socket, int id, bool state)
: name(name), pwd(pwd), socket(socket), id(id), state(state){
}

void User::setName(QString name){
    this->name = name;
}

void User::setPwd(QString pwd){
    this->pwd = pwd;
}

void User::setState(bool state){
    this->state = state;
}

bool User::getState(){
    return state;
}

void User::setId(int id){
    this->id = id;
}

void User::setSocket(QTcpSocket* socket){
    this->socket = socket;
}

QString User::getName(){
    return name;
}

QString User::getPwd(){
    return pwd;
}

int User::getId(){
    return id;
}

QTcpSocket* User::getSocket(){
    return socket;
}
