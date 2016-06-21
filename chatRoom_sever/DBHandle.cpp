#include "DBHandle.h"

DBHandle* DBHandle::instance = 0;

DBHandle::DBHandle()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
}

DBHandle* DBHandle::getInstance(){
    if(0 == instance)
        instance = new DBHandle;
    return instance;
}

void DBHandle::createConn(){
    db.setDatabaseName("user.db");
    db.open();
}

void DBHandle::destoryConn(){
    db.close();
    db.removeDatabase("user.db");
}
