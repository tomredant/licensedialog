QT       += core gui widgets
SOURCES +=test.cpp
TEMPLATE = app
#CONFIG+=static
TARGET = test
#QMAKE_LFLAGS+=-static -static-libgcc -static-libstdc++ -lstdc++
#DEFINES+=STATIC
INCLUDEPATH +=D:/users/Tom/code/showlicense/core/
LIBS += -LD:/users/Tom/code/build-showlicense-Qt_5_15_3-Debug/core/debug -lshowlicense
