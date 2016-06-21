#include "UserHandle.h"
#include "DBHandle.h"
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>

UserHandle::UserHandle()
{
}

//插入用户
void UserHandle::insertUser(User* user){
    DBHandle* helper = DBHandle::getInstance();
    helper->createConn();
    QSqlQuery query;
    query.prepare("insert into table_user(name, pwd)"
                  "values(:name, :pwd);");
    query.bindValue(":name", user->getName());
    query.bindValue(":pwd", user->getPwd());
    query.exec();

    helper->destoryConn();
}

//检查名字是否在数据库
bool UserHandle::hasUserName(QString name){
    bool ret = false;
    DBHandle* helper = DBHandle::getInstance();
    helper->createConn();
    QSqlQuery query;
    query.prepare("select name from table_user where name = :name;");
    query.bindValue(":name", name);
    query.exec();
    if(query.next()){
        ret = true;
    }else{
        ret = false;
    }

    helper->destoryConn();
    return ret;
}

//检查姓名和名字是否匹配
bool UserHandle::isMatch(QString name, QString pwd){
    bool ret = false;
    DBHandle* helper = DBHandle::getInstance();
    helper->createConn();
    QSqlQuery query;
    query.prepare("select name from table_user where name = :name"
                  " and pwd = :pwd;");
    query.bindValue(":name", name);
    query.bindValue(":pwd", pwd);
    query.exec();
    if(query.next()){
        ret = true;
    }else{
        ret = false;
    }

    qDebug() << ret << "isMatch";
    helper->destoryConn();
    return ret;
}
