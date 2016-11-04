#include "nodohumano.h"

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

NodoHumano* NodoHumano::clonarHumano(NodoHumano* humano){
    NodoHumano* nuevo = new NodoHumano(humano->id, humano->nombre,humano->apellido,
                                       humano->pais,humano->creencia,humano->profesion,
                                       humano->correo);
    nuevo->continente = humano->continente;
    for(int i = 0; i < 7; i++){
        nuevo->listaHijos[i] = humano->listaHijos[i];
        nuevo->listaPecados[i] = humano->listaPecados[i];
    }
    nuevo->listaHijos[7] = nuevo->listaHijos[8];

    return nuevo;
}
