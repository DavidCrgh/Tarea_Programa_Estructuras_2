#ifndef PARAISO_H
#define PARAISO_H
#include "arbolavl.h"
#include "listamundo.h"

struct Paraiso{
    ArbolAvl* arbolParaiso;
    ListaMundo* listaParaiso;

    Paraiso(){
        arbolParaiso= new ArbolAvl();
        listaParaiso= new ListaMundo();
    }
};

#endif // PARAISO_H
