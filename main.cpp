#include "musicPlayer.h"

#include <QApplication>
#include <QSettings>

#define EXIT_CODE_REBOOT 1000

int main(int argc, char *argv[])
{
    int exitCode;
    do {
        QApplication a(argc, argv);
        QCoreApplication::setOrganizationName("iyl");
        QCoreApplication::setApplicationName("MusicPlayer");

        // 初始化默认字体
        QFont defaultFont = QApplication::font();

        // 加载保存的字体设置
        QSettings settings("iyl","MusicPlayer");

        // 字体家族
        QString fontFamily = settings.value("app/fontFamily", defaultFont.family()).toString();

        // 字号
        int fontSize = settings.value("app/fontSize",
                                      settings.value("app/size", defaultFont.pixelSize()).toInt()).toInt();

        // 创建最终字体
        QFont appFont(fontFamily);
        appFont.setPixelSize(fontSize);

        // 设置全局字体
        qApp->setFont(appFont);
        QApplication::setFont(appFont);

        MusicPlayer w;
        w.show();
        exitCode = a.exec();
    } while (exitCode == EXIT_CODE_REBOOT);
    return exitCode;
}
