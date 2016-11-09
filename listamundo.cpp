#include "listamundo.h"
#include "windows.h"
#include <iostream>
#include <cstdlib>
#include "unistd.h"
using namespace std;

/*
 *
 * Entradas: El comando con el cual se ejecutará el correo.
 * Salidas: Ninguna.
 * Envia un correo, dados como parametros el correo a enviar y el mensaje.
 *
 * */

void enviarCorreo(const char* ejecucion){
    chdir("C:\\Users\\Francisco Contreras\\workspace\\pruebaCorreo\\src\\pruebaCorreo\\");
    system(ejecucion);
}

/*
 *
 *Entradas: El continente.
 *Salidas: El correo correspondiente al continente.
 *La funcion determina dado un continente, al cual correo pertenece.
 *
 * */

QString determinarCorreoHumano(QString continente){

QString america= "mundoamerica2016@gmail.com";
QString europa= "mundoeuropa2016@gmail.com";
QString asia= "mundoasia2016@gmail.com";
QString africa= "mundoafrica2016@gmail.com";
QString oceania="mundooceania2016@gmail.com";

    if(continente=="America"){
        return america;
    }
    else if(continente=="Europa"){
        return europa;
    }
     else if(continente=="Asia"){
        return asia;
    }
     else if(continente== "Africa"){
        return africa;
    }
     else if(continente=="Oceania"){
        return oceania;
    }
     else{
        return "Ninguno";
    }

}

/*
 *
 * Entradas: Ninguna.
 * Salidas: La cantidad de humanos en la lista del mundo.
 * La funcion determina cuantos humanos existen en la lista del mundo.
 *
 * */

int ListaMundo::cantidadHumanos(){
    NodoHumano* nodoPersonaTemporal=primerHumano;

    int sumatoria=0;
    while(nodoPersonaTemporal!=NULL){
        nodoPersonaTemporal= nodoPersonaTemporal->siguiente;
        sumatoria++;

    }
        return sumatoria;
}

/*
 *
 *Entradas: id, nombre, apellido, pais y creencia.
 *Salidas: Ninguna.
 *Inserta un nodo en la lista del mundo de manera ordenada.
 *
 * */


void ListaMundo::insertar(int id,QString nombre, QString apellido,QString pais,QString creencia,
         QString profesion, QString correo){
    NodoHumano* humanoNuevo = new NodoHumano(id,nombre,apellido,pais,creencia,profesion,correo);

    if(primerHumano==NULL){
        primerHumano= humanoNuevo;
    }else if(primerHumano->id > humanoNuevo->id){
        primerHumano->anterior= humanoNuevo;
        humanoNuevo->siguiente= primerHumano;
        primerHumano= humanoNuevo;
    }else{
        NodoHumano* humanoTemporal = primerHumano;
        while(humanoTemporal->siguiente!=NULL && humanoTemporal->id< humanoNuevo->id){
            humanoTemporal= humanoTemporal->siguiente;
        }
        if(humanoTemporal->id > humanoNuevo->id){
                humanoNuevo->siguiente=humanoTemporal;
                humanoNuevo->anterior=humanoTemporal->anterior;
                humanoTemporal->anterior->siguiente= humanoNuevo;
                humanoTemporal->anterior=humanoNuevo;
        }else{
            humanoTemporal->siguiente= humanoNuevo;
            humanoNuevo->anterior=humanoTemporal;
        }
    }
}

/*
 *
 * Entradas: La persona a la que se le asignará hijos y el indice de apellido.
 * Salidas: Ninguna.
 * Le asigna a la persona ingresada los hijos que le correspondan.
 *
 * */

void ListaMundo::asignarHijos(NodoHumano *candidato, int indiceApellido){
    node* arbolApellido = arregloArbolesApellido[indiceApellido];
    int cantidadHijos = rand()%9;
    NodoHumano* hijo;

    for(int i = 0; i < cantidadHijos; i++){
        hijo = NULL;
        while(tieneCandidatos(arbolApellido,arbolApellido,candidato)){
            hijo = randomNode(arbolApellido)->humano;
            if(hijo != candidato && !esFamiliar(candidato,hijo) && !esFamiliar(hijo, candidato) && estaDisponible(hijo, arbolApellido)){
                break;
            }
        }
        candidato->listaHijos[i] = hijo;
    }
}

