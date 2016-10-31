#include "infierno.h"

void Infierno::condenar(QString pPais, ListaMundo *listaMundo){
    std::vector<NodoHumano*> heapPecadores(listaMundo->contarNacionales(pPais));
    heapPecadores = listaMundo->generarHeapCondenados(pPais);
    int cuartoPecadores = heapPecadores.size()/4;

    if(cuartoPecadores > 0){
        for(int i = 0; i < cuartoPecadores; i++){
            NodoHumano* humanoActual = heapPecadores[i];
            arbolInfierno->insertar(humanoActual);
            listaMundo->borrar(humanoActual);
            listaCondenados->insertarNodoHumano(humanoActual);

        }
    }

}
