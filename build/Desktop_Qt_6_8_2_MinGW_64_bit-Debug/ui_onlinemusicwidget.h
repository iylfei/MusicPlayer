/********************************************************************************
** Form generated from reading UI file 'onlinemusicwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ONLINEMUSICWIDGET_H
#define UI_ONLINEMUSICWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OnlineMusicWidget
{
public:
    QGroupBox *searchGroup;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *searchButton;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *optionsButton;
    QPushButton *minButton;
    QPushButton *closeButton;
    QTextBrowser *lyric;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGroupBox *playerGroup;
    QLabel *titleLabel;
    QWidget *layoutWidget1;
    QHBoxLayout *sliderLayout;
    QLabel *currentTimeLabel;
    QSlider *progressSlider;
    QLabel *totalTimeLabel;
    QLabel *authorLabel;
    QWidget *layoutWidget2;
    QHBoxLayout *playLayout;
    QPushButton *prevButton;
    QPushButton *playButton;
    QPushButton *nextButton;
    QWidget *layoutWidget3;
    QHBoxLayout *volumeLayout;
    QPushButton *volumeButton;
    QSlider *volumeSlider;
    QPushButton *localMusicListButton;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QListView *musicList;
    QLabel *musicListLabel;

    void setupUi(QWidget *OnlineMusicWidget)
    {
        if (OnlineMusicWidget->objectName().isEmpty())
            OnlineMusicWidget->setObjectName("OnlineMusicWidget");
        OnlineMusicWidget->resize(1076, 622);
        searchGroup = new QGroupBox(OnlineMusicWidget);
        searchGroup->setObjectName("searchGroup");
        searchGroup->setGeometry(QRect(200, 10, 661, 81));
        searchGroup->setStyleSheet(QString::fromUtf8("border:1px solid white;\n"
"border-radius:10px;"));
        label = new QLabel(searchGroup);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 20, 141, 41));
        label->setStyleSheet(QString::fromUtf8("border:1px solid white;\n"
"border-radius:5px;\n"
""));
        lineEdit = new QLineEdit(searchGroup);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(190, 20, 321, 41));
        QFont font;
        font.setPointSize(12);
        lineEdit->setFont(font);
        searchButton = new QPushButton(searchGroup);
        searchButton->setObjectName("searchButton");
        searchButton->setGeometry(QRect(530, 20, 71, 41));
        searchButton->setMinimumSize(QSize(71, 41));
        searchButton->setMaximumSize(QSize(71, 41));
        searchButton->setStyleSheet(QString::fromUtf8("QPushButton#searchButton\n"
"{\n"
"	background:transparent;\n"
"	border:1px solid white;\n"
"	border-radius:5px;\n"
"}\n"
"QPushButton#searchButton:hover \n"
"{	\n"
"	background:transparent;\n"
"	color:rgb(255, 255, 255);\n"
"}"));
        layoutWidget = new QWidget(OnlineMusicWidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(933, 0, 145, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        optionsButton = new QPushButton(layoutWidget);
        optionsButton->setObjectName("optionsButton");
        optionsButton->setFont(font);
        optionsButton->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"border:none;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/prefix1/images/options.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        optionsButton->setIcon(icon);
        optionsButton->setIconSize(QSize(25, 25));

        horizontalLayout->addWidget(optionsButton);

        minButton = new QPushButton(layoutWidget);
        minButton->setObjectName("minButton");
        minButton->setMinimumSize(QSize(45, 38));
        minButton->setMaximumSize(QSize(45, 38));
        minButton->setBaseSize(QSize(0, 0));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(false);
        minButton->setFont(font1);
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

        closeButton = new QPushButton(layoutWidget);
        closeButton->setObjectName("closeButton");
        closeButton->setMinimumSize(QSize(44, 38));
        closeButton->setMaximumSize(QSize(44, 38));
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(false);
        closeButton->setFont(font2);
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

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 2);
        lyric = new QTextBrowser(OnlineMusicWidget);
        lyric->setObjectName("lyric");
        lyric->setGeometry(QRect(650, 130, 411, 361));
        scrollArea = new QScrollArea(OnlineMusicWidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(1040, 120, 16, 371));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 16, 352));
        scrollArea->setWidget(scrollAreaWidgetContents);
        playerGroup = new QGroupBox(OnlineMusicWidget);
        playerGroup->setObjectName("playerGroup");
        playerGroup->setGeometry(QRect(50, 520, 881, 91));
        titleLabel = new QLabel(playerGroup);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setGeometry(QRect(10, 10, 201, 31));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font3.setPointSize(14);
        titleLabel->setFont(font3);
        titleLabel->setStyleSheet(QString::fromUtf8(""));
        layoutWidget1 = new QWidget(playerGroup);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(160, 60, 711, 24));
        sliderLayout = new QHBoxLayout(layoutWidget1);
        sliderLayout->setObjectName("sliderLayout");
        sliderLayout->setContentsMargins(0, 0, 0, 0);
        currentTimeLabel = new QLabel(layoutWidget1);
        currentTimeLabel->setObjectName("currentTimeLabel");
        currentTimeLabel->setStyleSheet(QString::fromUtf8("color: grey;"));

        sliderLayout->addWidget(currentTimeLabel);

        progressSlider = new QSlider(layoutWidget1);
        progressSlider->setObjectName("progressSlider");
        progressSlider->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"    background-color: #CCCCCC;\n"
"    height: 8px;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"    background-color: rgb(71, 213, 213); \n"
"    border-radius: 4px;  \n"
"}\n"
"\n"
"QSlider::add-page:horizontal {\n"
"    background-color: #CCCCCC;  \n"
"    border-radius: 4px; \n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    background-color: white; \n"
"    border: none;\n"
"    width: 16px;\n"
"    margin: -4px 0;\n"
"    border-radius: 8px; \n"
"}"));
        progressSlider->setOrientation(Qt::Orientation::Horizontal);

        sliderLayout->addWidget(progressSlider);

        totalTimeLabel = new QLabel(layoutWidget1);
        totalTimeLabel->setObjectName("totalTimeLabel");
        totalTimeLabel->setStyleSheet(QString::fromUtf8("color: grey;"));

        sliderLayout->addWidget(totalTimeLabel);

        authorLabel = new QLabel(playerGroup);
        authorLabel->setObjectName("authorLabel");
        authorLabel->setGeometry(QRect(10, 50, 111, 16));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font4.setPointSize(11);
        authorLabel->setFont(font4);
        authorLabel->setStyleSheet(QString::fromUtf8("color:white;"));
        layoutWidget2 = new QWidget(playerGroup);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(380, 10, 131, 51));
        playLayout = new QHBoxLayout(layoutWidget2);
        playLayout->setObjectName("playLayout");
        playLayout->setContentsMargins(0, 0, 0, 0);
        prevButton = new QPushButton(layoutWidget2);
        prevButton->setObjectName("prevButton");
        prevButton->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border:none;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/prefix1/images/left.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        prevButton->setIcon(icon1);
        prevButton->setIconSize(QSize(30, 30));

        playLayout->addWidget(prevButton);

        playButton = new QPushButton(layoutWidget2);
        playButton->setObjectName("playButton");
        playButton->setStyleSheet(QString::fromUtf8("QPushButton#playButton{\n"
"background-color: transparent;\n"
"border:none;\n"
"}\n"
""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/prefix1/images/play.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        icon2.addFile(QString::fromUtf8(":/images/prefix1/images/pause.png"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        playButton->setIcon(icon2);
        playButton->setIconSize(QSize(40, 40));

        playLayout->addWidget(playButton);

        nextButton = new QPushButton(layoutWidget2);
        nextButton->setObjectName("nextButton");
        nextButton->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border:none;"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/prefix1/images/right.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        nextButton->setIcon(icon3);
        nextButton->setIconSize(QSize(30, 30));

        playLayout->addWidget(nextButton);

        layoutWidget3 = new QWidget(playerGroup);
        layoutWidget3->setObjectName("layoutWidget3");
        layoutWidget3->setGeometry(QRect(630, 20, 191, 41));
        volumeLayout = new QHBoxLayout(layoutWidget3);
        volumeLayout->setObjectName("volumeLayout");
        volumeLayout->setContentsMargins(0, 0, 0, 0);
        volumeButton = new QPushButton(layoutWidget3);
        volumeButton->setObjectName("volumeButton");
        volumeButton->setFont(font);
        volumeButton->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"border:none;"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/prefix1/images/colume.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        icon4.addFile(QString::fromUtf8(":/images/prefix1/images/columeOff.png"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        volumeButton->setIcon(icon4);
        volumeButton->setIconSize(QSize(25, 25));

        volumeLayout->addWidget(volumeButton);

        volumeSlider = new QSlider(layoutWidget3);
        volumeSlider->setObjectName("volumeSlider");
        volumeSlider->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"    background-color: rgb(132, 132, 132);\n"
"    height: 8px;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"	background-color: rgb(241, 161, 0);\n"
"    border-radius: 4px;  \n"
"}\n"
"\n"
"QSlider::add-page:horizontal {\n"
"    border-radius: 4px; \n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    background-color: white; \n"
"    border: none;\n"
"    width: 16px;\n"
"    margin: -4px 0;\n"
"    border-radius: 8px; \n"
"}"));
        volumeSlider->setOrientation(Qt::Orientation::Horizontal);

        volumeLayout->addWidget(volumeSlider);

        layoutWidget2->raise();
        authorLabel->raise();
        layoutWidget2->raise();
        layoutWidget2->raise();
        titleLabel->raise();
        localMusicListButton = new QPushButton(OnlineMusicWidget);
        localMusicListButton->setObjectName("localMusicListButton");
        localMusicListButton->setGeometry(QRect(1020, 580, 31, 31));
        localMusicListButton->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border:none;"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/prefix1/images/localMusicList.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        localMusicListButton->setIcon(icon5);
        localMusicListButton->setIconSize(QSize(25, 25));
        textEdit = new QTextEdit(OnlineMusicWidget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(410, 130, 211, 171));
        textEdit_2 = new QTextEdit(OnlineMusicWidget);
        textEdit_2->setObjectName("textEdit_2");
        textEdit_2->setGeometry(QRect(410, 300, 211, 191));
        musicList = new QListView(OnlineMusicWidget);
        musicList->setObjectName("musicList");
        musicList->setGeometry(QRect(40, 130, 271, 361));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font5.setPointSize(12);
        musicList->setFont(font5);
        musicList->setStyleSheet(QString::fromUtf8("color:black;"));
        musicListLabel = new QLabel(OnlineMusicWidget);
        musicListLabel->setObjectName("musicListLabel");
        musicListLabel->setGeometry(QRect(50, 90, 141, 41));
        musicListLabel->setStyleSheet(QString::fromUtf8(""));
        playerGroup->raise();
        layoutWidget2->raise();
        searchGroup->raise();
        lyric->raise();
        scrollArea->raise();
        localMusicListButton->raise();
        textEdit->raise();
        textEdit_2->raise();
        musicListLabel->raise();
        musicList->raise();

        retranslateUi(OnlineMusicWidget);

        QMetaObject::connectSlotsByName(OnlineMusicWidget);
    } // setupUi

    void retranslateUi(QWidget *OnlineMusicWidget)
    {
        OnlineMusicWidget->setWindowTitle(QCoreApplication::translate("OnlineMusicWidget", "OnlineMusicWidget", nullptr));
        searchGroup->setTitle(QString());
        label->setText(QCoreApplication::translate("OnlineMusicWidget", "\346\220\234\347\264\242\346\255\214\346\233\262\345\220\215\347\247\260", nullptr));
        lineEdit->setText(QString());
        searchButton->setText(QCoreApplication::translate("OnlineMusicWidget", "\346\220\234\347\264\242", nullptr));
        optionsButton->setText(QString());
        minButton->setText(QCoreApplication::translate("OnlineMusicWidget", "\342\200\224", nullptr));
        closeButton->setText(QCoreApplication::translate("OnlineMusicWidget", "X", nullptr));
        playerGroup->setTitle(QString());
        titleLabel->setText(QCoreApplication::translate("OnlineMusicWidget", "\346\255\214\346\233\262\345\220\215", nullptr));
        currentTimeLabel->setText(QCoreApplication::translate("OnlineMusicWidget", "00:00", nullptr));
        totalTimeLabel->setText(QCoreApplication::translate("OnlineMusicWidget", "00:00", nullptr));
        authorLabel->setText(QCoreApplication::translate("OnlineMusicWidget", "\344\275\234\350\200\205", nullptr));
        prevButton->setText(QString());
        playButton->setText(QString());
        nextButton->setText(QString());
        volumeButton->setText(QString());
#if QT_CONFIG(tooltip)
        localMusicListButton->setToolTip(QCoreApplication::translate("OnlineMusicWidget", "<html><head/><body><p>\346\234\254\345\234\260\346\255\214\346\233\262</p><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        localMusicListButton->setText(QString());
        musicListLabel->setText(QCoreApplication::translate("OnlineMusicWidget", "\346\222\255\346\224\276\345\210\227\350\241\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OnlineMusicWidget: public Ui_OnlineMusicWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ONLINEMUSICWIDGET_H
