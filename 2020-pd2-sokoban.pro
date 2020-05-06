QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    _background.cpp \
    _block.cpp \
    _box.cpp \
    _end.cpp \
    _ground.cpp \
    _player.cpp \
    _wall.cpp \
    level_1.cpp \
    level_2.cpp \
    main.cpp \
    firstwindow.cpp

HEADERS += \
    background.h \
    block.h \
    box.h \
    end.h \
    firstwindow.h \
    ground.h \
    level_1.h \
    level_2.h \
    main.h \
    player.h \
    sokoban.h \
    wall.h

FORMS += \
    firstwindow.ui \
    level_1.ui \
    level_2.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    rec.qrc
