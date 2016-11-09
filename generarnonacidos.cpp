#include "generarnonacidos.h"

using namespace std;

/*
 * Entradas: raiz del arbol binario sobre el que se deasea bucar
 * Salidas: ninguna
 *
 * Funcion recursiva que busca los ids de cada nodo del arbol en las
 * estructuras del mundo, paraiso e infierno y las mete a una lista
 * de ids si todos retornan negativo.
 */
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

/*
 * Entradas: estructuras del mundo, paraiso, infierno y el arbol de la vida
 * Salidas: QString con los ids de los no nacidos
 *
 * Funcion que genera una lista simple temporal de ids a partir de los ids del
 * arbol de la vida que no se encuentran en ningun otra estructura.
 */
QString generarNoNacidos(ListaMundo *mundo, Infierno *infierno, Paraiso *paraiso, ArbolVida *arbolVida){
    ListaIds* listaIds = new ListaIds(mundo, infierno, paraiso);
    listaIds->popularLista(arbolVida->raiz);
    return listaIds->imprimir();
}