/*
 *
 * Entradas: El nodoHumano a insertar.
 * Salidas: Ninguna.
 * Se inserta en la lista, un nodo y se inserta de manera ordenada.
 *
 * */

void ListaMundo::insertar(NodoHumano* pHumano){
    for(int i=0;i<7;i++){
        pHumano->listaPecados[i]=0;
    }
    if(primerHumano==NULL){
        primerHumano = pHumano;
    }else if(primerHumano->id > pHumano->id){
        primerHumano->anterior= pHumano;
        pHumano->siguiente= primerHumano;
        primerHumano = pHumano;
    }else{
        NodoHumano* humanoTemporal = primerHumano;
        while(humanoTemporal->siguiente!=NULL && humanoTemporal->id < pHumano->id){
            humanoTemporal = humanoTemporal->siguiente;
        }
        if(humanoTemporal->id > pHumano->id){
                pHumano->siguiente = humanoTemporal;
                pHumano->anterior = humanoTemporal->anterior;
                humanoTemporal->anterior->siguiente = pHumano;
                humanoTemporal->anterior = pHumano;
        }else{
            humanoTemporal->siguiente = pHumano;
            pHumano->anterior = humanoTemporal;
        }
    }
}

/*
 *
 * Entradas: El humano por borrarse.
 * Salidas: Ninguna.
 * La funcion borra de la lista el humano indicado
 *
 * */

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

/*
 *
 * Entradas: El humano a insertar.
 * Salidas: Ninguna.
 * La funcion inserta al inicio de la lista el nodoHumano indicado.
 *
 * */

void ListaMundo::insertarAlInicio(NodoHumano* humano){
    if(primerHumano==NULL){
        primerHumano=humano;
    }
    else{
        humano->siguiente= primerHumano;
        primerHumano=humano;
    }
}

/*
 * Entradas: Apellido y país.
 * Salidas: Un vector con las personas que cumplen con el filtro de apellido y país.
 * La funcion crea un arreglo con las personas en la lista del mundo que cumplan con el filtro seleccionado y lo devuelve.
 *
 * */


std::vector<NodoHumano*> ListaMundo::filtroApellidoPais(QString apellido,QString pais){
    ListaMundo* listaTemporal= new ListaMundo();
    NodoHumano* humanoTemporal= primerHumano;

    while(humanoTemporal!=NULL){
        if(humanoTemporal->apellido==apellido && humanoTemporal->pais==pais){
            NodoHumano*humanoAInsertar= humanoTemporal->clonarHumano(humanoTemporal);
            listaTemporal->insertarAlInicio(humanoAInsertar);
        }
        humanoTemporal= humanoTemporal->siguiente;
    }
    int largoListaTemporal= listaTemporal->largoLista();

    std::vector<NodoHumano*> arregloFiltrados(largoListaTemporal);
    NodoHumano* humanoListaTemporal= listaTemporal->primerHumano;
        for(int i=0;i<arregloFiltrados.size();i++){
            arregloFiltrados[i]=humanoListaTemporal;
            humanoListaTemporal= humanoListaTemporal->siguiente;
        }
        arregloFiltrados=ordenarPecadores(arregloFiltrados,largoListaTemporal);

        return arregloFiltrados;
}


/*
 *
 * Entradas:  Id y la raiz del arbol.
 * Salidas: Ninguna.
 * Reemplaza al humano del arbol del mundo que se vaya a eliminar con uno cercano en la lista para mantener completo y balanceado el arbol.
 *
 *
 * */

void ListaMundo::reemplazarHumano(int id, node* raiz){
    if(raiz == NULL){
        return;
    } else if(raiz->humano->id == id){
        if(raiz->humano->anterior != NULL){
            raiz->humano = raiz->humano->anterior;
        }else{
            raiz->humano = raiz->humano->siguiente;
        }
    } else if(id < raiz->humano->id){
        reemplazarHumano(id, raiz->left);
    } else {
        reemplazarHumano(id, raiz->right);
    }
}

/*
 *
 * Entradas: Id.
 * Salidas: Retorna un booleano en caso de que exista el id.
 * Se busca en la lista del mundo, si el id existe retorna true, en caso contrario false;
 *
 * */

