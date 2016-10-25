#include "hilointerfaz.h"

HiloInterfaz::HiloInterfaz(QObject* parent, VentanaPrincipal* pVentanaPrincipal)
{
    ventanaPrincipal= pVentanaPrincipal;
    stop=false;
    pause=false;
    connect(this,SIGNAL(actualizarVentanaNacimiento()),ventanaPrincipal->ventanaMundo->ventanaNacimiento,SLOT(actualizarVentana()));

}

void HiloInterfaz::run(){

    while(!stop){

        while(pause){

           msleep(1000);
        }

        emit actualizarVentanaNacimiento();

        msleep(10);
    }

}

