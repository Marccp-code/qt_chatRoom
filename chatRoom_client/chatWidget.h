#ifndef CHATWIDGET_H
#define CHATWIDGET_H

#include <QWidget>
#include <QString>
#include "Package.h"
#include <QTcpSocket>
namespace Ui {
class chatWidget;
}

class chatWidget : public QWidget
{
    Q_OBJECT

public:
    explicit chatWidget(QString myName, QTcpSocket* socket, QWidget *parent = 0);
    ~chatWidget();

private slots:
    void on_btn_send_clicked();
    void toSingleChat(pack_t* pack);
      void toBordCast(pack_t* pack);
      void toGroupChat(pack_t* pack);
    void on_btn_exit_clicked();
    void toRefresh_onlineUsers(pack_t*);

    void on_btn_groupChat_clicked();

    void on_btn_record_clicked();

    void on_btn_status_clicked();

    void on_pb_online_clicked();

signals:
    void chatMassage(QString str, QString name);
private:
    Ui::chatWidget *ui;
    QTcpSocket* socket;
    QString myName;
    bool state;
  protected:

};

#endif // CHATWIDGET_H
