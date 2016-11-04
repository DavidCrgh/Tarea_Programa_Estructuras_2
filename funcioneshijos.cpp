#include "funcioneshijos.h"

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

bool tieneCandidatos(node *nodo, node* arbol, NodoHumano *humano){
    if(nodo == NULL){
        return false;
    } else{
        return (estaDisponible(nodo->humano,arbol) && !esFamiliar(humano, nodo->humano) && !esFamiliar(nodo->humano, humano)
                && nodo->humano != humano) || tieneCandidatos(nodo->left,arbol, humano)
                || tieneCandidatos(nodo->right,arbol,humano);
    }
}
