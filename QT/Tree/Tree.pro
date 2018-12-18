#-------------------------------------------------
#
# Project created by QtCreator 2018-09-15T20:20:28
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = Tree
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        dialog.cpp \
    altura.tpp \
    bst.tpp \
    parients.tpp \
    nivelnodo.tpp \
    deletes.tpp \
    manipulacion.tpp \
    printbst.tpp \
    main.cpp

HEADERS += \
        dialog.h \
    nodobst.h \
    bst.h \
    functions.h \
    word.h \
    iterator.h \
    subbst.h

FORMS += \
        dialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    palabras2.txt \
    numeros.txt \
    cartasClashRoyale.txt
