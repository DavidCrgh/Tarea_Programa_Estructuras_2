#include "ventanaprincipal.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VentanaPrincipal w;
    w.show();

    qDebug("Ein Klassiker");

    return a.exec();
}
