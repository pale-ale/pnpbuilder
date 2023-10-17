TARGET = tests
SOURCES = main.cpp
HEADERS = TestComponentSystem.hpp
QT += widgets testlib
INCLUDEPATH += ../src
LIBS += -L../src -lsrc
LIBS += -lsfml-graphics -lsfml-window -lsfml-system