#include "hiloarbolvida.h"

HiloArbolVida::HiloArbolVida(QObject* parent, ArbolVida *pArbolVida, ListaMundo* pMundo, Infierno* pInfierno, Paraiso* pParaiso)
{
    stop=false;
    pause=false;
    tiempo = 10;
    arbolVida = pArbolVida;
    mundo = pMundo;
    infierno = pInfierno;
    paraiso = pParaiso;

}

void HiloArbolVida::run(){
    int maximo= 10000000;
    srand(time(NULL));
    while(!stop){
        while(pause){
           msleep(100);
        }
        msleep(tiempo * 1000);
        int id= (1.0*rand()/RAND_MAX)*maximo;
        while(arbolVida->buscar(id, arbolVida->raiz)){
            id= (1.0*rand()/RAND_MAX)*maximo;
        }
        arbolVida->raiz= arbolVida->insertar(id, arbolVida->raiz);

        NodoArbolSplay* buscadoInfierno = infierno->arbolInfierno->buscar(id);
        if(buscadoInfierno != NULL){
            QString correo;
            QString cuerpoCorreo;
            QString ejecucion="cmd /c correoEnviar.exe ";

            buscadoInfierno->humano->ubicacion="Paraiso";
            infierno->arbolInfierno->borrar(id);
            infierno->listaCondenados->borrar(buscadoInfierno->humano);
            paraiso->arbolParaiso=insert(paraiso->arbolParaiso,buscadoInfierno->humano);
            paraiso->listaParaiso->insertar(buscadoInfierno->humano->id, buscadoInfierno->humano->nombre, buscadoInfierno->humano->apellido,
                                            buscadoInfierno->humano->pais,buscadoInfierno->humano->creencia, buscadoInfierno->humano->profesion,
                                            buscadoInfierno->humano->correo);
            cuerpoCorreo+="El_humano_de_ID:_"+QString::number(buscadoInfierno->humano->id)+"_se_ha_ido_del_infierno_al_paraiso_y_sus_pecados_han_sido_limpiados,___";
            correo= buscadoInfierno->humano->correo;

            correo+=" ";
            correo+=cuerpoCorreo;
            ejecucion+=correo;
            const char* envioCorreo=ejecucion.toUtf8().constData();

            HiloEnviarCorreo* hiloCorreo= new HiloEnviarCorreo();
            hiloCorreo->start();
            hiloCorreo->ejecucion=envioCorreo;
            hiloCorreo->pause=false;

        }

        if(mundo->arbolMundo != NULL){
            QString correo;
            QString cuerpoCorreo;
            QString ejecucion="cmd /c correoEnviar.exe ";

            NodoHumano* buscadoMundo = mundo->buscar(id,mundo->arbolMundo);
            if(buscadoMundo != NULL){
                buscadoMundo->ubicacion="Paraiso";
                mundo->reemplazarHumano(buscadoMundo->id, mundo->arbolMundo);
                mundo->borrar(buscadoMundo);
                paraiso->arbolParaiso = insert(paraiso->arbolParaiso, buscadoMundo);
                paraiso->listaParaiso->insertar(buscadoMundo);


                cuerpoCorreo+="El_humano_de_ID:_"+QString::number(buscadoMundo->id)+"_se_ha_ido_del_mundo_al_paraiso_y_sus_pecados_han_sido_limpiados,___";
                correo= buscadoMundo->correo;

                correo+=" ";
                correo+=cuerpoCorreo;
                ejecucion+=correo;
                const char* envioCorreo=ejecucion.toUtf8().constData();

                HiloEnviarCorreo* hiloCorreo= new HiloEnviarCorreo();
                hiloCorreo->start();
                hiloCorreo->ejecucion=envioCorreo;
                hiloCorreo->pause=false;

            }
        }
    }
}
