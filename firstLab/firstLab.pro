QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    actions.cpp \
    affine_transform.cpp \
    controller.cpp \
    error_show.cpp \
    figure.cpp \
    inputLoader.cpp \
    main.cpp \
    mainwindow.cpp \
    matrix.cpp \
    point3d.cpp \
    point_array.cpp

HEADERS += \
    actions.h \
    affine_transform.h \
    controller.h \
    error_show.h \
    errors.h \
    figure.h \
    inputLoader.h \
    mainwindow.h \
    matrix.h \
    point3d.h \
    point_array.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
