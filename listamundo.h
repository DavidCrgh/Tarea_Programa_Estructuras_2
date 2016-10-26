#ifndef LISTAMUNDO_H
#define LISTAMUNDO_H
#include <string>
#include <ctime>
#include <QDebug>
#include <stdlib.h>

struct Pais;
struct NodoHumano;
struct ListaMundo;

void insertion_sort (Pais* arregloPaises[], int largo);
int sumaPecadosHumano(NodoHumano* persona);

struct Pais{

    QString nombrePais;
    int pecadosTotales;

    Pais(QString pNombrePais,int pPecadosTotales){

        nombrePais=pNombrePais;
        pecadosTotales=pPecadosTotales;

    }


};

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

struct ListaMundo{
    NodoHumano* primerHumano;


    ListaMundo(){
        primerHumano = NULL;

    }
    int cantidadHumanos();
    void sumarPecados();
    void insertar(int id,QString nombre,QString apellido,QString pais, QString creencia,
                          QString profesion,QString correo);
    bool existeId(int id);
    NodoHumano* buscarIdFamilia(int id);
    QString imprimirListaMundo(QString* listaNombrePecados);
    void otorgarPecados();

    QString paisesPecadores(QString* paises,bool top);
};

#endif // LISTAMUNDO_H
