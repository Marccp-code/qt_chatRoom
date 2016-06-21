/********************************************************************************
** Form generated from reading UI file 'setting.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTING_H
#define UI_SETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Setting
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_ip;
    QLineEdit *le_ip;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_port;
    QLineEdit *le_port;
    QPushButton *btn_ok;

    void setupUi(QDialog *Setting)
    {
        if (Setting->objectName().isEmpty())
            Setting->setObjectName(QStringLiteral("Setting"));
        Setting->resize(334, 117);
        widget = new QWidget(Setting);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 312, 99));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btn_ip = new QPushButton(widget);
        btn_ip->setObjectName(QStringLiteral("btn_ip"));

        horizontalLayout->addWidget(btn_ip);

        le_ip = new QLineEdit(widget);
        le_ip->setObjectName(QStringLiteral("le_ip"));

        horizontalLayout->addWidget(le_ip);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        btn_port = new QPushButton(widget);
        btn_port->setObjectName(QStringLiteral("btn_port"));

        horizontalLayout_2->addWidget(btn_port);

        le_port = new QLineEdit(widget);
        le_port->setObjectName(QStringLiteral("le_port"));

        horizontalLayout_2->addWidget(le_port);


        verticalLayout->addLayout(horizontalLayout_2);

        btn_ok = new QPushButton(widget);
        btn_ok->setObjectName(QStringLiteral("btn_ok"));

        verticalLayout->addWidget(btn_ok);


        retranslateUi(Setting);

        QMetaObject::connectSlotsByName(Setting);
    } // setupUi

    void retranslateUi(QDialog *Setting)
    {
        Setting->setWindowTitle(QApplication::translate("Setting", "Dialog", 0));
        btn_ip->setText(QApplication::translate("Setting", "IP ", 0));
        btn_port->setText(QApplication::translate("Setting", "Port", 0));
        btn_ok->setText(QApplication::translate("Setting", "ok", 0));
    } // retranslateUi

};

namespace Ui {
    class Setting: public Ui_Setting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTING_H
