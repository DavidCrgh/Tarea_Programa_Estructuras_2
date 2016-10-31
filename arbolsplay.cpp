#include "arbolsplay.h"

void ArbolSplay::rotarDerecha(NodoArbolSplay *pPadre){
    NodoArbolSplay* tope= pPadre->izquierda;
    NodoArbolSplay* base= tope->derecha;
    NodoArbolSplay* abajo= pPadre->padre;

    if(abajo){
        if(abajo->derecha==pPadre){
            abajo->derecha=tope;
        }
        else{
            abajo->izquierda=tope;
        }
    }
    if(base){
        base->padre=pPadre;
    }
    tope->padre=abajo;
    tope->derecha= pPadre;
    pPadre->padre = tope;
    pPadre->izquierda= base;
}

void ArbolSplay::rotarIzquierda(NodoArbolSplay *pPadre){
    NodoArbolSplay* tope= pPadre->derecha;
    NodoArbolSplay* base= tope->izquierda;
    NodoArbolSplay* abajo= pPadre->padre;

    if(abajo){
        if(abajo->derecha==pPadre){
            abajo->derecha=tope;
        }
        else{
            abajo->izquierda=tope;
        }
    }
    if(base){
        base->padre=pPadre;
    }
    tope->padre=abajo;
    tope->izquierda= pPadre;
    pPadre->padre = tope;
    pPadre->derecha= base;
}

void ArbolSplay::splay(NodoArbolSplay *nodoSplay){
    while(true){
        NodoArbolSplay* padre= nodoSplay->padre;
        if(!padre){
            break;
        }
        NodoArbolSplay* abuelo= padre->padre;
        if(!abuelo){
            if(padre->izquierda==nodoSplay){
                rotarDerecha(padre);
            }
            else{
                rotarIzquierda(padre);
            }
            break;
        }
        if(abuelo->izquierda==padre){
            if(padre->izquierda==nodoSplay){
                rotarDerecha(abuelo);
                rotarDerecha(padre);
            }
            else{
                rotarIzquierda(padre);
                rotarDerecha(abuelo);
            }
        }else{
            if(padre->izquierda==nodoSplay){
                rotarDerecha(padre);
                rotarIzquierda(abuelo);
            }
            else{
                rotarIzquierda(abuelo);
                rotarIzquierda(padre);
            }
        }
    }
    raiz=nodoSplay;
}

void ArbolSplay::insertar(NodoHumano *humano){
        if(!raiz){
            raiz= new NodoArbolSplay(humano);
        }
        NodoArbolSplay* padre=raiz;
        while(true){
            if(padre->humano==humano){

                break;
            }
            if(humano->id<(padre->id)){

                if(padre->izquierda){

                    padre=padre->izquierda;

                }
                else{
                    padre->izquierda= new NodoArbolSplay(humano);
                    padre->izquierda->padre=padre;
                    padre= padre->izquierda;
                    break;
                }
            }
            else{
                if(padre->derecha){
                    padre=padre->derecha;

                }
                else{
                    padre->derecha= new NodoArbolSplay(humano);
                    padre->derecha->padre=padre;
                    padre= padre->derecha;
                    break;
                }
            }
        }
    splay(padre);
}

NodoArbolSplay* ArbolSplay::buscar(int id){
    if(!raiz){
        return NULL;
    }
    NodoArbolSplay* padre= raiz;

    while(padre){
        if(padre->id==id){
            break;
        }
        if(id<(padre->id)){
            if(padre->izquierda){
                padre=padre->izquierda;
            }
            else{
                break;
            }
        }
        else{
            if(padre->derecha){
                padre=padre->derecha;
            }
            else{
                break;
            }
        }
    }
    splay(padre);

    if(padre->id==id){
        return padre;
    }
    else {
        return NULL;
    }
}

bool ArbolSplay::borrar(int id)
{
    NodoArbolSplay* borrado = buscar(id);
    if(!borrado){
        return false;
    }
    splay(borrado);
    NodoArbolSplay* padre  = borrado->izquierda;
    if(!padre){
        raiz = borrado->derecha;
        raiz->padre = NULL;
        return true;
    }
    while(padre->derecha){
        padre = padre->derecha;
    }
    if(borrado->derecha){
        padre->derecha = borrado->derecha;
        borrado->derecha->padre = padre;
    }
    raiz = borrado->izquierda;
    raiz->padre = NULL;
    return true;
}
