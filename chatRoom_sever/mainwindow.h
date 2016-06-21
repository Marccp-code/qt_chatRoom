#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include "Package.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void onNewConnection();
private slots:
    void on_btn_boardCast_clicked();
    void toShowMainWindow(pack_t*);
    void toShowMainWindow_string(QString);
    void on_btn_refresh_clicked();
    void solve_onlineListEmit(QString);
    void toSetTextEdit(QString);
    void toSendPackage(pack_t*, QTcpSocket* socket);
private:
    Ui::MainWindow *ui;
    QTcpServer* server;
    QString ip;
    int port;
protected:
    void closeEvent();
};

#endif // MAINWINDOW_H
