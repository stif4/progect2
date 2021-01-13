QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    acter.cpp \
    afisha2.cpp \
    by.cpp \
    cassir2.cpp \
    cchoicepathdelegate.cpp \
    in.cpp \
    login.cpp \
    main.cpp \
    dialog.cpp \
    ordertoby.cpp \
    performance2.cpp \
    reader.cpp \
    tickets.cpp

HEADERS += \
    acter.h \
    afisha2.h \
    by.h \
    cassir2.h \
    cchoicepathdelegate.h \
    dialog.h \
    in.h \
    login.h \
    ordertoby.h \
    performance2.h \
    reader.h \
    tickets.h

FORMS += \
    acter.ui \
    by.ui \
    dialog.ui \
    in.ui \
    login.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=
