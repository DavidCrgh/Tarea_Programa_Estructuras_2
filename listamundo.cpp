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

    else if(primerHumano->id> humanoNuevo->id){

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

bool ListaMundo:: existeId(int id){
    NodoHumano* humanoActual=primerHumano;
    while (humanoActual!=NULL){

        if(humanoActual->id==id)
            return true;
        humanoActual=humanoActual->siguiente;
    }
    return false;

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
    int humano=1;
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

