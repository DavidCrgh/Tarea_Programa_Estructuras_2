#include "hilocrearhumanos.h"

HiloCrearHumanos::HiloCrearHumanos(QObject* parent,ListaMundo* pListaMundo,QString* pApellidos,QString* pNombres,QString* pPaises,
      QString* pCreencias,QString* pProfesiones,int pCantidadHumanos,ArbolVida* pArbolVida,Paraiso* pParaiso)
{

listaMundo=pListaMundo;
apellidos=pApellidos;
nombres=pNombres;
paises=pPaises;
creencias=pCreencias;
profesiones=pProfesiones;
cantidadHumanos=pCantidadHumanos;
arbolVida=pArbolVida;
paraiso=pParaiso;
}



void HiloCrearHumanos::run(){

    srand(time(NULL));
    int maximo= 10000000;

    for(int i=0;i<cantidadHumanos;i++){
        int id= (1.0*rand()/RAND_MAX)*maximo;
        int indiceApellido = rand()%1000;

            while(listaMundo->existeId(id)){
                id= (1.0*rand()/RAND_MAX)*maximo;
            }

        QString nombre= nombres[rand()%1000];
        QString apellido= apellidos[indiceApellido];
        QString pais= paises[rand()%242];
        QString creencia= creencias[rand()%10];
        QString profesion= profesiones[rand()%50];
        QString correo= "javier16contreras@hotmail.com";

        NodoHumano* nuevoHumano = new NodoHumano(id,nombre,apellido,pais,creencia,profesion,correo);
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
}
