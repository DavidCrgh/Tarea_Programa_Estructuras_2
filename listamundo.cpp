#include "listamundo.h"

using namespace std;


string NodoHumano::obtenerNacimiento(){
    time_t momento = time(0);
    string momentoString = "";

    tm* tiempoLocal = localtime(&momento);

    momentoString += "Fecha de Nacimiento: ";
    momentoString += to_string(tiempoLocal->tm_mday) + "/";
    momentoString += to_string(tiempoLocal->tm_mon) + "/";
    momentoString += to_string(1900 + tiempoLocal->tm_year) + "\n";

    momentoString += "Hora de Nacimiento: ";
    momentoString += to_string(tiempoLocal->tm_hour) + ":";
    momentoString += to_string(tiempoLocal->tm_min) + ":";
    momentoString += to_string(tiempoLocal->tm_sec);

    return momentoString;
}

int ListaMundo::cantidadHumanos(){

    NodoHumano* nodoPersonaTemporal=primerHumano;

    int sumatoria=0;
    while(nodoPersonaTemporal!=NULL){
        nodoPersonaTemporal= nodoPersonaTemporal->siguiente;
        sumatoria++;

    }
        return sumatoria;

}

void ListaMundo::insertar(int id,QString nombre, QString apellido,QString pais,QString creencia,
         QString profesion, QString correo){
    NodoHumano* humanoNuevo= new NodoHumano(id,nombre,apellido,pais,creencia,profesion,correo);

    if(primerHumano==NULL)
        primerHumano= humanoNuevo;

    else if(primerHumano->id > humanoNuevo->id){

        primerHumano->anterior= humanoNuevo;
        humanoNuevo->siguiente= primerHumano;
        primerHumano= humanoNuevo;

    }
    else{

        NodoHumano* humanoTemporal = primerHumano;
        while(humanoTemporal->siguiente!=NULL && humanoTemporal->id< humanoNuevo->id){

            humanoTemporal= humanoTemporal->siguiente;

        }

        if(humanoTemporal->id > humanoNuevo->id){

                humanoNuevo->siguiente=humanoTemporal;
                humanoNuevo->anterior=humanoTemporal->anterior;
                humanoTemporal->anterior->siguiente= humanoNuevo;
                humanoTemporal->anterior=humanoNuevo;

        }
        else{

            humanoTemporal->siguiente= humanoNuevo;
            humanoNuevo->anterior=humanoTemporal;
        }

      //  nodoNuevo->siguiente= primerHumano;
       // primerHumano=nodoNuevo;

    }

}

void ListaMundo::borrar(NodoHumano *borrado){
    if(borrado->anterior == NULL){
        primerHumano = primerHumano->siguiente;
        primerHumano->anterior->siguiente = NULL;
        primerHumano->anterior = NULL;
    } else if(borrado->siguiente == NULL){
        borrado->anterior->siguiente = NULL;
        borrado->anterior = NULL;
    } else {
        borrado->anterior->siguiente = borrado->siguiente;
        borrado->siguiente->anterior = borrado->anterior;
        borrado->siguiente = NULL;
        borrado->anterior = NULL;
    }
}

bool ListaMundo:: existeId(int id){
    NodoHumano* humanoActual=primerHumano;
    while (humanoActual!=NULL){

        if(humanoActual->id==id)
            return true;
        humanoActual=humanoActual->siguiente;
    }
    return false;

}


int ListaMundo:: largoLista(){

    int largo=0;
    NodoHumano* humanoTemporal= primerHumano;

    while(humanoTemporal!=NULL){

        largo++;
        humanoTemporal= humanoTemporal->siguiente;

    }

    return largo;
}

NodoHumano* ListaMundo::buscarIdFamilia(int id){

    NodoHumano* humanoTemporal= primerHumano;
    while(humanoTemporal!=NULL){

        if(humanoTemporal->id == id)
            return humanoTemporal;

        humanoTemporal= humanoTemporal->siguiente;

    }
        return NULL;

}


QString ListaMundo::imprimirListaMundo(QString* listaNombrePecado){

    NodoHumano* humanoTemporal= primerHumano;
    QString informacion;
    int humano=0;
    int indice=0;

    while(humanoTemporal!=NULL){
        informacion+= QString::number(humano)+") ";
        informacion+= "Nombre: "+humanoTemporal->nombre+"\n";
        informacion+= "Apellido: "+ humanoTemporal->apellido+"\n";
        informacion+= "ID: "+QString::number(humanoTemporal->id)+"\n";
        informacion+= QString ::fromStdString(humanoTemporal->momentoNacimiento)+"\n";
        informacion+= "Creencia: "+ humanoTemporal->creencia+"\n";
        informacion+= "País: "+ humanoTemporal->pais+"\n";
        informacion+= "Profesión: "+ humanoTemporal->profesion+"\n";
        informacion+= "Correo: "+ humanoTemporal->correo+"\n";
        informacion+= "Cantidad de Pecados \n";
        for(int i=0; i<7;i++){
            informacion+= listaNombrePecado[i]+"\t";
        }
        informacion+= "\n";
        for(int i=0; i<7;i++){
            informacion+= QString::number(humanoTemporal->listaPecados[i])+"\t";
        }
        informacion+= "\n\n";
        humanoTemporal= humanoTemporal->siguiente;
        humano++;
        indice++;
    }
    return informacion;
}

