#include "infierno.h"
#include "windows.h"
#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * Entradas: pais que se va a condenar y la referencia a la lista del mundo
 * Salidas: ninguna
 *
 * Funcion que genera un heap de los pecadores del pais ingresado y borra al
 * 25% de los mas pecadores del mundo y los mete al infierno.
 * Despues envia un correo con todos los condenados al correo del continente
 * al cual pertenece el pais.
 */
void Infierno::condenar(QString pPais, ListaMundo *listaMundo){
    std::vector<NodoHumano*> heapPecadores(listaMundo->contarNacionales(pPais));
    heapPecadores = listaMundo->generarHeapCondenados(pPais);
    int cuartoPecadores = heapPecadores.size()/4;
    QString correo;
    QString cuerpoCorreo;
    QString ejecucion="cmd /c correoEnviar.exe ";

    if(cuartoPecadores > 0){

        for(int i = 0; i < cuartoPecadores; i++){
            NodoHumano* humanoActual = heapPecadores[i];
            humanoActual->ubicacion="Infierno";
            arbolInfierno->insertar(humanoActual);
            listaMundo->borrar(humanoActual);
            listaCondenados->insertarNodoHumano(humanoActual);
            cuerpoCorreo+="El_humano_de_ID:_"+QString::number(humanoActual->id)+"_se_ha_ido_al_infierno,___";
            correo=humanoActual->correo;

        }
        correo+=" ";
        correo+=cuerpoCorreo;
        ejecucion+=correo;
        const char* enviarCorreo=ejecucion.toUtf8().constData();

        system(enviarCorreo);

    }

}
