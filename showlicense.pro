TEMPLATE = subdirs
#CONFIG += ordered
SUBDIRS = core \
          test
test.depends = core
CONFIG += console

core.subdir  = core
test.subdir  = test