bool ListaMundo:: existeId(int id){
    NodoHumano* humanoActual=primerHumano;

    while (humanoActual!=NULL){
        if(humanoActual->id==id)
            return true;
        humanoActual=humanoActual->siguiente;
    }
    return false;
}

/*
 *
 * Entradas: Ninguna
 * Salidas: Largo de la lista.
 * Determina la cantidad de nodos Humanos existentes en la lista y lo retorna
 *
 * */

int ListaMundo::largoLista(){
    int largo=0;
    NodoHumano* humanoTemporal= primerHumano;

    while(humanoTemporal!=NULL){
        largo++;
        humanoTemporal= humanoTemporal->siguiente;
    }
    return largo;
}

/*
 *
 * Entradas: Inicio del rango del id por buscar, Fin del rango del id por buscar, id por buscar.
 * Salidas: Si se encuentra el humano se retorna, en otro caso NULL.
 * La funcion determina un rango en el cual se puede encontrar el id del humano por buscar y lo recorre.
 *
 * */



NodoHumano* buscarAuxiliar(NodoHumano *inicio, NodoHumano *fin,int id){
    if(inicio==fin){
        if(inicio->id > id){
            while(inicio!=NULL && inicio->id>=id ){
                if(inicio->id ==id){
                    return inicio;
                }
                inicio=inicio->anterior;

            }

        }
        else{
            while(inicio!=NULL && inicio->id<=id){
                if(inicio->id ==id){
                    return inicio;
                }
                inicio=inicio->siguiente;
        }
    }
}
    else{
        while(inicio!=fin){
            if(inicio->id==id){
                return inicio;
            }
            inicio=inicio->siguiente;
        }
    }
    return NULL;
}

/*
 *
 * Entradas: El humano a imprimir la información.
 * Salidas: Un QString con la informacion del humano.
 * La funcion almacena en una variable la información de la persona y la retorna.
 *
 * */


QString imprimirHumano(NodoHumano* humanoTemporal){
    QString listaNombrePecado[]={"Lujuria","Gula","Avaricia","Pereza","Ira","Envidia","Soberbia"};
    QString informacion;
    informacion += "Id: " + QString::number(humanoTemporal->id)+"\n";
    informacion+= "Nombre: "+humanoTemporal->nombre+"\n";
    informacion+= "Apellido: "+humanoTemporal->apellido+"\n";
    informacion+= "Ubicacion: "+humanoTemporal->ubicacion+"\n";
    informacion+= "Pais: "+humanoTemporal->pais+"\n";
    informacion+= "Suma de Pecados Total: "+ QString::number(sumaPecadosHumano(humanoTemporal))+"\n";

    for(int i=0; i<7;i++){
        informacion+= listaNombrePecado[i]+"\t";
    }
    informacion+= "\n";
    for(int i=0; i<7;i++){
        informacion+= QString::number(humanoTemporal->listaPecados[i])+"\t";
    }
    informacion+="\n";
    return informacion;
}

/*
 *
 * Entradas: El humano el cual se desea extraer la informacion.
 * Salidas: Un QString con la informacion de hijos y nietos del humano ingresado.
 * La funcion almacena en una variable la informacion de hijos y nietos de la persona y la retorna.
 *
 * */


QString imprimirNodo(NodoHumano* humanoTemporal){
    QString informacion;
    informacion += "Padre:\n";
    informacion += imprimirHumano(humanoTemporal);
    informacion += "\nHijos:\n\n";

    for(int i = 0; i < 7; i++){
        if(humanoTemporal->listaHijos[i] == NULL){
            break;
        } else {
            informacion += "=====================================================================\n";
            informacion += imprimirHumano(humanoTemporal->listaHijos[i]);
            informacion += "\nNietos:\n\n";
            for(int j = 0; j < 7; j++){
                if(humanoTemporal->listaHijos[i]->listaHijos[j] == NULL){
                    break;
                } else {
                    informacion += imprimirHumano(humanoTemporal->listaHijos[i]->listaHijos[j]);
                }
            }
            informacion += "=====================================================================\n";
        }
    }
    return informacion;
}

/*
 *
 * Entradas: Id del humano a buscar, raiz del arbol.
 * Salidas: El humano en caso de ser encontrado, NULL en cualquier otro caso.
 * La funcion busca mediante el arbol, en que posibles rangos podría estar el id, y lo busca en ese rango.
 *
 * */


