#ifndef PACKAGE_H
#define PACKAGE_H

#define APPEAL_REG                   1
#define APPEAL_LOGIN                 2
#define REG_SUCCESS                  3
#define REG_FAILED                   4
#define APPEAL_CHAT                  5
#define LOG_SUCCESS                  6
#define LOG_FAILED                   7
#define BORDCAST                     8
#define EXIT                         9
#define REFRESH_ONLINEUSERS         10
#define GROUP_CHAT                  11
#define STATE_CHANGE                12

typedef struct Pack{
    int type;
    int id;
    char name[20];
    char des_name[20];
    char pwd[20];
    char chat_info[50];
}pack_t;

#endif // PACKAGE_H
