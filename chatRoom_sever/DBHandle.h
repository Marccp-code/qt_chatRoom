#ifndef DBHANDLE_H
#define DBHANDLE_H
#include <QSqlDatabase>

class DBHandle
{
private:
    static DBHandle* instance;
    QSqlDatabase db;
    DBHandle();
public:
    static DBHandle* getInstance();
    void createConn();
    void destoryConn();
};

#endif // DBHANDLE_H
