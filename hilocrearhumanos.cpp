#include "hilocrearhumanos.h"
#include "windows.h"


HiloCrearHumanos::HiloCrearHumanos(QObject* parent,ListaMundo* pListaMundo,QString* pApellidos,QString* pNombres,QString* pPaises,
      QString* pCreencias,QString* pProfesiones,ArbolVida* pArbolVida,Paraiso* pParaiso,QString* pContinentes)
{

listaMundo=pListaMundo;
apellidos=pApellidos;
nombres=pNombres;
paises=pPaises;
creencias=pCreencias;
profesiones=pProfesiones;
arbolVida=pArbolVida;
paraiso=pParaiso;
continentes=pContinentes;
arbolIds= new ArbolVida();

cantidadHumanos=0;
stop= false;
pause=true;

}



void HiloCrearHumanos::run(){

while(!stop){

    while(pause){
        msleep(10);
    }

    srand(time(NULL));
    int maximo= 10000000;

    for(int i=0;i<cantidadHumanos;i++){
        if(i > 9000)
            qDebug("Prueba");
        int id= (1.0*rand()/RAND_MAX)*maximo;
        int indiceApellido = rand()%1000;

            while(arbolIds->buscar(id,arbolIds->raiz)){
                id= (1.0*rand()/RAND_MAX)*maximo;
            }
        arbolIds->raiz= arbolIds->insertar(id,arbolIds->raiz);

        int randomContinentePais= rand()%242;

        QString nombre= nombres[rand()%1000];
        QString apellido= apellidos[indiceApellido];
        QString pais= paises[randomContinentePais];
        QString creencia= creencias[rand()%10];
        QString profesion= profesiones[rand()%50];
        QString continenteHumano= continentes[randomContinentePais];
        QString correo= determinarCorreoHumano(continenteHumano);

        NodoHumano* nuevoHumano = new NodoHumano(id,nombre,apellido,pais,creencia,profesion,correo);
        nuevoHumano->continente=continenteHumano;
        if(arbolVida->buscar(nuevoHumano->id,arbolVida->raiz)){
            QString correo;
            QString cuerpoCorreo;
            QString ejecucion="cmd /c correoEnviar.exe ";

            nuevoHumano->ubicacion="Paraiso";
            cuerpoCorreo+="El_humano_de_ID:_"+QString::number(nuevoHumano->id)+"_se_ha_ido_al_paraiso_y_sus_pecados_han_sido_limpiados,___";
            correo= nuevoHumano->correo;
            paraiso->arbolParaiso= insert(paraiso->arbolParaiso,nuevoHumano);
            paraiso->listaParaiso->insertarNodoHumano(nuevoHumano);



            correo+=" ";
            correo+=cuerpoCorreo;
            ejecucion+=correo;
            const char* envioCorreo=ejecucion.toUtf8().constData();

           // enviarCorreo(envioCorreo);

            HiloEnviarCorreo* hiloCorreo= new HiloEnviarCorreo();
            hiloCorreo->start();
            hiloCorreo->ejecucion=envioCorreo;
            hiloCorreo->pause=false;
            //WinExec(enviarCorreo,SW_HIDE);

        }
        else{
            nuevoHumano->ubicacion="Mundo";
            listaMundo->insertarNodoHumano(nuevoHumano);
            listaMundo->arregloArbolesApellido[indiceApellido] = insert(listaMundo->arregloArbolesApellido[indiceApellido],nuevoHumano);
            listaMundo->asignarHijos(nuevoHumano,indiceApellido);
        }
    }
    listaMundo->generarArbol();
    pause=true;
}
}
