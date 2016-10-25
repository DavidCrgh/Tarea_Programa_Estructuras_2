#include "hilocrearhumanos.h"

HiloCrearHumanos::HiloCrearHumanos(QObject* parent,ListaMundo* pListaMundo,QString* pApellidos,QString* pNombres,QString* pPaises,
      QString* pCreencias,QString* pProfesiones,int pCantidadHumanos)
{

listaMundo=pListaMundo;
apellidos=pApellidos;
nombres=pNombres;
paises=pPaises;
creencias=pCreencias;
profesiones=pProfesiones;
cantidadHumanos=pCantidadHumanos;

}



void HiloCrearHumanos::run(){

    srand(time(NULL));

    for(int i=0;i<cantidadHumanos;i++){
        int id= rand()%10000000;

            while(listaMundo->existeId(id)){
                id= rand()%10000000;
            }

        QString nombre= nombres[rand()%1000];
        QString apellido= apellidos[rand()%1000];
        QString pais= paises[rand()%242];
        QString creencia= creencias[rand()%10];
        QString profesion= profesiones[rand()%50];
        QString correo= "javier16contreras@hotmail.com";

        listaMundo->insertar( id,nombre,apellido,pais,creencia,profesion,correo);
}
}
