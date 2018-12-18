#-------------------------------------------------
#
# Project created by QtCreator 2018-11-17T23:17:25
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = RegularExpressionToDeterministicAutomaton
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
        main.cpp \
        mainwindow.cpp \
    A_btngenerate.cpp \
    B_normalizarinphrases.cpp \
    C_analizelistphrases.cpp \
    Z0_normalizarstring.cpp \
    Z1_functionstest.cpp \
    D_normalizefontlistphrases.cpp \
    customview.cpp \
    nfafunction.tpp

HEADERS += \
        mainwindow.h \
    state.h \
    alphabet.h \
    NFA.h \
    DFA.h \
    normalizarstring.h \
    phrases.h \
    functionsTest.h \
    customview.h \
    statecompuesto.h \
    state2.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    automata.dot \
    finiteautomaton.dot
