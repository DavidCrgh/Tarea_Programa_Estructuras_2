#ifndef LISTAMUNDO_H
#define LISTAMUNDO_H
#include <string>
#include <ctime>

struct NodoHumano{
    int id;
    std::string nombre;
    std::string apellido;
    std::string pais;
    std::string creencia;
    std::string profesion;
    std::string correo;
    std::string momentoNacimiento;
    int listaPecados[7];
    NodoHumano* listaHijos[8];

    NodoHumano* siguiente;
    NodoHumano* anterior;

    NodoHumano(int pId, std::string pNombre, std::string pApellido, std::string pPais,
               std::string pCreencia, std::string pProfesion, std::string pCorreo){
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
};

#endif // LISTAMUNDO_H
