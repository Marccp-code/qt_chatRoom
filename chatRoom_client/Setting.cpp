#include "Setting.h"
#include "ui_setting.h"

Setting::Setting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Setting)
{
    ui->setupUi(this);
}

Setting::~Setting()
{
    delete ui;
}

void Setting::on_btn_ok_clicked()
{
    QString ip = ui->le_ip->text();
    QString port = ui->le_port->text();
    emit connMessage(ip, port);
    ui->le_ip->clear();
    ui->le_port->clear();
    this->hide();
}
