#include "globales.h"

QString apellidos[1000];
QString nombres [1000];
QString paises[242];
QString profesiones[50];
QString creencias[10];
QString continentes[242];
QString nombrePecado[]={"Lujuria","Gula","Avaricia","Pereza","Ira","Envidia","Soberbia"};
//ArbolApellidos* arbolesApellidos[1000];

QString* cargarApellidos(){

    QFile inputFile(":/datos/recursos/datos/apellidos.txt");
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

QString* cargarContinentes(){

    QFile inputFile(":/datos/recursos/datos/continentes.txt");
    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);
       int indice=0;
       while (!in.atEnd())
       {
          QString line = in.readLine();
          continentes[indice]=line;
          indice++;
       }

       inputFile.close();
    }
    return continentes;
}

QString* cargarNombres(){
    QFile inputFile(":/datos/recursos/datos/nombres.txt");
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

    QFile inputFile(":/datos/recursos/datos/paises.txt");
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

    QFile inputFile(":/datos/recursos/datos/religiones.txt");
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

    QFile inputFile(":/datos/recursos/datos/profesiones.txt");
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

/*ArbolApellidos** popularArbolesApellido()
{
    for(int i = 0; i < 1000; i++){
        arbolesApellidos[i] = new ArbolApellidos();

    }
    return arbolesApellidos;
}*/





