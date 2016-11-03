#include "hilocrearhumanos.h"

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
bool stop= false;
bool pause=false;

}



void HiloCrearHumanos::run(){
while(!stop){

    while(pause){

        msleep(10);
    }

    srand(time(NULL));
    int maximo= 10000000;

    for(int i=0;i<cantidadHumanos;i++){
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
            paraiso->arbolParaiso= insert(paraiso->arbolParaiso,nuevoHumano);
            paraiso->listaParaiso->insertarNodoHumano(nuevoHumano);

        }
        else{
            listaMundo->insertarNodoHumano(nuevoHumano);
            listaMundo->arregloArbolesApellido[indiceApellido] = insert(listaMundo->arregloArbolesApellido[indiceApellido],nuevoHumano);
            listaMundo->asignarHijos(nuevoHumano,indiceApellido);
        }
    }
    listaMundo->generarArbol();
    pause=true;
}
}
