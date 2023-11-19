TARGET = tests
SOURCES = main.cpp
HEADERS = ComponentSystem/TestComponentSystem.hpp Network/TestNetwork.hpp
CONFIG += DEBUG
QT += widgets testlib network
INCLUDEPATH += ../src
LIBS += -L../src -lsrc
LIBS += -lsfml-graphics -lsfml-window -lsfml-system
QMAKE_CXXFLAGS += -std=c++20 -g
