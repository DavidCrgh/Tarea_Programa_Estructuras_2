#ifndef HILOCREARHUMANOS_H
#define HILOCREARHUMANOS_H

#include <QtCore>
#include "listamundo.h"
#include "arbolvida.h"
#include "paraiso.h"

//#include "arbolapellidos.h"


class HiloCrearHumanos : public QThread
{
    Q_OBJECT
public:
    HiloCrearHumanos(QObject* parent=0,ListaMundo* listaMundo=0,QString* apellidos=0,QString* nombres=0,QString* paises=0,
        QString* creencias=0,QString* profesiones=0,int cantidadHumanos=0,ArbolVida* arbolVida=0,Paraiso* paraiso=0);
        ListaMundo* listaMundo;
        QString* apellidos;
        QString* nombres;
        QString* paises;
        QString* creencias;
        QString* profesiones;
        int cantidadHumanos;
        ArbolVida* arbolVida;
        Paraiso* paraiso;
        //ArbolApellidos** arbolApellidos;
    void run();
};

#endif // HILOCREARHUMANOS_H
