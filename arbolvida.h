#ifndef ARBOLVIDA_H
#define ARBOLVIDA_H
#include <cstdlib>
//#include "listamundo.h"

struct NodoVida{
    int id;
    NodoVida* derecha;
    NodoVida* izquierda;

    NodoVida(int pId){
        id = pId;
        derecha = NULL;
        izquierda = NULL;
    }
};

struct ArbolVida{
    NodoVida* raiz;

    ArbolVida(){
        raiz = NULL;
    }

    NodoVida* insertar(int pId, NodoVida* nodo);
    bool buscar(int pId, NodoVida* nodo);
    void limpiarArbol();
};

#endif // ARBOLVIDA_H
