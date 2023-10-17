TARGET = client
SOURCES = main.cpp
QT += widgets testlib
INCLUDEPATH += ../src
LIBS += -L../src -lsrc
LIBS += -lsfml-graphics -lsfml-window -lsfml-system