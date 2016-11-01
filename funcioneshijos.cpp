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

bool tieneCandidatos(node *arbol, NodoHumano *humano){
    if(arbol == NULL){
        return false;
    } else{
        return (!esFamiliar(humano, arbol->humano) && !esFamiliar(arbol->humano, humano) && arbol->humano != humano) ||
                tieneCandidatos(arbol->left, humano) || tieneCandidatos(arbol->right, humano);
    }
}
