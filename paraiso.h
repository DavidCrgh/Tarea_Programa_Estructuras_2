#ifndef PARAISO_H
#define PARAISO_H
#include "arbolavl.h"
#include "listamundo.h"
#include "avltest.h"

struct Paraiso{
    node * arbolParaiso;
    ListaMundo* listaParaiso;

    Paraiso(){
        arbolParaiso= NULL;
        listaParaiso= new ListaMundo();
    }
};

#endif // PARAISO_H
