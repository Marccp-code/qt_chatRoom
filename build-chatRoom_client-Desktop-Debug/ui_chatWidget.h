/********************************************************************************
** Form generated from reading UI file 'chatWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATWIDGET_H
#define UI_CHATWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chatWidget
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QTextEdit *te_info;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pb_online;
    QPushButton *btn_exit;
    QLabel *label;
    QListWidget *lw_online;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *le_send;
    QPushButton *btn_send;
    QLabel *tl_status;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *le_groupChat;
    QPushButton *btn_groupChat;
    QPushButton *btn_record;

    void setupUi(QWidget *chatWidget)
    {
        if (chatWidget->objectName().isEmpty())
            chatWidget->setObjectName(QStringLiteral("chatWidget"));
        chatWidget->resize(520, 538);
        layoutWidget = new QWidget(chatWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 511, 531));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        te_info = new QTextEdit(layoutWidget);
        te_info->setObjectName(QStringLiteral("te_info"));

        horizontalLayout_2->addWidget(te_info);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pb_online = new QPushButton(layoutWidget);
        pb_online->setObjectName(QStringLiteral("pb_online"));

        horizontalLayout->addWidget(pb_online);

        btn_exit = new QPushButton(layoutWidget);
        btn_exit->setObjectName(QStringLiteral("btn_exit"));

        horizontalLayout->addWidget(btn_exit);


        verticalLayout->addLayout(horizontalLayout);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        lw_online = new QListWidget(layoutWidget);
        lw_online->setObjectName(QStringLiteral("lw_online"));

        verticalLayout->addWidget(lw_online);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        le_send = new QLineEdit(layoutWidget);
        le_send->setObjectName(QStringLiteral("le_send"));

        horizontalLayout_3->addWidget(le_send);

        btn_send = new QPushButton(layoutWidget);
        btn_send->setObjectName(QStringLiteral("btn_send"));

        horizontalLayout_3->addWidget(btn_send);

        tl_status = new QLabel(layoutWidget);
        tl_status->setObjectName(QStringLiteral("tl_status"));

        horizontalLayout_3->addWidget(tl_status);


        verticalLayout_2->addLayout(horizontalLayout_3);


        verticalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        le_groupChat = new QLineEdit(layoutWidget);
        le_groupChat->setObjectName(QStringLiteral("le_groupChat"));

        horizontalLayout_4->addWidget(le_groupChat);

        btn_groupChat = new QPushButton(layoutWidget);
        btn_groupChat->setObjectName(QStringLiteral("btn_groupChat"));

        horizontalLayout_4->addWidget(btn_groupChat);

        btn_record = new QPushButton(layoutWidget);
        btn_record->setObjectName(QStringLiteral("btn_record"));

        horizontalLayout_4->addWidget(btn_record);


        verticalLayout_3->addLayout(horizontalLayout_4);


        retranslateUi(chatWidget);

        QMetaObject::connectSlotsByName(chatWidget);
    } // setupUi

    void retranslateUi(QWidget *chatWidget)
    {
        chatWidget->setWindowTitle(QApplication::translate("chatWidget", "Form", 0));
        pb_online->setText(QApplication::translate("chatWidget", "Online/Hide", 0));
        btn_exit->setText(QApplication::translate("chatWidget", "Exit", 0));
        label->setText(QApplication::translate("chatWidget", "Online Users", 0));
        btn_send->setText(QApplication::translate("chatWidget", "Send", 0));
        tl_status->setText(QApplication::translate("chatWidget", "OnLine", 0));
        btn_groupChat->setText(QApplication::translate("chatWidget", "Group Chat", 0));
        btn_record->setText(QApplication::translate("chatWidget", "Record", 0));
    } // retranslateUi

};

namespace Ui {
    class chatWidget: public Ui_chatWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATWIDGET_H
