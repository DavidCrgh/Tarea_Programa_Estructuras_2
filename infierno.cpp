#include "infierno.h"
#include "windows.h"
#include <cstdlib>
#include <iostream>
using namespace std;

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
       //int a= WinExec(enviarCorreo,SW_HIDE);
       //cout<<a;
    }

}
