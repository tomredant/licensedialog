QT       += core gui widgets
TARGET = showlicense
TEMPLATE = lib
DEFINES += QT_DEPRECATED_WARNINGS
RESOURCES += core.qrc
CONFIG+=staticlib static
QMAKE_LFLAGS+=-static -static-libgcc -static-libstdc++ -lstdc++
DEFINES+=STATIC
CONFIG += dll
CONFIG += c++11
SOURCES +=licensedialog.cpp \
    showlicense.cpp \
    licensedialog.cpp \
    showlicense.cpp \
    licensedialog.cpp \
    showlicense.cpp
HEADERS += \
    licensedialog.h \
    showlicense.h \
    licensedialog.h \
    showlicense.h \
    licensedialog.h \
    showlicense.h
FORMS += \
    licensedialog.ui

QMAKE_AR += D:\Qt\qt5-build\qtbase\lib\libQt5Widgets.a
