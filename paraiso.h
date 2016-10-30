#ifndef PARAISO_H
#define PARAISO_H
#include "listamundo.h"
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

struct Paraiso{
    ArbolAvl* arbolParaiso;
    ListaMundo* listaParaiso;

    Paraiso(){
        arbolParaiso= new ArbolAvl();
        listaParaiso= new ListaMundo();
    }
};

#endif // PARAISO_H
