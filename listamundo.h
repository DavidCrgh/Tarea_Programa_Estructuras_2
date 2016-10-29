#ifndef LISTAMUNDO_H
#define LISTAMUNDO_H
#include <string>
#include <ctime>
#include <QDebug>
#include <stdlib.h>
#include <vector>

struct Pais;
struct NodoHumano;
struct ListaMundo;
struct NodoArbolMundo;
struct ArbolMundo;


void insertion_sort (Pais* arregloPaises[], int largo);
void ordenarPecadores(std::vector<NodoHumano*> arregloPecadores, int pLargo);
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
};




#endif // LISTAMUNDO_H
