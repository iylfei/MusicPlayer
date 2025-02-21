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
    QLabel *previewLabel;
    QFontComboBox *fontComboBox;
    QHBoxLayout *fontsizeLayout;
    QLabel *sizelabel;
    QSpacerItem *horizontalSpacer;
    QComboBox *sizecomboBox;
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
        layoutWidget = new QWidget(Settings);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 0, 661, 471));
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
        layoutWidget1 = new QWidget(performance);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(30, 30, 431, 411));
        performanceLayout = new QVBoxLayout(layoutWidget1);
        performanceLayout->setObjectName("performanceLayout");
        performanceLayout->setContentsMargins(0, 0, 0, 0);
        backgroundLayout = new QHBoxLayout();
        backgroundLayout->setObjectName("backgroundLayout");
        backgroundlabel = new QLabel(layoutWidget1);
        backgroundlabel->setObjectName("backgroundlabel");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\351\273\221\344\275\223")});
        font1.setPointSize(18);
        backgroundlabel->setFont(font1);
        backgroundlabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        backgroundLayout->addWidget(backgroundlabel);

        backgroundButton = new QPushButton(layoutWidget1);
        backgroundButton->setObjectName("backgroundButton");

        backgroundLayout->addWidget(backgroundButton);


        performanceLayout->addLayout(backgroundLayout);

        fontFamilyLayout = new QHBoxLayout();
        fontFamilyLayout->setObjectName("fontFamilyLayout");
        fontFamilyLabel = new QLabel(layoutWidget1);
        fontFamilyLabel->setObjectName("fontFamilyLabel");
        fontFamilyLabel->setFont(font1);
        fontFamilyLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        fontFamilyLayout->addWidget(fontFamilyLabel);

        previewLabel = new QLabel(layoutWidget1);
        previewLabel->setObjectName("previewLabel");

        fontFamilyLayout->addWidget(previewLabel);

        fontComboBox = new QFontComboBox(layoutWidget1);
        fontComboBox->setObjectName("fontComboBox");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        fontComboBox->setCurrentFont(font2);

        fontFamilyLayout->addWidget(fontComboBox);

        fontFamilyLayout->setStretch(0, 3);
        fontFamilyLayout->setStretch(1, 1);
        fontFamilyLayout->setStretch(2, 3);

        performanceLayout->addLayout(fontFamilyLayout);

        fontsizeLayout = new QHBoxLayout();
        fontsizeLayout->setObjectName("fontsizeLayout");
        sizelabel = new QLabel(layoutWidget1);
        sizelabel->setObjectName("sizelabel");
        QFont font3;
        font3.setPointSize(16);
        sizelabel->setFont(font3);
        sizelabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        fontsizeLayout->addWidget(sizelabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        fontsizeLayout->addItem(horizontalSpacer);

        sizecomboBox = new QComboBox(layoutWidget1);
        sizecomboBox->setObjectName("sizecomboBox");

        fontsizeLayout->addWidget(sizecomboBox);

        fontsizeLayout->setStretch(0, 3);
        fontsizeLayout->setStretch(1, 3);
        fontsizeLayout->setStretch(2, 2);

        performanceLayout->addLayout(fontsizeLayout);

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

        backgroundlabel->setText(QCoreApplication::translate("Settings", " \350\203\214\346\231\257", nullptr));
        backgroundButton->setText(QCoreApplication::translate("Settings", "\350\207\252\345\256\232\344\271\211\350\203\214\346\231\257", nullptr));
        fontFamilyLabel->setText(QCoreApplication::translate("Settings", "\345\255\227\344\275\223", nullptr));
        previewLabel->setText(QString());
        sizelabel->setText(QCoreApplication::translate("Settings", " \346\226\207\345\255\227\345\244\247\345\260\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
