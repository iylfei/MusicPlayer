/********************************************************************************
** Form generated from reading UI file 'onlinemusicwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ONLINEMUSICWIDGET_H
#define UI_ONLINEMUSICWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OnlineMusicWidget
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *searchButton;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *minButton;
    QPushButton *closeButton;

    void setupUi(QWidget *OnlineMusicWidget)
    {
        if (OnlineMusicWidget->objectName().isEmpty())
            OnlineMusicWidget->setObjectName("OnlineMusicWidget");
        OnlineMusicWidget->resize(1076, 600);
        groupBox = new QGroupBox(OnlineMusicWidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(200, 10, 661, 81));
        groupBox->setStyleSheet(QString::fromUtf8("border:1px solid white;\n"
"border-radius:10px;"));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 20, 141, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("\346\226\260\345\256\213\344\275\223")});
        font.setPointSize(16);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color:white;\n"
"border:1px solid white;\n"
"border-radius:5px;\n"
""));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(190, 20, 321, 41));
        QFont font1;
        font1.setPointSize(12);
        lineEdit->setFont(font1);
        searchButton = new QPushButton(groupBox);
        searchButton->setObjectName("searchButton");
        searchButton->setGeometry(QRect(530, 20, 71, 41));
        searchButton->setMinimumSize(QSize(71, 41));
        searchButton->setMaximumSize(QSize(71, 41));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\346\226\260\345\256\213\344\275\223")});
        font2.setPointSize(14);
        searchButton->setFont(font2);
        searchButton->setStyleSheet(QString::fromUtf8("QPushButton#searchButton\n"
"{\n"
"	background:transparent;\n"
"	color:rgb(200, 200, 200);\n"
"	border:1px solid white;\n"
"	border-radius:5px;\n"
"}\n"
"QPushButton#searchButton:hover \n"
"{	\n"
"	background:transparent;\n"
"	color:rgb(255, 255, 255);\n"
"}"));
        widget = new QWidget(OnlineMusicWidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(970, 0, 101, 40));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        minButton = new QPushButton(widget);
        minButton->setObjectName("minButton");
        minButton->setMinimumSize(QSize(45, 38));
        minButton->setMaximumSize(QSize(45, 38));
        minButton->setBaseSize(QSize(0, 0));
        QFont font3;
        font3.setPointSize(14);
        font3.setBold(false);
        minButton->setFont(font3);
        minButton->setStyleSheet(QString::fromUtf8("QPushButton#minButton\n"
"{\n"
"	border: none;\n"
"	background-color: transparent;\n"
"	color: white;\n"
"}\n"
"QPushButton#minButton:hover\n"
"{\n"
"	border:none;\n"
"	border-radius:5px;\n"
"	background-color: grey;\n"
"	color: blue;\n"
"}"));

        horizontalLayout->addWidget(minButton);

        closeButton = new QPushButton(widget);
        closeButton->setObjectName("closeButton");
        closeButton->setMinimumSize(QSize(44, 38));
        closeButton->setMaximumSize(QSize(44, 38));
        closeButton->setFont(font3);
        closeButton->setStyleSheet(QString::fromUtf8("QPushButton#closeButton\n"
"{\n"
"	border: none;\n"
"	background-color: transparent;\n"
"	color: rgb(255, 0, 0);\n"
"}\n"
"QPushButton#closeButton:hover\n"
"{\n"
"	border:none;\n"
"	border-radius:5px;\n"
"	background-color:rgb(255, 0, 0);\n"
"	color: white;\n"
"}\n"
"QPushButton#closeButton:pressed {\n"
"    background-color: rgb(200, 0, 0);  \n"
"    color: white;\n"
"}"));

        horizontalLayout->addWidget(closeButton);

        groupBox->raise();
        closeButton->raise();

        retranslateUi(OnlineMusicWidget);

        QMetaObject::connectSlotsByName(OnlineMusicWidget);
    } // setupUi

    void retranslateUi(QWidget *OnlineMusicWidget)
    {
        OnlineMusicWidget->setWindowTitle(QCoreApplication::translate("OnlineMusicWidget", "OnlineMusicWidget", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("OnlineMusicWidget", "\346\220\234\347\264\242\346\255\214\346\233\262\345\220\215\347\247\260", nullptr));
        lineEdit->setText(QString());
        searchButton->setText(QCoreApplication::translate("OnlineMusicWidget", "\346\220\234\347\264\242", nullptr));
        minButton->setText(QCoreApplication::translate("OnlineMusicWidget", "-", nullptr));
        closeButton->setText(QCoreApplication::translate("OnlineMusicWidget", "X", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OnlineMusicWidget: public Ui_OnlineMusicWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ONLINEMUSICWIDGET_H
