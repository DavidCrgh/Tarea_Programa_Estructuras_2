#ifndef NODOID_H
#define NODOID_H
#include "listamundo.h"

struct NodoId{
    int id;
    NodoHumano* humano;
    NodoId* derecha;
    NodoId* izquierda;

    NodoId(int pId, NodoHumano* pHumano){
        id = pId;
        humano = pHumano;
        derecha = NULL;
        izquierda = NULL;
    }
};

#endif // NODOID_H
