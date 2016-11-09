#include "arbolavl.h"

void ArbolAvl::insertar(NodoHumano *pHumano){
    NodoArbolAvl* temporal,* atras,*ancestro;
    NodoArbolAvl* nodoNuevo= new NodoArbolAvl(pHumano);

    temporal= raiz;
    atras=ancestro= NULL;

    if(raiz==NULL){
        raiz=nodoNuevo;
        return;
    }
    while(temporal!=NULL){
        atras=temporal;

        if(temporal->factorBalance!='='){
            ancestro=temporal;
        }
        if(nodoNuevo->id<temporal->id){
            temporal= temporal->izquierda;
        }else{
            temporal = temporal->derecha;
        }
    }
    nodoNuevo->padre= atras;
    if(nodoNuevo->id < atras->id){
        atras->izquierda= nodoNuevo;
    }
    else{
        atras->derecha= nodoNuevo;
    }
    reconstruirAvl(ancestro,nodoNuevo);
}

void ArbolAvl::reconstruirAvl(NodoArbolAvl *ancestro, NodoArbolAvl *nodoNuevo){
    if(ancestro==NULL){
        if(nodoNuevo->id < raiz->id){
            raiz->factorBalance='L';
        }else{

            raiz->factorBalance='R';
        }
    }
    else if(((ancestro->factorBalance == 'L') && (nodoNuevo->id > ancestro->id)) ||
            ((ancestro->factorBalance == 'R') && (nodoNuevo->id < ancestro->id)))
       {
        ancestro->factorBalance = '=';
        ajustarFactoresBalance(ancestro,nodoNuevo);
       }
    else if((ancestro->factorBalance=='R') && (nodoNuevo->id > ancestro->derecha->id)){
        ancestro->factorBalance = '=';
        rotarIzquierda(ancestro);
        ajustarFactoresBalance(ancestro->padre,nodoNuevo);
    }
    else if((ancestro->factorBalance =='L') && (nodoNuevo->id < ancestro->izquierda->id)){
        ancestro->factorBalance= '=';
        rotarDerecha(ancestro);
        ajustarFactoresBalance(ancestro->padre,nodoNuevo);
    }
    else if((ancestro->factorBalance=='L') && (nodoNuevo->id > ancestro->izquierda->id)){
        rotarIzquierda(ancestro->izquierda);
        rotarDerecha(ancestro);
        ajustarIzquierdaDerecha(ancestro,nodoNuevo);
    }
    else{
        rotarDerecha(ancestro->derecha);
        rotarIzquierda(ancestro);
        ajustarDerechaIzquierda(ancestro,nodoNuevo);
    }
}


void ArbolAvl::ajustarFactoresBalance(NodoArbolAvl *fin, NodoArbolAvl *inicio){
    NodoArbolAvl* temporal = inicio->padre;

    while(temporal!= fin&temporal!=NULL){
        if(inicio->id < temporal->id){
            temporal->factorBalance='L';
        }
        else{
            temporal->factorBalance='R';
        }
        temporal= temporal->padre;
    }
}

void ArbolAvl::rotarIzquierda(NodoArbolAvl *nodo){
   NodoArbolAvl* temporal = nodo->derecha;

   nodo->derecha= temporal->izquierda;
   if(temporal->izquierda!=NULL){
       temporal->izquierda->padre= nodo;
   }
   if(nodo->padre==NULL){
       raiz=temporal;
       temporal->padre=NULL;
   }
   else if(nodo->padre->izquierda == nodo){
       nodo->padre->izquierda= temporal;
   }else{
       nodo->padre->derecha= temporal;
   }
   temporal->izquierda= nodo;
   nodo->padre= temporal;
}

void ArbolAvl::rotarDerecha(NodoArbolAvl *nodo){
    NodoArbolAvl* temporal = nodo->izquierda;

    nodo->izquierda= temporal->derecha;
    if(temporal->derecha!=NULL){
        temporal->derecha->padre= nodo;
    }
    if(nodo->padre==NULL){
        raiz=temporal;
        temporal->padre=NULL;
    }
    else if(nodo->padre->izquierda == nodo){
        nodo->padre->izquierda= temporal;
    }
    else{
        nodo->padre->derecha= temporal;
    }
    temporal->derecha= nodo;
    nodo->padre= temporal;

 }

void ArbolAvl::ajustarIzquierdaDerecha(NodoArbolAvl *fin, NodoArbolAvl *inicio){
    if(fin==raiz){
        fin->factorBalance= '=';
    }
    else if(inicio->id < fin->padre->id){

        fin->factorBalance='R';
        ajustarFactoresBalance(fin->padre->izquierda,inicio);
    }
    else{
        fin->factorBalance='=';
        fin->padre->izquierda->factorBalance='L';
        ajustarFactoresBalance(fin,inicio);
    }
}

void ArbolAvl::ajustarDerechaIzquierda(NodoArbolAvl *fin, NodoArbolAvl *inicio){
    if(fin==raiz){
        fin->factorBalance= '=';
    }
    else if(inicio->id > fin->padre->id){
        fin->factorBalance='L';
        ajustarFactoresBalance(fin->padre->derecha,inicio);
    }
    else{
        fin->factorBalance='=';
        fin->padre->derecha->factorBalance='R';
        ajustarFactoresBalance(fin,inicio);
    }

}