NodoHumano* ListaMundo::buscar(int id, node *raiz){

    if(raiz->humano->id==id)
        return raiz->humano;

    else if(raiz->right==NULL & raiz->left==NULL){
        return buscarAuxiliar(raiz->humano,raiz->humano,id);

    }

    else if(id> raiz->humano->id && id< raiz->right->humano->id){
        return buscarAuxiliar(raiz->humano,raiz->right->humano,id);
    }

    else if(id< raiz->humano->id && id> raiz->left->humano->id){ //> < antes asi
        return buscarAuxiliar(raiz->left->humano,raiz->humano,id);
    }

    else if(id<raiz->humano->id){
        return buscar(id,raiz->left);
    }

    else{
        return buscar(id,raiz->right);
    }

}

/*
 *
 * Entradas: El id.
 * Salidas: El humano si fue encontrado, NULL en otro caso.
 * La funcion busca en la lista del mundo si existe alguna coincidencia de id y retorna el nodo correspondiente.
 *
 * */


NodoHumano* ListaMundo::buscar(int id){
    NodoHumano* humanoTemporal= primerHumano;
    while(humanoTemporal!=NULL){
        if(humanoTemporal->id == id){
            return humanoTemporal;
        }
        humanoTemporal= humanoTemporal->siguiente;
    }
        return NULL;
}

/*
 *
 * Entradas: Lista con los nombres de pecados.
 * Salidas: Un QString con la informacion de todos los humanos del mundo.
 * La funcion almacena en una variable QString toda la informacion de los humanos del mundo.
 *
 * */



QString ListaMundo::imprimirListaMundo(QString* listaNombrePecado){
    NodoHumano* humanoTemporal= primerHumano;
    QString informacion;
    int humano=1;
    int indice=0;

    while(humanoTemporal!=NULL){
        informacion+= QString::number(humano)+") ";
        informacion+= "Nombre: "+humanoTemporal->nombre+"\n";
        informacion+= "Apellido: "+ humanoTemporal->apellido+"\n";
        informacion+= "ID: "+QString::number(humanoTemporal->id)+"\n";
        informacion+= "Ubicacion: "+humanoTemporal->ubicacion+"\n";
        informacion+= QString ::fromStdString(humanoTemporal->momentoNacimiento)+"\n";
        informacion+= "Creencia: "+ humanoTemporal->creencia+"\n";
        informacion+= "País: "+ humanoTemporal->pais+"\n";
        informacion+= "Continente: "+humanoTemporal->continente+"\n";

        informacion+= "Profesión: "+ humanoTemporal->profesion+"\n";
        informacion+= "Correo: "+ humanoTemporal->correo+"\n";
        informacion+= "Suma de Pecados en total: "+QString::number(sumaPecadosHumano(humanoTemporal)) +"\n";
        informacion+= "Cantidad de Pecados \n";
        for(int i=0; i<7;i++){
           informacion+= listaNombrePecado[i]+"\t";
        }
        informacion+= "\n";
        for(int i=0; i<7;i++){
            informacion+= QString::number(humanoTemporal->listaPecados[i])+"\t";
        }
        informacion+= "\n\n";
        informacion += "Hijos:\n[";
        for(int i = 0; i < 8; i++){
            if(humanoTemporal->listaHijos[i] != NULL){
                informacion += humanoTemporal->listaHijos[i]->nombre +
                        " (" + QString::number(humanoTemporal->listaHijos[i]->id) + "), ";
            }
        }
        informacion += "]\n\n";
        humanoTemporal= humanoTemporal->siguiente;
        humano++;
        indice++;
    }
    return informacion;
}


/*
 *
 * Entradas: Ninguna
 * Salidas: Ninguna
 * La funcion otorga pecados a los humanos del mundo y otorga la herencia a hijos y nietos.
 *
 * */

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


        for(int i = 0; i < 8; i++){
            if(humanoTemporal->listaHijos[i] != NULL){
                for(int j=0;j<7;j++)
                    humanoTemporal->listaHijos[i]->listaPecados[j] += (arregloPecados[j] / 2);

                for(int k = 0; k < 8; k++){
                    if(humanoTemporal->listaHijos[i]->listaHijos[k] != NULL){
                        for(int w=0;w<7;w++)
                            humanoTemporal->listaHijos[i]->listaHijos[k]->listaPecados[w] += (arregloPecados[w] / 4);
                    } else{
                        break;
                    }
                }
            } else{
                break;
            }
        }
        humanoTemporal= humanoTemporal->siguiente;
    }

}

