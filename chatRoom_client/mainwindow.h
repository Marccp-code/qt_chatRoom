#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <Package.h>
#include "Setting.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btn_reg_clicked();
    void on_btn_log_clicked();
    void on_btn_set_clicked();
    void on_btn_connect_clicked();
     void onReadyRead();
     void sove_chatMassage(QString str, QString name);
     void toConnMessage(QString ip, QString port);
private:
    Ui::MainWindow *ui;
    QTcpSocket* socket;
     void enter_chatRoom();
     Setting* set;
     QString ip;
     int port;
     QString myName;

signals:
     void singleChat(pack_t* pack);
     void groupChat(pack_t*);
     void bordCast(pack_t* pack);
     void refresh_onlineUsers(pack_t* pack);
};

#endif // MAINWINDOW_H
