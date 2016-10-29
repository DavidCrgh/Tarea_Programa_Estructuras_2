#ifndef INFIERNO_H
#define INFIERNO_H
#include "listamundo.h"
#include <vector>

struct NodoArbolSplay{
    int id;
    NodoHumano* humano;

    NodoArbolSplay* izquierda;
    NodoArbolSplay* derecha;
    NodoArbolSplay* padre;

    NodoArbolSplay(NodoHumano* pHumano){
        id = pHumano->id;
        humano = pHumano;
        izquierda = NULL;
        derecha = NULL;
        padre=NULL;
    }
};

struct ArbolSplay{
    NodoArbolSplay* raiz;

    ArbolSplay(){
        raiz = NULL;
    }
    void rotarIzquierda(NodoArbolSplay* padre);
    void rotarDerecha(NodoArbolSplay* padre);
    void splay(NodoArbolSplay* nodoSplay);
    void insertar(NodoHumano* pHumano);
    NodoArbolSplay* buscar(int id);
    bool borrar(int id);

};

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