/*
 *
 * Entradas: Un nodo Humano.
 * Salidas: La cantidad total de pecados de ese humano.
 * La funcion retorna la sumatoria total de pecados de la persona ingresada.
 *
 * */

int sumaPecadosHumano(NodoHumano* persona){

    int sumatoria=0;
    for(int i=0; i<7 ;i++)
        sumatoria+= persona->listaPecados[i];
    return sumatoria;


}

/*
 *
 * Entradas: Arreglo de estructura de tipo Pais, longitud del arreglo.
 * Salidas: Ninguna.
 * La funcion ordena de menor a mayor la cantidad de pecados que posea cada pais.
 *
 * */

void insertion_sort(Pais* arr[], int length){
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


/*
 *
 * Entradas: Un vector de humanos, largo del vector.
 * Salidas: El vector de humano ordena de mas a menos pecador.
 * La funcion ordena de mayor a menor la cantidad de pecados de los humanos.
 *
 * */

std::vector<NodoHumano*> ordenarPecadores(std::vector<NodoHumano*>arregloPecadores, int largo){
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
    return arregloPecadores;
}

/*
 *
 * Entradas: Un arreglo con las personas que estan en el paraiso.
 * Salidas: El arreglo de las persoans del paraiso ordenadas en orden alfabetico.
 * La funcion ordena en forma alfabetica por apellido, las personas del paraiso.
 *
 * */


std::vector<NodoHumano*> ordenarSalvados(std::vector<NodoHumano*> arregloSalvados, int largo){
    int j;
    NodoHumano* temporal;
    NodoHumano* humanoJ;
    NodoHumano* humanoK;

    for(int i = 0; i < largo; i++){
        j = i;
        humanoJ= arregloSalvados[j];
        humanoK= arregloSalvados[j-1];

        while(j > 0 && strcasecmp((humanoJ->apellido).toUtf8().constData(),(humanoK->apellido).toUtf8().constData())<0){

            temporal = arregloSalvados[j];
            arregloSalvados[j] = arregloSalvados[j-1];
            arregloSalvados[j-1] = temporal;
            j--;
            humanoJ= arregloSalvados[j];
            humanoK= arregloSalvados[j-1];
        }
    }
    return arregloSalvados;
}

/*
 *
 * Entradas: Un arreglo con los continentes del mundo.
 * Salidas: El arreglo de continentes ordenado del mayor al menos pecador.
 * La funcion ordena de mayor a menor los pecados totales de los continentes.
 *
 * */

std::vector<Continente*> ordenarContinentes(std::vector<Continente*> arregloContinentes){

    int j;
    Continente* temporal;

    for(int i = 0; i < 5; i++){
        j = i;

        Continente* continenteJ= arregloContinentes[j];
        Continente* continenteK= arregloContinentes[j-1];

        while(j > 0 && continenteJ->pecadosTotales > continenteK->pecadosTotales){
            temporal = arregloContinentes[j];
            arregloContinentes[j] = arregloContinentes[j-1];
            arregloContinentes[j-1] = temporal;
            j--;
            continenteJ= arregloContinentes[j];
            continenteK= arregloContinentes[j-1];
        }
    }
    return arregloContinentes;


}

/*
 *
 * Entradas: Ninguna.
 * Salidas: El arreglo de continentes ordenados de mas a menos pecador.
 * La funcion verifica cada continente contra todos los humanos y extrae la cantidad total de pecados con el fin de ordenarlos de mayor a menor.
 *
 * */

std::vector<Continente*> ListaMundo::mapaCalor(){
    std::vector <Continente*> continentes(5);

    QString arregloContinentes[]={"America","Europa","Asia","Africa","Oceania"};

    for(int i=0;i<5;i++){
        int contador=0;
    NodoHumano* humanoTemporal= primerHumano;

        while(humanoTemporal!=NULL){

            if(humanoTemporal->continente== arregloContinentes[i]){

                contador+=sumaPecadosHumano(humanoTemporal);

            }
            humanoTemporal=humanoTemporal->siguiente;

        }

        continentes[i]= new Continente(arregloContinentes[i],contador);
    }

    continentes= ordenarContinentes(continentes);

    return continentes;

}


/*
 *
 * Entradas: Arreglo de los paises, cual top, si 10 ó 5.
 * Salidas: Un QString indicando los paises en el top 10 o top 5
 * La funcion determina la cantidad de pecados de los paises, los ordena de mayor a menor, y determine los tops de acuerdo al arreglo.
 *
 * */

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

      if(cualTop){
          for(int i=241; i>231; i--)
              top += arregloPaises[i]->nombrePais+ " " +QString::number(arregloPaises[i]->pecadosTotales)+"\n";
      }
      else{
          int i=0;

          for(int j=i; j< i+5; j++)
              top += arregloPaises[j]->nombrePais+" "+QString::number(arregloPaises[j]->pecadosTotales)+"\n";
      }

      return top;

}

