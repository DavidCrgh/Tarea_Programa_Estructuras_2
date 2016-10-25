#include "globales.h"

QString apellidos[1000];
QString nombres [1000];
QString paises[242];
QString profesiones[50];
QString creencias[10];
QString nombrePecado[]={"Lujuria","Gula","Avaricia","Pereza","Ira","Envidia","Soberbia"};


QString* cargarApellidos(){

    QFile inputFile("C:/Users/Francisco Contreras/Documents/Tarea_Programada_Estructuras_2/recursos/datos/apellidos.txt");
    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);
       int indice=0;
       while (!in.atEnd())
       {
          QString line = in.readLine();
          apellidos[indice]=line;
          indice++;
       }

       inputFile.close();
    }
    return apellidos;
}

QString* cargarNombres(){
    QFile inputFile("C:/Users/Francisco Contreras/Documents/Tarea_Programada_Estructuras_2/recursos/datos/nombres.txt");
    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);
       int indice=0;
       while (!in.atEnd())
       {
          QString line = in.readLine();
          nombres[indice]=line;
          indice++;
       }

       inputFile.close();
    }
    return nombres;
}

QString* cargarPaises(){

    QFile inputFile("C:/Users/Francisco Contreras/Documents/Tarea_Programada_Estructuras_2/recursos/datos/paises.txt");
    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);
       int indice=0;
       while (!in.atEnd())
       {
          QString line = in.readLine();
          paises[indice]=line;
          indice++;
       }

       inputFile.close();
    }

    return paises;
}

QString* cargarCreencias(){

    QFile inputFile("C:/Users/Francisco Contreras/Documents/Tarea_Programada_Estructuras_2/recursos/datos/religiones.txt");
    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);
       int indice=0;
       while (!in.atEnd())
       {
          QString line = in.readLine();
          creencias[indice]=line;
          indice++;
       }

       inputFile.close();
    }
        return creencias;
}

QString* cargarProfesiones(){

    QFile inputFile("C:/Users/Francisco Contreras/Documents/Tarea_Programada_Estructuras_2/recursos/datos/profesiones.txt");
    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);
       int indice=0;
       while (!in.atEnd())
       {
          QString line = in.readLine();
          profesiones[indice]=line;
          indice++;
       }

       inputFile.close();
    }
    return profesiones;
}

QString* cargarPecados(){


    return nombrePecado;

}