void ListaMundo::otorgarPecados(){

    srand(time(NULL));

    NodoHumano* humanoTemporal = primerHumano;

    while(humanoTemporal!=NULL){

        int lujuria=rand()%101;
        int gula=rand()%101;
        int avaricia=rand()%101;
        int pereza=rand()%101;
        int ira=rand()%101;
        int envidia=rand()%101;
        int soberbia=rand()%101;

        int arregloPecados[7]= {lujuria,gula,avaricia,pereza,ira,envidia,soberbia};

        for(int i=0;i<7;i++)
            humanoTemporal->listaPecados[i]+= arregloPecados[i];

        humanoTemporal= humanoTemporal->siguiente;

    }

}

int sumaPecadosHumano(NodoHumano* persona){

    int sumatoria=0;
    for(int i=0; i<7 ;i++)
        sumatoria+= persona->listaPecados[i];
    return sumatoria;


}

void insertion_sort (Pais* arr[], int length){
        int j;
       Pais* temp;

    for (int i = 0; i < length; i++){
        j = i;

        while (j > 0 && arr[j]->pecadosTotales < arr[j-1]->pecadosTotales){
              temp = arr[j];
              arr[j] = arr[j-1];
              arr[j-1] = temp;
              j--;
              }
        }
}

void ordenarPecadores(std::vector<NodoHumano*>arregloPecadores, int largo){
    int j;
    NodoHumano* temporal;

    for(int i = 0; i < largo; i++){
        j = i;

        while(j > 0 && sumaPecadosHumano(arregloPecadores[j]) > sumaPecadosHumano(arregloPecadores[j-1])){
            temporal = arregloPecadores[j];
            arregloPecadores[j] = arregloPecadores[j-1];
            arregloPecadores[j-1] = temporal;
            j--;
        }
    }
}




QString ListaMundo::paisesPecadores(QString* paises,bool cualTop){
    Pais* arregloPaises[242];
    QString top;

    for(int i=0;i<242;i++){
        int contador=0;
        NodoHumano* humanoTemporal=primerHumano;

        while(humanoTemporal!=NULL){
            if(humanoTemporal->pais==paises[i])
                contador+=sumaPecadosHumano(humanoTemporal);
            humanoTemporal=humanoTemporal->siguiente;
        }
       Pais* pais= new Pais(paises[i],contador);
       arregloPaises[i]=pais;
    }
      insertion_sort(arregloPaises,242);

      for (int i=0;i<20;i++){

          qDebug()<<arregloPaises[i]->nombrePais<<" "<<arregloPaises[i]->pecadosTotales<<"\n";

      }

      if(cualTop){
          for(int i=241; i>231; i--)
              top += arregloPaises[i]->nombrePais+ " " +QString::number(arregloPaises[i]->pecadosTotales)+"\n";
      }
      else{
          int i=0;
          while(arregloPaises[i]->pecadosTotales==0){
            i++;
          }

          for(int j=i; j< i+5; j++)
              top += arregloPaises[j]->nombrePais+" "+QString::number(arregloPaises[j]->pecadosTotales)+"\n";
      }

      return top;

}

NodoHumano* ListaMundo::mitadLista(){

    int largo= largoLista();
    int contador=0;

    NodoHumano* humanoTemporal= primerHumano;

    while(contador<(largo/2)){

        humanoTemporal=humanoTemporal->siguiente;
        contador++;

    }

    return humanoTemporal;

}

int ListaMundo::contarNacionales(QString pPais){
    int sumatoria = 0;
    NodoHumano* nodoActual = primerHumano;

    while(nodoActual != NULL){
        if(nodoActual->pais == pPais){
            sumatoria++;
        }
        nodoActual = nodoActual->siguiente;
    }

    return sumatoria;
}

std::vector<NodoHumano*> ListaMundo::generarHeapCondenados(QString pPais){
    int largoArreglo = contarNacionales(pPais);

    std::vector <NodoHumano*> arregloPecadores(largoArreglo);

    NodoHumano* nodoActual = primerHumano;
    int indice = 0;

    while(nodoActual != NULL){
        if(pPais == nodoActual->pais){
            arregloPecadores[indice] = nodoActual;
            indice++;
        }
        nodoActual = nodoActual->siguiente;
    }

    ordenarPecadores(arregloPecadores, largoArreglo);

    return arregloPecadores;
}

