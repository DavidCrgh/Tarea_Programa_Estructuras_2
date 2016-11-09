#include "funcioneshijos.h"

/*
 * Entradas: humano (candidato) que se desea buscar en la descendencia del otro humano
 * ingresado (humano).
 * Salidas: true si se encontro al candidato en alguna de las listas de hijos, falso de
 * lo contrario.
 *
 * Funcion que itera sobre la lista de hijos del humano y luego sobre la lista de hijos de
 * cada hijo buscando al canditado ingresado.
 */
bool esFamiliar(NodoHumano* humano, NodoHumano* candidato){
    for(int i = 0; i < 8; i++){
        if(humano->listaHijos[i] != NULL){
            if(humano->listaHijos[i] == candidato){
                return true;
            }
            for(int j = 0; j < 8; j++){
                if(humano->listaHijos[i]->listaHijos[j] != NULL && humano->listaHijos[i]->listaHijos[j] == candidato){
                    return true;
                }
            }
        }
    }
    return false;
}

/*
 * Entradas: humano que se desea buscar en las listas de hijos
 * nodo raiz del arbol sobre el que se desea buscar
 * Salidas: true si encontro al humano, false de lo contrario
 *
 * Funcion recursiva que busca al humano ingresado en las listas de hijos
 * de cada nodo del arbol AVL para ver si este no se encuentra en la lista
 * de hijos de alguien mas.
 */
bool estaDisponible(NodoHumano *humano, node *arbol){
    if(arbol == NULL){
        return true;
    } else{
        for(int i = 0; i < 7; i++){
            if(arbol->humano->listaHijos[i] == NULL){
                break;
            } else{
                if(arbol->humano->listaHijos[i] == humano){
                    return false;
                }
            }
        }
        return true && estaDisponible(humano, arbol->left) && estaDisponible(humano,arbol->right);
    }
}

/*
 * Entradas: nodo sobre el cual la funcion esta revisando, nodo raiz
 * del arbol de apellido correspondiente, humano al cual esta evaluando
 * Salidas: true si encuentra al menos un humano que puede ser hijo del
 * humano ingresado, false de lo contrario
 *
 * Funcion que busca en el arbol de apellidos ingresado para ver si el
 * humano ingresado tiene algun posible hijo.
 */
bool tieneCandidatos(node *nodo, node* arbol, NodoHumano *humano){
    if(nodo == NULL){
        return false;
    } else{
        return (estaDisponible(nodo->humano,arbol) && !esFamiliar(humano, nodo->humano) && !esFamiliar(nodo->humano, humano)
                && nodo->humano != humano) || tieneCandidatos(nodo->left,arbol, humano)
                || tieneCandidatos(nodo->right,arbol,humano);
    }
}
