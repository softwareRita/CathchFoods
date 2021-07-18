QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aid.cpp \
    background.cpp \
    box.cpp \
    food.cpp \
    main.cpp \
    mainscence.cpp \
    mushroom.cpp

HEADERS += \
    aid.h \
    background.h \
    box.h \
    config.h \
    food.h \
    mainscence.h \
    mushroom.h

FORMS += \
    mainscence.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    bg.qrc \
    pic.qrc \
    res.qrc
