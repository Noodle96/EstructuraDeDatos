#include "widget.h"
#include <QApplication>
#include "persona.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    Persona p1;
    p1.setCodigo(103);
    cout << p1.getCodigo() << std::endl;

    return a.exec();
}
