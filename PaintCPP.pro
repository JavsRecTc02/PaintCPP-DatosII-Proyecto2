QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    drawpanel.cpp \
    figures.cpp \
    main.cpp \
    mainwindow.cpp \
    resize.cpp \
    saveinsert.cpp

HEADERS += \
    drawpanel.h \
    figures.h \
    mainwindow.h \
    resize.h \
    saveinsert.h

FORMS += \
    mainwindow.ui

RC_ICONS = AppIcon.ico

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc

DISTFILES +=
