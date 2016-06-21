#include "chatWidget.h"
#include "ui_chatWidget.h"
#include <string>
#include <QFileDialog>
#include <QMessageBox>
using namespace std;

chatWidget::chatWidget(QString myName, QTcpSocket* socket, QWidget *parent) :
    myName(myName), socket(socket), QWidget(parent),
    ui(new Ui::chatWidget)
{
    ui->setupUi(this);
    state = true;
}

chatWidget::~chatWidget()
{
    delete ui;
}

void chatWidget::on_btn_send_clicked()
{
    QString str = ui->le_send->text();
    QString name = ui->lw_online->currentItem()->text();
    emit chatMassage(str, name);
    str = "to " + name + " : " + str;
    ui->te_info->append(str);
    ui->le_send->clear();
}

void chatWidget::toSingleChat(pack_t* pack){
    QString str = pack->chat_info;
    QString name = pack->name;
    str = "singleChat( from " + name + " ): " + str;
    ui->te_info->append(str);
}

void chatWidget::toBordCast(pack_t* pack){
    QString str = pack->chat_info;
    str = "bordCast: " + str;
    ui->te_info->append(str);
}

 void chatWidget::toGroupChat(pack_t* pack){
     ui->te_info->append(pack->chat_info);
     qDebug() << "troupchat" << pack->chat_info;
 }

void chatWidget::on_btn_exit_clicked()
{
    pack_t package;
    memset(&package, 0, sizeof(package));
    package.type = EXIT;
    string sText  = myName.toStdString();
    strcpy(package.name, sText.data());
   socket->write((char*)&package, sizeof(pack_t));
   // socket->waitForBytesWritten(3000);

   QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "./chat.txt",
               tr("Text Files (*.txt)"));
               if (!fileName.isEmpty()) {
                   QFile file(fileName);
                   if (!file.open(QIODevice::Append)) {
                       // error message
                  } else {
                    QTextStream stream(&file);
                      stream << ui->te_info->toPlainText();
                       stream.flush();
                       file.close();
                   }
                }

    this->close();
    QWidget* parent = this->parentWidget();
    parent->show();
    delete this;
}

 void chatWidget::toRefresh_onlineUsers(pack_t* pack){
     ui->lw_online->clear();
     QString str = pack->chat_info;
     QStringList strlist;
     strlist = str.split(",",  QString::SkipEmptyParts);
     QList<QString>::Iterator it;
     int i = 1;
     for(it = strlist.begin(); it != strlist.end(); it++, i++){
          QListWidgetItem* lst1 = new QListWidgetItem(*it, ui->lw_online);
          ui->lw_online->insertItem(i, lst1);
     }
      ui->lw_online->show();
 }

void chatWidget::on_btn_groupChat_clicked()
{
    pack_t package;
    memset(&package, 0, sizeof(package));
    package.type = GROUP_CHAT;
    string sMyName = myName.toStdString();
    strcpy(package.name, sMyName.data());
    QString str = ui->le_groupChat->text();
    string sText  = str.toStdString();
    strcpy(package.chat_info, sText.data());
    socket->write((char*)&package, sizeof(pack_t));
//    socket->waitForBytesWritten(sizeof(pack_t));
    ui->le_groupChat->clear();
}

void chatWidget::on_btn_record_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "./chat.txt",
              tr("Text Files (*.txt)"));

           if (!fileName.isEmpty()) {
               QFile file(fileName);
               if (!file.open(QIODevice::ReadOnly)) {
                  QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
                  return;
              }
              QTextStream in(&file);
              ui->te_info->setText(in.readAll());
                file.close();
          }
}

void chatWidget::on_btn_status_clicked()
{

}
/*
 * testClient *a;
QFile sendFile = new QFile(sendFilePath);
if (!sendFile->open(QFile::ReadOnly ))
{    return;}
QByteArray outBlock;
outBlock = sendFile->read(sendFile.size());
a->writeData(outBlock,outBlock.size());



QByteArray inBlock;
inBlock = a->readAll();	//读入所有数据
QFile receivedFile = new QFile(receiveFilePath);	//打开接收文件
if (!receivedFile->open(QFile::WriteOnly ))
{    return;}
QFile receivedFile->write(inBlock);	//写入文件
inBlock.resize(0);

 *
*/


void chatWidget::on_pb_online_clicked()
{
    state = !state;
    if(state){
        ui->tl_status->setText("OnLine");
    }
    else{
        ui->tl_status->setText("Hide");
    }

    pack_t package;
    memset(&package, 0, sizeof(package));
    package.type = STATE_CHANGE;
    string sMyName = myName.toStdString();
    strcpy(package.name, sMyName.data());
    socket->write((char*)&package, sizeof(pack_t));
}
