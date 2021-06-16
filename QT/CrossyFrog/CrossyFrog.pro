QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bash.cpp \
    choosefrog.cpp \
    frog.cpp \
    gameMode00.cpp \
    main.cpp \
    mainwindow.cpp \
    menu.cpp \
    player.cpp \
    resources.cpp \
    splash.cpp \
    tools/allblocks.cpp \
    tools/allgrounds.cpp \
    tools/block.cpp \
    tools/ground.cpp \
    tools/item.cpp \
    tools/patern.cpp

HEADERS += \
    bash.h \
    choosefrog.h \
    frog.h \
    gameMode00.h \
    mainwindow.h \
    menu.h \
    player.h \
    resources.h \
    splash.h \
    tools/allblocks.h \
    tools/allgrounds.h \
    tools/block.h \
    tools/ground.h \
    tools/includes.h \
    tools/item.h \
    tools/patern.h \
    tools/tools.h

FORMS += \
    bash.ui \
    choosefrog.ui \
    gameMode00.ui \
    mainwindow.ui \
    menu.ui \
    splash.ui

TRANSLATIONS += \
    fr_FR.ts \
    en_US.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    en_US.qm \
    en_US.ts \
    fr_FR.qm \
    fr_FR.ts

RESOURCES += \
    resources.qrc
