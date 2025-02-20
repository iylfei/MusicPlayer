/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QListWidget *settingList;
    QStackedWidget *settingStacked;
    QWidget *performance;
    QLabel *label_2;
    QLabel *label;
    QFontComboBox *fontComboBox;
    QComboBox *comboBox;
    QWidget *widget1;
    QHBoxLayout *backgroundLayout;
    QLabel *backgroundlabel;
    QPushButton *backgroundButton;
    QWidget *page_2;

    void setupUi(QDialog *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName("Settings");
        Settings->resize(661, 544);
        buttonBox = new QDialogButtonBox(Settings);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(290, 490, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        widget = new QWidget(Settings);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 661, 471));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        settingList = new QListWidget(widget);
        QFont font;
        font.setFamilies({QString::fromUtf8("\351\273\221\344\275\223")});
        font.setPointSize(26);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(settingList);
        __qlistwidgetitem->setTextAlignment(Qt::AlignCenter);
        __qlistwidgetitem->setFont(font);
        settingList->setObjectName("settingList");
        settingList->setStyleSheet(QString::fromUtf8("QListWidget::item { \n"
"    height: 80px; \n"
"    padding: 5px; \n"
"}\n"
""));
        settingList->setLineWidth(1);

        horizontalLayout->addWidget(settingList);

        settingStacked = new QStackedWidget(widget);
        settingStacked->setObjectName("settingStacked");
        performance = new QWidget();
        performance->setObjectName("performance");
        label_2 = new QLabel(performance);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 110, 151, 61));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\351\273\221\344\275\223")});
        font1.setPointSize(14);
        label_2->setFont(font1);
        label = new QLabel(performance);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 180, 69, 19));
        fontComboBox = new QFontComboBox(performance);
        fontComboBox->setObjectName("fontComboBox");
        fontComboBox->setGeometry(QRect(100, 130, 213, 25));
        comboBox = new QComboBox(performance);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(100, 180, 83, 25));
        widget1 = new QWidget(performance);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(30, 30, 150, 30));
        backgroundLayout = new QHBoxLayout(widget1);
        backgroundLayout->setObjectName("backgroundLayout");
        backgroundLayout->setContentsMargins(0, 0, 0, 0);
        backgroundlabel = new QLabel(widget1);
        backgroundlabel->setObjectName("backgroundlabel");
        backgroundlabel->setFont(font1);

        backgroundLayout->addWidget(backgroundlabel);

        backgroundButton = new QPushButton(widget1);
        backgroundButton->setObjectName("backgroundButton");

        backgroundLayout->addWidget(backgroundButton);

        settingStacked->addWidget(performance);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        settingStacked->addWidget(page_2);

        horizontalLayout->addWidget(settingStacked);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 5);

        retranslateUi(Settings);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Settings, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Settings, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QDialog *Settings)
    {
        Settings->setWindowTitle(QCoreApplication::translate("Settings", "Dialog", nullptr));

        const bool __sortingEnabled = settingList->isSortingEnabled();
        settingList->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = settingList->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("Settings", "\345\244\226\350\247\202", nullptr));
        settingList->setSortingEnabled(__sortingEnabled);

        label_2->setText(QCoreApplication::translate("Settings", "\345\255\227\344\275\223", nullptr));
        label->setText(QCoreApplication::translate("Settings", "\345\244\247\345\260\217", nullptr));
        backgroundlabel->setText(QCoreApplication::translate("Settings", "\350\203\214\346\231\257", nullptr));
        backgroundButton->setText(QCoreApplication::translate("Settings", "\350\207\252\345\256\232\344\271\211\350\203\214\346\231\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
