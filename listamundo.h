#ifndef LISTAMUNDO_H
#define LISTAMUNDO_H
#include <string>
#include <ctime>
#include <QDebug>
#include <stdlib.h>
#include <vector>
#include "nodohumano.h"
#include "arbolavl.h"

struct Pais;
struct ListaMundo;
struct NodoArbolMundo;
struct ArbolMundo;
struct ArbolApellidos;

void insertion_sort (Pais* arregloPaises[], int largo);
std::vector<NodoHumano*> ordenarPecadores(std::vector<NodoHumano*> arregloPecadores, int pLargo);

std::vector<NodoHumano*> ordenarSalvados(std::vector<NodoHumano*> arregloSalvados, int pLargo);

int sumaPecadosHumano(NodoHumano* persona);
NodoHumano* desplazarPuntero(NodoHumano* persona, int cantidad, bool direccion);

struct NodoArbolMundo{
    int id;
    NodoHumano* humano;
    NodoArbolMundo* derecha;
    NodoArbolMundo* izquierda;

    NodoArbolMundo(int pId, NodoHumano* pHumano){
        id = pId;
        humano = pHumano;
        derecha = NULL;
        izquierda = NULL;
    }
};

struct ArbolMundo{
    NodoArbolMundo* raiz;

    ArbolMundo(){
        raiz=NULL;
    }
    NodoArbolMundo* insertarArbolMundo(NodoHumano *humano, NodoArbolMundo* raiz);
    int cantidadNodos(NodoArbolMundo* raiz);
};

struct Pais{
    QString nombrePais;
    int pecadosTotales;

    Pais(QString pNombrePais,int pPecadosTotales){
        nombrePais=pNombrePais;
        pecadosTotales=pPecadosTotales;
    }
};

struct ListaMundo{
    NodoHumano* primerHumano;
    ArbolMundo* arbolMundo;

    ListaMundo(){
        primerHumano = NULL;
        arbolMundo= new ArbolMundo();
    }
    int cantidadHumanos();
    void sumarPecados();
    void insertar(int id,QString nombre,QString apellido,QString pais, QString creencia,
                          QString profesion,QString correo);
    void borrar(NodoHumano* borrado);
    bool existeId(int id);
    NodoHumano* buscarIdFamilia(int id);
    QString imprimirListaMundo(QString* listaNombrePecados);
    void otorgarPecados();

    QString paisesPecadores(QString* paises,bool top);

    void generarArbol();

    int largoLista();
    int contarNacionales(QString pPais);

    std::vector<NodoHumano*> generarHeapCondenados(QString pPais);

    NodoHumano* mitadLista();

    QString listaCondenadosSalvadosOrdenada(bool cualLista);


    void insertarNodoHumano(NodoHumano* humano);
};
#endif // LISTAMUNDO_H
