#include "nodohumano.h"

using namespace std;

/*
 * Entradas: ninguna
 * Salidas: string con la fecha y hora
 *
 * Genera un string con el momento exacto de invocacion de la
 * funcion.
 */
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

/*
 * Entradas: humano que se desea duplicar
 * Salidas: nodo humano identico al humano ingresado
 *
 * Recibe un nodo humano y genera un nuevo nodo humano con exactamente
 * los mismos atributos que el nodo ingresado. Esto para obtener una
 * direccion de memoria distinta.
 */
NodoHumano* NodoHumano::clonarHumano(NodoHumano* humano){
    NodoHumano* nuevo = new NodoHumano(humano->id, humano->nombre,humano->apellido,
                                       humano->pais,humano->creencia,humano->profesion,
                                       humano->correo);
    nuevo->continente = humano->continente;
    nuevo->ubicacion= humano->ubicacion;
    for(int i = 0; i < 7; i++){
        nuevo->listaHijos[i] = humano->listaHijos[i];
        nuevo->listaPecados[i] = humano->listaPecados[i];
    }
    nuevo->listaHijos[7] = nuevo->listaHijos[8];

    return nuevo;
}

/*
 * Entradas: cadena con el filtro que se desea
 * Salidas: true si el humano cumple con el filtro, false de
 * lo contrario
 *
 * Busca en los atributos del nodo humano para ver si alguno de ellos
 * cumple con el filtro ingresado.
 */
bool NodoHumano::cumpleFiltro(QString filtro){
    return continente == filtro || pais == filtro ||
            creencia == filtro || profesion == filtro;
}
