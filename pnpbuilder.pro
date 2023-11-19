TEMPLATE = subdirs
SUBDIRS = src client server tests
client.depends = src
server.depends = src
tests.depends = src