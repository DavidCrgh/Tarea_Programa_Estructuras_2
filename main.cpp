#include "ventanaprincipal.h"
#include <QApplication>
#include "globales.h"
#include "listamundo.h"
#include "hilointerfaz.h"
#include <cstdlib>
#include <iostream>
#include "unistd.h"
#include <windows.h>


using namespace  std;

/* Correos
 * America: mundoamerica2016@gmail.com
 * Europa: mundoeuropa2016@gmail.com
 * Asia: mundoasia2016@gmail.com
 * Africa:mundoafrica2016@gmail.com
 * Oceania:mundooceania2016@gmail.com
 *
 * */

int main(int argc, char *argv[])
{
    chdir("C:\\Users\\Francisco Contreras\\workspace\\pruebaCorreo\\src\\pruebaCorreo\\");

      // WinExec("cmd /c correoEnviar.exe mundooceania2016@gmail.com hola",SW_HIDE); //system();

 QString* apellidos=    cargarApellidos();
 QString* nombres=      cargarNombres();
 QString* paises=       cargarPaises();
 QString* creencias=    cargarCreencias();
 QString* profesiones=  cargarProfesiones();
 QString* nombrePecados= cargarPecados();
 QString* continentes = cargarContinentes();

 for(int i=0;i<242;i++)
     qDebug()<<continentes[i];

 //ArbolApellidos** arbolesApellidos= popularArbolesApellido();

 ListaMundo* listaMundo= new ListaMundo();
 HiloInterfaz* hiloInterfazPrincipal;

    QApplication a(argc, argv);
    VentanaPrincipal* w = new VentanaPrincipal(NULL,apellidos,nombres,paises,creencias,profesiones,
                                               nombrePecados,listaMundo,continentes/*,arbolesApellidos*/);
    w->show();

    hiloInterfazPrincipal= new HiloInterfaz(NULL,w);
    hiloInterfazPrincipal->start();

    return a.exec();
}