/*
 *
 * Entradas: Ninguna
 * Salidas: La mitad de la lista
 * La funcion recorre la funcion y devuelve el humano que esté en la mitad de la lista.
 *
 * */


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

/*
 * Entradas: pais sobre el cual se desean contar los ciudadanos
 * Salidas: cantidad de ciudadanos en el pais ingresado
 *
 * Itera sobre la lista correspondiente y suma uno a un contador
 * si el pais del humano actual corresponde
 */
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

<<<<<<< Updated upstream
/*
 *
 * Entradas: Cual lista se ordenará.
 * Salidas: un QString con la información de la lista ordenada seleccionada.
 * La función determina si se ordenará la lista del paraiso o la del infierno y se llama para cada una un método especial de ordenamiento, al final se devuelve la información de los humanos de la lista ordenada.
 *
 * */
=======
>>>>>>> Stashed changes

QString ListaMundo::listaCondenadosSalvadosOrdenada(bool cualLista){
    QString listaNombrePecado[]={"Lujuria","Gula","Avaricia","Pereza","Ira","Envidia","Soberbia"};

    int largo = largoLista();

    std::vector<NodoHumano*> arregloCondenadosSalvados(largo);
    NodoHumano* humanoTemporal= primerHumano;


    for(int i=0; i<largo;i++){
        arregloCondenadosSalvados[i]= humanoTemporal;
        humanoTemporal= humanoTemporal->siguiente;
    }
   if(cualLista)
        arregloCondenadosSalvados= ordenarPecadores(arregloCondenadosSalvados,largo);
   else {
        if(largo>2)
            arregloCondenadosSalvados=ordenarSalvados(arregloCondenadosSalvados,largo); //TODO todavia no ordena
   }
    int indice=0;
    int humano=1;
    QString informacion;

    while(indice<largo){
        NodoHumano* humanoTemporal= arregloCondenadosSalvados[indice];

    informacion+= QString::number(humano)+") ";
    informacion+= "Nombre: "+humanoTemporal->nombre+"\n";
    informacion+= "Apellido: "+ humanoTemporal->apellido+"\n";
    informacion+= "ID: "+QString::number(humanoTemporal->id)+"\n";
    informacion+= QString ::fromStdString(humanoTemporal->momentoNacimiento)+"\n";
    informacion+= "Creencia: "+ humanoTemporal->creencia+"\n";
    informacion+= "País: "+ humanoTemporal->pais+"\n";
    informacion+= "Profesión: "+ humanoTemporal->profesion+"\n";
    informacion+= "Correo: "+ humanoTemporal->correo+"\n";
    informacion+= "Suma de Pecados en total: " + QString::number(sumaPecadosHumano(humanoTemporal))+"\n";
    informacion+= "\n Cantidad de Pecados \n";
    for(int i=0; i<7;i++){
        informacion+= listaNombrePecado[i]+"\t";
    }
    informacion+= "\n";
    for(int i=0; i<7;i++){
        informacion+= QString::number(humanoTemporal->listaPecados[i])+"\t";
    }
    informacion+= "\n\n";
    informacion += "Hijos:\n[";
    for(int i = 0; i < 8; i++){
        if(humanoTemporal->listaHijos[i] != NULL){
            informacion += humanoTemporal->listaHijos[i]->nombre +
                    " (" + QString::number(humanoTemporal->listaHijos[i]->id) + "), ";
        }
    }
    informacion += "]\n\n";
    indice++;
    humano++;
    }

    return informacion;
}

