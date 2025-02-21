#include "onlinemusicwidget.h"

#include <QApplication>
#include <QSettings>

#define EXIT_CODE_REBOOT 1000

int main(int argc, char *argv[])
{
    int exitCode;
    do{
        QApplication a(argc, argv);
        QCoreApplication::setOrganizationName("iyl");
        QCoreApplication::setApplicationName("MusicPlayer");
        QSettings settings("iyl","MusicPlayer");
        if (settings.contains("app/font")) {
            QFont font;
            font.fromString(settings.value("app/font").toString());
            a.setFont(font);
        }
        OnlineMusicWidget w;
        w.show();

        exitCode = a.exec();
    }while (exitCode == EXIT_CODE_REBOOT);

    return exitCode;
}
