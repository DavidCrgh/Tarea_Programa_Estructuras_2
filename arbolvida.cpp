#include "arbolvida.h"

NodoVida* ArbolVida::insertar(int id, NodoVida* raiz)
{
    if(raiz == NULL){
        return new NodoVida(id);
    } else if(raiz->id < id){
        raiz->derecha = insertar(id, raiz->derecha);
    } else if(raiz->id >= id){
        raiz->izquierda = insertar(id, raiz->izquierda);
    }
    return raiz;
}

bool ArbolVida::buscar(int pId, NodoVida* raiz){
    if(raiz == NULL){
        return false;
    } else if(raiz->id == pId){
        return true;
    } else {
        return buscar(pId, raiz->izquierda) || buscar(pId, raiz->derecha);
    }
}

int ArbolVida::contarNodos(NodoVida* nodo){
    if(nodo == NULL){
        return 0;
    } else{
        return 1 + contarNodos(nodo->izquierda) + contarNodos(nodo->derecha);
    }
}

void ArbolVida::limpiarArbol(){
    raiz = NULL;
}
