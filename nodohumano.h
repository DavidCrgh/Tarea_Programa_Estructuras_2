#ifndef NODOHUMANO_H
#define NODOHUMANO_H
#include <string>
#include <ctime>
#include <QDebug>
#include <stdlib.h>
#include <vector>

struct NodoHumano{
    int id;
    QString nombre;
    QString apellido;
    QString pais;
    QString creencia;
    QString profesion;
    QString correo;
    std::string momentoNacimiento;
    int listaPecados[7];
    NodoHumano* listaHijos[8];

    NodoHumano* siguiente;
    NodoHumano* anterior;

    NodoHumano(int pId, QString pNombre, QString pApellido, QString pPais,
               QString pCreencia, QString pProfesion, QString pCorreo){
        id = pId;
        nombre = pNombre;
        apellido = pApellido;
        pais = pPais;
        creencia = pCreencia;
        profesion = pProfesion;
        correo = pCorreo;
        momentoNacimiento = obtenerNacimiento();
        for(int i = 0; i < 7; i++){
            listaPecados[i] = 0;
        }
        siguiente = NULL;
        anterior = NULL;
    }
    std::string obtenerNacimiento();
};
#endif // NODOHUMANO_H
