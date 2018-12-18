QT += widgets

HEADERS     = codeeditor.h \
    word.h \
    nfa.h
SOURCES     = main.cpp \
              codeeditor.cpp
# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/widgets/codeeditor
INSTALLS += target

DISTFILES += \
    testToStudy.txt \
    operadoresSeparadores.txt \
    palabrasReservadas.txt \
    templates.txt
