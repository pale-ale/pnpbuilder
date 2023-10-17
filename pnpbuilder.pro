# SOURCES += main.cpp
# 
# QMAKE_CXXFLAGS += -std=c++20
# 
# CONFIG += debug testcase no_testcase_installs

TEMPLATE = subdirs
SUBDIRS = src client server tests
client.depends = src
server.depends = src
tests.depends = src