#ifndef INFIERNO_H
#define INFIERNO_H
#include "arbolsplay.h"
#include "listamundo.h"

struct Infierno{
    ArbolSplay* arbolInfierno;
    ListaMundo* listaCondenados;

    Infierno(){

        arbolInfierno= new ArbolSplay();
        listaCondenados= new ListaMundo();

    }

    void condenar(QString pPais, ListaMundo* listaMundo);
};

#endif // INFIERNO_H