/*
 * Entradas: cadena con el pais del cual se desea generar el heap
 * Salidas: vector(heap) del pais ingreado
 *
 * Genera un vector de humanos a partir de los humanos de la lista del
 * mundo que pertenecen al pais ingresado y despues la ordena para hacer
 * el heap.
 */
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

   arregloPecadores= ordenarPecadores(arregloPecadores, largoArreglo);

    return arregloPecadores;
}

/*
 * Entradas: numero.
 * Salidas: La potencia más cercana, mayor, del número ingresado.
 * La funcion determina la potencia más cercana, mayor, del número ingresado.
 *
 * */


int determinarPotenciaCercana(int numero)
{
    return (pow(2, ceil(log(numero)/log(2)))) - 1;
}

/*
 * Entradas: ninguna
 * Salidas: ninguna
 *
 * Genera un arbol binario balanceado y completo en todos sus niveles con el 1%
 * de los humanos de la lista del mundo mas los que sean necesarios para que el
 * arbol sea completo. Esto se determina caculando la potencia de dos mas cerca-
 * na al 1% menos uno.
 */
void ListaMundo::generarArbol(){
    arbolMundo = NULL;
    NodoHumano* mitadHumano= mitadLista();
    int cantidadCompleta= determinarPotenciaCercana(largoLista()/100);

    arbolMundo = insert(arbolMundo, mitadHumano);
    cantidadCompleta--;

    int desplazamiento = largoLista() / cantidadCompleta;

    NodoHumano* humanoIzquierda= mitadHumano;
    NodoHumano* humanoDerecha= mitadHumano;
    std::vector <NodoHumano*> arregloPecadores(cantidadCompleta);

    for(int i = 0; i < cantidadCompleta; i++){
        humanoDerecha = desplazarPuntero(humanoDerecha,desplazamiento,true);
        humanoIzquierda =  desplazarPuntero(humanoIzquierda, desplazamiento,false);
        arregloPecadores[i] = humanoDerecha;
        arregloPecadores[++i] = humanoIzquierda;
    }

    for(int i = 0; i < cantidadCompleta; i++){
        arbolMundo = insert(arbolMundo, arregloPecadores[i]);
    }

}

/*
 *
 * Entradas: El nodo de la persona, la cantidad de desplazamiento, la dirección en la que se desplazará.
 * Salidas: Devuelve el nodo humano en donde quedó el puntero.
 * La función desplaza el puntero dada una dirección de memoria, y retorna el nodo en donde el puntero quedó apuntando.
 *
 * */

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

/*
 * Entradas: nodo raiz del arbol que se desea contar
 * Salidas: cantidad de nodos en el arbol
 *
 * Funcion recursiva que cuenta la cantidad total de nodos en el arbol ingresado.
 */
int ArbolMundo::cantidadNodos(NodoArbolMundo* raiz){

    if(raiz==NULL)
        return 0;
    else
        return 1+ cantidadNodos(raiz->derecha) + cantidadNodos(raiz->izquierda);

}

/*
 *
 * Entradas: El humano a insertar y la raiz del arbol
 * Salidas: Retorna la raiz para poder reconstruir el árbol.
 * La funcion inserta en el arbol del mundo, preguntando por el id para ver en que posicion debe insertarlo.
 *
 * */
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

/*
 * Entradas: nodo humano que se desea insertar a la lista
 * Salidas: ninguna
 *
 * Inserta un nodo humano a la lista de forma ordenada.
 */
void ListaMundo::insertarNodoHumano(NodoHumano* humanoNuevo){

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

    }
}

/*
 *
 * Entradas: Ninguna.
 * Salidas: Total de pecados.
 * La funcion determina la cantidad total de pecados de toda la humanidad.
 *
 * */

long long ListaMundo::sumarPecadosHumanidad(){
    long long sumador = 0;
    NodoHumano* humanoActual = primerHumano;

    while(humanoActual != NULL){
        sumador += sumaPecadosHumano(humanoActual);
        humanoActual = humanoActual->siguiente;
    }

    return sumador;
}

