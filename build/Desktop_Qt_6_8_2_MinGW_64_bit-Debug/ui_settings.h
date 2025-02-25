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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QListWidget *settingList;
    QStackedWidget *settingStacked;
    QWidget *performance;
    QWidget *layoutWidget1;
    QVBoxLayout *performanceLayout;
    QHBoxLayout *backgroundLayout;
    QLabel *backgroundlabel;
    QPushButton *backgroundButton;
    QHBoxLayout *fontFamilyLayout;
    QLabel *fontFamilyLabel;
    QFontComboBox *fontComboBox;
    QHBoxLayout *fontsizeLayout;
    QLabel *sizelabel;
    QSpacerItem *horizontalSpacer_2;
    QComboBox *sizecomboBox;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *textColorLayout;
    QLabel *textColorlabel;
    QPushButton *blackButton;
    QPushButton *whiteButton;
    QPushButton *blueButton;
    QPushButton *yellowButton;
    QPushButton *redButton;
    QLabel *fontColorlabel;
    QWidget *page_2;

    void setupUi(QDialog *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName("Settings");
        Settings->resize(661, 544);
        Settings->setMinimumSize(QSize(661, 544));
        Settings->setMaximumSize(QSize(661, 544));
        buttonBox = new QDialogButtonBox(Settings);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(290, 490, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        layoutWidget = new QWidget(Settings);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 0, 661, 481));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        settingList = new QListWidget(layoutWidget);
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

        settingStacked = new QStackedWidget(layoutWidget);
        settingStacked->setObjectName("settingStacked");
        performance = new QWidget();
        performance->setObjectName("performance");
        performance->setMinimumSize(QSize(543, 469));
        performance->setMaximumSize(QSize(543, 469));
        layoutWidget1 = new QWidget(performance);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 20, 521, 441));
        performanceLayout = new QVBoxLayout(layoutWidget1);
        performanceLayout->setObjectName("performanceLayout");
        performanceLayout->setContentsMargins(0, 0, 0, 0);
        backgroundLayout = new QHBoxLayout();
        backgroundLayout->setSpacing(5);
        backgroundLayout->setObjectName("backgroundLayout");
        backgroundlabel = new QLabel(layoutWidget1);
        backgroundlabel->setObjectName("backgroundlabel");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(backgroundlabel->sizePolicy().hasHeightForWidth());
        backgroundlabel->setSizePolicy(sizePolicy);
        backgroundlabel->setMinimumSize(QSize(256, 103));
        backgroundlabel->setMaximumSize(QSize(256, 103));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\351\273\221\344\275\223")});
        font1.setPointSize(18);
        backgroundlabel->setFont(font1);
        backgroundlabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        backgroundLayout->addWidget(backgroundlabel);

        backgroundButton = new QPushButton(layoutWidget1);
        backgroundButton->setObjectName("backgroundButton");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(backgroundButton->sizePolicy().hasHeightForWidth());
        backgroundButton->setSizePolicy(sizePolicy1);
        backgroundButton->setMinimumSize(QSize(220, 0));

        backgroundLayout->addWidget(backgroundButton);


        performanceLayout->addLayout(backgroundLayout);

        fontFamilyLayout = new QHBoxLayout();
        fontFamilyLayout->setSpacing(5);
        fontFamilyLayout->setObjectName("fontFamilyLayout");
        fontFamilyLabel = new QLabel(layoutWidget1);
        fontFamilyLabel->setObjectName("fontFamilyLabel");
        sizePolicy.setHeightForWidth(fontFamilyLabel->sizePolicy().hasHeightForWidth());
        fontFamilyLabel->setSizePolicy(sizePolicy);
        fontFamilyLabel->setMaximumSize(QSize(220, 16777215));
        fontFamilyLabel->setFont(font1);
        fontFamilyLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        fontFamilyLayout->addWidget(fontFamilyLabel);

        fontComboBox = new QFontComboBox(layoutWidget1);
        fontComboBox->setObjectName("fontComboBox");
        sizePolicy1.setHeightForWidth(fontComboBox->sizePolicy().hasHeightForWidth());
        fontComboBox->setSizePolicy(sizePolicy1);
        fontComboBox->setMinimumSize(QSize(220, 0));
        fontComboBox->setMaximumSize(QSize(220, 16777215));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        fontComboBox->setCurrentFont(font2);

        fontFamilyLayout->addWidget(fontComboBox);

        fontFamilyLayout->setStretch(0, 3);
        fontFamilyLayout->setStretch(1, 1);

        performanceLayout->addLayout(fontFamilyLayout);

        fontsizeLayout = new QHBoxLayout();
        fontsizeLayout->setSpacing(5);
        fontsizeLayout->setObjectName("fontsizeLayout");
        sizelabel = new QLabel(layoutWidget1);
        sizelabel->setObjectName("sizelabel");
        sizePolicy.setHeightForWidth(sizelabel->sizePolicy().hasHeightForWidth());
        sizelabel->setSizePolicy(sizePolicy);
        sizelabel->setMaximumSize(QSize(280, 16777215));
        QFont font3;
        font3.setPointSize(16);
        sizelabel->setFont(font3);
        sizelabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        fontsizeLayout->addWidget(sizelabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        fontsizeLayout->addItem(horizontalSpacer_2);

        sizecomboBox = new QComboBox(layoutWidget1);
        sizecomboBox->setObjectName("sizecomboBox");
        sizePolicy1.setHeightForWidth(sizecomboBox->sizePolicy().hasHeightForWidth());
        sizecomboBox->setSizePolicy(sizePolicy1);
        sizecomboBox->setMinimumSize(QSize(0, 0));
        sizecomboBox->setMaximumSize(QSize(220, 16777215));

        fontsizeLayout->addWidget(sizecomboBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        fontsizeLayout->addItem(horizontalSpacer);

        fontsizeLayout->setStretch(0, 4);

        performanceLayout->addLayout(fontsizeLayout);

        textColorLayout = new QHBoxLayout();
        textColorLayout->setSpacing(5);
        textColorLayout->setObjectName("textColorLayout");
        textColorlabel = new QLabel(layoutWidget1);
        textColorlabel->setObjectName("textColorlabel");
        sizePolicy.setHeightForWidth(textColorlabel->sizePolicy().hasHeightForWidth());
        textColorlabel->setSizePolicy(sizePolicy);
        textColorlabel->setMaximumSize(QSize(220, 16777215));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font4.setPointSize(16);
        textColorlabel->setFont(font4);
        textColorlabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        textColorLayout->addWidget(textColorlabel);

        blackButton = new QPushButton(layoutWidget1);
        blackButton->setObjectName("blackButton");
        sizePolicy1.setHeightForWidth(blackButton->sizePolicy().hasHeightForWidth());
        blackButton->setSizePolicy(sizePolicy1);
        blackButton->setMinimumSize(QSize(30, 30));
        blackButton->setMaximumSize(QSize(30, 30));
        blackButton->setStyleSheet(QString::fromUtf8("QPushButton#blackButton {\n"
"background-color:black;\n"
"border:2px solid rgb(230, 230, 230);\n"
"border-radius: 15px;\n"
"}\n"
"QPushButton#blackButton:hover {\n"
"border:2px solid rgb(200, 200, 200);\n"
"}\n"
""));

        textColorLayout->addWidget(blackButton);

        whiteButton = new QPushButton(layoutWidget1);
        whiteButton->setObjectName("whiteButton");
        sizePolicy1.setHeightForWidth(whiteButton->sizePolicy().hasHeightForWidth());
        whiteButton->setSizePolicy(sizePolicy1);
        whiteButton->setMinimumSize(QSize(30, 30));
        whiteButton->setMaximumSize(QSize(30, 30));
        whiteButton->setStyleSheet(QString::fromUtf8("QPushButton#whiteButton {\n"
"background-color:white;\n"
"border:2px solid rgb(230, 230, 230);\n"
"border-radius: 15px;\n"
"}\n"
"QPushButton#whiteButton:hover {\n"
"border:2px solid rgb(200, 200, 200);\n"
"}\n"
""));

        textColorLayout->addWidget(whiteButton);

        blueButton = new QPushButton(layoutWidget1);
        blueButton->setObjectName("blueButton");
        sizePolicy1.setHeightForWidth(blueButton->sizePolicy().hasHeightForWidth());
        blueButton->setSizePolicy(sizePolicy1);
        blueButton->setMinimumSize(QSize(30, 30));
        blueButton->setMaximumSize(QSize(30, 30));
        blueButton->setStyleSheet(QString::fromUtf8("QPushButton#blueButton {\n"
"background-color:rgb(121, 255, 251);\n"
"border:2px solid rgb(230, 230, 230);\n"
"border-radius: 15px;\n"
"}\n"
"QPushButton#blueButton:hover {\n"
"border:2px solid rgb(200, 200, 200);\n"
"}\n"
""));

        textColorLayout->addWidget(blueButton);

        yellowButton = new QPushButton(layoutWidget1);
        yellowButton->setObjectName("yellowButton");
        sizePolicy1.setHeightForWidth(yellowButton->sizePolicy().hasHeightForWidth());
        yellowButton->setSizePolicy(sizePolicy1);
        yellowButton->setMinimumSize(QSize(30, 30));
        yellowButton->setMaximumSize(QSize(30, 30));
        yellowButton->setStyleSheet(QString::fromUtf8("QPushButton#yellowButton {\n"
"background-color:rgb(255, 255, 127);\n"
"border:2px solid rgb(230, 230, 230);\n"
"border-radius: 15px;\n"
"}\n"
"QPushButton#yellowButton:hover {\n"
"border:2px solid rgb(200, 200, 200);\n"
"}\n"
""));

        textColorLayout->addWidget(yellowButton);

        redButton = new QPushButton(layoutWidget1);
        redButton->setObjectName("redButton");
        sizePolicy1.setHeightForWidth(redButton->sizePolicy().hasHeightForWidth());
        redButton->setSizePolicy(sizePolicy1);
        redButton->setMinimumSize(QSize(30, 30));
        redButton->setMaximumSize(QSize(30, 30));
        redButton->setStyleSheet(QString::fromUtf8("QPushButton#redButton {\n"
"background-color:rgb(200, 0, 0);\n"
"border:2px solid rgb(230, 230, 230);\n"
"border-radius: 15px;\n"
"}\n"
"QPushButton#redButton:hover {\n"
"border:2px solid rgb(200, 200, 200);\n"
"}\n"
""));

        textColorLayout->addWidget(redButton);

        fontColorlabel = new QLabel(layoutWidget1);
        fontColorlabel->setObjectName("fontColorlabel");
        sizePolicy1.setHeightForWidth(fontColorlabel->sizePolicy().hasHeightForWidth());
        fontColorlabel->setSizePolicy(sizePolicy1);

        textColorLayout->addWidget(fontColorlabel);

        textColorLayout->setStretch(0, 2);
        textColorLayout->setStretch(1, 1);
        textColorLayout->setStretch(2, 1);
        textColorLayout->setStretch(3, 1);
        textColorLayout->setStretch(4, 1);
        textColorLayout->setStretch(6, 1);

        performanceLayout->addLayout(textColorLayout);

        performanceLayout->setStretch(0, 1);
        performanceLayout->setStretch(1, 1);
        performanceLayout->setStretch(2, 1);
        performanceLayout->setStretch(3, 1);
        settingStacked->addWidget(performance);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        settingStacked->addWidget(page_2);

        horizontalLayout->addWidget(settingStacked);

        horizontalLayout->setStretch(0, 1);

        retranslateUi(Settings);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Settings, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Settings, qOverload<>(&QDialog::reject));

        settingStacked->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QDialog *Settings)
    {
        Settings->setWindowTitle(QCoreApplication::translate("Settings", "\350\256\276\347\275\256", nullptr));

        const bool __sortingEnabled = settingList->isSortingEnabled();
        settingList->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = settingList->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("Settings", "\345\244\226\350\247\202", nullptr));
        settingList->setSortingEnabled(__sortingEnabled);

        backgroundlabel->setText(QCoreApplication::translate("Settings", "\350\203\214\346\231\257", nullptr));
        backgroundButton->setText(QCoreApplication::translate("Settings", "\350\207\252\345\256\232\344\271\211\350\203\214\346\231\257", nullptr));
        fontFamilyLabel->setText(QCoreApplication::translate("Settings", "\345\255\227\344\275\223", nullptr));
        sizelabel->setText(QCoreApplication::translate("Settings", "\345\255\227\345\217\267", nullptr));
        textColorlabel->setText(QCoreApplication::translate("Settings", "\346\226\207\345\255\227\351\242\234\350\211\262", nullptr));
        blackButton->setText(QString());
        whiteButton->setText(QString());
        blueButton->setText(QString());
        yellowButton->setText(QString());
        redButton->setText(QString());
        fontColorlabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
