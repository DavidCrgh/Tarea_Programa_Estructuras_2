#include "generarnonacidos.h"

using namespace std;

void ListaIds::popularLista(NodoVida *nodo){
    if(nodo == NULL){
        return;
    } else{
        popularLista(nodo->izquierda);
        NodoHumano* buscadoMundo = mundo->buscar(nodo->id,mundo->arbolMundo);
        NodoArbolSplay* buscadoInfierno = infierno->arbolInfierno->buscar(nodo->id);
        NodoHumano* buscadoParaiso = paraiso->listaParaiso->buscar(nodo->id);

        if(buscadoMundo == NULL && buscadoParaiso == NULL && buscadoInfierno == NULL){
            insertar(nodo->id);
        }
        popularLista(nodo->derecha);
    }
}

void ListaIds::insertar(int id){
    NodoId* nuevo = new NodoId(id);
    nuevo->siguiente = primerNodo;
    primerNodo = nuevo;
}

QString ListaIds::imprimir(){
    NodoId* nodoActual = primerNodo;
    QString mensaje = "Almas sin Nacer:\n";

    while(nodoActual != NULL){
        mensaje += QString::number(nodoActual->id) + "\n";
        nodoActual = nodoActual->siguiente;
    }
    return mensaje;
}

QString generarNoNacidos(ListaMundo *mundo, Infierno *infierno, Paraiso *paraiso, ArbolVida *arbolVida){
    ListaIds* listaIds = new ListaIds(mundo, infierno, paraiso);
    listaIds->popularLista(arbolVida->raiz);
    return listaIds->imprimir();
}
