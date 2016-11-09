#include "listamundo.h"
#include "windows.h"
#include <iostream>
#include <cstdlib>
#include "unistd.h"
using namespace std;

void enviarCorreo(const char* ejecucion){
    chdir("C:\\Users\\Francisco Contreras\\workspace\\pruebaCorreo\\src\\pruebaCorreo\\");
    system(ejecucion);
}

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

void ListaMundo::insertarAlInicio(NodoHumano* humano){
    if(primerHumano==NULL){
        primerHumano=humano;
    }
    else{
        humano->siguiente= primerHumano;
        primerHumano=humano;
    }
}

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

bool ListaMundo:: existeId(int id){
    NodoHumano* humanoActual=primerHumano;

    while (humanoActual!=NULL){
        if(humanoActual->id==id)
            return true;
        humanoActual=humanoActual->siguiente;
    }
    return false;
}

int ListaMundo::largoLista(){
    int largo=0;
    NodoHumano* humanoTemporal= primerHumano;

    while(humanoTemporal!=NULL){
        largo++;
        humanoTemporal= humanoTemporal->siguiente;
    }
    return largo;
}

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
        //informacion+= "Ubicacion: "+humanoTemporal->ubicacion+"\n";
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

int sumaPecadosHumano(NodoHumano* persona){

    int sumatoria=0;
    for(int i=0; i<7 ;i++)
        sumatoria+= persona->listaPecados[i];
    return sumatoria;


}

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

int determinarPotenciaCercana(int numero)
{
    return (pow(2, ceil(log(numero)/log(2)))) - 1;
}

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

long long ListaMundo::sumarPecadosHumanidad(){
    long long sumador = 0;
    NodoHumano* humanoActual = primerHumano;

    while(humanoActual != NULL){
        sumador += sumaPecadosHumano(humanoActual);
        humanoActual = humanoActual->siguiente;
    }

    return sumador;
}

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