void ListaMundo::generarArbol(){

    arbolMundo->raiz=NULL;

    NodoHumano* mitadHumano= mitadLista();
    NodoHumano* humanoIzquierda= mitadHumano;
    NodoHumano* humanoDerecha= mitadHumano;

    int mitadLista= largoLista()/2;

    int unoPorciento= largoLista()/100;

    int desplazamiento = mitadLista/(unoPorciento/2);
    int caca;
    arbolMundo->raiz = arbolMundo->insertarArbolMundo(mitadHumano, arbolMundo->raiz);

    while(arbolMundo->cantidadNodos(arbolMundo->raiz)< unoPorciento){
        humanoIzquierda = desplazarPuntero(humanoIzquierda, desplazamiento, false);
        humanoDerecha = desplazarPuntero(humanoDerecha, desplazamiento, true);
       // desplazarPuntero(humanoIzquierda,desplazamiento, false);
        //desplazarPuntero(humanoDerecha,desplazamiento,true);
        //int indice=0;

       // if(direccion){
            /*while(humanoDerecha->siguiente!=NULL && indice< desplazamiento){

                humanoDerecha=humanoDerecha->siguiente;
                indice++;

            }*/
        //}

        //else{
            /*indice =0;
            while(humanoIzquierda->anterior!=NULL && indice< desplazamiento){

                humanoIzquierda=humanoIzquierda->anterior;
                indice++;

            }*/

   //     }


        arbolMundo->raiz= arbolMundo->insertarArbolMundo(humanoIzquierda, arbolMundo->raiz);
        arbolMundo->raiz= arbolMundo->insertarArbolMundo(humanoDerecha,arbolMundo->raiz);
        caca = arbolMundo->cantidadNodos(arbolMundo->raiz);

        humanoIzquierda = desplazarPuntero(humanoIzquierda, desplazamiento/2, true);
        humanoDerecha = desplazarPuntero(humanoDerecha, desplazamiento/2, false);

        /*indice=0;
        while(indice< desplazamiento/2){

            humanoDerecha=humanoDerecha->anterior;
            indice++;

        }*/
    //}

    //else{
        /*indice =0;
        while(indice< desplazamiento/2){

            humanoIzquierda=humanoIzquierda->siguiente;
            indice++;

        }

//     }*/

        arbolMundo->raiz= arbolMundo->insertarArbolMundo(humanoIzquierda, arbolMundo->raiz);
        arbolMundo->raiz= arbolMundo->insertarArbolMundo(humanoDerecha,arbolMundo->raiz);
        caca = arbolMundo->cantidadNodos(arbolMundo->raiz);

        humanoIzquierda = desplazarPuntero(humanoIzquierda, desplazamiento/2, false);
        humanoDerecha = desplazarPuntero(humanoDerecha, desplazamiento/2, true);


         //indice=0;

       // if(direccion){
            /*while(humanoDerecha->siguiente!=NULL && indice< desplazamiento/2){

                humanoDerecha=humanoDerecha->siguiente;
                indice++;

            }*/
        //}

        //else{
            /*indice =0;
            while(humanoIzquierda->anterior!=NULL && indice< desplazamiento/2){

                humanoIzquierda=humanoIzquierda->anterior;
                indice++;

            }

    //     }*/
    }



}

NodoHumano* desplazarPuntero(NodoHumano *persona, int cantidad, bool direccion){
    int indice=0;

    if(direccion){
        while(persona->siguiente!=NULL && indice< cantidad){

            persona=persona->siguiente;
            indice++;
        }
    }

    else{
        while(persona->anterior!=NULL && indice< cantidad){

            persona=persona->anterior;
            indice++;
        }
    }
    return persona;
}

int ArbolMundo::cantidadNodos(NodoArbolMundo* raiz){

    if(raiz==NULL)
        return 0;
    else
        return 1+ cantidadNodos(raiz->derecha) + cantidadNodos(raiz->izquierda);

}


NodoArbolMundo* ArbolMundo::insertarArbolMundo(NodoHumano *humano, NodoArbolMundo* raiz){
    if(raiz == NULL){
        return new NodoArbolMundo(humano->id, humano);
    } else if(raiz->id < humano->id){
        raiz->derecha = insertarArbolMundo(humano, raiz->derecha);
    } else if(raiz->id >= humano->id){
        raiz->izquierda = insertarArbolMundo(humano, raiz->izquierda);
    }
    return raiz;
}
