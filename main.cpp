#include "ventanaprincipal.h"
#include <QApplication>
#include "globales.h"
#include "listamundo.h"
#include "hilointerfaz.h"

int main(int argc, char *argv[])
{

 QString* apellidos=    cargarApellidos();
 QString* nombres=      cargarNombres();
 QString* paises=       cargarPaises();
 QString* creencias=    cargarCreencias();
 QString* profesiones=  cargarProfesiones();
 QString* nombrePecados= cargarPecados();
 ListaMundo* listaMundo= new ListaMundo();
 HiloInterfaz* hiloInterfazPrincipal;

    QApplication a(argc, argv);
    VentanaPrincipal* w = new VentanaPrincipal(NULL,apellidos,nombres,paises,creencias,profesiones,nombrePecados,listaMundo);
    w->show();

    hiloInterfazPrincipal= new HiloInterfaz(NULL,w);
    hiloInterfazPrincipal->start();


    return a.exec();

}
