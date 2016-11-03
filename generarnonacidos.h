#ifndef GENERARNONACIDOS_H
#define GENERARNONACIDOS_H
#include <QtCore>
#include "listamundo.h"
#include "infierno.h"
#include "paraiso.h"
#include "arbolvida.h"
#include <vector>

struct NodoId{
    int id;
    NodoId* siguiente;

    NodoId(int pId){
        id = pId;
        siguiente = NULL;
    }
};

struct ListaIds{
    NodoId* primerNodo;
    ListaMundo* mundo;
    Infierno* infierno;
    Paraiso* paraiso;

    ListaIds(ListaMundo *pMundo, Infierno *pInfierno, Paraiso *pParaiso){
        primerNodo = NULL;
        mundo = pMundo;
        infierno = pInfierno;
        paraiso = pParaiso;
    }

    void popularLista(NodoVida* nodo);
    void insertar(int id);
    QString imprimir();
};

QString generarNoNacidos(ListaMundo* mundo, Infierno* infierno, Paraiso* paraiso, ArbolVida* arbolVida);

#endif // GENERARNONACIDOS_H
