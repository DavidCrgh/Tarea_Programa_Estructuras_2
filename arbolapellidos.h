#ifndef ARBOLAPELLIDOS_H
#define ARBOLAPELLIDOS_H
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

struct ArbolApellidos{
    NodoId* raiz;

    ArbolApellidos(){
        raiz = NULL;
    }
};


#endif // ARBOLAPELLIDOS_H
