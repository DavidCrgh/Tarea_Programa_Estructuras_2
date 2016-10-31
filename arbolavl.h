#ifndef ARBOLAVL_H
#define ARBOLAVL_H
#include "nodohumano.h"
#include <cstdlib>

struct NodoArbolAvl{
    int id;
    NodoHumano* humano;

    NodoArbolAvl* izquierda;
    NodoArbolAvl* derecha;
    NodoArbolAvl* padre;
    char factorBalance;

    NodoArbolAvl(NodoHumano* pHumano){
        id = pHumano->id;
        humano = pHumano;
        izquierda = NULL;
        derecha = NULL;
        padre=NULL;
        factorBalance= '=';
    }
};

struct ArbolAvl{
    NodoArbolAvl* raiz;

    ArbolAvl(){
        raiz = NULL;
    }
    void insertar(NodoHumano* pHumano);
    void reconstruirAvl(NodoArbolAvl* ancestro,NodoArbolAvl* nodoNuevo);
    void ajustarFactoresBalance(NodoArbolAvl* fin,NodoArbolAvl* inicio);
    void rotarIzquierda(NodoArbolAvl* nodo);
    void rotarDerecha(NodoArbolAvl* nodo);
    void ajustarIzquierdaDerecha(NodoArbolAvl* fin,NodoArbolAvl* inicio);
    void ajustarDerechaIzquierda(NodoArbolAvl* fin,NodoArbolAvl* inicio);
    NodoArbolAvl* buscar(int id);
};
#endif // ARBOLAVL_H
