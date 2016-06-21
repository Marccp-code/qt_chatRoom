#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHostAddress>
#include "Package.h"
#include <string.h>
#include <string>
#include <QDebug>
#include <chatWidget.h>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    port = 8888;
    ip = "127.0.0.1";
    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_reg_clicked()
{
    pack_t package;
    memset(&package, 0, sizeof(package));
    package.type = APPEAL_REG;

    QString qName = ui->le_name->text();
    string sName = qName.toStdString();
    strcpy(package.name, sName.data());

    QString qPwd = ui->le_pwd->text();
    string sPwd = qPwd.toStdString();
    strcpy(package.pwd, sPwd.data());


    socket->waitForBytesWritten(sizeof(pack_t));
    socket->write((char*)&package, sizeof(pack_t));


    ui->le_name->clear();
    ui->le_pwd->clear();
}

void MainWindow::on_btn_log_clicked()
{
    pack_t package;
    memset(&package, 0, sizeof(package));
    package.type = APPEAL_LOGIN;

    QString qName = ui->le_name->text();
    myName = qName;
    string sName = qName.toStdString();
    strcpy(package.name, sName.data());

    QString qPwd = ui->le_pwd->text();
    string sPwd = qPwd.toStdString();
    strcpy(package.pwd, sPwd.data());


    // socket->waitForBytesWritten(sizeof(pack_t));
    socket->write((char*)&package, sizeof(pack_t));


    ui->le_name->clear();
    ui->le_pwd->clear();
}

void MainWindow::on_btn_set_clicked()
{
   set = new Setting();
   connect(set, SIGNAL(connMessage(QString,QString)), this, SLOT(toConnMessage(QString,QString)));
   set->show();
}

void MainWindow::on_btn_connect_clicked()
{
    socket->connectToHost(ip, port);
    bool connected = socket->waitForConnected();
    if(connected){
          ui->lb_status->setText("connected");
    }else{
          ui->lb_status->setText("connect failed");
    }
}

void MainWindow::onReadyRead(){
  pack_t pack;
//  socket->waitForReadyRead();
  //while(socket->bytesAvailable() < sizeof(pack_t));
   socket->read((char*)&pack, sizeof(pack_t));
  // socket->waitForReadyRead(sizeof(pack_t));
    qDebug() << pack.type << "onReadyRead";
    switch(pack.type){
        case REG_SUCCESS:
            ui->lb_caution->setText("Regist Success!");
            break;
        case REG_FAILED:
            ui->lb_caution->setText("Regist Failed!");
            break;
        case LOG_SUCCESS:
            enter_chatRoom();
            break;
        case LOG_FAILED:
            ui->lb_caution->setText("Login Failed!");
            break;
        case APPEAL_CHAT:
            emit singleChat(&pack);
            break;
        case BORDCAST:
            emit bordCast(&pack);
            break;
        case REFRESH_ONLINEUSERS:
            refresh_onlineUsers(&pack);
            break;
         case GROUP_CHAT:
             emit groupChat(&pack);
        default:
            break;
    }
}

void MainWindow::enter_chatRoom(){
    chatWidget* cw = new chatWidget(myName, socket);
    connect(cw, SIGNAL(chatMassage(QString, QString)),  this, SLOT(sove_chatMassage(QString, QString)));
    connect(this, SIGNAL(singleChat(pack_t*)),  cw, SLOT(toSingleChat(pack_t*)));
    connect(this, SIGNAL(groupChat(pack_t*)),  cw, SLOT(toGroupChat(pack_t*)));
    connect(this, SIGNAL(bordCast(pack_t*)),  cw, SLOT(toBordCast(pack_t*)));
    connect(this, SIGNAL(refresh_onlineUsers(pack_t*)), cw, SLOT(toRefresh_onlineUsers(pack_t*)));
    this->hide();
    cw->show();
}

void MainWindow::sove_chatMassage(QString str, QString name){
    pack_t package;
    memset(&package, 0, sizeof(package));
    package.type = APPEAL_CHAT;
    string sMyName = myName.toStdString();
    strcpy(package.name, sMyName.data());

    string sName = name.toStdString();
    strcpy(package.des_name, sName.data());
    string sText  = str.toStdString();
    strcpy(package.chat_info, sText.data());
    qDebug() << "chatsingle" << package.chat_info;
    socket->write((char*)&package, sizeof(pack_t));
//    socket->waitForBytesWritten(sizeof(pack_t));
}

 void MainWindow::toConnMessage(QString ip, QString port){
     this->ip = ip;
     int int_port = port.toInt();
     this->port = int_port;
 }
