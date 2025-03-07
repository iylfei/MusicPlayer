QT       += core gui network sql multimedia multimedia-private

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

CODECFORTR = UTF-8
CODECFORSRC = UTF-8

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    musicPlayer.cpp \
    settings.cpp

HEADERS += \
    musicPlayer.h \
    settings.h

FORMS += \
    musicPlayer.ui \
    settings.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    musicPlayer.qrc
