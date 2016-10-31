#include "hilocrearhumanos.h"

HiloCrearHumanos::HiloCrearHumanos(QObject* parent,ListaMundo* pListaMundo,QString* pApellidos,QString* pNombres,QString* pPaises,
      QString* pCreencias,QString* pProfesiones,int pCantidadHumanos /*ArbolApellidos** pArbolApellidos*/)
{

listaMundo=pListaMundo;
apellidos=pApellidos;
nombres=pNombres;
paises=pPaises;
creencias=pCreencias;
profesiones=pProfesiones;
cantidadHumanos=pCantidadHumanos;
//arbolApellidos=pArbolApellidos;

}



void HiloCrearHumanos::run(){

    srand(time(NULL));
    int maximo= 10000000;

    for(int i=0;i<cantidadHumanos;i++){
        int id= (1.0*rand()/RAND_MAX)*maximo;

            while(listaMundo->existeId(id)){
                id= (1.0*rand()/RAND_MAX)*maximo;
            }

        QString nombre= nombres[rand()%1000];
        QString apellido= apellidos[rand()%1000];
        QString pais= paises[rand()%242];
        QString creencia= creencias[rand()%10];
        QString profesion= profesiones[rand()%50];
        QString correo= "javier16contreras@hotmail.com";

        listaMundo->insertar( id,nombre,apellido,pais,creencia,profesion,correo);
}
    listaMundo->generarArbol();
}
