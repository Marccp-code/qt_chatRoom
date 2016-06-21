#ifndef USERHANDLE_H
#define USERHANDLE_H
#include <QString>
#include "User.h"

class UserHandle
{
public:
    UserHandle();
    void insertUser(User* user);
    bool hasUserName(QString name);
    bool isMatch(QString name, QString pwd);
};

#endif // USERHANDLE_H
