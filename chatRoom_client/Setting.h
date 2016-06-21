#ifndef SETTING_H
#define SETTING_H

#include <QDialog>
#include <QString>

namespace Ui {
class Setting;
}

class Setting : public QDialog
{
    Q_OBJECT

public:
    explicit Setting(QWidget *parent = 0);
    ~Setting();
signals:
   void connMessage(QString ip, QString port);
private slots:
    void on_btn_ok_clicked();

private:
    Ui::Setting *ui;
    QString ip;
    QString port;
};

#endif // SETTING_H