/*
 * Entradas: suma total de los pecados de la humanidad
 * Salidas: cadena con la lista de humanos generada
 *
 * Retorna una cadena con la informacion de los humanos actualmente
 * en la lista con la suma de sus pecados y el porcentaje que repre-
 * sentan de toda la humanidad.
 */
QString ListaMundo::imprimirOrdenPecados(long long pecadosHumanidad){
    QString listaNombrePecado[]={"Lujuria","Gula","Avaricia","Pereza","Ira","Envidia","Soberbia"};
    int largo = largoLista();

    if(largo > 0){
        std::vector<NodoHumano*> arregloHumanos(largo);
        NodoHumano* humanoActual = primerHumano;


        for(int i = 0; i < largo; i++){
            arregloHumanos[i] = humanoActual;
            humanoActual = humanoActual->siguiente;
        }

        arregloHumanos = ordenarPecadores(arregloHumanos,largo);
        QString informacion;
        NodoHumano* humanoTemporal;
        double porcentajePecados;

        for(int j = 0; j < largo; j++){
            humanoTemporal = arregloHumanos[j];

            informacion+= QString::number(j+1)+") ";
            informacion+= "Nombre: "+humanoTemporal->nombre+"\n";
            informacion+= "Apellido: "+ humanoTemporal->apellido+"\n";
            informacion+= "ID: "+QString::number(humanoTemporal->id)+"\n";
            informacion+= QString ::fromStdString(humanoTemporal->momentoNacimiento)+"\n";
            informacion+= "Creencia: "+ humanoTemporal->creencia+"\n";
            informacion+= "País: "+ humanoTemporal->pais+"\n";
            informacion+= "Profesión: "+ humanoTemporal->profesion+"\n";
            informacion+= "Correo: "+ humanoTemporal->correo+"\n";
            informacion+= "Suma de Pecados en total: " + QString::number(sumaPecadosHumano(humanoTemporal))+"\n";
            porcentajePecados = ((double)sumaPecadosHumano(humanoTemporal) / pecadosHumanidad) * 100.0;
            informacion+= "Porcentaje de Pecados: " + QString::number(porcentajePecados) + "%\n";
            informacion+= "\n Cantidad de Pecados \n";
            for(int i=0; i<7;i++){
                informacion+= listaNombrePecado[i]+"\t";
            }
            informacion+= "\n";
            for(int i=0; i<7;i++){
                informacion+= QString::number(humanoTemporal->listaPecados[i])+"\t";
            }
            informacion+= "\n\n";
            informacion += "Hijos:\n[";
            for(int i = 0; i < 8; i++){
                if(humanoTemporal->listaHijos[i] != NULL){
                    informacion += humanoTemporal->listaHijos[i]->nombre +
                            " (" + QString::number(humanoTemporal->listaHijos[i]->id) + "), ";
                }
            }
            informacion += "]\n\n";
        }

        return informacion;
    } else {
        return "Sin humanos.";
    }
}
/*
 *
 * Entradas: El arbol del apellido por buscar, la lista del mundo.
 * Salidas: Una lista con todos los nodos correspondientes a ese apellido.
 * La funcion recorre recursivamente el arbol y va insertando nodos en la lista.
 *
 * */
ListaMundo* ListaMundo::filtrarApellidos(node *arbolApellido, ListaMundo *lista){
    if(lista == NULL){
        lista = new ListaMundo();
    }
    if(arbolApellido != NULL){
        lista->insertarNodoHumano(arbolApellido->humano->clonarHumano(arbolApellido->humano));
        filtrarApellidos(arbolApellido->left,lista);
        filtrarApellidos(arbolApellido->right,lista);
    }
    return lista;
}

/*
 * Entradas: cadena con la cual se van a filtrar los humanos
 * Salidas: listaMundo auxiliar
 *
 * Funcion que itera sobre una listaMundo principal y mete los humanos
 * que cumplen con el filtro ingresado a una lista auxiliar que despues
 * es retornada.
 */
ListaMundo* ListaMundo::filtrarLista(QString filtro){
    ListaMundo* lista = new ListaMundo();
    NodoHumano* humanoActual = primerHumano;

    while(humanoActual != NULL){
        if(humanoActual->cumpleFiltro(filtro)){
            lista->insertarNodoHumano(humanoActual->clonarHumano(humanoActual));
        }
        humanoActual = humanoActual->siguiente;
    }

    return lista;
}
