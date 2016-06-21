#ifndef USER_H
#define USER_H
#include <QString>
#include <QTcpSocket>

class User
{
private:
    QString name;
    QString pwd;
    int id;
    QTcpSocket* socket;
    bool state;
public:
    User();
    User(QString name, QString pwd, QTcpSocket* socket,
         int id = 0, bool state = true);
    void setName(QString name);
    void setPwd(QString pwd);
    void setId(int id);
    void setState(bool state);
    bool getState();
    void setSocket(QTcpSocket* socket);
    QString getName();
    QString getPwd();
    QTcpSocket* getSocket();
    int getId();
};

#endif // USER_H
